
#include<stdio.h>
#include<math.h>


int main(){
    printf("Input 15 numbers in the array:\n");
    int i;

    int myArray[15];
    for(i=0;i<15;i++){
        scanf("%d", &myArray[i]);
    }

    int max = -1;

    for(int i=0;i<15;i++){
        if(myArray[i]>max){
            max = myArray[i];
        }
    }
    printf("Largest number from 15 numbers array is: %d ", max);

    return 1;

}