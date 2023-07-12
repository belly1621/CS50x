#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //open memory card
    FILE *inptr = fopen(argv[1], "r");
    //check valid file
    if (inptr == NULL)
    {
        printf("Could not open");
        return 2;
    }

    unsigned char buffer[512];

    // track number of images
    int image_count = 0;

    FILE *output_file = NULL;

    char *filename = malloc(8 * sizeof(char));

    //read 512 bytes
    while (fread(buffer, sizeof(char), 512, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", image_count);

            output_file = fopen(filename, "w");

            image_count ++;
        }


        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(inptr);

    return 0;
}
