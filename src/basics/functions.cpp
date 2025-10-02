#include <iostream>
#include <string>
#include <vector>

/**
 * Functions in C++
 * 
 * This example demonstrates different aspects of functions in C++:
 * - Function declarations and definitions
 * - Parameters and return values
 * - Function overloading
 * - Default parameters
 * - Pass by value vs pass by reference
 */

// Function declaration (prototype)
int add(int a, int b);
void printMessage(const std::string& message);
double calculateArea(double length, double width = 1.0); // Default parameter

// Function overloading - same name, different parameters
int multiply(int a, int b);
double multiply(double a, double b);
int multiply(int a, int b, int c);

// Pass by reference example
void swap(int& a, int& b);
void modifyVector(std::vector<int>& vec);

// Recursive function
int factorial(int n);

// Lambda function example (C++11)
void demonstrateLambda();

int main() {
    std::cout << "=== C++ Functions ===" << std::endl;
    std::cout << std::endl;
    
    // Basic function call
    std::cout << "1. Basic function call:" << std::endl;
    int result = add(5, 3);
    std::cout << "  add(5, 3) = " << result << std::endl;
    std::cout << std::endl;
    
    // Function with string parameter
    std::cout << "2. Function with string parameter:" << std::endl;
    printMessage("Hello from function!");
    std::cout << std::endl;
    
    // Function with default parameter
    std::cout << "3. Function with default parameter:" << std::endl;
    double area1 = calculateArea(5.0, 3.0);
    double area2 = calculateArea(5.0);  // Uses default width = 1.0
    std::cout << "  calculateArea(5.0, 3.0) = " << area1 << std::endl;
    std::cout << "  calculateArea(5.0) = " << area2 << std::endl;
    std::cout << std::endl;
    
    // Function overloading
    std::cout << "4. Function overloading:" << std::endl;
    int intResult = multiply(4, 5);
    double doubleResult = multiply(4.5, 2.5);
    int tripleResult = multiply(2, 3, 4);
    std::cout << "  multiply(4, 5) = " << intResult << std::endl;
    std::cout << "  multiply(4.5, 2.5) = " << doubleResult << std::endl;
    std::cout << "  multiply(2, 3, 4) = " << tripleResult << std::endl;
    std::cout << std::endl;
    
    // Pass by reference
    std::cout << "5. Pass by reference:" << std::endl;
    int x = 10, y = 20;
    std::cout << "  Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "  After swap: x = " << x << ", y = " << y << std::endl;
    std::cout << std::endl;
    
    // Pass by reference with vector
    std::cout << "6. Pass by reference with vector:" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "  Original vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    modifyVector(numbers);
    std::cout << "  Modified vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Recursive function
    std::cout << "7. Recursive function (factorial):" << std::endl;
    int n = 5;
    int fact = factorial(n);
    std::cout << "  factorial(" << n << ") = " << fact << std::endl;
    std::cout << std::endl;
    
    // Lambda functions
    std::cout << "8. Lambda functions:" << std::endl;
    demonstrateLambda();
    std::cout << std::endl;
    
    std::cout << "=== End of Functions Example ===" << std::endl;
    
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

void printMessage(const std::string& message) {
    std::cout << "  Message: " << message << std::endl;
}

double calculateArea(double length, double width) {
    return length * width;
}

int multiply(int a, int b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

int multiply(int a, int b, int c) {
    return a * b * c;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void modifyVector(std::vector<int>& vec) {
    for (int& element : vec) {
        element *= 2;  // Double each element
    }
}

int factorial(int n) {
    if (n <= 1) {
        return 1;  // Base case
    }
    return n * factorial(n - 1);  // Recursive case
}

void demonstrateLambda() {
    // Simple lambda function
    auto square = [](int x) -> int {
        return x * x;
    };
    
    std::cout << "  square(5) = " << square(5) << std::endl;
    
    // Lambda with capture
    int multiplier = 3;
    auto multiplyBy = [multiplier](int x) -> int {
        return x * multiplier;
    };
    
    std::cout << "  multiplyBy(4) = " << multiplyBy(4) << std::endl;
    
    // Lambda with reference capture
    int sum = 0;
    auto addToSum = [&sum](int x) {
        sum += x;
    };
    
    addToSum(10);
    addToSum(20);
    std::cout << "  sum after adding 10 and 20 = " << sum << std::endl;
}
