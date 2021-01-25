// Prints command-line arguments

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc == 2 && strlen(argv[1]) == 26) //Checks for 2 command-line arguments and length of 26 characters

    {
        //This block checks for duplicates
        int count = strlen(argv[1]);

        for (int a = 0; a < count - 1; a++) 
        {
            for (int b = a + 1; b < count; b++) 
            {
                if (argv[1][a] == argv[1][b]) 
                {
                    printf("Error: duplicate found\n");
                    return 1;
                }
                else
                {

                }
            }
        }
        //Check whether each character is alphabetical
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]))
            {
                if (isupper(argv[1][i]))
                {
                }
                else
                {
                    argv[1][i] = toupper(argv[1][i]); //change lowercase alphabetical characters to uppercase
                }
            }
            else
            {
                //Or print error if input was not alphabetical letters
                printf("Usage: %s\n", argv[0]);
                return 1;
            }
        }    
        
        //Prompt user for text to input
        string input = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int j = 0; j < strlen(input); j++)
        {
            //Check whether each character is alphabetical or not
            if (isalpha(input[j]))
            {

                if (islower(input[j]))
                {
                    
                    printf("%c", tolower(argv[1][input[j] - 97]));
                }
           
                else
                {
                    printf("%c", argv[1][input[j] - 65]);
                }
            }
            else
            
            {
                //If not alphabetical remain the same character that it was. Including spaces, punctuation marks etc
                printf("%c", input[j]);    
            }
        }
        printf("\n");
        return 0;
    }
    else if (argc == 1) //if no arguments were inputed except programm name
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;    
    }
    
    else
        //Exit with error if have more than 2 command-line arguments including name of the programm
    {

        if (argc != 2 && strlen(argv[1]) == 26)
        {
            printf("Usage: %s KEY", argv[0]);
            return 1;
        }
        else if (argc == 2 && strlen(argv[1]) != 26) //got 2 arguments, but second is not equal to 26 alphabetical characters
        {
            printf("Key must contain 26 characters");
            return 1;
        }
        else 
        {
            printf("Usage_else: %s key\n", argv[0]);
            return 1;
        }
    }
}

