#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main (void)
{
    // Initializing input variable
    float input = 0;
    // Making sure our dear user is forced to conform to the program.
    do
    {
        input = get_float("Change owed: ");    
    }
    // Gotta be positive to make any sort of sense, right?
    while (input < 0);
    // A cent is one hundredth of a dollar.
    int cents = round(input * 100);
    // A quarter
    float quarter = 0.25;
    // One tenth
    float dime = 0.1;
    // Twice less than one tenth
    float nickel = 0.05;
    // Five times less than that
    float penny = 0.01;
    // Calculating numbers of coins in need and passing down the remainder.
    int quartersNeeded = input / quarter;
    float remainderChange = input - (quartersNeeded * quarter);
    int dimesNeeded = round(remainderChange / dime);
    remainderChange = remainderChange - (dimesNeeded * dime);
    int nickelsNeeded = round(remainderChange / nickel);
    remainderChange = remainderChange - (nickelsNeeded * nickel);
    int penniesNeeded = round(remainderChange / penny);
    remainderChange = remainderChange - (penniesNeeded * penny);
    int coinsNeeded = round(quartersNeeded + dimesNeeded + nickelsNeeded + penniesNeeded);
    

    printf("%i quarters; %i dimes; %i nickels; %i pennies, remainder change: %0.2f\n", quartersNeeded, dimesNeeded, nickelsNeeded, penniesNeeded, remainderChange);
    printf("%i\n", coinsNeeded);

}
