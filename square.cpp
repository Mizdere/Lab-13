#include <iostream>
using namespace std;

// This program declares the Square class and uses member functions to find
// the perimeter and area of the square, now with constructors and destructor

// Last Modified Date: 5/15/2024

class Square {
private:
    float side; // Member data to store the length of a side of the square

public:
    Square(); // Default constructor
    Square(float length); // Constructor that initializes side with a value
    ~Square(); // Destructor

    void setSide(float length); // Task: Sets the side of the square
    float findArea(); // Task: Calculates the area of the square
    float findPerimeter(); // Task: Calculates the perimeter of the square
};

int main() {
    Square box; // box is defined as an object of the Square class using default constructor
    float size; // size contains the length of a side of the square

    cout << "Please input the length of the side of the square: ";
    cin >> size;

    box.setSide(size);
    cout << "The area of the square is " << box.findArea() << endl;
    cout << "The perimeter of the square is " << box.findPerimeter() << endl;

    // Creating another object called box1 with a side of 9
    Square box1(9);
    cout << "The area of box1 is " << box1.findArea() << endl;
    cout << "The perimeter of box1 is " << box1.findPerimeter() << endl;

    return 0;
}

// Default constructor that sets the side to 1
Square::Square() : side(1) {
    cout << "Default constructor called, side set to 1." << endl;
}

// Constructor that allows initializing the side length
Square::Square(float length) : side(length) {
    cout << "Parameterized constructor called, side set to " << length << "." << endl;
}

// Destructor
Square::~Square() {
    cout << "Destructor called." << endl;
}

void Square::setSide(float length) {
    side = length;
}

float Square::findArea() {
    return side * side;
}

float Square::findPerimeter() {
    return 4 * side;
}
