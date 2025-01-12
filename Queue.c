#include <stdio.h>
#include <stdlib.h>

// Node yapısı
typedef struct Node {
    int data;           // Veriyi tutacak
    struct Node* next;  // Bir sonraki düğüme işaretçi
} Node;

// Queue yapısı
typedef struct Queue {
    Node* bas; // Kuyruğun başını gösterir
    Node* son; // Kuyruğun sonunu gösterir
} Queue;

// Kuyruğu başlatma
void initQueue(Queue* q) {
    q->bas = NULL;
    q->son = NULL;
}

// Kuyruğa eleman ekleme
void enQueue(Queue* q, int value) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = value;
    yeni->next = NULL;

    if (q->son == NULL) { // Kuyruk boşsa
        q->bas = yeni;
        q->son = yeni;
        return;
    }

    q->son->next = yeni; // Son düğümün next'ini yeni düğüme bağla
    q->son = yeni;       // Sonu güncelle
}

// Kuyruktan eleman çıkarma
void deQueue(Queue* q) {
    if (q->bas == NULL) { // Kuyruk boşsa
        printf("Kuyruk boş\n");
        return;
    }

    Node* temp = q->bas;    // Başı geçici olarak tut
    q->bas = q->bas->next;  // Başı bir sonraki düğüme kaydır

    if (q->bas == NULL) {   // Kuyruk tamamen boşsa
        q->son = NULL;
    }

    free(temp); // Çıkarılan düğümü serbest bırak
}

// Kuyruğu yazdırma
void printQueue(Queue* q) {
    if (q->bas == NULL) {
        printf("Kuyruk boş\n");
        return;
    }

    Node* temp = q->bas;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Ana fonksiyon
int main() {
    Queue q;
    initQueue(&q);

    enQueue(&q, 5);
    enQueue(&q, 3);
    enQueue(&q, 65);
    enQueue(&q, 20);

    printf("Kuyruk: ");
    printQueue(&q);

    deQueue(&q);
    printf("Dequeue Kuyruk: ");
    printQueue(&q);

    return 0;
}
