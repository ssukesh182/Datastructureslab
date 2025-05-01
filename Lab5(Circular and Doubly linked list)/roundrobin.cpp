
#include <iostream>

#include "ProcessQueue.h"

using namespace std;

int main() {
    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;

    ProcessQueue pq(quantum);
    int choice, time;

    do {
        cout << "\nMenu:\n1. Insert Process\n2. Execute\n3. Display Queue\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter process execution time: ";
            cin >> time;
            pq.insertProcess(time);
            break;
        case 2:
            pq.executeProcess();
            break;
        case 3:
            pq.displayQueue();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
