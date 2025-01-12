#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    int data;
    struct StackNode* sonra;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

void initialize(Stack* stack) {
    stack->top = NULL;
}

void push(Stack* stack, int value) {
    StackNode* yeni = (StackNode*)malloc(sizeof(StackNode));
    yeni->data = value;
    yeni->sonra = stack->top;
    stack->top = yeni;
}

void pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack bos.\n");
        return;
    }
    StackNode* temp = stack->top;
    stack->top = stack->top->sonra;
    free(temp);
}

void listele(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack bos\n");
        return;
    }
    StackNode* temp = stack->top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->sonra;
    }
}

void destroy(Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
}

int main() {
    Stack stack;
    initialize(&stack);
    push(&stack, 14);
    push(&stack, 10);
    push(&stack, 5);
    push(&stack, 7);
    pop(&stack);
    printf("Stack:\n");
    listele(&stack);
    destroy(&stack);

    return 0;
}
