#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Declaring important global variables
int i;
int key;
string ciphertext;
//Declaring the functions that rotate characters and validate the key input
string rotate(string message);
bool analyze_key_validity(string s);

int main(int argc, string argv[])
{
    //If there's only 1 argument and its a number
    if (argc != 2 || !analyze_key_validity(argv[1]))
    {
        printf("Usage: ./caesar key\n"); //If not, print what is solicited in the problem description
        return 1; //Returning 1, which is a standard occurence in case of problems
    }
    else
    {
        key = atoi(argv[1]); //If yes, turn key value always to int
        string message = get_string("plaintext: "); //Getting user input for the text to be analyzed
        ciphertext = rotate(message); //Making 'ciphertext' be calculated passing the user text as input
        printf("ciphertext:%s", ciphertext); //Printing the ciphertext
        printf("\n");
        return 0; //Return 0, which represents everything's fine
    }
}
//Making the function to rotate the letters (encrypt the text)
string rotate(string message)
{
    //Set i value to 0 to start the while loop
    i = 0;
    while (message[i] != '\0') //While the content in message[i] is different than '\0' (last thing in a string)
    {
        // Check if it's lowercase between a and z
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((((message[i] - 'a') + key) % 26) + 'a'); // Yes? So move 'key' characters forward
        }
        // check if it's uppercase between A and Z
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((((message[i] - 'A') + key) % 26) + 'A'); // Yes? So move 'key' characters forward
        }
        else
        {
            message[i] = message[i]; //Not lower between a~z nor upper between A~Z? Then do nothing to the content of message[i]
        }
        i++; //At the end of each iteration, increment i
    }
    return message; //Return the message encrypted according to the key
}
//Making the function to analyze the validity of the key, receiving precisely 'key' as argument
bool analyze_key_validity(string k)
{
    for (i = 0; i < strlen(k); i++)
    {
        if (!isdigit(k[i])) //If key is not a number
        {
            return false; // Return false to the if in line 19, leading to Usage: ./caesar key message error of line 21
        }
    }
    return true; // Return true to the if in line 19, letting the program continue to run
}