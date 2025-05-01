#include <cstdio>
#include <cstdlib>

void printarray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d  ", arr[i]);
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
    for(int i = 0; i <size-1;i++){
        int min = i;
        for(int j = i+1; j < size;j++){
            if(arr[j]< arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

}

int main() {
    int size;
    int choice;
    int key;
    int arr[] = {4, 7, 8, 2};
    size = sizeof(arr) / sizeof(arr[0]);

    printf("\n");
    
    while(choice < 5){

        printf("\n");

        printf("1. Bubble sort\n");
        printf("2. Insertion sort\n");
        printf("3. Selection sort\n");
        printf("4. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);

        if(choice == 1){
            bubblesort(arr,size);
            printf("The array after bubble sort is\n");
            printarray(arr,size);
        }
        else if(choice == 2){
            insertionsort(arr,size);
            printf("The array after insertion sort is\n");
            printarray(arr,size);
        }
        else if(choice == 3){
        
            selectionsort(arr,size);
            printf("The array after selection sort is\n");
            printarray(arr,size);
        }

        else {
            printf("Exited from program");
        }

    }
}
