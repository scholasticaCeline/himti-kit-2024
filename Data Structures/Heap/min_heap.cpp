#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define parent(i) (i/2)
#define leftChild(i) (i*2)
#define rightChild(i) (2*i+1)

const int size = 100;
int minHeapArr[size];
int lastValueIdx = 0;

void print() {
    for(int i = 1; i <= lastValueIdx; i++) {
        printf("%d ", minHeapArr[i]);
    }
    puts("");
}

void findMin(){
    printf("Smallest value: %d", minHeapArr[1]);
}

void insertMinHeap(int newNum) {
    lastValueIdx++;

    // Insert newNum into the array
    minHeapArr[lastValueIdx] = newNum;

    // Up-heap (bubble up)
    int curr = lastValueIdx;
    while(curr > 1 && minHeapArr[curr] < minHeapArr[parent(curr)]) {
        // Swap
        int temp = minHeapArr[curr];
        minHeapArr[curr] = minHeapArr[parent(curr)];
        minHeapArr[parent(curr)] = temp;
        curr = parent(curr); 
    }
}

void deleteMin(){
    //delete root, replace pake array paling terakhir, benerin and swap
    minHeapArr[1] = minHeapArr[lastValueIdx];
    lastValueIdx--;

    int currIdx = 1;
    int currValue = minHeapArr[1];
    int minIdx = currIdx;
    int minValue = currValue;

    while(1){
        int leftChildIdx = leftChild(currIdx);
        int rightChildIdx = rightChild(currIdx);


        if(minHeapArr[minIdx] < minHeapArr[leftChildIdx] && leftChildIdx <= lastValueIdx){
            minIdx = leftChildIdx;
            minValue = minHeapArr[leftChildIdx];
        } 
        if(minHeapArr[minIdx] < minHeapArr[rightChildIdx] && rightChildIdx <= lastValueIdx){
            minIdx = leftChildIdx;
            minValue = minHeapArr[leftChildIdx];
        }
        

        if(minIdx != currIdx){
            int temp = minHeapArr[minIdx];
            minHeapArr[minIdx] = minHeapArr[currIdx];
            minHeapArr[currIdx] = temp;
            
            currIdx = minIdx;
            currValue = minValue;
        }
        else break;
    }
}

int main() {
    insertMinHeap(7);
    insertMinHeap(200);
    insertMinHeap(135);
    insertMinHeap(20);
    insertMinHeap(1);
    insertMinHeap(3);
    print();
    deleteMin();
    print();


    return 0;
}
