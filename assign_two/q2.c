#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct MyStack
{
    int head;
    int size;
    int myArray[5];
};

void push(struct MyStack* ,int num);
void pop(struct MyStack*);
void print(struct MyStack*);

int main(void)

{
    printf("creating stack ... \n");

    struct MyStack* stack_1 =  (struct MyStack*)malloc(sizeof(struct MyStack));
    // stack_1->head=4;
    stack_1->size=5;
    printf("Size is %d \n", stack_1->size);

    stack_1->head= 3;
    printf("head is %d \n", stack_1->head);

 
    for(int i=0;i<stack_1->size;i++)
    {
        stack_1->myArray[i]=i;
    }

    for(int loop=0; loop<100;loop++)
    {
        int n;
        printf("1 - Print Complete stack \n");
        printf("2 - Push a number \n");
        printf("3 - pop top number \n");
        printf("4 - Exit the stack program \n");
    printf("\n");

        scanf("%d",&n);
        switch(n){
            case 1:
    printf("\n");
                printf("Stack data from bottom to top: \n");
                print(stack_1);                   
            case 2:

            int number;
    printf("\n");
                printf("Enter number to push at the top of stack:");
                scanf("%d",&number);
                push(stack_1,number);

            case 3:
                pop(stack_1);
                   printf("\n");
printf("Successfully popped top number \n");
 
             case 4:
    printf("\n");
                printf("Exiting\n");
                break;
 

            default:
                printf("Please print 1, 2, 3 or 4... No other inputs!   \n  ");
    printf("\n");
       
        }
        

    }

    return 1;

}


// push(3);
//    push(5);
//    push(9);
//    push(1);
//    push(12);
//    push(15);

//    printf("Element at top of the stack: %d\n" ,peek());
//    printf("Elements: \n");

//    // print stack data 
//    while(!isempty()) {
//       int data = pop();
//       printf("%d\n",data);
//    }

//    printf("Stack full: %s\n" , isfull()?"true":"false");
//    printf("Stack empty: %s\n" , isempty()?"true":"false");

void print(struct MyStack* stack_1)
{
    printf("Inside Print function... \n");

    if(stack_1->head==stack_1->size){
        printf("MyStack is empty. Please push numbers first\n");

    }
    
    for(int i=stack_1->size-1;i>=stack_1->head+1;i--){
        printf("%d\n",stack_1->myArray[i]);
    }
    printf("\n");

}

void push(struct MyStack* stack_1, int num){
    printf("Inside Push function... \n");

    if(stack_1->head==-1){
        printf("MyStack is completely full, kindly pop some numbers first \n");
    printf("\n");
    }
    else if(stack_1->head!=-1){
        stack_1->head=stack_1->head-1;
        stack_1->myArray[stack_1->head+1] = num;
    }
}


void pop(struct MyStack* stack_1)
{
    if(stack_1->head==stack_1->size-1){
    printf("MyStack is completely empty, kindly push some numbers first \n ");
    printf("\n");
    }
    else if(stack_1->head!=stack_1->size-1){
        int number = stack_1->myArray[stack_1->head+1];
        printf("Element getting popped : %d\n", number);
    printf("\n");

        stack_1->head=stack_1->head+1;
    }
}


// void push(char element, char stack[], int *top, int stackSize){
//  if(*top == -1){
//   stack[stackSize - 1] = element;
//   *top = stackSize - 1;
//  }
//  else if(*top == 0){
//   printf("The stack is already full. \n");
//  }
//  else{
//   stack[(*top) - 1] = element;
//   (*top)--;
//  }
// }
// void pop(char stack[], int *top, int stackSize){
//  if(*top == -1){
//    printf("The stack is empty. \n");
//  }
//  else{
//   printf("Element popped: %c \n", stack[(*top)]);
//   // If the element popped was the last element in the stack
//   // then set top to -1 to show that the stack is empty
//   if((*top) == stackSize - 1){
//     (*top) = -1;
//   }
//   else{
//     (*top)++;
//   }
//  }
// }

