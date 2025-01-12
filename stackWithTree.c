#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n* sol;
    struct n* sag;
};
typedef struct n node;

struct stack {
    node* treeNode;
    struct stack* next;
};
typedef struct stack Stack;

// Yığına eleman ekleyen fonksiyon
void push(Stack** s, node* treeNode) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->treeNode = treeNode;
    newStack->next = *s;
    *s = newStack;
}

// Yığından eleman çıkaran fonksiyon
node* pop(Stack** s) {
    if (*s == NULL) {
        return NULL;
    }
    Stack* temp = *s;
    node* result = temp->treeNode;
    *s = temp->next;
    free(temp);
    return result;
}

// Yığın boş mu kontrolü
int isEmpty(Stack* s) {
    return s == NULL;
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

    Stack* stack = NULL;
    push(&stack, root);  // Kök düğümü yığına ekle

    while (!isEmpty(stack)) {
        node* current = pop(&stack);  // Yığından bir düğüm al
        printf("%d ", current->data);  // Düğümü ziyaret et

        // Sağ çocuk varsa, önce sağ çocuğu ekle
        if (current->sag != NULL) {
            push(&stack, current->sag);
        }
        
        // Sol çocuk varsa, sonra sol çocuğu ekle
        if (current->sol != NULL) {
            push(&stack, current->sol);
        }
    }
}

// In-order traversal (sıralı geçiş) işlemi
void inOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    Stack* stack = NULL;
    node* current = root;

    while (!isEmpty(stack) || current != NULL) {
        // Sol alt ağacı yığına ekle
        while (current != NULL) {
            push(&stack, current);
            current = current->sol;
        }

        // Yığından bir düğüm al ve ziyaret et
        current = pop(&stack);
        printf("%d ", current->data);

        // Sağ alt ağaca geç
        current = current->sag;
    }
}

// Post-order traversal (sonraki geçiş) işlemi
void postOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    Stack* stack1 = NULL;
    Stack* stack2 = NULL;
    
    // Kökü yığına ekle
    push(&stack1, root);

    while (!isEmpty(stack1)) {
        node* current = pop(&stack1);
        push(&stack2, current);

        // Sol ve sağ alt ağaçları sırasıyla yığına ekle
        if (current->sol != NULL) {
            push(&stack1, current->sol);
        }
        if (current->sag != NULL) {
            push(&stack1, current->sag);
        }
    }

    // stack2'deki elemanları çıkar ve ziyaret et
    while (!isEmpty(stack2)) {
        node* current = pop(&stack2);
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
    preOrderTraversal(agac);  

    printf("\n\nIn-order Traversal (Sirali Gecis):\n");
    inOrderTraversal(agac);   // Ağacın in-order traversal'ını yazdır

    printf("\n\nPost-order Traversal (Sonraki Gecis):\n");
    postOrderTraversal(agac); // Ağacın post-order traversal'ını yazdır

    return 0;
}
