#include <iostream>
using namespace std;

bool isPalindrome(int num);
bool isArmstrong(int num);
bool isPerfect(int num);

int main() {
    char choice;
    int number;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "a. Palindrome\n";
        cout << "b. Armstrong Number\n";
        cout << "c. Perfect Number\n";
        cout << "d. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 'd') {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        cout << "Enter a number: ";
        cin >> number;

        if (choice == 'a') {
            if (isPalindrome(number)) {
                cout << number << " is a Palindrome number." << endl;
            } else {
                cout << number << " is not a Palindrome number." << endl;
            }
        } else if (choice == 'b') {
            if (isArmstrong(number)) {
                cout << number << " is an Armstrong number." << endl;
            } else {
                cout << number << " is not an Armstrong number." << endl;
            }
        } else if (choice == 'c') {
            if (isPerfect(number)) {
                cout << number << " is a Perfect number." << endl;
            } else {
                cout << number << " is not a Perfect number." << endl;
            }
        } else {
            cout << "Invalid choice! Please choose again." << endl;
        }
    }
    return 0;
}

bool isPalindrome(int num) {
    if (num < 0) return false; 
    int reversed = 0, original = num, remainder;
    while (original != 0) {
        remainder = original % 10;
        reversed = reversed * 10 + remainder;
        original /= 10;
    }
    return reversed == num;
}

bool isArmstrong(int num) {
    if (num < 0) return false; 
    int original = num;
    int n = 0;
    int temp = original;
    do {
        temp /= 10;
        n++;
    } while (temp != 0);
    
    int sum = 0;
    temp = num;
    while (temp != 0) {
        int remainder = temp % 10;
        int power = 1;
        for (int i = 0; i < n; i++) {
            power *= remainder;
        }
        sum += power;
        temp /= 10;
    }
    return sum == num;
}

bool isPerfect(int num) {
    if (num <= 0) return false; 
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}