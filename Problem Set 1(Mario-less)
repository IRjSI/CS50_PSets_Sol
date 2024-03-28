#include <cs50.h>
#include <stdio.h>

int main()
{

    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ((n - 1) - i); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    // printf("\n");

    return 0;
}
