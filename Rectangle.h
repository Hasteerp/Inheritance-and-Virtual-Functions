#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include <string>
using namespace std;


#include "Shape.h"

class Rectangle : Shape {
private:
    float width;
    float height;
    
    // The x and y coordinates of the triangle separately

public:
    // Constructor
    Rectangle (string n, float xcent, float ycent, float x2cent, float y2cent);
    
    // Destructor
    virtual ~Rectangle();
    
    // Accessor
    float getwidth() const;       // Returns the coordinates of the triangle
    float getheight() const;
    

    // Mutator
    void setwidth(float x1cent);
    void setheight(float x2cent); 
     // Sets the coordinates of the triangle
    
    // Utility methods
    virtual void draw() const;     // Draws thye circle; for the assignment it
                                   // prints the information of the circle
    
    virtual float computeArea() const;   // Computes the area of the circle
    
    virtual Shape* clone() const;  // Clones the object
};

#endif /* Rectangle_h */


