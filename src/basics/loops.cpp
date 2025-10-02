#include <iostream>
#include <vector>

/**
 * Loops in C++
 * 
 * This example demonstrates different types of loops in C++:
 * - for loops
 * - while loops
 * - do-while loops
 * - range-based for loops (C++11)
 */

int main() {
    std::cout << "=== C++ Loops ===" << std::endl;
    std::cout << std::endl;
    
    // Traditional for loop
    std::cout << "1. Traditional for loop:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << "  Iteration " << i << std::endl;
    }
    std::cout << std::endl;
    
    // For loop with different increment
    std::cout << "2. For loop with step 2:" << std::endl;
    for (int i = 0; i < 10; i += 2) {
        std::cout << "  Even number: " << i << std::endl;
    }
    std::cout << std::endl;
    
    // While loop
    std::cout << "3. While loop:" << std::endl;
    int count = 1;
    while (count <= 3) {
        std::cout << "  Count: " << count << std::endl;
        count++;
    }
    std::cout << std::endl;
    
    // Do-while loop (executes at least once)
    std::cout << "4. Do-while loop:" << std::endl;
    int number = 5;
    do {
        std::cout << "  Number: " << number << std::endl;
        number--;
    } while (number > 0);
    std::cout << std::endl;
    
    // Nested loops
    std::cout << "5. Nested loops (multiplication table):" << std::endl;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            std::cout << "  " << i << " x " << j << " = " << (i * j) << std::endl;
        }
    }
    std::cout << std::endl;
    
    // Range-based for loop (C++11) with array
    std::cout << "6. Range-based for loop with array:" << std::endl;
    int numbers[] = {10, 20, 30, 40, 50};
    for (int num : numbers) {
        std::cout << "  Array element: " << num << std::endl;
    }
    std::cout << std::endl;
    
    // Range-based for loop with vector
    std::cout << "7. Range-based for loop with vector:" << std::endl;
    std::vector<std::string> fruits = {"apple", "banana", "orange", "grape"};
    for (const auto& fruit : fruits) {
        std::cout << "  Fruit: " << fruit << std::endl;
    }
    std::cout << std::endl;
    
    // Loop control statements
    std::cout << "8. Loop control statements (break and continue):" << std::endl;
    std::cout << "   Numbers 1-10, skip 5, stop at 8:" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        if (i == 5) {
            continue;  // Skip this iteration
        }
        if (i == 8) {
            break;     // Exit the loop
        }
        std::cout << "  " << i << std::endl;
    }
    std::cout << std::endl;
    
    // Infinite loop with break condition
    std::cout << "9. Controlled infinite loop:" << std::endl;
    int counter = 0;
    while (true) {
        counter++;
        std::cout << "  Counter: " << counter << std::endl;
        if (counter >= 3) {
            break;  // Exit the infinite loop
        }
    }
    std::cout << std::endl;
    
    // Loop with multiple variables
    std::cout << "10. For loop with multiple variables:" << std::endl;
    for (int i = 0, j = 10; i < 5; ++i, --j) {
        std::cout << "  i = " << i << ", j = " << j << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "=== End of Loops Example ===" << std::endl;
    
    return 0;
}
