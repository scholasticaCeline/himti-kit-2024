#include <stdio.h>
#include <stdlib.h>

const int SIZE = 10;
int parent[SIZE] = {0};
int rank[SIZE] = {0};

void print(){
    printf("%-10s", "rank");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", rank[i]);
    }
    puts("");

    printf("%-10s", "parent");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", parent[i]);
    }
    puts("");

    printf("%-10s", "value");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", i);
    }
    puts("");
}

void makeSet(int num){
    parent[num] = num;
}

//find root
int findSet(int key){
    if(key == parent[key]){
        return key;
    }

    return parent[key];
}

void unionSet(int a, int b){
    printf("Union of %d and %d\n", a, b);
    a = findSet(a);
    b = findSet(b);

    //if different set: union it
    if(a != b){
        if(rank[a] < rank[b]){
            int temp = a;
            a = b;
            b = temp;
        }
    } 
    //union
    parent[b] = a;
    //update rank
    if(rank[a] == rank[b]){
        rank[a]++;
    }
}

void displaySet(int key){
    printf("root of %d: %d\n", key, findSet(key));
}

int main(){
    system("cls");

    printf("Initial Set\n");
    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);
    print();
    puts("");
    unionSet(4, 3);
    print();


    puts("");
    unionSet(2, 1);
    print();

    puts("");
    unionSet(3, 1);
    print();

    return 0;
}