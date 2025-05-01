#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Inserted successfully!\n";
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty. Nothing to delete.\n";
            return;
        }
        cout << "Deleted: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }
        cout << "Heap elements: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    void search(int key) {
        auto it = find(heap.begin(), heap.end(), key);
        if (it != heap.end())
            cout << "Element " << key << " found at position " << (it - heap.begin()) << endl;
        else
            cout << "Element " << key << " not found.\n";
    }

    void heapSort() {
        if (heap.empty()) {
            cout << "Heap is empty. Nothing to sort.\n";
            return;
        }
        vector<int> temp = heap;
        vector<int> sorted;

        while (!temp.empty()) {
            sorted.push_back(temp[0]);
            temp[0] = temp.back();
            temp.pop_back();
            heapifyDownHelper(temp, 0);
        }

        reverse(sorted.begin(), sorted.end());
        cout << "Sorted elements (descending): ";
        for (int val : sorted)
            cout << val << " ";
        cout << endl;
    }

private:
    void heapifyDownHelper(vector<int>& arr, int index) {
        int size = arr.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDownHelper(arr, largest);
        }
    }
};

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\n--- Priority Queue (Max Heap) Menu ---\n";
        cout << "1. Insert\n2. Delete Max\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            pq.insert(value);
            break;
        case 2:
            pq.deleteMax();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            pq.search(value);
            break;
        case 5:
            pq.heapSort();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
