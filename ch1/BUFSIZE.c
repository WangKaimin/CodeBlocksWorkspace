/*--- BUFSIZE.C -------------------------- Listing 1-1 --------
 * Purpose:  Demonstrate use of setvbuf
 * Usage:    bufsize infile outfile [insize [outsize]]
 * Method:   Copies infile to outfile one character at a time,
 *           reporting elapsed time. Infile is set to use a
 *           buffer of insize bytes, while outfile uses an
 *           outsize bytes buffer. Default size is 512 bytes.
 * >> Should be changed per text for UNIX systems <<
 *-----------------------------------------------------------*/

//#include <bios.h>   /* for timer function */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <windows.h>


#undef CopyFile
#pragma comment(lib, "kernel32.lib")//yyw

#define DEF_BUF 512

long GetCPUTime() //获取当前时间，精度100微秒
{
	static LARGE_INTEGER li = {0};
	LARGE_INTEGER linow = {0};
	if (li.QuadPart == 0)
		QueryPerformanceFrequency(&li); //获得时钟频率 by wkm
	QueryPerformanceCounter(&linow);
	//printf("linow.QuadPart * 10000 / li.QuadPart=%ld\n",linow.QuadPart * 10000 / li.QuadPart);
	return linow.QuadPart * 10000 / li.QuadPart;
}

#ifdef __TURBOC__               /* Borland   */
#define get_clock_ticks(x) x=biostime(0,0L)
#else                           /* Microsoft and Watcom */
#define get_clock_ticks(x) \
	x = GetCPUTime()//yyw
//        _bios_timeofday(_TIME_GETCLOCK, &x)//yyw
#endif

long CopyFile ( char *infilename, char *outfilename,
            size_t insize, size_t outsize )
{
    int  c;
    long starttime, donetime;
    FILE *infile, *outfile;

    /* open input file and setup its buffer */
    if (( infile = fopen ( infilename, "rb" )) == NULL)
    {
          printf ( "Can't open %s\n", infilename );
          exit ( 1 );
    }

    if ( setvbuf ( infile, NULL, _IOFBF, insize ))
    {
         printf ( "Couldn't set infile buffer to %u bytes.\n",
                   insize );
         exit ( 1 );
    }


    /* open output file and setup its buffer */

    if (( outfile = fopen ( outfilename, "wb" )) == NULL )
    {
          printf ( "Can't open %s\n", outfilename );
          exit ( 1 );
    }

    if ( setvbuf ( outfile, NULL, _IOFBF, outsize ))
    {
         printf ( "Couldn't set outfile buffer to %u bytes.\n",
                   outsize );
        exit ( 1 );
    }

    /* do it */

    get_clock_ticks ( starttime );    /* get timer value */
    while (( c = fgetc ( infile )) != EOF )
        fputc ( c, outfile );
    get_clock_ticks ( donetime );
    fclose ( infile );
    fclose ( outfile );

    return ( donetime - starttime );
}


int main ( int argc, char *argv[] )
{
    size_t insize, outsize;
    int    i;
    long   total, average, lo, hi, elapsed;
    long   min_average = LONG_MAX, min_lo, min_hi; //by WangKaimin
    size_t  min_insize, min_outsize; //by wkm

    insize = outsize = DEF_BUF;

    if ( argc < 3 || argc > 5 )
    {
        fprintf ( stderr,
         "Usage: BUFSIZE infile outfile [insize [outsize]]\n" );
        return ( EXIT_FAILURE );
    }

    /* get buffer sizes */
    if ( argc > 3 )
         insize = (unsigned) atoi ( argv[3] );

    if ( argc > 4 )
         outsize = (unsigned) atoi ( argv[4] );

    /* now, copy the file five times */

    for( ; ; insize += 64,outsize += 64)
    {
        total = hi = 0;
        lo = LONG_MAX;
        for ( i = 1; ; i++ )
        {
            elapsed = CopyFile ( argv[1], argv[2], insize, outsize );
            if ( elapsed > hi )
                hi = elapsed;
            if ( elapsed < lo )
                lo = elapsed;
            total += elapsed;

            if ( total > 500 ||   /* Change this value depending   */
                                  /*   on how long you can wait    */
                     i > 4 )      /* Do 4 passes, if time limit OK */
                break;
        }

        average = total / i;

        /* by wkm */
        if(min_average>average)
        {
            min_average = average;
            min_lo = lo;
            min_hi = hi;
            min_insize = insize;
            min_outsize = outsize;
        }


        printf ( "Average of %4ld ticks (%4ld - %4ld). "
                 "Insize = %5u. Outsize = %5u.\n",
                 average, lo, hi, insize, outsize );
        if(insize >= 2048)
            break;
    }

    printf ( "\nThe best one:\n" );
    printf ( "Average of %4ld ticks (%4ld - %4ld). "
            "Insize = %5u. Outsize = %5u.\n",
            min_average, min_lo, min_hi, min_insize, min_outsize );

    return ( EXIT_SUCCESS );
}
