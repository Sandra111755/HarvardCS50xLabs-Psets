#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef char FILENAME[8];
typedef uint8_t BLOCKSIZE[512];

// initialize image counter for sprintf
int imagescounter = 0;

// initialize array of 8 chars for storing file name structure
FILENAME fname;

// initialize a file pointer for output files
FILE *outpointer = NULL;

// initialize array of unsigned integers of size 512 bytes for buffer for storing the read data
BLOCKSIZE buffer;

int main(int argc, char *argv[])
{
    // ensures only one argument

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open .raw file at (pointer) inpointer if able

    FILE *inpointer = fopen(argv[1], "r");
    if (inpointer == NULL)
    {
        printf("could not open file");
        return 1;
    }

    /* pass the data from the inpointer into the buffer in 512 byte blocks
       will iterate in 512 byte blocks until the end of the .raw file */

    while (fread(buffer, sizeof(buffer), 1, inpointer))
    {
        /* read buffer data header (if it exists) in the buffer
           if header data exists name a new file incrementally using the imagescounter variable.
           opens new file for writing and image counter iterates */

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(fname, "%03i.jpg", imagescounter);
            outpointer = fopen(fname, "w");
            imagescounter++;
        }

        /* writes from the outpointer to the buffer*/

        if (outpointer != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outpointer);
        }
    }

    fclose(outpointer);
    fclose(inpointer);
    return 0;
}