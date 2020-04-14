#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_letters(string input);
int count_words(string input);
int count_sentences(string input);
int coleman_liau_index(string input);

int main (void)
{
    string text = get_string("Text: ");

    int index = coleman_liau_index(text);
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    else
    {
     printf("Grade %i\n", index);
    }
    // int letter_count = count_letters(text);
    // int word_count = count_words(text);
    // int sentence_count = count_sentences(text);
    // printf("%i letter(s)\n%i word(s)\n%i sentence(s)\n", letter_count, word_count, sentence_count);
}


int count_letters(string input)
{
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            count++;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            count++;
        }
    }
    return count;
}

int count_words(string input)
{
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string input)
{
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            count++;
        }
    }
    return count;
}


int coleman_liau_index(string input)
{
    int letter_count = count_letters(input);
    int word_count = count_words(input);
    int sentence_count = count_sentences(input);

    float l = (letter_count / word_count) * 100;
    float s = (sentence_count / word_count) * 100;

    return (0.0588 * l) - (0.296 * s) - 15.8;
}
