#include <cs50.h>
#include<math.h>
#include <stdio.h>
bool luhnAlg(int cardNum);
int length = 0;
int main(void)
{
    long input;
    input = get_long("number: ");
    long n = input;
    long n1 = input, n2 = input;
    while (input){
        n2 = n1;
        n1 = input;
        input /= 10;
    }
    while(n!=0){
        length++;
        n = n/10;
    }

    // printf("First two digits of %ld are %ld\n", n, n2);
    // printf("%d\n", luhnAlg(n));
    // printf("Length: %i\n", length);
    if (((n2 == 34 || n2 == 37) && length == 15) && luhnAlg(n)){
        printf("AMEX\n");
    }
    else if (((n2 == 51 || n2 == 52 || n2 == 53 || n2 == 54 || n2 == 55) && length == 16) && luhnAlg(n)){
        printf("MASTERCARD\n");
    }
    else if (((n2 / 10) == 4 && (length == 13 || length == 16)) && luhnAlg(n)){
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }

}

bool luhnAlg(int cardNum){
    int numberOfDigits = length;
    int sum = 0; 
    bool isSecondDigit = false;
    for (int i = numberOfDigits - 1; i >=0; i--){
        int thisDigit = cardNum % 10;
        cardNum = cardNum / 10;

        if (isSecondDigit == true){
            thisDigit = thisDigit * 2;
        }

        sum += thisDigit/10;
        sum += thisDigit%10;

        isSecondDigit = !isSecondDigit;
    }
    return (sum % 10 == 0); 
}
