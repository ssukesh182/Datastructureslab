#include <cstdlib>
#include <cstdio>


void printarray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }
}


void bubblesort(int arr[], int size){
    for(int i = 0; i < size-1;i++){
        for(int j = 0; j < size-1-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void insertionsort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}


void selectionsort(int arr[], int size){
    for(int i = 0; i <size;i++){
        int min = i;
        for(int j = i+1; j < size+1;i++){
            if(arr[j]< arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

}