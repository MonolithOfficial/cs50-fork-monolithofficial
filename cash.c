#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Initializing input variable
    float dollars = 0;
    // Making sure our dear user is forced to conform to the program.
    do
    {
        dollars = get_float("Change owed: ");    
    }
    // Gotta be positive to make any sort of sense, right?
    while (dollars < 0);
    // A cent is one hundredth of a dollar.
    int cents = round(dollars * 100);

    // Calculating the number of coins in need and passing down the remainder.
    int quartersNeeded = cents / 25;
    int qRemainder = cents % 25;
    int dimesNeeded = qRemainder / 10;
    int dRemainder = qRemainder % 10;
    int nickelsNeeded = dRemainder / 5;
    int nRemainder = dRemainder % 5;
    int penniesNeeded = nRemainder / 1;

    int totalCoins = quartersNeeded + dimesNeeded + nickelsNeeded + penniesNeeded;

    printf("%i\n", totalCoins);
}
