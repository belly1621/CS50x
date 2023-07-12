#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Use CTYPE.H
//Coleman Liau Index = Index = .0588 * L - .296 * S - 15.8
//L = average number of letters per 100 words
//S = average number of sentances per 100 words
//TODO: get text, print text, - DONE 12:02pm 6/25/22
//TODO: count letters (isletter),Define "Word"(Count spaces + 1 word),Define sentences(any . , ! , ?)
//TODO: round output to nearest whole, output grade, DONE 12:51pm 6/25/22
// if < 1 output "Before Grade 1", if > 16 output "Grade 16+"

int count_letters(string text);
int main(void)
{
    string text = get_string("Text:");

    int count_letters(string text);

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}