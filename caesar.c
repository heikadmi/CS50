// Prints command-line arguments

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if command line has one additional argument (except of programm call) only
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
                //Iterate for next symbol to check wether its a digit or not then out of the loop
            }
            else
            {
                //Or print error if input was not a digit
                printf("Usage: %s\n", argv[0]);
                return 1;
            }
        }    
        
        //Prompt user for text to input
        string input = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int j = 0; j < strlen(input); j++)
        {
            //Check whether each symbol is alphabetical or not
            if (isalpha(input[j]))
            {
                //If alphabetical check for lowercase and print letter + key
                if (islower(input[j]))
                {
                    //(input[j] - 97) - index lowercase letters from a - 0 to z - 25; 
                    //since we have 26 letters only (atoi(argv[1] % 26) - calculates remainder from division by 26 which is helpful when user input > 26)
                    printf("%c", (97 + ((input[j] - 97) + (atoi(argv[1]) % 26)) % 26));
                }
                //Or uppercase and print letter + key
                else
                {
                    printf("%c", (65 + ((input[j] - 65) + (atoi(argv[1]) % 26)) % 26));
                }
            }
            else
            
            {
                //If not alphabetical remain the same symbol that it was. Including spaces, exclamation marks etc.
                printf("%c", input[j]);    
            }
        }
        printf("\n");
    }
    else
        //Exit with error if have more than 2 command-line arguments including name of the programm
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
}

