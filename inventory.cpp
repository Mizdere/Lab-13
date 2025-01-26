// This program declares a class called Inventory that has itemnNumber (which
// contains the id number of a product) and numOfItem (which contains the
// quantity on hand of the corresponding product) as private data members.
// The program will read these values from a file and store them in an
// array of objects (of type Inventory). It will then print these values
// to the screen.

// Last Modified Date: 5/15/2024

// Example: Given the following data file:
//		986 8
//		432 24
//
// This program reads these values into an array of objects and prints the
// following:
//		Item number 986 has 8 items in stock
//		Item number 432 has 24 items in stock

#include <iostream>
#include <fstream>
using namespace std;

const int NUMOFPROD = 10;    // This holds the number of products a store sells 

class Inventory
{
public:
    void getId(int item) {
        itemNumber = item;    // Assigns the item number to the itemNumber member
    }

    void getAmount(int num) {
        numOfItem = num;      // Assigns the quantity to the numOfItem member
    }

    void display() {
        // Prints item number and quantity in stock
        cout << "Item number " << itemNumber << " has " << numOfItem << " items in stock" << endl;
    }

private:
    int itemNumber;           // This is an id number of the product 
    int numOfItem;            // This is the number of items in stock
};

int main()
{
    ifstream infile;  // Input file to read values into array 
    infile.open("Inventory.dat");
    if (!infile) {
        cerr << "Error opening file. Program terminating.\n";
        return 1;
    }

    Inventory products[NUMOFPROD];  // Array of Inventory objects

    int pos = 0;    // Loop counter
    int id;         // Variable holding the id number
    int total;      // Variable holding the total for each id number

    // Read inventory numbers and number of items from a file into the array of objects
    while (infile >> id >> total && pos < NUMOFPROD) {
        products[pos].getId(id);
        products[pos].getAmount(total);
        pos++;
    }

    // Print out the values (itemNumber and numOfItem) for each object in the array products
    for (int i = 0; i < pos; i++) {
        products[i].display();
    }

    return 0;
}
