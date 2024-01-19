/*
Smart Pointers
-[]std::unique_ptr
    scoped pointer,when goes out of scope calls delete
    can't copy them,can only move
    Represents exclusive ownership of a dynamically allocated object.
    When a std::unique_ptr is destroyed, it automatically deallocates the associated memory.
-[]std::shared_ptr
    Represents shared ownership of a dynamically allocated object.
    Keeps track of the number of std::shared_ptr instances pointing to the same object.
    When the last std::shared_ptr pointing to an object is destroyed, the object is deallocated.
-[]std::weak_ptr
    Represents non-owning "weak" references to objects managed by std::shared_ptr.
    Does not contribute to the object's reference count.
    Used to break circular references that can occur with std::shared_ptr.

when you call new u don't have to delete
*/

#include <iostream>
#include <string>
#include <memory>

//unique pointer


int main(){
    int choice;
    std::unique_ptr<int> uniquePtr;
    std::shared_ptr<int> sharedPtr;
    std::weak_ptr<int> weakPtr;

    do {
        std::cout << "Choose a smart pointer type:\n";
        std::cout << "1. Unique Pointer\n";
        std::cout << "2. Shared Pointer\n";
        std::cout << "3. Weak Pointer\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Using std::unique_ptr
                uniquePtr = std::make_unique<int>(42);
                std::cout << "Unique Pointer: " << *uniquePtr << "\n";
                // No need to explicitly delete, memory is automatically released when uniquePtr goes out of scope.
                break;

            case 2:
                // Using std::shared_ptr
                sharedPtr = std::make_shared<int>(42);
                std::cout << "Shared Pointer (count = " << sharedPtr.use_count() << "): " << *sharedPtr << "\n";
                {
                    // Creating another shared pointer
                    std::shared_ptr<int> sharedPtr2 = sharedPtr;
                    std::cout << "Shared Pointer (count = " << sharedPtr.use_count() << "): " << *sharedPtr << "\n";
                }
                // Memory is automatically released when sharedPtr goes out of scope.
                break;

            case 3:
                // Using std::weak_ptr
                sharedPtr = std::make_shared<int>(42);
                weakPtr = sharedPtr;
                std::cout << "Weak Pointer (expired = " << weakPtr.expired() << "): ";
                if (std::shared_ptr<int> sharedPtrFromWeak = weakPtr.lock()) {
                    std::cout << *sharedPtrFromWeak << "\n";
                } else {
                    std::cout << "Object has been deleted\n";
                }
                break;

            case 0:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 0);
    std::cin.get();
}