#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void max_heapify(int array[], int index, int heapSize){
  /* add your code here */
    int left_child = ((2*index)+1);
    int right_child = ((2*index)+2);
    int max = index;
    int temp = 0;
    
    if(left_child<heapSize && array[left_child]>array[index]){
        max = left_child;
    }
     if(right_child<heapSize && array[right_child]>array[max]){
        max = right_child;
    }
    if(max!=index){
        temp = array[index];
        array[index] = array[max];
        array[max] = temp;
        max_heapify(array, max, heapSize);
        
    }
    
}

int* build_max_heap(int array[], int arraySize){
    int j;
    for (j = arraySize/2; j >= 0; j--) {
        max_heapify(array, j, arraySize);
    }
    return array;
}

void display(int *max_heap, int arraySize){
	int counter;
    for (counter = 0; counter < arraySize; counter++) {
        printf("%d ", max_heap[counter]);
    }
}

int main(){
    int index, arraySize;
	int *array = calloc(MAX, sizeof(int));
    int *max_heap = calloc(MAX, sizeof(int));
    
    scanf("%d", &arraySize);
    
    for (index = 0; index < arraySize; index++) {
        scanf("%d", &array[index]);
    }
    max_heap = build_max_heap(array, arraySize);
    display(max_heap, arraySize);
}