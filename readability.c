#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string s)
{
    int letters = 0;
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        char c = s[i];
        c = toupper(c);
        if (c >= 'A' && c <= 'Z')
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string s)
{
    int words = 1;
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        char c = s[i];
        if (c == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string s)
{
    int sentences = 0;
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        char c = s[i];
        if (c == '.' || c == '?' || c == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
