#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle(string n, float x1cent, float y1cent, float x2cent, float y2cent, float x3cent, float y3cent):Shape(n, (x1cent+x2cent+x3cent)/3, (y1cent+y2cent+y3cent)/3) {
    x1=x1cent;
    y1=y1cent;
    x2=x2cent;
    y2=y2cent;
    x3=x3cent;
    y3=y3cent;
    
}

Triangle::~Triangle() {
    // Nothing to do
}

// Accessor
float Triangle::getx1() const {
    return x1;
}
float Triangle::getx2() const {
    return x2;
}
float Triangle::getx3() const {
    return x3;
}
float Triangle::gety1() const {
    return y1;
}
float Triangle::gety2() const {
    return y2;
}
float Triangle::gety3() const {
    return y3;
}

// Mutator
void Triangle::setx1(float x1cent) {
    x1 = x1cent;
}
void Triangle::setx2(float x2cent) {
    x2 = x2cent;
}
void Triangle::setx3(float x3cent) {
    x3 = x3cent;
}
void Triangle::sety1(float y1cent) {
    y1 = y1cent;
}
void Triangle::sety2(float y2cent) {
    y2 = y2cent;
}
void Triangle::sety3(float y3cent) {
    y3 = y3cent;
}


void Triangle::draw() const {
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "triangle: " << name << " "
         << x_centre << " " << y_centre
         << " " <<x1<< " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << computeArea()
         << endl;
}

float Triangle::computeArea() const {
    //float area= (abs(x1*abs(abs(y2)-abs(y3)))+abs(x2*abs(abs(y3)-abs(y1)))+abs(x3*abs(abs(y1)-abs(y2))))/2;
    float area= abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2);
    return (area);
}

Shape* Triangle::clone() const {
    return (new Triangle(*this));
}