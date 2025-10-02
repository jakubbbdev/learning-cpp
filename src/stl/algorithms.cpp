#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <random>
#include <iterator>

/**
 * STL Algorithms in C++
 * 
 * This example demonstrates various STL algorithms:
 * - Non-modifying algorithms (find, count, for_each, etc.)
 * - Modifying algorithms (transform, replace, reverse, etc.)
 * - Sorting algorithms (sort, partial_sort, nth_element)
 * - Binary search algorithms (binary_search, lower_bound, upper_bound)
 * - Set algorithms (set_union, set_intersection, set_difference)
 * - Heap algorithms (make_heap, push_heap, pop_heap)
 * - Numeric algorithms (accumulate, inner_product, partial_sum)
 */

void demonstrateNonModifyingAlgorithms() {
    std::cout << "=== NON-MODIFYING ALGORITHMS ===" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Find
    auto it = std::find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        std::cout << "  Found 5 at position: " << std::distance(numbers.begin(), it) << std::endl;
    }
    
    // Count
    int count = std::count(numbers.begin(), numbers.end(), 3);
    std::cout << "  Count of 3: " << count << std::endl;
    
    // Count if
    int evenCount = std::count_if(numbers.begin(), numbers.end(), 
                                 [](int n) { return n % 2 == 0; });
    std::cout << "  Count of even numbers: " << evenCount << std::endl;
    
    // For each
    std::cout << "  Doubled numbers: ";
    std::for_each(numbers.begin(), numbers.end(), 
                  [](int n) { std::cout << n * 2 << " "; });
    std::cout << std::endl;
    
    // All of, any of, none of
    bool allPositive = std::all_of(numbers.begin(), numbers.end(), 
                                  [](int n) { return n > 0; });
    bool anyGreaterThan5 = std::any_of(numbers.begin(), numbers.end(), 
                                      [](int n) { return n > 5; });
    bool noneNegative = std::none_of(numbers.begin(), numbers.end(), 
                                    [](int n) { return n < 0; });
    
    std::cout << "  All positive: " << (allPositive ? "Yes" : "No") << std::endl;
    std::cout << "  Any > 5: " << (anyGreaterThan5 ? "Yes" : "No") << std::endl;
    std::cout << "  None negative: " << (noneNegative ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
}

void demonstrateModifyingAlgorithms() {
    std::cout << "=== MODIFYING ALGORITHMS ===" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Transform
    std::vector<int> doubled;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(doubled),
                  [](int n) { return n * 2; });
    
    std::cout << "  Original: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "  Doubled: ";
    for (int n : doubled) std::cout << n << " ";
    std::cout << std::endl;
    
    // Replace
    std::vector<int> replaceTest = {1, 2, 3, 2, 4, 2, 5};
    std::replace(replaceTest.begin(), replaceTest.end(), 2, 99);
    
    std::cout << "  After replacing 2 with 99: ";
    for (int n : replaceTest) std::cout << n << " ";
    std::cout << std::endl;
    
    // Replace if
    std::vector<int> replaceIfTest = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::replace_if(replaceIfTest.begin(), replaceIfTest.end(),
                   [](int n) { return n % 2 == 0; }, 0);
    
    std::cout << "  After replacing even numbers with 0: ";
    for (int n : replaceIfTest) std::cout << n << " ";
    std::cout << std::endl;
    
    // Reverse
    std::vector<int> reverseTest = {1, 2, 3, 4, 5};
    std::reverse(reverseTest.begin(), reverseTest.end());
    
    std::cout << "  Reversed: ";
    for (int n : reverseTest) std::cout << n << " ";
    std::cout << std::endl;
    
    // Rotate
    std::vector<int> rotateTest = {1, 2, 3, 4, 5};
    std::rotate(rotateTest.begin(), rotateTest.begin() + 2, rotateTest.end());
    
    std::cout << "  Rotated left by 2: ";
    for (int n : rotateTest) std::cout << n << " ";
    std::cout << std::endl << std::endl;
}

void demonstrateSortingAlgorithms() {
    std::cout << "=== SORTING ALGORITHMS ===" << std::endl;
    
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    // Sort
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    
    std::cout << "  Original: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "  Sorted: ";
    for (int n : sortedNumbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Sort with custom comparator
    std::vector<int> customSort = numbers;
    std::sort(customSort.begin(), customSort.end(), std::greater<int>());
    
    std::cout << "  Sorted (descending): ";
    for (int n : customSort) std::cout << n << " ";
    std::cout << std::endl;
    
    // Partial sort
    std::vector<int> partialSort = numbers;
    std::partial_sort(partialSort.begin(), partialSort.begin() + 3, partialSort.end());
    
    std::cout << "  Partial sort (first 3): ";
    for (int n : partialSort) std::cout << n << " ";
    std::cout << std::endl;
    
    // Nth element
    std::vector<int> nthElement = numbers;
    std::nth_element(nthElement.begin(), nthElement.begin() + 2, nthElement.end());
    
    std::cout << "  Nth element (3rd smallest): " << nthElement[2] << std::endl;
    std::cout << std::endl;
}

void demonstrateBinarySearchAlgorithms() {
    std::cout << "=== BINARY SEARCH ALGORITHMS ===" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Binary search
    bool found = std::binary_search(numbers.begin(), numbers.end(), 5);
    std::cout << "  Binary search for 5: " << (found ? "Found" : "Not found") << std::endl;
    
    // Lower bound
    auto lower = std::lower_bound(numbers.begin(), numbers.end(), 5);
    std::cout << "  Lower bound for 5: position " << std::distance(numbers.begin(), lower) << std::endl;
    
    // Upper bound
    auto upper = std::upper_bound(numbers.begin(), numbers.end(), 5);
    std::cout << "  Upper bound for 5: position " << std::distance(numbers.begin(), upper) << std::endl;
    
    // Equal range
    auto range = std::equal_range(numbers.begin(), numbers.end(), 5);
    std::cout << "  Equal range for 5: [" << std::distance(numbers.begin(), range.first) 
              << ", " << std::distance(numbers.begin(), range.second) << ")" << std::endl;
    std::cout << std::endl;
}

void demonstrateSetAlgorithms() {
    std::cout << "=== SET ALGORITHMS ===" << std::endl;
    
    std::vector<int> set1 = {1, 2, 3, 4, 5};
    std::vector<int> set2 = {3, 4, 5, 6, 7};
    std::vector<int> result;
    
    // Set union
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   std::back_inserter(result));
    
    std::cout << "  Set 1: ";
    for (int n : set1) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "  Set 2: ";
    for (int n : set2) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "  Union: ";
    for (int n : result) std::cout << n << " ";
    std::cout << std::endl;
    
    // Set intersection
    result.clear();
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                         std::back_inserter(result));
    
    std::cout << "  Intersection: ";
    for (int n : result) std::cout << n << " ";
    std::cout << std::endl;
    
    // Set difference
    result.clear();
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                       std::back_inserter(result));
    
    std::cout << "  Difference (set1 - set2): ";
    for (int n : result) std::cout << n << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void demonstrateHeapAlgorithms() {
    std::cout << "=== HEAP ALGORITHMS ===" << std::endl;
    
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6};
    
    // Make heap
    std::make_heap(numbers.begin(), numbers.end());
    
    std::cout << "  After make_heap: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Push heap
    numbers.push_back(8);
    std::push_heap(numbers.begin(), numbers.end());
    
    std::cout << "  After push_heap(8): ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    // Pop heap
    std::pop_heap(numbers.begin(), numbers.end());
    int maxElement = numbers.back();
    numbers.pop_back();
    
    std::cout << "  Popped element: " << maxElement << std::endl;
    std::cout << "  After pop_heap: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void demonstrateNumericAlgorithms() {
    std::cout << "=== NUMERIC ALGORITHMS ===" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "  Sum: " << sum << std::endl;
    
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
    std::cout << "  Product: " << product << std::endl;
    
    // Partial sum
    std::vector<int> partialSums;
    std::partial_sum(numbers.begin(), numbers.end(), std::back_inserter(partialSums));
    
    std::cout << "  Partial sums: ";
    for (int n : partialSums) std::cout << n << " ";
    std::cout << std::endl;
    
    // Inner product
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    int dotProduct = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
    
    std::cout << "  Dot product: " << dotProduct << std::endl;
    
    // Adjacent difference
    std::vector<int> differences;
    std::adjacent_difference(numbers.begin(), numbers.end(), std::back_inserter(differences));
    
    std::cout << "  Adjacent differences: ";
    for (int n : differences) std::cout << n << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void demonstratePermutationAlgorithms() {
    std::cout << "=== PERMUTATION ALGORITHMS ===" << std::endl;
    
    std::vector<int> numbers = {1, 2, 3};
    
    std::cout << "  All permutations of {1, 2, 3}:" << std::endl;
    do {
        std::cout << "    ";
        for (int n : numbers) std::cout << n << " ";
        std::cout << std::endl;
    } while (std::next_permutation(numbers.begin(), numbers.end()));
    
    std::cout << std::endl;
}

int main() {
    std::cout << "=== STL Algorithms ===" << std::endl;
    std::cout << std::endl;
    
    demonstrateNonModifyingAlgorithms();
    demonstrateModifyingAlgorithms();
    demonstrateSortingAlgorithms();
    demonstrateBinarySearchAlgorithms();
    demonstrateSetAlgorithms();
    demonstrateHeapAlgorithms();
    demonstrateNumericAlgorithms();
    demonstratePermutationAlgorithms();
    
    std::cout << "=== End of STL Algorithms Example ===" << std::endl;
    
    return 0;
}
