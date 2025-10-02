#include <iostream>
#include <string>
#include <vector>

/**
 * Inheritance in C++
 * 
 * This example demonstrates:
 * - Single inheritance
 * - Multiple inheritance
 * - Virtual functions and polymorphism
 * - Access specifiers in inheritance
 * - Constructor and destructor in inheritance
 * - Method overriding
 */

// Base class
class Animal {
protected:
    std::string name;
    int age;
    
public:
    // Constructor
    Animal(const std::string& animalName, int animalAge) 
        : name(animalName), age(animalAge) {
        std::cout << "  Animal constructor called for " << name << std::endl;
    }
    
    // Virtual destructor (important for polymorphism)
    virtual ~Animal() {
        std::cout << "  Animal destructor called for " << name << std::endl;
    }
    
    // Virtual function (can be overridden)
    virtual void makeSound() const {
        std::cout << "  " << name << " makes a generic animal sound" << std::endl;
    }
    
    // Non-virtual function
    void eat() const {
        std::cout << "  " << name << " is eating" << std::endl;
    }
    
    // Pure virtual function (makes class abstract)
    virtual void move() const = 0;
    
    // Getter methods
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

// Derived class - Single inheritance
class Dog : public Animal {
private:
    std::string breed;
    
public:
    // Constructor
    Dog(const std::string& dogName, int dogAge, const std::string& dogBreed)
        : Animal(dogName, dogAge), breed(dogBreed) {
        std::cout << "  Dog constructor called for " << name << std::endl;
    }
    
    // Destructor
    ~Dog() {
        std::cout << "  Dog destructor called for " << name << std::endl;
    }
    
    // Override virtual function
    void makeSound() const override {
        std::cout << "  " << name << " barks: Woof! Woof!" << std::endl;
    }
    
    // Implement pure virtual function
    void move() const override {
        std::cout << "  " << name << " runs on four legs" << std::endl;
    }
    
    // Additional method specific to Dog
    void fetch() const {
        std::cout << "  " << name << " fetches the ball" << std::endl;
    }
    
    std::string getBreed() const { return breed; }
};

// Another derived class
class Cat : public Animal {
private:
    bool isIndoor;
    
public:
    Cat(const std::string& catName, int catAge, bool indoor = true)
        : Animal(catName, catAge), isIndoor(indoor) {
        std::cout << "  Cat constructor called for " << name << std::endl;
    }
    
    ~Cat() {
        std::cout << "  Cat destructor called for " << name << std::endl;
    }
    
    void makeSound() const override {
        std::cout << "  " << name << " meows: Meow! Meow!" << std::endl;
    }
    
    void move() const override {
        std::cout << "  " << name << " walks silently" << std::endl;
    }
    
    void climb() const {
        std::cout << "  " << name << " climbs the tree" << std::endl;
    }
    
    bool getIsIndoor() const { return isIndoor; }
};

// Multiple inheritance example
class Flyable {
public:
    virtual void fly() const = 0;
    virtual ~Flyable() = default;
};

class Bird : public Animal, public Flyable {
private:
    double wingspan;
    
public:
    Bird(const std::string& birdName, int birdAge, double birdWingspan)
        : Animal(birdName, birdAge), wingspan(birdWingspan) {
        std::cout << "  Bird constructor called for " << name << std::endl;
    }
    
    ~Bird() {
        std::cout << "  Bird destructor called for " << name << std::endl;
    }
    
    void makeSound() const override {
        std::cout << "  " << name << " chirps: Tweet! Tweet!" << std::endl;
    }
    
    void move() const override {
        std::cout << "  " << name << " flies through the air" << std::endl;
    }
    
    void fly() const override {
        std::cout << "  " << name << " soars with " << wingspan 
                  << "cm wingspan" << std::endl;
    }
    
    double getWingspan() const { return wingspan; }
};

// Virtual inheritance example (diamond problem)
class LivingThing {
protected:
    std::string species;
    
public:
    LivingThing(const std::string& sp) : species(sp) {}
    virtual ~LivingThing() = default;
    virtual void breathe() const {
        std::cout << "  " << species << " breathes" << std::endl;
    }
};

class Mammal : virtual public LivingThing {
public:
    Mammal(const std::string& sp) : LivingThing(sp) {}
    void breathe() const override {
        std::cout << "  " << species << " breathes with lungs" << std::endl;
    }
};

class WingedAnimal : virtual public LivingThing {
public:
    WingedAnimal(const std::string& sp) : LivingThing(sp) {}
    void breathe() const override {
        std::cout << "  " << species << " breathes efficiently for flight" << std::endl;
    }
};

class Bat : public Mammal, public WingedAnimal {
public:
    Bat() : LivingThing("Bat"), Mammal("Bat"), WingedAnimal("Bat") {}
    void breathe() const override {
        std::cout << "  Bat breathes with lungs optimized for flight" << std::endl;
    }
};

int main() {
    std::cout << "=== C++ Inheritance ===" << std::endl;
    std::cout << std::endl;
    
    // Single inheritance
    std::cout << "1. Single inheritance:" << std::endl;
    Dog dog("Buddy", 3, "Golden Retriever");
    dog.makeSound();
    dog.move();
    dog.eat();
    dog.fetch();
    std::cout << "   Breed: " << dog.getBreed() << std::endl;
    std::cout << std::endl;
    
    // Another single inheritance example
    std::cout << "2. Another single inheritance example:" << std::endl;
    Cat cat("Whiskers", 2, true);
    cat.makeSound();
    cat.move();
    cat.eat();
    cat.climb();
    std::cout << "   Indoor cat: " << (cat.getIsIndoor() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
    
    // Multiple inheritance
    std::cout << "3. Multiple inheritance:" << std::endl;
    Bird bird("Tweety", 1, 25.5);
    bird.makeSound();
    bird.move();
    bird.fly();
    bird.eat();
    std::cout << "   Wingspan: " << bird.getWingspan() << "cm" << std::endl;
    std::cout << std::endl;
    
    // Polymorphism with pointers
    std::cout << "4. Polymorphism with pointers:" << std::endl;
    std::vector<Animal*> animals;
    animals.push_back(new Dog("Max", 4, "German Shepherd"));
    animals.push_back(new Cat("Luna", 3, false));
    animals.push_back(new Bird("Eagle", 2, 180.0));
    
    for (Animal* animal : animals) {
        std::cout << "   " << animal->getName() << " (age " << animal->getAge() << "):" << std::endl;
        animal->makeSound();
        animal->move();
        animal->eat();
        std::cout << std::endl;
    }
    
    // Clean up memory
    for (Animal* animal : animals) {
        delete animal;
    }
    std::cout << std::endl;
    
    // Virtual inheritance
    std::cout << "5. Virtual inheritance (diamond problem):" << std::endl;
    Bat bat;
    bat.breathe();
    std::cout << std::endl;
    
    // Polymorphism with references
    std::cout << "6. Polymorphism with references:" << std::endl;
    Dog anotherDog("Rex", 5, "Labrador");
    Cat anotherCat("Mittens", 4, true);
    
    Animal& animalRef1 = anotherDog;
    Animal& animalRef2 = anotherCat;
    
    animalRef1.makeSound();
    animalRef2.makeSound();
    std::cout << std::endl;
    
    std::cout << "=== End of Inheritance Example ===" << std::endl;
    
    return 0;
}
