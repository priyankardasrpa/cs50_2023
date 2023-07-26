#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void char_to_binary(bool byte[], char ch);
void print_byte(bool byte[]);
void reset_bits(bool byte[]);

int main(void)
{
    // This is the array which represents a byte
    // This array will be used to encode the decimal numbers
    bool byte[BITS_IN_BYTE] = {false, false, false, false, false, false, false, false};

    // Get the string the from the user
    string message = get_string("Message: ");

    // Loop the entire string

    int index = 0;
    while (message[index] != '\0')
    {
        // Set the entire byte to zero
        reset_bits(byte);
        // Write the decimal in byte
        char_to_binary(byte, message[index]);
        // Print the byte
        print_byte(byte);
        // Move to the next index
        index += 1;
    }
}

// Prints the entire byte to the console using emoji
void print_byte(bool byte[])
{
    for (int index = 0; index < BITS_IN_BYTE; index++)
    {
        print_bulb(byte[index]);
    }
    printf("\n");
}

// Sets the byte to all zeros
void reset_bits(bool byte[])
{
    for (int index = 0; index < BITS_IN_BYTE; index++)
    {
        byte[index] = false;
    }

    return;
}

// Given a char it converts into a binary
void char_to_binary(bool byte[], char ch)
{
    int decimal = (int) ch;
    int index = 7;

    while (decimal >= 1)
    {
        if (decimal % 2 == 1)
        {
            byte[index] = true;
            // printf("%d\n", byte[index]);
        }
        else
        {
            byte[index] = false;
            // printf("%d\n", byte[index]);
        }
        decimal = decimal / 2;
        index -= 1;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
