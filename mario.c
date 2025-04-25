#include <cs50.h>
#include <stdio.h>

void output(int n);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);
    output(height);
}

void output(int n)
{
    for (int times = 0; times < n; times++)
    {
        for (int i = n - 1; i > times; i--)
        {
            printf(" ");
        }
        for (int j = times + 1; j > 0; j--)
        {
            printf("#");
        }
        printf("  ");
        for (int k = times + 1; k > 0; k--)
        {
            printf("#");
        }
        printf("\n");
    }
}
