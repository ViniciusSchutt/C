#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main()
{
    //Declaring variables
    int cents;
    int coins = 0;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    float dollars;
    do
    {
        //Get charge values
        dollars = get_float("Charge: $ ");
    }
    //While this condition is satisfied, keep re asking the user for a valid number
    while (dollars < 0);
    //If the informed value is zero, automatically the number os coins will be zero as well
    if (dollars == 0.00)
    {
        printf("%d\n", coins);
    }
    //Converting the dollars value to cents
    cents = round(dollars * 100);
    //While cents are greater than 25, do the following:
    while (cents >= 25)
    {
        cents = cents - quarters;
        coins++;
    }
    //While cents are simultaneously greater than dimes and lesser than quarters, do the following:
    while (cents < 25 && cents >= 10)
    {
        cents = cents - dimes;
        coins++;
    }
    //While cents are simultaneously greater than nickels and lesser than dimes, do the following:
    while (cents < 10 && cents >= 5)
    {
        cents = cents - nickels;
        coins++;
    }
    //While cents are simultaneously greater than pennies and lesser than nickels, do the following:
    while (cents < 5 && cents >= 1)
    {
        cents = cents - pennies;
        coins++;
    }
    //Print the number os coins in the screen
    printf("%d\n", coins);

}