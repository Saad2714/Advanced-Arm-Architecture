
#include<stdio.h>
#include<math.h>


int main()
{
    int myArr[20];
    int i = 0;
    int j = 0;

    for(i = 0; i < 20; i++){
        scanf("%d", &myArr[i]);
    }

    for( i = 0; i < 20; i++){
        for(j = 0; j < 20 - i - 1; j++){
            if(myArr[j] > myArr[j + 1]){
                int swap = myArr[j + 1];
                myArr[j + 1] = myArr[j];
                myArr[j] = swap;
            }
        }
    }
    
    printf("Sorted array in ascending order: ");
    for(i = 0; i < 20; i++){
        printf("%d ", myArr[i]);
    }

    return 0;
    
}