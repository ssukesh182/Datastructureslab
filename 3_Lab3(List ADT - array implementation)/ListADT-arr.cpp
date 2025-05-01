#include using namespace std;

#define SIZE 5

class ListADT {
private:
int arr[SIZE];
int length;

public:
ListADT();
void insertBeginning(int val);
void insertEnd(int val);
void insertPosition(int pos, int val);
void deleteBeginning();
void deleteEnd();
void deletePosition(int pos);
void search(int val);
void display();
void rotate(int k);
};

int main() {
ListADT list;
int choice, val, pos, k;

while (true) {
cout << "\nMenu:\n";
cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n";
cout << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
cout << "7. Search\n8. Display\n9. Rotate\n10. Exit\n";
cout << "Enter choice: ";
cin >> choice;

switch (choice) {
case 1:
cout << "Enter value: ";
cin >> val;
list.insertBeginning(val);
break;
case 2:
cout << "Enter value: ";
cin >> val;
list.insertEnd(val);
break;
case 3:
cout << "Enter position and value: ";
cin >> pos >> val;
list.insertPosition(pos, val);
break;
case 4:
list.deleteBeginning();
break;
case 5:
list.deleteEnd();
break;
case 6:
cout << "Enter position: ";
cin >> pos;
list.deletePosition(pos);
break;
case 7:
cout << "Enter value: ";
cin >> val;
list.search(val);
break;
case 8:
list.display();
break;
case 9:
cout << "Enter k: ";
cin >> k;
list.rotate(k);
break;
case 10:
return 0;
default:
cout << "Invalid choice!\n";
}
}
}

ListADT::ListADT() : length(0) {}

void ListADT::insertBeginning(int val) {
if (length == SIZE) {
cout << "List is full!\n";
return;
}
for (int i = length; i > 0; i--) {
arr[i] = arr[i - 1];
}
arr[0] = val;
length++;
}

void ListADT::insertEnd(int val) {
if (length == SIZE) {
cout << "List is full!\n";
return;
}
arr[length++] = val;
}

void ListADT::insertPosition(int pos, int val) {
if (length == SIZE || pos < 1 || pos > length + 1) {
cout << "Invalid position!\n";
return;
}
for (int i = length; i >= pos; i--) {
arr[i] = arr[i - 1];
}
arr[pos - 1] = val;
length++;
}

void ListADT::deleteBeginning() {
if (length == 0) {
cout << "List is empty!\n";
return;
}
for (int i = 0; i < length - 1; i++) {
arr[i] = arr[i + 1];
}
length--;
}

void ListADT::deleteEnd() {
if (length == 0) {
cout << "List is empty!\n";
return;
}
length--;
}

void ListADT::deletePosition(int pos) {
if (length == 0 || pos < 1 || pos > length) {
cout << "Invalid position!\n";
return;
}
for (int i = pos - 1; i < length - 1; i++) {
arr[i] = arr[i + 1];
}
length--;
}

void ListADT::search(int val) {
for (int i = 0; i < length; i++) {
if (arr[i] == val) {
cout << "Element found at position " << i + 1 << "\n";
return;
}
}
cout << "Element not found!\n";
}

void ListADT::display() {
if (length == 0) {
cout << "List is empty!\n";
return;
}
cout << "List: ";
for (int i = 0; i < length; i++) {
cout << arr[i] << " ";
}
cout << "\n";
}

void ListADT::rotate(int k) {
if (length == 0) return;
k = k % length;
if (k == 0) return;
int temp[SIZE];
for (int i = 0; i < length; i++) {
temp[(i + k) % length] = arr[i];
}
for (int i = 0; i < length; i++) {
arr[i] = temp[i];
}
}