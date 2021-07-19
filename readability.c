#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h> //So I can use the 'round' function

int nletters = 0; //Variable to store the number of letters
int nwords = 1; //Variable to store the number of words (this variable starts in 1, because there will always be at least one word)
int nsentences = 0; //Variable to store the number of sentences
int n_letters(string text); //Declaring the function that count letters at the top
int n_words(string text); //Declaring the function that count words at the top
int n_sentences(string text); //Declaring the function that count sentences at the top
float index; //Variable to receive Coleman-Liau index

int main(void)
{
    //Get user text input
    string text = get_string("Please, write a string of text: ");
    nletters = n_letters(text); //Calling the function and storing the returned value to nletters
    nwords = n_words(text); //Calling the function and storing the returned value to nwords
    nsentences = n_sentences(text); //Calling the function and storing the returned value to nsentences

    //Calculating the Coleman-Liau index
    index = 0.0588 * (100 * (float) nletters / (float) nwords) - 0.296 * (100 * (float) nsentences / (float) nwords) - 15.8;
    //If the index is between 0 and 16
    if (index < 16 && index >= 0)
    {
        //Print the grade rounded to the nearest whole number
        printf("Grade %i\n", (int) round(index));
    }
    //Else if its higher than 16
    else if (index >= 16)
    {
        //Just print 16+
        printf("Grade 16+\n");
    }
    else
    {
        //And if its less than 1, print Before 1
        printf("Before Grade 1\n");
    }

}
//Making the function to count letters
int n_letters(string text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        //check that the character is alphanumeric or not
        if (isalnum((unsigned char)text[i]))
        {
            //If yes, increment the variable number of letters by 1
            nletters++;
        }
    }
    return nletters;
}

//Creating the function to count words
int n_words(string text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        //check that the character in text[i] is a blank space = ' '
        if (isspace(text[i]))
        {
            //If it is, increment the number of words by 1
            nwords++;
        }
    }
    return nwords;
}
//Creating the function to count sentences
int n_sentences(string text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        //check if the character in text[i] is an end ('.'), interrogation ('?') or exclamation ('!') point
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            //If yes, increment the number of sentences by 1
            nsentences++;
        }
    }
    return nsentences;
}