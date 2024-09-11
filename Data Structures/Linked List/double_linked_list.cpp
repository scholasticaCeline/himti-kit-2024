#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

struct Node{
    int num;
    Node *next, *prev;
} *head, *tail;

Node *createNode(int num){
    Node *newNode = (struct Node*) malloc (sizeof(Node));

    newNode -> num = num;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    return newNode;
}

void pushHead(int val){
    Node *temp = createNode(val);
    if(!head) head = tail = temp;
    
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void print() {
    Node *curr = head;
    while (curr) {
        printf("%d -> ", curr->num);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main(){


    return 0;
}