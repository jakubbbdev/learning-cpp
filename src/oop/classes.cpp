#include <iostream>
#include <string>
#include <vector>

/**
 * Classes and Objects in C++
 * 
 * This example demonstrates:
 * - Class definition and object creation
 * - Constructors and destructors
 * - Member variables and methods
 * - Access specifiers (public, private, protected)
 * - Static members
 * - Friend functions
 */

class Student {
private:
    std::string name;
    int age;
    std::vector<double> grades;
    static int totalStudents;  // Static member variable

public:
    // Default constructor
    Student() : name("Unknown"), age(0) {
        totalStudents++;
        std::cout << "  Default constructor called for " << name << std::endl;
    }
    
    // Parameterized constructor
    Student(const std::string& studentName, int studentAge) 
        : name(studentName), age(studentAge) {
        totalStudents++;
        std::cout << "  Parameterized constructor called for " << name << std::endl;
    }
    
    // Copy constructor
    Student(const Student& other) : name(other.name), age(other.age), grades(other.grades) {
        totalStudents++;
        std::cout << "  Copy constructor called for " << name << std::endl;
    }
    
    // Destructor
    ~Student() {
        totalStudents--;
        std::cout << "  Destructor called for " << name << std::endl;
    }
    
    // Getter methods
    std::string getName() const { return name; }
    int getAge() const { return age; }
    
    // Setter methods
    void setName(const std::string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    
    // Method to add grade
    void addGrade(double grade) {
        if (grade >= 0.0 && grade <= 100.0) {
            grades.push_back(grade);
        }
    }
    
    // Method to calculate average grade
    double getAverageGrade() const {
        if (grades.empty()) {
            return 0.0;
        }
        
        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }
    
    // Method to display student info
    void displayInfo() const {
        std::cout << "  Student: " << name << ", Age: " << age;
        if (!grades.empty()) {
            std::cout << ", Average Grade: " << getAverageGrade();
        }
        std::cout << std::endl;
    }
    
    // Static method
    static int getTotalStudents() {
        return totalStudents;
    }
    
    // Friend function declaration
    friend void printStudentDetails(const Student& student);
};

// Initialize static member variable
int Student::totalStudents = 0;

// Friend function definition
void printStudentDetails(const Student& student) {
    std::cout << "  Friend function access: " << student.name 
              << " is " << student.age << " years old" << std::endl;
}

// Another class to demonstrate composition
class Course {
private:
    std::string courseName;
    std::string instructor;
    int credits;
    
public:
    Course(const std::string& name, const std::string& instructorName, int creditHours)
        : courseName(name), instructor(instructorName), credits(creditHours) {}
    
    void displayCourseInfo() const {
        std::cout << "  Course: " << courseName 
                  << ", Instructor: " << instructor 
                  << ", Credits: " << credits << std::endl;
    }
    
    std::string getCourseName() const { return courseName; }
    std::string getInstructor() const { return instructor; }
    int getCredits() const { return credits; }
};

int main() {
    std::cout << "=== C++ Classes and Objects ===" << std::endl;
    std::cout << std::endl;
    
    // Creating objects using different constructors
    std::cout << "1. Creating objects:" << std::endl;
    Student student1;  // Default constructor
    Student student2("Alice", 20);  // Parameterized constructor
    Student student3("Bob", 22);   // Parameterized constructor
    
    std::cout << "   Total students: " << Student::getTotalStudents() << std::endl;
    std::cout << std::endl;
    
    // Using setter methods
    std::cout << "2. Using setter methods:" << std::endl;
    student1.setName("Charlie");
    student1.setAge(19);
    student1.displayInfo();
    std::cout << std::endl;
    
    // Adding grades
    std::cout << "3. Adding grades:" << std::endl;
    student2.addGrade(85.5);
    student2.addGrade(92.0);
    student2.addGrade(78.5);
    student2.displayInfo();
    
    student3.addGrade(95.0);
    student3.addGrade(88.0);
    student3.displayInfo();
    std::cout << std::endl;
    
    // Using friend function
    std::cout << "4. Using friend function:" << std::endl;
    printStudentDetails(student2);
    std::cout << std::endl;
    
    // Copy constructor
    std::cout << "5. Copy constructor:" << std::endl;
    Student student4 = student2;  // Copy constructor
    student4.setName("David");
    student4.displayInfo();
    std::cout << std::endl;
    
    // Composition example
    std::cout << "6. Composition example:" << std::endl;
    Course course1("Computer Science 101", "Dr. Smith", 3);
    Course course2("Mathematics 201", "Prof. Johnson", 4);
    
    course1.displayCourseInfo();
    course2.displayCourseInfo();
    std::cout << std::endl;
    
    // Object arrays
    std::cout << "7. Object arrays:" << std::endl;
    Student students[3] = {
        Student("Eve", 21),
        Student("Frank", 23),
        Student("Grace", 20)
    };
    
    for (int i = 0; i < 3; ++i) {
        students[i].displayInfo();
    }
    std::cout << std::endl;
    
    // Vector of objects
    std::cout << "8. Vector of objects:" << std::endl;
    std::vector<Student> studentVector;
    studentVector.push_back(Student("Henry", 24));
    studentVector.push_back(Student("Ivy", 22));
    
    for (const auto& student : studentVector) {
        student.displayInfo();
    }
    std::cout << std::endl;
    
    std::cout << "   Final total students: " << Student::getTotalStudents() << std::endl;
    std::cout << std::endl;
    
    std::cout << "=== End of Classes Example ===" << std::endl;
    
    return 0;
}
