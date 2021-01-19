#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int compute_letters(string text);
int compute_words(string text);
int compute_sentence(string text);

int main(void)
{
    // Get text input
    string text = get_string("Text: ");

    // Score letter, words, sentences
    int letters = compute_letters(text);
    //printf("Letters: %i \n", letters);
    
    float words = compute_words(text);
    //printf("Words: %f \n", words);
    
    int sentence = compute_sentence(text);
    //printf("Sentence: %i \n", sentence);
    
    //Coleman-Liau index formula
    int index = round(0.0588 * (letters * 100 / words) - 0.296 * (sentence * 100 / words) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");    
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
//Calculate letters function
int compute_letters(string text)
{

    int count_let = 0;
    
    for (int i = 0, len = strlen(text); i < len; i++)

    {
        if (isalnum(text[i]))
        {
            count_let++;
        }
        
    }
    return count_let;
}
//Calculate words function
int compute_words(string text)
{
    int count_word = 1;
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '\x20')
        {
            count_word++;
        }
    }
    return count_word;
}
//Calculate sentences function
int compute_sentence(string text)
{
    int count_sentence = 0;
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '\x2E' || text[i] == '\x21' || text[i] == '\x3F')
        {
            count_sentence++;
        }
    }
    return count_sentence;
    
}
