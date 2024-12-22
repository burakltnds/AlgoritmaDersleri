#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100
//last in last out

struct Queue{
int items[MAX];
int front,rear;
};
//başlatma
void initialize(struct Queue *q ){
    q->front=-1;
    q->rear=-1;
}
//ekleme
void enQueue(struct Queue *q,int value){
if(q->rear==MAX-1){
    printf("Kuyruk Dolu");
}
if(q->front==-1){
    q->front=0;
}
q->rear++;
q->items[q->rear]=value;
}
//çıkarma
void deQueue(struct Queue *q){
if(q->front==-1){
printf("Kuyruk Bos");
}
int value=q->items[q->front];
q->front++;
if(q->front>q->rear){ //kuyruk boşsa
q->front=q->rear=-1;
}
return value;
}
//peek elemanı
int peek(struct Queue *q){
if(q->front==-1){
    printf("Kuyruk Bos");
}
return q->items[q->front];
}

//görüntüleme
void printQueue(struct Queue *q){
if(q->front==-1){
    printf("Kuyruk Bos");
}
for(int i=q->front;i<=q->rear;i++){
printf("%d  ",q->items[i]);
}
printf("\n");
}

int main(){
    struct Queue * q;
    initialize(&q);
    enQueue(&q,2);
    enQueue(&q,6);
    enQueue(&q,7);
    enQueue(&q,4);
    enQueue(&q,8);
    deQueue(&q);
    printQueue(&q);
}