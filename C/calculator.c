#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char * string;

void red(void);
void yellow(void);
void reset(void);

int get_int(string);
long get_long(string);
float get_float(string);

void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void factorial();
long cal_factorial(int);
void permutation();
void combination();


int main()
{
    system("cls");
    system("color F");
    printf(" Available operators: \n\n");
    printf("\tAddition\t(Key: +)\n\tSubtraction\t(Key: -)\n\tMultiplication\t(Key: *)\n\tDivision\t(Key: /)");
    printf("\n\tModulus \t(Key: %%)\n\tFactorial\t(Key: F)\n\tPermutation\t(Key: P)\n\tCombination\t(Key: C)\n");
    printf("\nPress Q to quit\n\n");

    inp_oper:
        printf("Enter Key of Operator: "); char oper = getche();
        oper = toupper(oper);

    functions:
        switch(oper)
        {
        case 'Q':
            return 0;
        case '+':
            addition();
            break;
        case '-':
            subtraction();
            break;
        case '*':
            multiplication();
            break;
        case '/':
            division();
            break;
        case '%':
            modulus();
            break;
        case 'F':
            factorial();
            break;
        case 'P':
            permutation();
            break;
        case 'C':
            combination();
            break;
        default:
            printf("\nInvalid Key\n");
            printf("Restart or Quit? [r or q] ");
            char temp = getche();
            if (temp == 'r')
            {
                system("cls");
                main();
            }
            else return 1;

    }

    return 0;
}


// functions

// color definiton
red () {
  printf("\033[1;31m");
}

yellow() {
  printf("\033[1;33m");
}

reset () {
  printf("\033[0m");
}

// function to get integer
int get_int (string print)
{
    printf("%s", print);
    int temp = 0;
    scanf("%d", &temp);
    return temp;
}

float get_float(string print)
{
    printf("%s", print);
    float temp = 0.0;
    scanf("%f", &temp);
    return temp;
}

// function to get long int
long get_long(string print)
{
    printf("%s", print);
    long temp = 0;
    scanf("%li", &temp);
    return temp;
}


// math functions

void addition(void)
{
    system("cls");
    printf(" Addition Initialized: \n");
    float _1 = get_float("  Enter First Number: ");
    float _2 = get_float("  Enter 2nd Number: ");
    yellow();
    printf("  Sum: %f\n", _1 + _2);
    reset();
    printf("Wanna continue with Addition? [y or n] ");
    char t = getche();
    if (t == 'y') addition();
    else main();
}

void subtraction(void)
{
    system("cls");
    printf(" Subtraction Initialized: \n");
    float _1 = get_float("  Enter First Number: ");
    float _2 = get_float("  Enter 2nd Number: ");
    yellow();
    printf("  Subtraction: %f\n", _1 - _2);
    reset();
    printf("Wanna continue with Subtraction? [y or n] ");
    char t = getche();
    if (t == 'y') subtraction();
    else main();
}

void multiplication(void)
{
    system("cls");
    printf(" Multiplication Initialized: \n");
    float _1 = get_float("  Enter First Number: ");
    float _2 = get_float("  Enter 2nd Number: ");
    yellow();
    printf("  Product: %f\n", _1 * _2);
    reset();
    printf("Wanna continue with Multiplication? [y or n] ");
    char t = getche();
    if (t == 'y') multiplication();
    else main();
}

void division(void)
{
    system("cls");
    printf("Division Initialized: \n");
    float _1 = get_float("  Enter First Number: ");
    float _2 = get_float("  Enter 2nd Number: ");
    yellow();
    printf("  Result: %f \n", _1 / _2);
    reset();
    printf("Wanna continue with Division? [y or n] ");
    if (getche() == 'y') division();
    else main();
}

void modulus(void)
{
    system("cls");
    printf("Modulus Initialized : \n");
    int _1 = get_int("  Enter First Number: ");
    int _2 = get_int("  Enter 2nd Number: ");
    yellow();
    printf("  Result: %i \n", _1 % _2);
    reset();
    printf("Wanna continue with Modulus? [y or n] ");
    if (getche() == 'y') modulus();
    else main();
}

void factorial(void)
{
    system("cls");
    printf("Factorial Initialized: \n");
    int n = get_int("  Enter Number: ");
    yellow();
    printf("  Factorial: %i \n", cal_factorial(n));
    reset();
    printf("Wanna continue with Factorial? [y or n] ");
    if (getche() == 'y') factorial();
    else main();
}

long cal_factorial(int n)
{
    long factorial = 1;
    for (int i = n; i > 1; i--)
    {
        factorial = factorial * i;
    }
    return factorial;
}

void permutation(void)
{
    system("cls");
    printf("Permutation Initialized: \n");
    int n = get_int("  Enter n: ");
    int r = get_int("  Enter r: ");

    if (n < r)
    {
        red();
        printf("  Please Enter n and r According to this: n >= r >= 0\n");
        reset();
        printf("Restart or Quit? [r or q] ");
        if (getche() == 'r') permutation();
        else main();
    }

    int nfac = cal_factorial(n);
    int l = n - r;
    int lfac = cal_factorial(l);
    yellow();
    printf("  Result: %i \n", nfac / lfac);
    reset();
    printf("Wanna continue with Permutation? [y or n] ");
    if (getche() == 'y') permutation();
    else main();
}

void combination(void)
{
    system("cls");
    printf("Combination Initialized: \n");
    int n = get_int("  Enter n: ");
    int r = get_int("  Enter r: ");

    if (n < r)
    {
        red();
        printf("  Please Enter n and r According to this: n >= r >= 0\n");
        reset();
        printf("Restart or Quit? [r or q] ");
        if (getche() == 'r') combination();
        else main();
    }

    int nfac = cal_factorial(n);
    int rfac = cal_factorial(r);
    int l = n - r;
    int lfac = cal_factorial(l);
    yellow();
    printf("  Result: %i \n", nfac / (lfac * rfac));
    reset();
    printf("Wanna continue with Combination? [y or n] ");
    if (getche() == 'y') combination();
    else main();

}
