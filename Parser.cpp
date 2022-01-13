
// The main function does three key things
//      1. It creates a database for up to 1000 shapes and up to 10 shape types
//      2. It registers your command parser call-back functions with the database
//      3. It invokes the command parser method of the database

#include <iostream>
using namespace std;
#include <sstream>

#include "Shape.h"
#include "ShapesDB.h"

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

#define MAX_SHAPES 1000
#define MAX_SHAPE_TYPES 10

// Create a database instance; making it global to simplify student code
ShapesDB sdb(MAX_SHAPES,MAX_SHAPE_TYPES);

Shape* parseCircleCommand(stringstream& line);
Shape* parserectangleCommand(stringstream& line);
Shape* parsetriangleCommand(stringstream& line);

int main () {

    // Register the command parser call back functions
    sdb.registerShapeType("rectangle", &parserectangleCommand);
    sdb.registerShapeType("circle", &parseCircleCommand);
    sdb.registerShapeType("triangle", &parsetriangleCommand);
    
    
    // Invoke the parser of the DB
    // No new commands should be registered after this
    sdb.parseCommands();
    
    // Done
    return (0);
}

Shape* parseCircleCommand(stringstream& line) {
    string name;
    float xcent;
    float ycent;
    float radius;
    line >> name >> xcent >> ycent >> radius;
    
    // Do a simple error check
    if (line.fail()) {
        cout << "Error: invalid input" << endl;
        return nullptr;
    }
    
    // Check to see if name is a reserved word
    if (sdb.isReserved(name)) {
        cout << "Error: " << name << " is a reserved word" << endl;
        return nullptr;
    }
    
    // Check if a shape with this name already exists
    if (sdb.shapeExists(name)) {
        cout << "Error: a shape with the name " << name << " already exists" << endl;
        return nullptr;
    }

    // Create the shape object and return a pointer to it
    Shape* myShape = (Shape*) new Circle(name, xcent, ycent, radius);
    cout << "created circle" << endl;
    return myShape;
}
Shape* parserectangleCommand(stringstream& line) {
    string name;
    float xcent;
    float ycent;
    float width;
    float height;
    line >> name >> xcent >> ycent >> width >> height;
    
    // Do a simple error check
    if (line.fail()) {
        cout << "Error: invalid input" << endl;
        return nullptr;
    }
    
    // Check to see if name is a reserved word
    if (sdb.isReserved(name)) {
        cout << "Error: " << name << " is a reserved word" << endl;
        return nullptr;
    }
    
    // Check if a shape with this name already exists
    if (sdb.shapeExists(name)) {
        cout << "Error: a shape with the name " << name << " already exists" << endl;
        return nullptr;
    }

    // Create the shape object and return a pointer to it
    Shape* myShape = (Shape*) new Rectangle(name, xcent, ycent, width, height);
    cout << "created rectangle" << endl;
    return myShape;
}
Shape* parsetriangleCommand(stringstream& line) {
    string name;
    float x1cent;
    float y1cent;
    float x2cent;
    float y2cent;
    float x3cent;
    float y3cent;
    line >> name >> x1cent >> y1cent >> x2cent >> y2cent >> x3cent >> y3cent;
    
    // Do a simple error check
    if (line.fail()) {
        cout << "Error: invalid input" << endl;
        return nullptr;
    }
    
    // Check to see if name is a reserved word
    if (sdb.isReserved(name)) {
        cout << "Error: " << name << " is a reserved word" << endl;
        return nullptr;
    }
    
    // Check if a shape with this name already exists
    if (sdb.shapeExists(name)) {
        cout << "Error: a shape with the name " << name << " already exists" << endl;
        return nullptr;
    }

    // Create the shape object and return a pointer to it
    Shape* myShape = (Shape*) new Triangle(name, x1cent, y1cent,  x2cent,  y2cent,  x3cent,  y3cent);
    cout << "created triangle" << endl;
    return myShape;
}
