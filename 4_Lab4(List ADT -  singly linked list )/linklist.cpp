#include "linkedlistheader.h"

int main() {
    List list1, list2;
    int choice, value;

    do {
        std::cout << "\nMenu:";
        std::cout << "\n1. Insert in Ascending Order";
        std::cout << "\n2. Merge with another list";
        std::cout << "\n3. Display List";
        std::cout << "\n4. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            list1.insertAscending(value);
            break;
        case 2:
            std::cout << "Enter values for second list (end with -1): ";
            while (true) {
                std::cin >> value;
                if (value == -1) break;
                list2.insertAscending(value);
            }
            list1.merge(list2);
            std::cout << "Lists merged successfully!" << std::endl;
            break;
        case 3:
            list1.display();
            break;
        case 4:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
