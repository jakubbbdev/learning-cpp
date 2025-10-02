# C++ Learning Project 🚀

A comprehensive C++ learning project designed to teach fundamental concepts through practical examples. This project is perfect for beginners who want to learn C++ programming step by step.

## 📚 Table of Contents

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Learning Modules](#learning-modules)
- [Building and Running](#building-and-running)
- [Learning Path](#learning-path)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This project provides hands-on examples covering essential C++ concepts:

- **Basic Concepts**: Variables, data types, loops, and functions
- **Object-Oriented Programming**: Classes, inheritance, and polymorphism
- **STL (Standard Template Library)**: Containers and algorithms

Each example is thoroughly commented in English to help you understand the concepts and best practices.

## 🔧 Prerequisites

- **C++ Compiler**: GCC 7.0+ or Clang 5.0+ or MSVC 2017+
- **CMake**: Version 3.16 or higher
- **Basic Programming Knowledge**: Familiarity with any programming language

## 📁 Project Structure

```
cpp_learning_project/
├── CMakeLists.txt              # CMake configuration
├── main.cpp                    # Main entry point with project overview
├── README.md                   # This file
└── src/
    ├── basics/                 # Basic C++ concepts
    │   ├── variables.cpp       # Data types and variables
    │   ├── loops.cpp          # Loop constructs
    │   └── functions.cpp      # Functions and parameters
    ├── oop/                   # Object-oriented programming
    │   ├── classes.cpp        # Classes and objects
    │   ├── inheritance.cpp    # Inheritance and virtual functions
    │   └── polymorphism.cpp   # Polymorphism and abstract classes
    └── stl/                   # Standard Template Library
        ├── containers.cpp     # STL containers
        └── algorithms.cpp     # STL algorithms
```

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone <your-repository-url>
cd cpp_learning_project
```

### 2. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

### 3. Run Examples

```bash
# Run the main program to see all available examples
./cpp_learning

# Run specific examples
./basics_variables
./basics_loops
./basics_functions
./oop_classes
./oop_inheritance
./oop_polymorphism
./stl_containers
./stl_algorithms
```

## 📖 Learning Modules

### 1. Basic Concepts (`src/basics/`)

#### Variables (`variables.cpp`)
- Data types (int, float, double, char, bool, string)
- Variable declarations and initialization
- Constants and the `const` keyword
- The `auto` keyword for type deduction
- Escape sequences and character literals

#### Loops (`loops.cpp`)
- Traditional `for` loops
- `while` and `do-while` loops
- Range-based `for` loops (C++11)
- Nested loops
- Loop control statements (`break`, `continue`)
- Infinite loops with break conditions

#### Functions (`functions.cpp`)
- Function declarations and definitions
- Parameters and return values
- Function overloading
- Default parameters
- Pass by value vs pass by reference
- Recursive functions
- Lambda functions (C++11)

### 2. Object-Oriented Programming (`src/oop/`)

#### Classes (`classes.cpp`)
- Class definition and object creation
- Constructors and destructors
- Member variables and methods
- Access specifiers (public, private, protected)
- Static members
- Friend functions
- Composition

#### Inheritance (`inheritance.cpp`)
- Single inheritance
- Multiple inheritance
- Virtual functions and polymorphism
- Access specifiers in inheritance
- Constructor and destructor in inheritance
- Method overriding
- Virtual inheritance (diamond problem)

#### Polymorphism (`polymorphism.cpp`)
- Virtual functions and dynamic binding
- Pure virtual functions and abstract classes
- Virtual destructors
- Function overriding vs overloading
- Runtime polymorphism
- Virtual function tables (vtable)

### 3. STL (Standard Template Library) (`src/stl/`)

#### Containers (`containers.cpp`)
- **Sequence Containers**: vector, list, deque, array
- **Associative Containers**: set, map, multiset, multimap
- **Unordered Containers**: unordered_set, unordered_map
- **Container Adaptors**: stack, queue, priority_queue

#### Algorithms (`algorithms.cpp`)
- **Non-modifying**: find, count, for_each, all_of, any_of, none_of
- **Modifying**: transform, replace, reverse, rotate
- **Sorting**: sort, partial_sort, nth_element
- **Binary Search**: binary_search, lower_bound, upper_bound
- **Set Operations**: set_union, set_intersection, set_difference
- **Heap Operations**: make_heap, push_heap, pop_heap
- **Numeric**: accumulate, inner_product, partial_sum

## 🛠️ Building and Running

### Using CMake (Recommended)

```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build all examples
make

# Run specific examples
./basics_variables
./oop_classes
./stl_containers
```

### Manual Compilation

```bash
# Compile individual examples
g++ -std=c++20 -Wall -Wextra src/basics/variables.cpp -o variables
g++ -std=c++20 -Wall -Wextra src/oop/classes.cpp -o classes
g++ -std=c++20 -Wall -Wextra src/stl/containers.cpp -o containers

# Run examples
./variables
./classes
./containers
```

## 🗺️ Learning Path

### Beginner Level
1. Start with `basics/variables.cpp` to understand data types
2. Move to `basics/loops.cpp` for control flow
3. Learn `basics/functions.cpp` for code organization

### Intermediate Level
4. Study `oop/classes.cpp` for object-oriented basics
5. Explore `oop/inheritance.cpp` for code reuse
6. Understand `oop/polymorphism.cpp` for flexible design

### Advanced Level
7. Master `stl/containers.cpp` for efficient data structures
8. Learn `stl/algorithms.cpp` for powerful operations

## 💡 Tips for Learning

- **Read the Comments**: Every example is thoroughly commented
- **Experiment**: Modify the code and see what happens
- **Practice**: Try to solve similar problems on your own
- **Debug**: Use a debugger to step through the code
- **Compile Often**: Fix errors as they appear

## 🔍 Key C++ Concepts Covered

- **Memory Management**: Stack vs heap, RAII
- **References and Pointers**: Understanding memory addresses
- **Templates**: Generic programming basics
- **Exception Handling**: Error management
- **Modern C++**: C++11/14/17/20 features
- **Best Practices**: Code style and conventions

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Areas for Contribution
- Additional examples
- Better documentation
- Performance improvements
- Cross-platform compatibility
- Unit tests

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- C++ community for excellent resources
- Contributors who help improve this project
- Educators who inspire learning

## 📞 Support

If you have questions or need help:

- Open an issue on GitHub
- Check the documentation
- Review the code comments
- Ask the community

---

**Happy Learning! 🎓**

Remember: The best way to learn programming is by doing. Don't just read the code - run it, modify it, and experiment with it!
