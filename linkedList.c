#include <stdio.h>

struct Node{
int data;
struct Node* next;
};

struct Node* creataNode(int data){
struct Node* newNode =(struct Node*) malloc(sizeof(struct Node));
if(!newNode){
    printf("Bellek Ayrilamadi.\n");
    exit(1);
}
newNode->data=data;
newNode->next=NULL;
return newNode;
}

//baştan ekle
void basaEkle(struct Node **head,int data){
struct Node* newNode=creataNode(data);

newNode->next=*head;
*head=newNode;
}
//sondan ekle
void sondanEkle(struct Node** head,int data){
struct Node* newNode=creataNode(data);
if(*head==NULL){
    *head=newNode;
    return ;
}
struct Node*temp=*head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=newNode;
}

//baştan sil
void bastanSil(struct Node** head){
    if(*head== NULL){
        printf("Liste Bos");
        return  ;
    }
struct Node*temp=*head;
*head=(*head)->next;
free(temp);
}

//sondan sil
void sondanSil(struct Node** head){
 if (*head==NULL){
    printf("Liste Bos");
    return ;
 }
 struct Node*temp = *head;
if(temp->next==NULL ){
    free(temp);
    *head=NULL;
    return ;
}

struct Node * prev=NULL;
while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
}
prev->next=NULL;
free(temp);
}

//listele

void printList(struct Node**head){
struct Node *temp=*head;
while(temp!=NULL){
printf("%d ->",temp->data);
temp=temp->next;
}
printf("NULL\n");
}


int main(){
    struct Node*head=NULL;
    basaEkle(&head,15);
    basaEkle(&head,20);
    basaEkle(&head,25);
    basaEkle(&head,30);
    basaEkle(&head,35);
    sondanEkle(&head,2);
    sondanEkle(&head,4);
    sondanEkle(&head,6);
    sondanEkle(&head,8);
    sondanEkle(&head,10);
    sondanSil(&head);
    bastanSil(&head);
    printList(&head);



}