#include <iostream>
using namespace std;

class Shape {
public:
    void squareArea() {
        double side;
        cout << "Enter the side length of the square: ";
        cin >> side;
        if (side > 0)
            cout << "Area of Square: " << side * side << " sq. units\n";
        else
            cout << "Invalid input. Side must be positive.\n";
    }

    void cubeSurfaceArea() {
        double side;
        cout << "Enter the side length of the cube: ";
        cin >> side;
        if (side > 0)
            cout << "Surface Area of Cube: " << 6 * side * side << " sq. units\n";
        else
            cout << "Invalid input. Side must be positive.\n";
    }

    void rectangleArea() {
        double length, width;
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
        if (length > 0 && width > 0)
            cout << "Area of Rectangle: " << length * width << " sq. units\n";
        else
            cout << "Invalid input. Length and width must be positive.\n";
    }

    void cuboidSurfaceArea() {
        double length, width, height;
        cout << "Enter length, width, and height of the cuboid: ";
        cin >> length >> width >> height;
        if (length > 0 && width > 0 && height > 0)
            cout << "Surface Area of Cuboid: " << 2 * (length * width + width * height + height * length) << " sq. units\n";
        else
            cout << "Invalid input. All dimensions must be positive.\n";
    }
};

int main() {
    Shape shape;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "a) Square\n";
        cout << "b) Cube\n";
        cout << "c) Rectangle\n";
        cout << "d) Cuboid\n";
        cout << "e) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': shape.squareArea(); break;
            case 'b': shape.cubeSurfaceArea(); break;
            case 'c': shape.rectangleArea(); break;
            case 'd': shape.cuboidSurfaceArea(); break;
            case 'e': cout << "Exiting the program...\n"; break;
            default: cout << "Invalid choice! Please select a valid option.\n";
        }
    } while (choice != 'e');

    return 0;
}
