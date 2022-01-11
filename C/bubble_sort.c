// program to sort array
#include <stdio.h>

int main(void)
{
   int n;
   printf("Size of Array: ");
   scanf("%d", &n);
   int array[n];
   printf("Array: ");
   for (int i = 0; i < n; i++)
   {
       
       scanf("%d", &array[i]);
   }

   int _1, _2;
   for (int l = 0; l < n - 1; l++)
   {
       for (int i = 0; i < n - 1; i++)
       {
           if (array[i] > array[i + 1])
           {
               _1 = array[i + 1];
               _2 = array[i];
               array[i] = _1;
               array[i + 1] = _2;
           }
        }
   }
    // ("Biggest Number: %d\n", array[n - 1]);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d   ", array[i]);
    printf("\n");
    return 0;
}
