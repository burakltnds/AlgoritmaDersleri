#include <stdio.h>
#include <stdlib.h>

//linkedlist
struct Node {
	int data;
	struct Node* sonraki;
};

struct LinkedList {
	struct Node* head;
};

void initialize(LinkedList *list) {
	list->head = NULL;
}

void basEkle(LinkedList* list, int x) {
	Node* yeni = (Node*)malloc(sizeof(Node));
	yeni->data = x;
	yeni->sonraki = list->head;
	list->head = yeni;
}

void sonEkle(LinkedList* list,int x) {
	if (list->head == NULL) {
		return ;
	}
	Node* yeni = (Node*)malloc(sizeof(Node));
	yeni->data = x;
	yeni->sonraki = NULL;
	Node* temp = list->head;
	while (temp->sonraki) {
		temp = temp->sonraki;
	}
	temp->sonraki = yeni;
}
void bastanSil(LinkedList *list) {
	if (list->head == NULL) { return ; }
	Node *temp = list->head;
	list->head = list->head->sonraki;
	free(temp);
}
void sondanSil(LinkedList *list){
	if (list->head == NULL) { return; }
	Node* temp = list->head;
	while (temp->sonraki->sonraki != NULL) {
		temp = temp->sonraki;
	}
	free(temp->sonraki);
	temp->sonraki = NULL;
}
void display(LinkedList* list) {
	if (list->head == NULL) { return ; }
	Node* temp = list->head;
	while (temp->sonraki != NULL) {
		printf("%d->", temp->data);
		temp = temp->sonraki;
	}
	printf("NULL");
}

//Stack
struct Node1 {
	int data;
	struct Node1* sonraki;
};
struct Stack{
	Node* top;
};
void initialize(Stack *stack) {
	stack->top = NULL;
}
void push(Stack *stack,int x) {
	Node* yeni = (Node*)malloc(sizeof(Node));
	yeni->data = x;
	yeni->sonraki = stack->top;
	stack->top = yeni;
}
void pop(Stack* stack){
	if (stack->top == NULL) { return ; }
	Node* temp = stack->top;
	stack->top = stack->top->sonraki;
	free(temp);
}

//Queue
struct Queue {
	Node* front;
	Node* rear;
};

void initialize(Queue* q) {
	q->front == NULL;
	q->rear == NULL;
}

void enQueue(Queue* q,int x) {
	Node* yeni = (Node*)malloc(sizeof(Node));
	yeni->data = x;
	yeni->sonraki = NULL;
	if(q->rear==NULL){
		q->front = NULL;
	}
	yeni->sonraki = q->rear;
	q->rear = yeni;
}

void deQueue(Queue* q) {
	if (q->front == NULL && q->rear == NULL) { return; }
	Node* temp = q->front;
	q->front = q->front->sonraki;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	free(temp);
}

//BUBLE SORT
void bubbleSort(int arr[],int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j]>arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
//QUİCK SORT
void quick(int arr[],int low,int high) {
	if (low < high) {
		int pivot = arr[high];
		int j = low - 1;
		
		for (int i = low; i < high; i++) {
		if(arr[i]<pivot) {
			j++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		}
		int temp = arr[j + 1];
		arr[j + 1] = arr[high];
		arr[high] = temp;
		int part= j + 1;
		quick(arr, low, part - 1);
		quick(arr, part + 1, high);
	}
}




//BİNARY SEARCH
void binarySearch(int arr[],int size,int target) {
	int sol = 0, sag = size - 1, orta;
	while (sol <= sag) {
		orta = sol + (sag - sol) / 2;
		if (arr[orta] == target) {
			sag = orta - 1;
		}
		sol = orta + 1;
	}
}

//BST
struct Node2 {
	int data;
	struct Node2* sag;
	struct Node2* Sol;
};

Node2* ekle(Node2* agac,int x) {
	if (agac == NULL) {
		agac->sag = NULL;
		agac->Sol = NULL;
		agac->data = x;
		return agac;
	}
	if (agac->data < x) {
		agac->sag = ekle(agac->sag, x);
		return agac;
	}
	agac->Sol = ekle(agac->Sol, x);
	return agac;
}

Node2* max(Node2* agac) {
	while (agac->sag != NULL) {
		agac = agac->sag;
		
	}
	return agac->sag;
}

Node2* min(Node2* agac) {
	while (agac->Sol != NULL) {
		agac = agac->Sol;

	}
	return agac->Sol;
}

void display(Node2* agac) {
	if (agac == NULL) {	return;}
	display(agac->sag);
	printf("%d-", agac->data);
	display(agac->Sol);
}

Node2 sil(Node2* agac,int x) {
	if (agac == NULL) { return ; }
	if (agac->data == x) {
		if (agac->sag == NULL && agac->Sol == NULL) {
			free(agac);
		}
		else if (agac->Sol == NULL) {
			Node2* temp = agac->sag;
			free(agac);
			return temp;
		}
		Node2* temp = agac->Sol;
		free(agac);
		return temp;
	}
	else if (agac->data < x) {
		sil(agac->sag, x);
	}
	sil(agac->Sol, x);
}
//ÇARPRAZLAMA 
struct Node3 {
	int data;
	Node3* sag;
	Node3* sol;
};

struct Yigin {
	Node3* treeNode;
	Node3* sonraki;
};

void push(Yigin** y, Node* treeNode) {
	Yigin *yeni = (Yigin*)malloc(sizeof(Yigin));
	yeni->treeNode = treeNode;
	yeni->sonraki =*y;
	*y = yeni;
}

Node3 pop(Yigin** y){
	if (*y->sonraki==NULL) { return ; }
	Yigin** temp = *y;
	Node3 result = temp->treeNode;
	*y = temp->sonraki;
	free(temp);
}
int isEmpty(Yigin** y) {
	return *y = NULL;
}

Node3* ekle(Node3* agac,int x) {
	if (agac->data == NULL) {
		agac->sag = NULL;
		agac->sol == NULL;
		agac->data = x;
	}

}

void preOrder(Node3 *root) {
	if (root == NULL) { return ; }
	Yigin* s = NULL;
	push(&s, root);
	while (s != NULL) {
		Node3* temp = pop(s);
		printf("%d", temp->data);
		if (temp->sag != NULL) {
			push(s, temp->sag);
		}
		else if (temp->sol != NULL) {
			push(s, temp->sol);
		}
	}
}









int main() {
	return 0; 
}
