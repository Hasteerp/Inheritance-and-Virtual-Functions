#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Shape.h"
#include "Rectangle.h"

Rectangle::Rectangle(string n, float xcent, float ycent, float x2cent, float y2cent):Shape(n, xcent, ycent) {
    width=x2cent;
    height=y2cent;
}

Rectangle::~Rectangle() {
    // Nothing to do
}

// Accessor
float Rectangle::getwidth() const {
    return width;
}
float Rectangle::getheight() const {
    return height;
}


// Mutator
void Rectangle::setwidth(float x1cent) {
    width = x1cent;
}
void Rectangle::setheight(float x2cent) {
    height = x2cent;
}



void Rectangle::draw() const {
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "rectangle: " << name << " "
         << x_centre << " " << y_centre
         << " " <<width<< " " << height << " " << computeArea()
         << endl;
}

float Rectangle::computeArea() const {
    return (width*height);
}

Shape* Rectangle::clone() const {
    return (new Rectangle(*this));
}

