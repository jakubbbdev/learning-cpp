#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <array>
#include <string>

/**
 * STL Containers in C++
 * 
 * This example demonstrates various STL containers:
 * - Sequence containers (vector, list, deque, array)
 * - Associative containers (set, map, multiset, multimap)
 * - Unordered containers (unordered_set, unordered_map)
 * - Container adaptors (stack, queue, priority_queue)
 */

void demonstrateVector() {
    std::cout << "=== VECTOR ===" << std::endl;
    
    // Creating and initializing vector
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<std::string> words = {"hello", "world", "cpp"};
    
    // Adding elements
    numbers.push_back(6);
    numbers.insert(numbers.begin() + 2, 10);  // Insert at position 2
    
    // Accessing elements
    std::cout << "  First element: " << numbers[0] << std::endl;
    std::cout << "  Last element: " << numbers.back() << std::endl;
    std::cout << "  Size: " << numbers.size() << std::endl;
    
    // Iterating through vector
    std::cout << "  All elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Using iterators
    std::cout << "  Using iterators: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

void demonstrateList() {
    std::cout << "=== LIST ===" << std::endl;
    
    std::list<int> myList = {1, 2, 3, 4, 5};
    
    // List operations
    myList.push_front(0);      // Add to front
    myList.push_back(6);       // Add to back
    myList.insert(++myList.begin(), 10);  // Insert after first element
    
    std::cout << "  List elements: ";
    for (int num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Remove elements
    myList.remove(3);          // Remove all occurrences of 3
    myList.pop_front();        // Remove first element
    
    std::cout << "  After removal: ";
    for (int num : myList) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
}

void demonstrateDeque() {
    std::cout << "=== DEQUE ===" << std::endl;
    
    std::deque<int> myDeque = {1, 2, 3};
    
    // Deque operations (efficient insertion at both ends)
    myDeque.push_front(0);
    myDeque.push_back(4);
    
    std::cout << "  Deque elements: ";
    for (int num : myDeque) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "  Front: " << myDeque.front() << std::endl;
    std::cout << "  Back: " << myDeque.back() << std::endl << std::endl;
}

void demonstrateSet() {
    std::cout << "=== SET ===" << std::endl;
    
    std::set<int> mySet = {5, 2, 8, 1, 9};
    
    // Set automatically sorts and removes duplicates
    mySet.insert(3);
    mySet.insert(5);  // Duplicate, won't be added
    
    std::cout << "  Set elements (sorted): ";
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Set operations
    std::cout << "  Contains 5: " << (mySet.count(5) ? "Yes" : "No") << std::endl;
    std::cout << "  Contains 10: " << (mySet.count(10) ? "Yes" : "No") << std::endl;
    
    mySet.erase(5);
    std::cout << "  After removing 5: ";
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
}

void demonstrateMap() {
    std::cout << "=== MAP ===" << std::endl;
    
    std::map<std::string, int> ages;
    
    // Adding key-value pairs
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 35;
    ages.insert({"David", 28});
    
    // Accessing values
    std::cout << "  Alice's age: " << ages["Alice"] << std::endl;
    std::cout << "  Bob's age: " << ages.at("Bob") << std::endl;
    
    // Iterating through map
    std::cout << "  All ages:" << std::endl;
    for (const auto& pair : ages) {
        std::cout << "    " << pair.first << ": " << pair.second << std::endl;
    }
    
    // Check if key exists
    if (ages.find("Eve") != ages.end()) {
        std::cout << "  Eve's age: " << ages["Eve"] << std::endl;
    } else {
        std::cout << "  Eve not found in map" << std::endl;
    }
    std::cout << std::endl;
}

void demonstrateUnorderedContainers() {
    std::cout << "=== UNORDERED CONTAINERS ===" << std::endl;
    
    // Unordered set (hash set)
    std::unordered_set<std::string> fruits = {"apple", "banana", "orange"};
    fruits.insert("grape");
    
    std::cout << "  Unordered set fruits: ";
    for (const auto& fruit : fruits) {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;
    
    // Unordered map (hash map)
    std::unordered_map<std::string, double> prices;
    prices["apple"] = 1.50;
    prices["banana"] = 0.80;
    prices["orange"] = 2.00;
    
    std::cout << "  Unordered map prices:" << std::endl;
    for (const auto& pair : prices) {
        std::cout << "    " << pair.first << ": $" << pair.second << std::endl;
    }
    std::cout << std::endl;
}

void demonstrateStack() {
    std::cout << "=== STACK ===" << std::endl;
    
    std::stack<int> myStack;
    
    // Push elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    std::cout << "  Stack operations:" << std::endl;
    std::cout << "    Top element: " << myStack.top() << std::endl;
    std::cout << "    Stack size: " << myStack.size() << std::endl;
    
    // Pop elements
    while (!myStack.empty()) {
        std::cout << "    Popping: " << myStack.top() << std::endl;
        myStack.pop();
    }
    std::cout << std::endl;
}

void demonstrateQueue() {
    std::cout << "=== QUEUE ===" << std::endl;
    
    std::queue<std::string> myQueue;
    
    // Enqueue elements
    myQueue.push("First");
    myQueue.push("Second");
    myQueue.push("Third");
    
    std::cout << "  Queue operations:" << std::endl;
    std::cout << "    Front element: " << myQueue.front() << std::endl;
    std::cout << "    Back element: " << myQueue.back() << std::endl;
    
    // Dequeue elements
    while (!myQueue.empty()) {
        std::cout << "    Processing: " << myQueue.front() << std::endl;
        myQueue.pop();
    }
    std::cout << std::endl;
}

void demonstratePriorityQueue() {
    std::cout << "=== PRIORITY QUEUE ===" << std::endl;
    
    std::priority_queue<int> maxHeap;  // Default is max heap
    
    // Insert elements
    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);
    
    std::cout << "  Max heap (priority queue):" << std::endl;
    while (!maxHeap.empty()) {
        std::cout << "    Highest priority: " << maxHeap.top() << std::endl;
        maxHeap.pop();
    }
    
    // Min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);
    
    std::cout << "  Min heap:" << std::endl;
    while (!minHeap.empty()) {
        std::cout << "    Lowest priority: " << minHeap.top() << std::endl;
        minHeap.pop();
    }
    std::cout << std::endl;
}

void demonstrateArray() {
    std::cout << "=== ARRAY ===" << std::endl;
    
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};
    
    std::cout << "  Array elements: ";
    for (int num : myArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "  Array size: " << myArray.size() << std::endl;
    std::cout << "  First element: " << myArray.front() << std::endl;
    std::cout << "  Last element: " << myArray.back() << std::endl;
    std::cout << "  Element at index 2: " << myArray[2] << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "=== STL Containers ===" << std::endl;
    std::cout << std::endl;
    
    demonstrateVector();
    demonstrateList();
    demonstrateDeque();
    demonstrateSet();
    demonstrateMap();
    demonstrateUnorderedContainers();
    demonstrateStack();
    demonstrateQueue();
    demonstratePriorityQueue();
    demonstrateArray();
    
    std::cout << "=== End of STL Containers Example ===" << std::endl;
    
    return 0;
}
