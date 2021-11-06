#include <stdio.h>
  
int main(void)
{
    int i = 0;
    printf("use while loop\n");
    while (i < 3)
    {
        printf("meow\n");
        i++;
    }

    printf("\nuse for loop\n");
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }

    printf("what is i? %d\n", i);
}