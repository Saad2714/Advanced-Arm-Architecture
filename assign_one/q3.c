
#include<stdio.h>
#include<math.h>


int main(){
    printf("Input 20 numbers in the array:\n");
    int i;

    int myArray[20];
    for(i=0;i<20;i++){
        scanf("%d", &myArray[i]);
    }

    // int max = -1;
    int count = 0;

    for(i=0;i<20;i++){
        if(myArray[i]%2 == 0){
            count++;
        }
    }
    printf("Even Numbers count is: %d ", count);

    return 1;

}