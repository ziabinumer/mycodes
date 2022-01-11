// C program to parse and print text
// i represents decrement
// s represents square
// d represents decrement
// o represents print

#include <string.h>
#include <stdio.h>
#include <cs50.h>
int* parse(char *text)
{
  int len = strlen(text);
  int i = 0, k = 0;
  static int r[10];
  for (int j = 0; j < len; j++)
  {
    switch(text[j])
    {
        case 'i':
          i++;
          break;
        case 'd':
          i--;
          break;
        case 's':
          i*=i;
          break;
        case 'o':
          r[k] = i;
          k++;
    }
  }
  return r;
}

int main()
{
    int k = 0;
    char *text;
    scanf("%s", *&text);
    int len = strlen(text);
    for (int i = 0; i < len; i++) if (text[i] == 'o') k++;

    int* returnedArr = parse(text);
    for (int i = 0; i < k; i++ )
    {
      printf("%i ", *(returnedArr + i));
    }

}
