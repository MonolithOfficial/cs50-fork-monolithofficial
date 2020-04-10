#include <cs50.h>
#include <stdio.h>

// Luhn's algorithm bool function prototype.
bool luhnAlg(string cardNum);

// Globally accesible variable for length of the input.
int length = 0;
int main(void)
{
    // Declaring input variable of type Long.
    long input;
    // Input prompt.
    input = get_long("number: ");
    // Copying input into variable "n", used for unmodified display of input.
    long n = input;
    // "trueInput" has the same purpose as "n" - displaying unmodified input later in code. 
    long trueInput = input;
    // "n1" and "n2" are used to single out the first two digits of the input down inside a while loop.
    long n1 = input, n2 = input;
    while (input)
    {
        n2 = n1;
        n1 = input;
        input /= 10;
    }
    // Determining length of the input via while loop and the global variable "length".
    while(n!=0)
    {
        length++;
        n = n/10;
    }
    // Convertng input stored in "trueInput" (unmodified) into a sequence of characters.
    char str[256];
    sprintf(str, "%ld", trueInput);

    // AMEX condition
    if (((n2 == 34 || n2 == 37) && length == 15) && luhnAlg(str))
    {
        printf("AMEX\n");
    }
    // MASTERCARD condition.
    else if (((n2 == 51 || n2 == 52 || n2 == 53 || n2 == 54 || n2 == 55) && length == 16) && luhnAlg(str))
    {
        printf("MASTERCARD\n");
    }
    // VISA condition
    else if (((n2 / 10) == 4 && (length == 13 || length == 16)) && luhnAlg(str))
    {
        printf("VISA\n");
    }
    // Everything else is deemed INVALID.
    else 
    {
        printf("INVALID\n");
    }

}

// Luhn's algorithm implemented in C. Output from this function goes into conditions created above.
bool luhnAlg(string cardNum)
{
    // Using global variable "length" again.
    int numberOfDigits = length;
    // Initializing final sum variable in advance.
    int sum = 0; 
    // Boolean variable used to select only every other digit of the input.
    bool isSecondDigit = false;
    // For loop, as seen, has a starting point of length -1, which is the second-to-last digit.
    for (int i = numberOfDigits - 1; i >= 0; i--)
    {
        int thisDigit = cardNum[i] - '0';

        // Multiplying every other digit by 2.
        if (isSecondDigit == true)
        {
            thisDigit = thisDigit * 2;
        }

        // Handling cases where digits sum up to a value greater than 9, aka gives 2 digits.
        sum += thisDigit / 10;
        sum += thisDigit % 10;

        // Reversing "isSecondDigit" value via NOT operator.
        isSecondDigit = !isSecondDigit;
    }
    // Returning the final sum which determines validity of the credit card number.
    return (sum % 10 == 0); 
}
