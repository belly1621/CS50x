// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t BYTE;
typedef int16_t SAMPLE_AUDIO;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE headerbuffer[HEADER_SIZE];

    fread(headerbuffer, sizeof(BYTE), 44, input);
    fwrite(headerbuffer, sizeof(BYTE), 44, output);

    // TODO: Read samples from input file and write updated data to output file

    SAMPLE_AUDIO buffer;

    while (fread(&buffer, sizeof(SAMPLE_AUDIO), 1, input) == 1)
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(SAMPLE_AUDIO), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
