#include <cs50.h>
#include <stdio.h>

int main(void)

//Prompt user for number 
{
    int n;
    do
    {
       n = get_int("What is height (choose between 1 and 8)? \n");
    }
    while (n < 1 || n > 8);

//Building blocks within choosen number of levels
    for (int i = 1; i <= n; i++)
    {    

//Variable number for 1 column
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
 
        for (int k = 0; k < i; k++)
        {        
            printf("#");
        }

//Space between columns
        printf("  ");

//Right column
        for (int g = 0; g < i; g++)
        {        
            printf("#");
        }

        printf("\n");
    }
        
}
       
       