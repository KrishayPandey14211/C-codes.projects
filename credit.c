#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardno = get_long("Number: ");
    long cn = cardno;
    int times = 1;
    int checksum = 0;
    int dig2 = 0;
    int twice = 0;
    int length = 0;
    int first2digits;

    while (cn > 0)
    {
        int digit = cn % 10;
        cn = cn / 10;
        if (times % 2 == 0)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                dig2 = (digit % 10) + 1;
                checksum = checksum + dig2;
            }
            else
            {
                checksum = checksum + digit;
            }
        }
        else
        {
            checksum = checksum + digit;
        }
        times++;
        length++;
    }

    if (length == 15 && checksum % 10 == 0)
    {
        first2digits = cardno / 10000000000000;
        if (first2digits == 34 || first2digits == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (length == 16 && checksum % 10 == 0)
    {
        first2digits = cardno / 100000000000000;
        if (first2digits / 10 == 4)
        {
            printf("VISA\n");
        }
        else if (first2digits == 51 || first2digits == 52 || first2digits == 53 ||
                 first2digits == 54 || first2digits == 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (length == 13 && checksum % 10 == 0)
    {
        first2digits = cardno / 1000000000000;
        if (first2digits == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
