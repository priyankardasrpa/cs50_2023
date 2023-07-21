#include <cs50.h>
#include <stdio.h>

bool isValidCardNumber(const long cardNumber);
int countDigits(long cardNumber);
int startsWith(long cardNumber);

int main(void)
{
    // Prompt for the card number
    long cardNumber = get_long("Number: ");

    // If the card has at least 13 digits
    if (countDigits(cardNumber) < 13)
    {
        printf("INVALID\n");
        return 0;
    }

    // If it's AMEX
    if (countDigits(cardNumber) == 15 && (startsWith(cardNumber) == 34 || startsWith(cardNumber) == 37) &&
        isValidCardNumber(cardNumber))
    {
        printf("AMEX\n");
        return 0;
    }

    // If it's Master Card
    if (countDigits(cardNumber) == 16 &&
        (startsWith(cardNumber) == 51 || startsWith(cardNumber) == 52 || startsWith(cardNumber) == 53 ||
         startsWith(cardNumber) == 54 || startsWith(cardNumber) == 55) &&
        isValidCardNumber(cardNumber))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    // If it's VISA
    if ((countDigits(cardNumber) == 16 || countDigits(cardNumber) == 13) &&
        (startsWith(cardNumber) >= 40 && startsWith(cardNumber) <= 49) && isValidCardNumber(cardNumber))
    {
        printf("VISA\n");
        return 0;
    }

    printf("INVALID\n");
    return 0;
}

// Returns the starting 2 digits
int startsWith(long cardNumber)
{
    int last = 0;
    int secondLast = 0;
    while (cardNumber >= 1)
    {
        secondLast = last;
        last = cardNumber % 10;
        cardNumber /= 10;
    }

    return last * 10 + secondLast;
}

// Returns the number of digits
int countDigits(long cardNumber)
{
    int count = 0;
    while (cardNumber >= 1)
    {
        count += 1;
        cardNumber /= 10;
    }
    return count;
}

bool isValidCardNumber(const long cardNumber)
{
    long verifyNumber = cardNumber;
    long sum = 0;
    int count = 1;

    // As long as it is not 0
    while (verifyNumber >= 1)
    {
        // If it is the 2nd to last digit
        if (count % 2 == 0)
        {
            long digit = verifyNumber % 10;
            // printf("%li\n", digit);
            digit = digit * 2;
            // printf("%li\n", digit);

            // If it has more than 1 digit
            if (digit > 9)
            {
                sum = sum + (digit % 10);
                digit = digit / 10;
                sum = sum + (digit % 10);
            }
            else
            {
                sum = sum + digit;
            }
        }
        verifyNumber = verifyNumber / 10;
        count += 1;
    }

    // printf("%li\n", sum);

    verifyNumber = cardNumber;
    count = 1;

    // Adding the previous sum to the digits that were not processed before
    while (verifyNumber >= 1)
    {
        if (count % 2 != 0)
        {
            long digit = verifyNumber % 10;
            sum = sum + digit;
        }
        verifyNumber = verifyNumber / 10;
        count += 1;
    }

    // printf("%li\n", sum);

    return sum % 10 == 0;
}