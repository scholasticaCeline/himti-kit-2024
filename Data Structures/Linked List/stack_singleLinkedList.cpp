#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

struct Node{
    int angka;
    Node *next;
} *head, *tail;

Node *createNode(int newVal){
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->angka = newVal;
    newNode->next = NULL;

    return newNode;
}

void pushHead(int num){
    Node *temp = createNode(num);

    if(!head){
        head = temp;
        tail = temp;
    } else{
        temp -> next = head;
        head = temp;
    }
}

void pushTail(int num){
    Node *temp = createNode(num);

    if(!head){
        head = temp;
        tail = temp;
    } else{
        tail -> next = temp;
        tail = temp;
    }
}

void popHead(){
    if(!head) return;
    else if(head == tail){
        free(head);
        head = NULL;
        tail = NULL;
    } else{
        Node *temp = head -> next;
        head -> next = NULL;
        free(head);
        head = temp;
    }
}

void popTail(){
    if(!head) return;
    else if(head == tail){
        free(head);
        head = NULL;
        tail = NULL;
    } else{
        
    }
}

void display(){
    Node *curr = head;
    while(curr){
        printf("%d ", curr->angka);
        curr = curr->next;
    }
    puts("");
}

int main(){
    pushHead(4);
    display();
    pushHead(9);
    display();
    pushHead(1);    
    display();


    return 0;
}