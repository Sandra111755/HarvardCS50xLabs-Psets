#include <cs50.h>
#include <stdio.h>

long long ccn;
long long ccnw;
long long ccne;
long long ccno;
long long ccns;
long long ccnd;
int ce = 0, co = 0, cs = 0, digits = 0;

int main(void)
{

// ensures a positive integer value
    do
    {
        ccn = get_long_long("Enter the credit card number to validate.");
    }
    while (ccn < 1);

//while loop takes even numbers starting with second to last number

    ccnw = ccn;
    while (ccnw != 0)
    {
        ccne = ((ccnw % 100 / 10) * 2);
        ce = ce + ccne % 10 + ccne / 10;
        ccnw = ccnw / 100;
    }

// while loop takes odd numbers starting with last number

    ccnw = ccn;
    while (ccnw != 0)
    {
        ccno = ccnw % 10;
        co = co + ccno;
        ccnw = ccnw / 100;
    }

// modulus/division applied previously to evens and sum of total digits added
    cs = ce + co;

// counts the number of digits in the card and assigns that to variable digits
    ccnw = ccn;
    while (ccnw != 0)
    {
        ccnd = ccnw % 10;
        digits++;
        ccnw = ccnw / 10;
    }

// finds the first digits of the number entered
    ccnw = ccn;
    while (ccnw >= 10)
    {
        ccnw = ccnw / 10;
        ccns = ccnw;
    }

//finds the first two digits of the number entered

    ccnw = ccn;
    while (ccnw >= 100)
    {
        ccnw = ccnw / 10;
        ccnd = ccnw;
    }

//validates checksum value and the first/second digits of the number entered

    if (((cs % 10) == 0) && ccns == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
    }
    else if ((((cs % 10) == 0) && (ccnd == 34 || ccnd == 37)) && (digits == 15))
    {
        printf("AMEX\n");
    }
    else if ((((cs % 10) == 0) && (ccnd == 51 || ccnd == 52 || ccnd == 53 || ccnd == 54 || ccnd == 55)) && (digits == 16))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}