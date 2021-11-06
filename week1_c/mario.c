#include <stdio.h>

int main(void)
{
    int n = 0;
    while(n <= 0 || n > 8) {
        printf("Height(1-8): ");
        scanf("%d", &n);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 16; j++){
            if(j == 8){
                printf(" ");
            } else if (j >= 8 - i && j <= 8 + i){
                printf("#");
            } else  {
                printf(" ");
            }
        }
        printf("\n");
    }
}