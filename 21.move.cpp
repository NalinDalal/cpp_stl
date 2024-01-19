#include <iostream>
#include <string>

class MyString {
private:
    std::string data;

public:
    // Constructor
    MyString(const std::string& str) : data(str) {
        std::cout << "Constructor: " << data << std::endl;
    }

    // Move Constructor
    MyString(MyString&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Move Constructor: " << data << std::endl;
    }

    // Move Assignment Operator
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            std::cout << "Move Assignment Operator: " << data << std::endl;
        }
        return *this;
    }

    // Display the string
    void display() const {
        std::cout << "String: " << data << std::endl;
    }
};

int main() {
    // Creating a string and an object using the constructor
    MyString originalString("Hello, World!");

    // Using std::move to transfer resources (move constructor)
    MyString movedString1 = std::move(originalString);
    std::cout << "After Move Constructor, Original String: ";
    originalString.display();
    std::cout << "After Move Constructor, Moved String 1: ";
    movedString1.display();

    // Creating another string
    MyString anotherString("This is another string.");

    // Using move assignment operator
    movedString1 = std::move(anotherString);
    std::cout << "After Move Assignment Operator, Another String: ";
    anotherString.display();
    std::cout << "After Move Assignment Operator, Moved String 1: ";
    movedString1.display();

    return 0;
}
