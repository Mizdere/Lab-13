// __________________________________________________________________
//
// This program declares a class for a circle that will have
// member functions that set the center, find the area, find
// the circumference and display these attributes.
// The program as written does not allow the user to input data, but
// rather has the radii and center coordinates of the circles
// (spheres in the program) initialized at definition or set by a function.

// class declaration section (header file)

// Last Modified Date: 5/15/2024



#include <iostream>
#include <iomanip>  // Include iomanip for setprecision
using namespace std;

// class declaration section (header file)
class Circles
{
public:
    Circles();                           // Default constructor
    Circles(float r);                    // Constructor with only radius
    Circles(int x, int y);               // Constructor with only center
    Circles(float r, int x, int y);      // Constructor that initializes all attributes
    ~Circles();                          // Destructor
    void printCircleStats();             // Outputs the radius and center of the circle. 
    double findArea();                   // Finds the area of the circle
    double findCircumference();          // Finds the circumference of the circle

private:
    float   radius;
    int     center_x;
    int     center_y;
};

const double PI = 3.14159; // More accurate PI value

// Client section 
int main()
{
    cout << fixed << setprecision(2); // Set precision for floating-point output

    Circles sphere1(5, 10, 15);  // Specific radius and center
    sphere1.printCircleStats();
    cout << "The area of the circle is " << sphere1.findArea() << endl;
    cout << "The circumference of the circle is " << sphere1.findCircumference() << endl;

    // Sphere3 with center at (15, 16) and default radius
    Circles sphere3(15, 16);
    sphere3.printCircleStats();
    cout << "The area of the circle is " << sphere3.findArea() << endl;
    cout << "The circumference of the circle is " << sphere3.findCircumference() << endl;

    return 0;
}

// Implementation section Member function implementation

Circles::Circles() : radius(1), center_x(0), center_y(0) // Default constructor
{
}

Circles::Circles(float r) : radius(r), center_x(0), center_y(0) // Constructor with only radius
{
}

Circles::Circles(int x, int y) : radius(1), center_x(x), center_y(y) // Constructor with only center
{
}

Circles::Circles(float r, int x, int y) : radius(r), center_x(x), center_y(y) // Constructor that sets all attributes
{
}

Circles::~Circles() // Destructor
{
    cout << "This concludes the Circles class." << endl;
}

double Circles::findArea() // Finds the area of the circle
{
    return PI * radius * radius;
}

double Circles::findCircumference() // Finds the circumference of the circle
{
    return 2 * PI * radius;
}

void Circles::printCircleStats() // This procedure prints out the radius and center coordinates
{
    cout << "The radius of the circle is " << radius << endl;
    cout << "The center of the circle is (" << center_x << ", " << center_y << ")" << endl;
}
