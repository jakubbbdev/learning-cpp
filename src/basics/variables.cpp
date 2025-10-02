#include <iostream>
#include <string>

/**
 * Variables and Data Types in C++
 * 
 * This example demonstrates different data types and variable declarations
 * in C++. Understanding data types is fundamental to C++ programming.
 */

int main() {
    std::cout << "=== C++ Variables and Data Types ===" << std::endl;
    std::cout << std::endl;
    
    // Integer types
    int age = 25;                    // 32-bit integer
    short smallNumber = 100;         // 16-bit integer
    long bigNumber = 1000000L;       // 32-bit or 64-bit integer
    long long hugeNumber = 1000000000LL; // 64-bit integer
    
    std::cout << "Integer types:" << std::endl;
    std::cout << "  int age = " << age << std::endl;
    std::cout << "  short smallNumber = " << smallNumber << std::endl;
    std::cout << "  long bigNumber = " << bigNumber << std::endl;
    std::cout << "  long long hugeNumber = " << hugeNumber << std::endl;
    std::cout << std::endl;
    
    // Floating point types
    float pi = 3.14159f;             // Single precision
    double e = 2.718281828;          // Double precision
    long double precision = 3.141592653589793238L; // Extended precision
    
    std::cout << "Floating point types:" << std::endl;
    std::cout << "  float pi = " << pi << std::endl;
    std::cout << "  double e = " << e << std::endl;
    std::cout << "  long double precision = " << precision << std::endl;
    std::cout << std::endl;
    
    // Character types
    char letter = 'A';                // Single character
    char newline = '\n';             // Escape sequence
    char tab = '\t';                 // Tab character
    
    std::cout << "Character types:" << std::endl;
    std::cout << "  char letter = '" << letter << "'" << std::endl;
    std::cout << "  char newline = '\\n' (newline character)" << std::endl;
    std::cout << "  char tab = '\\t' (tab character)" << std::endl;
    std::cout << std::endl;
    
    // Boolean type
    bool isStudent = true;           // Boolean value
    bool isWorking = false;          // Boolean value
    
    std::cout << "Boolean types:" << std::endl;
    std::cout << "  bool isStudent = " << std::boolalpha << isStudent << std::endl;
    std::cout << "  bool isWorking = " << std::boolalpha << isWorking << std::endl;
    std::cout << std::endl;
    
    // String type
    std::string name = "John Doe";   // String object
    std::string greeting = "Hello, " + name + "!"; // String concatenation
    
    std::cout << "String types:" << std::endl;
    std::cout << "  std::string name = \"" << name << "\"" << std::endl;
    std::cout << "  std::string greeting = \"" << greeting << "\"" << std::endl;
    std::cout << std::endl;
    
    // Constants
    const int MAX_STUDENTS = 100;    // Compile-time constant
    const double GRAVITY = 9.81;     // Compile-time constant
    
    std::cout << "Constants:" << std::endl;
    std::cout << "  const int MAX_STUDENTS = " << MAX_STUDENTS << std::endl;
    std::cout << "  const double GRAVITY = " << GRAVITY << std::endl;
    std::cout << std::endl;
    
    // Auto keyword (C++11 and later)
    auto autoInt = 42;               // Compiler deduces int
    auto autoDouble = 3.14;          // Compiler deduces double
    auto autoString = "Hello";       // Compiler deduces const char*
    
    std::cout << "Auto keyword (type deduction):" << std::endl;
    std::cout << "  auto autoInt = " << autoInt << " (deduced as int)" << std::endl;
    std::cout << "  auto autoDouble = " << autoDouble << " (deduced as double)" << std::endl;
    std::cout << "  auto autoString = \"" << autoString << "\" (deduced as const char*)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "=== End of Variables Example ===" << std::endl;
    
    return 0;
}
