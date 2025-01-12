#include <stdio.h>
#include <stdlib.h>

// Ağaç düğüm yapısını tanımlıyoruz.
struct n {
    int data;
    struct n* sol;
    struct n* sag;
};
typedef struct n node;

// Kuyruk (queue) yapısı için gerekli olan yapı
struct queue {
    node* treeNode;
    struct queue* next;
};
typedef struct queue Queue;

// Kuyruğa eleman ekleyen fonksiyon
void enqueue(Queue** q, node* treeNode) {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->treeNode = treeNode;
    newQueue->next = NULL;
    
    if (*q == NULL) {
        *q = newQueue;
    } else {
        Queue* temp = *q;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newQueue;
    }
}

// Kuyruktan eleman çıkaran fonksiyon
node* dequeue(Queue** q) {
    if (*q == NULL) {
        return NULL;
    }
    Queue* temp = *q;
    node* result = temp->treeNode;
    *q = temp->next;
    free(temp);
    return result;
}

// Kuyruk boş mu kontrolü
int isEmpty(Queue* q) {
    return q == NULL;
}

// Ağaca yeni düğüm ekleyen fonksiyon
node* ekle(node* agac, int x) {
    if (agac == NULL) {
        node* root = (node*)malloc(sizeof(node));
        root->sol = NULL;
        root->sag = NULL;
        root->data = x;
        return root;
    }
    if (agac->data < x) {
        agac->sag = ekle(agac->sag, x);
    } else {
        agac->sol = ekle(agac->sol, x);
    }
    return agac;
}

// Pre-order traversal (öncelikli geçiş) işlemi
void preOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    Queue* queue = NULL;
    enqueue(&queue, root);  // Kök düğümü kuyruğa ekle

    while (!isEmpty(queue)) {
        node* current = dequeue(&queue);  // Kuyruktan bir düğüm al
        printf("%d ", current->data);  // Düğümü ziyaret et

        // Sağ ve sol alt ağaçları kuyruğa ekle
        if (current->sol != NULL) {
            enqueue(&queue, current->sol);
        }
        if (current->sag != NULL) {
            enqueue(&queue, current->sag);
        }
    }
}

// In-order traversal (sıralı geçiş) işlemi
void inOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    Queue* queue = NULL;
    node* current = root;
    
    // Kuyruğa eklerken, önce sol alt ağaçları kuyruğa ekleriz.
    while (current != NULL || !isEmpty(queue)) {
        while (current != NULL) {
            enqueue(&queue, current);
            current = current->sol;
        }

        // Kuyruktan bir düğüm al ve ziyaret et
        current = dequeue(&queue);
        printf("%d ", current->data);

        // Sağ alt ağaç için kuyruğa ekle
        current = current->sag;
    }
}

// Post-order traversal (sonraki geçiş) işlemi
void postOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    Queue* queue = NULL;
    node* current = root;
    enqueue(&queue, current);
    
    // İkinci kuyruk ile işlemi tamamlarız.
    Queue* secondQueue = NULL;

    while (!isEmpty(queue)) {
        current = dequeue(&queue);
        enqueue(&secondQueue, current);
        
        if (current->sol != NULL) {
            enqueue(&queue, current->sol);
        }
        if (current->sag != NULL) {
            enqueue(&queue, current->sag);
        }
    }

    // İkinci kuyruktan çıktıları alın
    while (!isEmpty(secondQueue)) {
        current = dequeue(&secondQueue);
        printf("%d ", current->data);
    }
}

// Ana fonksiyon
int main() {
    node* agac = NULL;

    // Ağacı oluşturalım
    agac = ekle(agac, 5);
    agac = ekle(agac, 2);
    agac = ekle(agac, 1);
    agac = ekle(agac, 8);
    agac = ekle(agac, 7);
    agac = ekle(agac, 11);

    printf("Pre-order Traversal (Oncelikli Gecis):\n");
    preOrderTraversal(agac);  // Ağacın pre-order traversal'ını yazdır

    printf("\n\nIn-order Traversal (Sirali Gecis):\n");
    inOrderTraversal(agac);   // Ağacın in-order traversal'ını yazdır

    printf("\n\nPost-order Traversal (Sonraki Gecis):\n");
    postOrderTraversal(agac); // Ağacın post-order traversal'ını yazdır

    return 0;
}
