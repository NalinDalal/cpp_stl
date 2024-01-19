/*
std::async
-[]provides a high-level interface for launching asynchronous tasks
-[]execute a function asynchronously
-[]retrieve the result once the task is completed
-[]executed concurrently in a separate thread or in a thread pool
*/

#include <iostream>
#include <future>

int foo(int x) {
    return x * 2;
}

int main() {
    // Launch a task asynchronously
    std::future<int> result = std::async(foo, 10);

    // Do some other work concurrently with the asynchronous task

    // Retrieve the result when needed
    int finalResult = result.get();

    std::cout << "Result: " << finalResult << std::endl;

    return 0;
}
