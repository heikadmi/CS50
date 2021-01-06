#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{

//Promt user to input card number
   
    long cardn;
    do
    {
        cardn = get_long("Input card number: ");
    }
    while (cardn == 0); 
//This condition could help to avoid non card look like numbers: while (cardn < 4000000000000 || cardn > 5600000000000000);
    
//Define length of input
    long len;
    len = (log10(cardn) + 1);
    
//Declare variables
    
    int i = 1;
    int j = 0;
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int digit = 0;
    int digit1 = 1;
    long range;
    long range1;

//Choosing each other digit from second last:

    while (i < len || j < len)
    {
        range = cardn / pow(10, i);
        digit = (range % 10) * 2;
        i += 2;

//Then sum up one digit numbers 

        if (digit < 10)
        {
            sum1 = sum1 + digit;
        }

//and 2 digit numbers

        else   
        {
            sum1 = sum1 + (1 + digit % 10);    
        }

//Now sum up the rest numbers

        range1 = cardn / pow(10, j);
        digit1 = (range1 % 10);
        j += 2;
        sum2 = sum2 + digit1;
        //printf("%i \n", digit1);
        //printf("%i \n", digit);

    
//Calculate total sum
    }
    sum = sum1 + sum2;

// Make mask to find first digits of card

    int amex = cardn / pow(10, 13);
    int mast = cardn / pow(10, 14);
    int visa = cardn / pow(10, 15);
    int visa1 = cardn / pow(10, 12);

//Check for attributes (starting digits, lenght, checksum) and define paysystem
    
    if ((amex == 34 && len == 15 && sum % 10 == 0) || (amex == 37 && len == 15 && sum % 10 == 0))
    {
        printf("AMEX\n");
    }
    
    else if ((mast >= 51  && len == 16 && sum % 10 == 0) && (mast <= 55  && len == 16 && sum % 10 == 0))
    {
        printf("MASTERCARD\n");
    }
    
    else if ((visa == 4 && len == 16 && sum % 10 == 0) || (visa1 == 4 && len == 13 && sum % 10 == 0))
    {
        printf("VISA\n");
    }
    
    else
    {
        printf("INVALID\n");    
    }
//Control block 'uncomment' to use
    //int checksum = (cardn / pow (10, 15));
    //printf("First digits: %i \n", checksum);
    //printf("Length: %li \n", len);
    //printf("CHECKSUM: %i \n", sum); 
}