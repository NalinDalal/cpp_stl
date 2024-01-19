#include <iostream>
#include <string>
#include <algorithm>
#include <string_view>

static uint32_t s_AllocCount=0;

void* operator new(size_t size){
    s_AllocCount++;
    std::cout<<"Allocating "<<size<<" bytes\n";
    return malloc(size);
}
void PrintName(const std::string& name){
    std::cout<<name<<std::endl;
}

class MyStringLibrary {
public:
    /**
     * Concatenates two strings.
     * @param str1 The first string.
     * @param str2 The second string.
     * @return The concatenated string.
     */
    std::string concatStrings(const std::string& str1, const std::string& str2) {
        return str1 + str2;
    }

    /**
     * Reverses a string.
     * @param s The input string.
     * @return The reversed string.
     */
    std::string reverseString(const std::string& s) {
        std::string reversed = s;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }

    /**
     * Capitalizes the first letter of a string.
     * @param s The input string.
     * @return The string with the first letter capitalized.
     */
    std::string capitalizeString(const std::string& s) {
        if (s.empty()) {
            return s; // Return empty string if input is empty
        }
        std::string result = s;
        result[0] = std::toupper(result[0]);
        return result;
    }

    /**
     * Counts the occurrences of a substring in a string.
     * @param s The input string.
     * @param sub The substring to count.
     * @return The number of occurrences.
     */
    size_t countOccurrences(const std::string& s, const std::string& sub) {
        size_t count = 0;
        size_t pos = 0;
        while ((pos = s.find(sub, pos)) != std::string::npos) {
            ++count;
            pos += sub.length();
        }
        return count;
    }

    /**
     * Checks if a string is a palindrome.
     * @param s The input string.
     * @return True if the string is a palindrome, false otherwise.
     */
    bool isPalindrome(const std::string& s) {
        std::string reversed = reverseString(s);
        return s == reversed;
    }
};

int main(){
    // Creating a string
    std::string name="Nalin Dalal";
    std::string originalString="is a good coder";
    //---------------------------------------------
    PrintName(name);
    std::cout<<s_AllocCount<<" allocations"<<std::endl;
    PrintName("Nal");
    
    // Accessing individual characters
    char firstChar = originalString[0];
    char lastChar = originalString.back();
    //---------------------------------------------

    // Modifying individual characters
    originalString[7] = 'z';
    //---------------------------------------------
    std::string firstName=name.substr(0,5);
    std::string lastName=name.substr(6,11);
    PrintName(firstName);
    PrintName(lastName);

    //string_view firstName(name.c_str(),3);
    //---------------------------------------------------------

    // Concatenating strings
    std::string appendString = " How are you?";
    std::string concatenatedString = originalString + appendString;

    // Getting the length of a string
    std::size_t length = originalString.length();

    // Finding substrings
    std::size_t findResult = originalString.find("World");

    // Substring extraction
    std::string subString = originalString.substr(0, 5);

    // Erasing characters
    originalString.erase(5, 7);  // Remove characters starting at index 5, up to 7 characters

    // Inserting characters
    originalString.insert(5, " my friend");

    // Comparing strings
    std::string compareString = "Hello, my friend!";
    bool areEqual = (originalString == compareString);

    // Outputting results
    std::cout << "Original String: " << originalString << std::endl;
    std::cout << "First Character: " << firstChar << std::endl;
    std::cout << "Last Character: " << lastChar << std::endl;
    std::cout << "Concatenated String: " << concatenatedString << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Substring Found at Index: " << findResult << std::endl;
    std::cout << "Extracted Substring: " << subString << std::endl;
    std::cout << "Strings are Equal: " << std::boolalpha << areEqual << std::endl;
    
    //---------------------------------------------------------
    MyStringLibrary myStringLib;

    // Example usage
    std::string result = myStringLib.concatStrings("Hello", "World");
    std::cout << result << std::endl;  // Output: HelloWorld

    std::string reversedStr = myStringLib.reverseString("abc");
    std::cout << reversedStr << std::endl;  // Output: cba

    std::string capitalizedStr = myStringLib.capitalizeString("hello");
    std::cout << capitalizedStr << std::endl;  // Output: Hello

    size_t occurrences = myStringLib.countOccurrences("abca", "a");
    std::cout << occurrences << std::endl;  // Output: 2

    bool isPalindrome = myStringLib.isPalindrome("radar");
    std::cout << std::boolalpha << isPalindrome << std::endl;  
    
    //string reverse
    std::string reversedStrs = myStringLib.reverseString("abc");
    std::cout << reversedStrs << std::endl;  // Output: cba
    
    std::cin.get();
}