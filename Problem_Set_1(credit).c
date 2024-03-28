#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main()
{
    long int n,s,c,m,p,b,y,z,copy;
    int count=0;
    long int power,power2;
    s = p = 0;
    long int x = get_long("Number: ");
    c = x;
    b = x;
    copy = x;
    

    while(b>0)
    {
        count++;
        b = b/10;
    }

    power = pow(10,(count-2));
    power2 = pow(10,(count-1));

    while(x>0)
    {
        x = x/10;
        n = x%10;
        x = x/10;
        z = 2*n;
        if (z >= 10)
        {
          y = z%10;
          z = z/10;
          s = s + z + y;
        }

        else
          s = s + 2*n;

    }

   while(c>0)
    {
        m = c%10;
        c = c/100;
        p = p + m;

    }

    if((copy/power == 34 || copy/power == 37) && count == 15 && (s+p)%10 == 0)
    {
        printf("AMEX\n");
    }

    else if(copy/power2 == 4 && count <= 16 && count >= 13 && count != 15 && (s+p)%10 == 0)
    {
        printf("VISA\n");
    }

    else if((copy/power == 51 || copy/power == 52 || copy/power == 53 || copy/power == 54 || copy/power == 55) && count == 16 && (s+p)%10 == 0)
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
