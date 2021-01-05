//Cash change witn minimum coins used "greedy algorithm"

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
// Prompt user for amount of cash (dollars,cents)
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0.009);

//Transfer dollars to cents, then round
    int cents = round(dollars * 100);

//Get number of quaters
    int quarters = cents / 25;

//Remainder from division of the sum by quarters change with dimes
    int dimes = (cents % 25) / 10;

//Remainder from the change with quarters and dimes change with nickles
    int nickles = (cents % 25 % 10) / 5;

//Remainder from the change with quarters, dimes and nickles change with pennies
    int pennies = (cents % 25 % 10 % 5) / 1;

//Finally calculate number of coins
    int total = quarters + dimes + nickles + pennies;
    
    printf("%i \n", total);
}
