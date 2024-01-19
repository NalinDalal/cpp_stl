#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

int main() {
    // Creating and populating a std::map
    std::map<int, std::string> orderedMap;
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[4] = "Four";
    orderedMap[2] = "Two";

    // Displaying the contents of the ordered map
    std::cout << "Ordered Map:\n";
    for (const auto& pair : orderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Creating and populating a std::unordered_map
    std::unordered_map<int, std::string> unorderedMap;
    unorderedMap[3] = "Three";
    unorderedMap[1] = "One";
    unorderedMap[4] = "Four";
    unorderedMap[2] = "Two";

    // Displaying the contents of the unordered map
    std::cout << "\nUnordered Map:\n";
    for (const auto& pair : unorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Accessing elements in a map
    int keyToFind = 2;
    auto orderedMapIterator = orderedMap.find(keyToFind);
    if (orderedMapIterator != orderedMap.end()) {
        std::cout << "\nElement found in Ordered Map: " << orderedMapIterator->second << std::endl;
    } else {
        std::cout << "\nElement not found in Ordered Map\n";
    }

    auto unorderedMapIterator = unorderedMap.find(keyToFind);
    if (unorderedMapIterator != unorderedMap.end()) {
        std::cout << "Element found in Unordered Map: " << unorderedMapIterator->second << std::endl;
    } else {
        std::cout << "Element not found in Unordered Map\n";
    }

    return 0;
}
