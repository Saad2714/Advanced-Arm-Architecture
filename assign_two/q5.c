#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct  MyQueue{
    int top, bottom;
    int  myArray[10];
    int size;
};
void add_to_queue(struct  MyQueue*, int num);
void remove_from_Queue(struct  MyQueue*);
void print(struct  MyQueue*);
int main()
{
    printf("creating queue ... \n");

    struct  MyQueue* queue_1 =  (struct  MyQueue*)malloc(sizeof(struct  MyQueue));
    queue_1->size=10;
    printf("Size is %d \n", queue_1->size);

    queue_1->top=-1;
    printf("Top is %d \n", queue_1->top);

    queue_1->bottom = -1;
    printf("Bottom is %d \n", queue_1->bottom);

    for(int i=0;i<queue_1->size;i++){
        queue_1-> myArray[i]=0;
    }
    printf("\n");
    
    for(int loop=0; loop<100;loop++)
    {
        int n;
        printf("1 - Print Complete Queue  \n ");
        printf("2 - Add to Queue  \n ");
        printf("3 - Remove from Queue  \n ");
        printf("4 - Exit the Queue program  \n ");
    printf("\n");
        
        scanf(" %d ",&n);
        switch(n){
            case 1:
    printf("\n");
                    print(queue_1);
            case 2:
                    int  number;
    printf("\n");
                    printf("Enter  number:");
                    scanf("  %d  ",& number);
                    add_to_queue(queue_1, number);

            case 3:
                   remove_from_Queue(queue_1);
    printf("\n");
                     printf("Successfully popped top number   \n  ");
            case 4:
    printf("\n");
                printf("Closing the program  \n  ");
                break;

            default:
    printf("\n");
                printf("Please print 1, 2, 3 or 4... No other inputs!   \n  ");
        }
    }
    return 1;
    printf("\n");

}

// int peek() {
//    return intArray[front];
// }

// bool isEmpty() {
//    return itemCount == 0;
// }

// bool isFull() {
//    return itemCount == MAX;
// }

// int size() {
//    return itemCount;
// }  

// void insert(int data) {

//    if(!isFull()) {
	
//       if(rear == MAX-1) {
//          rear = -1;            
//       }       

//       intArray[++rear] = data;
//       itemCount++;
//    }
// }

// int removeData() {
//    int data = intArray[front++];
	
//    if(front == MAX) {
//       front = 0;
//    }
	
//    itemCount--;
//    return data;  
// }




void print(struct  MyQueue* queue_1)
{
    printf("Inside Print function... \n");

    if(queue_1->top==queue_1->bottom){
        printf("Circular_Queue is completely empty, kindly push some numbers first \n ");
    printf("\n");

    }
    for(int i=queue_1->top;i<queue_1->bottom;i++){
        printf(" %d  \n ",queue_1-> myArray[i]);
    }
    printf("\n");

}



void add_to_queue(struct  MyQueue* queue_1, int num)
{
    printf("Inside add_to_queue function... \n");

    if(queue_1->bottom == queue_1->size){
    printf("\n");

        printf("Circular_Queue is completely full, kindly pop some numbers first \n ");
    printf("\n");
        
        return;
    }

    if(queue_1->top==-1 && queue_1->bottom==-1){
    printf("\n");

        queue_1->top = 0;
        queue_1->bottom = 0;
    }
    queue_1-> myArray[queue_1->bottom] = num;
    queue_1->bottom+=1;
    printf("\n");

}

void remove_from_Queue(struct  MyQueue* queue_1)
{
    printf("Inside remove_from_Queue function... \n");

    if(queue_1->top>=queue_1->bottom || queue_1->top==-1){
        printf("Circular_Queue is completely empty, kindly push some numbers first \n ");
    printf("\n");
    }
    int  number = queue_1-> myArray[queue_1->top];
    for(int i=queue_1->top;i<queue_1->bottom-1;i++){
        queue_1-> myArray[i] = queue_1-> myArray[i+1];
    }
    printf("\n");

    queue_1->bottom-=1;
    
}



// int Queue::deQueue()
// {
//     if (front == -1)
//     {
//         printf("\nQueue is Empty");
//         return INT_MIN;
//     }
 
//     int data = arr[front];
//     arr[front] = -1;
//     if (front == rear)
//     {
//         front = -1;
//         rear = -1;
//     }
//     else if (front == size-1)
//         front = 0;
//     else
//         front++;
 
//     return data;
// }
 
// // Function displaying the elements
// // of Circular Queue
// void Queue::displayQueue()
// {
//     if (front == -1)
//     {
//         printf("\nQueue is Empty");
//         return;
//     }
//     printf("\nElements in Circular Queue are: ");
//     if (rear >= front)
//     {
//         for (int i = front; i <= rear; i++)
//             printf("%d ",arr[i]);
//     }
//     else
//     {
//         for (int i = front; i < size; i++)
//             printf("%d ", arr[i]);
 
//         for (int i = 0; i <= rear; i++)
//             printf("%d ", arr[i]);
//     }
// }
