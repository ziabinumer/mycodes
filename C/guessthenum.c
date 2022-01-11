#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num;
    srand(time(0));
    // num = rand(); printf("%d", num);
    num = num%100 + 1;
    int gnum = 0;
    int gtimes = 0;
    int correct = 0;
    printf("Number is between 1 and 100\n");
    while(!correct)
    {
        printf("Make your Guess: "); scanf("%d", &gnum);
        gtimes++;
        if (num == gnum)
        {
            printf("You guessed it right.\n");
            printf("You took %d times to guess it", gtimes);
            correct = 1;
        }
        else
        {
            if (gnum > num) printf("Your guess is greater than the correct.\n");
            else printf("Your guess is smaller than correct.\n");
            correct = 0;
        }
    }
    return 0;
}
