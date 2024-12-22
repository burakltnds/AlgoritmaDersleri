#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100
//last in first out

struct Stack{
int data[MAX];
int top;
};

void initialize(struct Stack*stack){
stack->top=-1;
}
bool isFull(struct Stack * stack){
return stack->top==MAX-1;
}
bool isEmpty(struct Stack * stack){
return stack->top==-1;
}

//ekle
void push(struct Stack * stack,int value){
    if(isFull(stack)){
        printf("Dolu");
        return ;
    }
    return stack->data[++stack->top]=value;
}

//çıkar
int pop(struct Stack * stack){
    if(isEmpty(stack)){
        printf("Bos");
        return ;
    }
    return stack->data[stack->top--];
}
//en üst elemanı
int peek(struct Stack * stack){
    if(isEmpty(stack)){
        printf("Bos");
        return ;
    }
    return stack->data[stack->top];
}
//görüntüle
void display(struct Stack * stack){
    if(isEmpty(stack)){
        printf("Bos");
        return ;
    }
    for(int i=0;i<=stack->top;i++){
        printf("%d  " , stack->data[i]);

    }
    printf("\n");
}

int main(){
   struct Stack stack;
   initialize(&stack);
    push(&stack,10);
    push(&stack,15);
    push(&stack,20);
    push(&stack,25);
    push(&stack,32);
    push(&stack,7);
    pop(&stack);
    display(&stack);
    printf("peek: %d" , peek(&stack));
    
   
}