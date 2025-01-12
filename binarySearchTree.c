#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n* sol;
    struct n* sag;
};
typedef struct n node;

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

int max(node* agac) {
    while (agac->sag != NULL) {
        agac = agac->sag;
    }
    return agac->data;
}

int min(node* agac) {
    while (agac->sol != NULL) {
        agac = agac->sol;
    }
    return agac->data;
}

void dolas(node* agac) {
    if (agac == NULL) {
        return;
    }
    dolas(agac->sol);
    printf("Agac Elemanlari: %d\n", agac->data);
    dolas(agac->sag);
}

node* sil(node* agac, int x) {
    if (agac == NULL) {
        return NULL;
    }

    if (agac->data == x) {
        if (agac->sol == NULL && agac->sag == NULL) {
            free(agac);
            return NULL;
        } else if (agac->sol == NULL) {
            node* temp = agac->sag;
            free(agac);
            return temp;
        } else if (agac->sag == NULL) {
            node* temp = agac->sol;
            free(agac);
            return temp;
        } else {
            int minValue = min(agac->sag);
            agac->data = minValue;
            agac->sag = sil(agac->sag, minValue);
        }
    } else if (agac->data < x) {
        agac->sag = sil(agac->sag, x);
    } else {
        agac->sol = sil(agac->sol, x);
    }
    return agac;
}

int main() {
    node* agac = NULL;
    agac = ekle(agac, 5);
    agac = ekle(agac, 2);
    agac = ekle(agac, 1);
    agac = ekle(agac, 8);
    agac = ekle(agac, 7);
    agac = ekle(agac, 11);

    printf("Agac dolasim:\n");
    dolas(agac);

    printf("\n\n5 elemanini sil\n");
    agac = sil(agac, 5);

    printf("Agac dolasim:\n");
    dolas(agac);
    
    printf("\n\nMin Deger:%d\n",min(agac));
    printf("\n\nMax Deger:%d\n",max(agac));
    return 0;
}
