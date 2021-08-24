// Max from 3

#include<stdio.h>
#include<math.h>

int main()
{
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);
    int max = num1;
    if(num2 > num1){
        if(num2 > num3){
            max = num2;
        }
        else{
            max = num3;
        }
    }
    else if(num3 > num1){
        max = num3;
    }

    printf("Maximum from given 3 numbers is %d ", max);
    return 1;
}

