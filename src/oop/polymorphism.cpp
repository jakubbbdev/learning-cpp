#include <iostream>
#include <string>
#include <vector>
#include <memory>

/**
 * Polymorphism in C++
 * 
 * This example demonstrates:
 * - Virtual functions and dynamic binding
 * - Pure virtual functions and abstract classes
 * - Virtual destructors
 * - Function overriding vs overloading
 * - Runtime polymorphism
 * - Virtual function tables (vtable)
 */

// Abstract base class
class Shape {
protected:
    std::string name;
    double x, y;  // Position coordinates
    
public:
    Shape(const std::string& shapeName, double posX = 0, double posY = 0)
        : name(shapeName), x(posX), y(posY) {
        std::cout << "  Shape constructor: " << name << std::endl;
    }
    
    // Virtual destructor (crucial for polymorphism)
    virtual ~Shape() {
        std::cout << "  Shape destructor: " << name << std::endl;
    }
    
    // Pure virtual functions (must be implemented by derived classes)
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;
    
    // Virtual function (can be overridden)
    virtual void move(double newX, double newY) {
        x = newX;
        y = newY;
        std::cout << "  " << name << " moved to (" << x << ", " << y << ")" << std::endl;
    }
    
    // Non-virtual function
    void displayInfo() const {
        std::cout << "  Shape: " << name << " at (" << x << ", " << y << ")" << std::endl;
        std::cout << "    Area: " << getArea() << std::endl;
        std::cout << "    Perimeter: " << getPerimeter() << std::endl;
    }
    
    // Getter methods
    std::string getName() const { return name; }
    double getX() const { return x; }
    double getY() const { return y; }
};

// Concrete derived class
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(const std::string& circleName, double r, double posX = 0, double posY = 0)
        : Shape(circleName, posX, posY), radius(r) {
        std::cout << "  Circle constructor: " << name << std::endl;
    }
    
    ~Circle() {
        std::cout << "  Circle destructor: " << name << std::endl;
    }
    
    // Implement pure virtual functions
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void draw() const override {
        std::cout << "  Drawing a circle with radius " << radius << std::endl;
    }
    
    // Override virtual function
    void move(double newX, double newY) override {
        Shape::move(newX, newY);
        std::cout << "  Circle-specific move completed" << std::endl;
    }
    
    double getRadius() const { return radius; }
};

// Another concrete derived class
class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(const std::string& rectName, double w, double h, double posX = 0, double posY = 0)
        : Shape(rectName, posX, posY), width(w), height(h) {
        std::cout << "  Rectangle constructor: " << name << std::endl;
    }
    
    ~Rectangle() {
        std::cout << "  Rectangle destructor: " << name << std::endl;
    }
    
    double getArea() const override {
        return width * height;
    }
    
    double getPerimeter() const override {
        return 2 * (width + height);
    }
    
    void draw() const override {
        std::cout << "  Drawing a rectangle " << width << "x" << height << std::endl;
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

// Another concrete derived class
class Triangle : public Shape {
private:
    double base, height;
    
public:
    Triangle(const std::string& triName, double b, double h, double posX = 0, double posY = 0)
        : Shape(triName, posX, posY), base(b), height(h) {
        std::cout << "  Triangle constructor: " << name << std::endl;
    }
    
    ~Triangle() {
        std::cout << "  Triangle destructor: " << name << std::endl;
    }
    
    double getArea() const override {
        return 0.5 * base * height;
    }
    
    double getPerimeter() const override {
        // Simplified calculation (assuming right triangle)
        double hypotenuse = sqrt(base * base + height * height);
        return base + height + hypotenuse;
    }
    
    void draw() const override {
        std::cout << "  Drawing a triangle with base " << base 
                  << " and height " << height << std::endl;
    }
    
    double getBase() const { return base; }
    double getHeight() const { return height; }
};

// Function to demonstrate polymorphism
void demonstratePolymorphism(const std::vector<Shape*>& shapes) {
    std::cout << "  === Polymorphism Demonstration ===" << std::endl;
    
    for (const Shape* shape : shapes) {
        std::cout << std::endl;
        shape->displayInfo();
        shape->draw();
        shape->move(shape->getX() + 10, shape->getY() + 10);
    }
}

// Function to calculate total area using polymorphism
double calculateTotalArea(const std::vector<Shape*>& shapes) {
    double totalArea = 0.0;
    for (const Shape* shape : shapes) {
        totalArea += shape->getArea();
    }
    return totalArea;
}

int main() {
    std::cout << "=== C++ Polymorphism ===" << std::endl;
    std::cout << std::endl;
    
    // Creating objects
    std::cout << "1. Creating shape objects:" << std::endl;
    Circle circle("MyCircle", 5.0, 0, 0);
    Rectangle rectangle("MyRectangle", 4.0, 6.0, 10, 10);
    Triangle triangle("MyTriangle", 3.0, 4.0, 20, 20);
    std::cout << std::endl;
    
    // Direct object calls
    std::cout << "2. Direct object calls:" << std::endl;
    circle.displayInfo();
    rectangle.displayInfo();
    triangle.displayInfo();
    std::cout << std::endl;
    
    // Polymorphism with pointers
    std::cout << "3. Polymorphism with pointers:" << std::endl;
    std::vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);
    shapes.push_back(&triangle);
    
    demonstratePolymorphism(shapes);
    std::cout << std::endl;
    
    // Dynamic allocation and polymorphism
    std::cout << "4. Dynamic allocation and polymorphism:" << std::endl;
    std::vector<std::unique_ptr<Shape>> dynamicShapes;
    
    dynamicShapes.push_back(std::make_unique<Circle>("DynamicCircle", 3.0));
    dynamicShapes.push_back(std::make_unique<Rectangle>("DynamicRectangle", 5.0, 3.0));
    dynamicShapes.push_back(std::make_unique<Triangle>("DynamicTriangle", 4.0, 3.0));
    
    for (const auto& shape : dynamicShapes) {
        shape->displayInfo();
        shape->draw();
    }
    std::cout << std::endl;
    
    // Polymorphism with references
    std::cout << "5. Polymorphism with references:" << std::endl;
    Shape& shapeRef1 = circle;
    Shape& shapeRef2 = rectangle;
    
    std::cout << "  Circle via reference:" << std::endl;
    shapeRef1.displayInfo();
    shapeRef1.draw();
    
    std::cout << "  Rectangle via reference:" << std::endl;
    shapeRef2.displayInfo();
    shapeRef2.draw();
    std::cout << std::endl;
    
    // Function that uses polymorphism
    std::cout << "6. Function using polymorphism:" << std::endl;
    double totalArea = calculateTotalArea(shapes);
    std::cout << "  Total area of all shapes: " << totalArea << std::endl;
    std::cout << std::endl;
    
    // Virtual function table demonstration
    std::cout << "7. Virtual function behavior:" << std::endl;
    for (Shape* shape : shapes) {
        std::cout << "  " << shape->getName() << " area calculation: ";
        std::cout << shape->getArea() << std::endl;
    }
    std::cout << std::endl;
    
    // Array of polymorphic objects
    std::cout << "8. Array of polymorphic objects:" << std::endl;
    Shape* shapeArray[] = {&circle, &rectangle, &triangle};
    
    for (int i = 0; i < 3; ++i) {
        std::cout << "  Shape " << (i + 1) << ": ";
        shapeArray[i]->draw();
    }
    std::cout << std::endl;
    
    std::cout << "=== End of Polymorphism Example ===" << std::endl;
    
    return 0;
}
