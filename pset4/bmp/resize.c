/****************************************************************************
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: factor infile outfile\n");
        return 1;
    }
    
    // factor of resizing
    int n = atoi(argv[1]);
    if ( n <= 0 || n > 100 )
        return 5;
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];    

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf1,bf2;
    fread(&bf1, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi1,bi2;
    fread(&bi1, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf1.bfType != 0x4d42 || bf1.bfOffBits != 54 || bi1.biSize != 40 || 
        bi1.biBitCount != 24 || bi1.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // alter header 
    bi2 = bi1;
    bf2 = bf1;
    bi2.biSize = bi1.biSize;
    bi2.biWidth = n * bi1.biWidth;
    bi2.biHeight = n * bi1.biHeight;
    bf2.bfSize = 54 + bi2.biWidth * abs(bi2.biHeight) * 3 + abs(bi2.biHeight) * ((4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4);
    bi2.biSizeImage = bi2.biWidth * abs(bi2.biHeight) * 3 + abs(bi2.biHeight) * ((4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf2, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi2, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi1.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // determine padding for scalines of output file
    int padding2 = (4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi1.biHeight); i < biHeight; i++)
    {
        // temporary storage for triples
        RGBTRIPLE temp[bi2.biWidth];
        int cur = 0;
        
        // iterate over pixels in scanline
        for (int j = 0; j < bi1.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            // write RGB triple to outfile
            for (int i = 0; i < n; i++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                // store the triples
                temp[cur] = triple;
                cur++;
            } 
         }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
        

        // then add it back (to demonstrate how)
        for (int i = 0; i < n - 1; i++)
        {
            for (int k = 0; k < padding2; k++)
                fputc(0x00, outptr);    
            fwrite(temp,sizeof(temp),1,outptr);       
        }
        // the remaining padding
        for (int k = 0; k < padding2; k++)
                fputc(0x00, outptr);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
