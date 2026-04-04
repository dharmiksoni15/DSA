#include <stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

// push

void push(int value){
    if(top == MAX-1){
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top]=value;
        printf("%d pushed \n",value);
    }
}

// pop

void pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        printf("%d popped \n",stack[top]);
        top--;   
    }
}

// Peek
void peek(){
    if(top == -1){
        printf("stack is Empty\n");
    }
    else{
        printf("Top Element:%d \n",stack[top]);
    }
}

// Display

void display(){
    if(top == -1){
        printf("stack empty\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}

int main(){
    push(10);
    push(20);
    push(30);

    display();
    peek();

    pop();
    display();

    return 0;
}