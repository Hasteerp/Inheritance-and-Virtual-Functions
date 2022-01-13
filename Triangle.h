#ifndef Triangle_h
#define Triangle_h

#include <iostream>
#include <string>
using namespace std;


#include "Shape.h"

class Triangle : Shape {
private:
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;// The x and y coordinates of the triangle separately

public:
    // Constructor
    Triangle (string n, float x1cent, float y1cent, float x2cent, float y2cent, float x3cent, float y3cent);
    
    // Destructor
    virtual ~Triangle();
    
    // Accessor
    float getx1() const;       // Returns the coordinates of the triangle
    float getx2() const;
    float getx3() const;
    float gety1() const;
    float gety2() const;
    float gety3() const;

    // Mutator
    void setx1(float x1cent);
    void setx2(float x2cent); 
    void setx3(float x3cent); 
    void sety1(float y1cent); 
    void sety2(float y2cent); 
    void sety3(float y3cent); // Sets the coordinates of the triangle
    
    // Utility methods
    virtual void draw() const;     // Draws thye circle; for the assignment it
                                   // prints the information of the circle
    
    virtual float computeArea() const;   // Computes the area of the circle
    
    virtual Shape* clone() const;  // Clones the object
};

#endif /* Triangle_h */


