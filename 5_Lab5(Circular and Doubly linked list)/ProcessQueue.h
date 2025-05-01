#include <iostream>
using namespace std;
class Process {
public:
    int time;
    Process* next;

    Process(int t) {
        time = t;
        next = nullptr;
    }
};

class ProcessQueue {
private:
    Process* head;
    Process* tail;
    int timeQuantum;

public:
    ProcessQueue(int tq) {
        head = tail = nullptr;
        timeQuantum = tq;
    }

    // Insert a process into the circular queue
    void insertProcess(int time) {
        Process* newProcess = new Process(time);
        if (!head) {
            head = tail = newProcess;
            tail->next = head; // Circular connection
        } else {
            tail->next = newProcess;
            newProcess->next = head;
            tail = newProcess;
        }
        cout << "Process with time " << time << " inserted.\n";
    }

    // Execute the process at the front
    void executeProcess() {
        if (!head) {
            cout << "No processes to execute.\n";
            return;
        }

        cout << "Executing process with time: " << head->time << endl;
        head->time -= timeQuantum;

        if (head->time <= 0) {
            cout << "Process completed.\n";
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Process* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }
        } else {
            cout << "Process needs more time, remaining time: " << head->time << endl;
            tail = head;
            head = head->next;
        }
    }

    // Display the queue
    void displayQueue() {
        if (!head) {
            cout << "Queue is empty.\n";
            return;
        }

        Process* temp = head;
        cout << "Processes in queue: ";
        do {
            cout << temp->time << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Destructor to clean up memory
    ~ProcessQueue() {
        while (head) {
            Process* temp = head;
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                head = head->next;
                tail->next = head;
                delete temp;
            }
        }
    }
};