#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
} Node;

typedef struct BagliList {
    Node* head;
} BagliList;

void initialize(BagliList* liste) {
    liste->head = NULL;
}

void basEkle(BagliList* liste, int value) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = value;
    yeni->sonraki = liste->head;
    liste->head = yeni;
}

void sonEkle(BagliList* liste, int value) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = value;
    yeni->sonraki = NULL;

    if (liste->head == NULL) {
        liste->head = yeni;
        return;
    }

    Node* temp = liste->head;
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;
    }
    temp->sonraki = yeni;
}

void arayaEkle(BagliList* liste, int value, int index) {
    if (index == 0) {
        basEkle(liste, value);
        return;
    }

    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = value;

    Node* temp = liste->head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->sonraki;
    }

    if (temp == NULL) {
        printf("Gecersiz Index Sona Eklendi\n");
        sonEkle(liste, value);
        return;
    }

    yeni->sonraki = temp->sonraki;
    temp->sonraki = yeni;
}

void sondanSil(BagliList* liste) {
    if (liste->head == NULL) {
        printf("Liste Bos!!!\n");
        return;
    }

    if (liste->head->sonraki == NULL) {
        free(liste->head);
        liste->head = NULL;
        return;
    }

    Node* temp = liste->head;
    while (temp->sonraki->sonraki != NULL) {
        temp = temp->sonraki;
    }

    free(temp->sonraki);
    temp->sonraki = NULL;
}

void bastanSil(BagliList* liste) {
    if (liste->head == NULL) {
        printf("Liste Bos!!!\n");
        return;
    }

    Node* temp = liste->head;
    liste->head = liste->head->sonraki;
    free(temp);
}

void display(BagliList* liste) {
    if (liste->head == NULL) {
        printf("Liste Bos!!!\n");
        return;
    }

    Node* temp = liste->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->sonraki;
    }
    printf("NULL\n");
}

int main() {
    BagliList liste;
    initialize(&liste);

    basEkle(&liste, 10);
    sonEkle(&liste, 20);
    sonEkle(&liste, 30);
    arayaEkle(&liste, 15, 1);

    printf("Liste: ");
    display(&liste);

    bastanSil(&liste);
    printf("Bastan Silindikten Sonra Liste: ");
    display(&liste);

    sondanSil(&liste);
    printf("Sondan Silindikten Sonra Liste: ");
    display(&liste);

    return 0;
}
