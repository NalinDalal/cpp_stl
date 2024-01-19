#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int choice;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            priority_queue<int> pq1; // plus vector<int> and less<int>
            priority_queue<int, vector<int>, greater<int>> pq2;
            pq1.push(3);
            pq1.push(1);
            pq1.push(2);
            pq2.push(3);
            pq2.push(1);
            pq2.push(2);
            int a[] = {4, 6, 5};
            priority_queue<int> pq3(a, a + 3);
            while (!pq1.empty()) {
                cout << pq1.top() << ' '; //3 2 1
                pq1.pop();
            }
            cout << "\n";
            while (!pq2.empty()) {
                cout << pq2.top() << ' '; //1 2 3
                pq2.pop();
            }
            cout << "\n";
            while (!pq3.empty()) {
                cout << pq3.top() << ' '; //6 5 4
                pq3.pop();
            }
            break;
        }
        case 2: {
            priority_queue<int> Q1;
            vector<int> v1 = {8, 1, 6, 4, 0, 7, 2, 9};
            for (int x : v1)
                Q1.push(x);
            while (!Q1.empty()) {
                std::cout << Q1.top() << " ";
                Q1.pop();
            }
            cout << endl;
            cout << "----------------------------------------------------------------";
            auto cmp = [](int a, int b) {
                return a < b;
            };

            priority_queue<int, vector<int>, decltype(cmp)> Q2(cmp);
            vector<int> v2 = {8, 1, 6, 4, 0, 7, 2, 9};
            for (int x : v2)
                Q2.push(x);
            while (!Q2.empty()) {
                cout << Q2.top() << " ";
                Q2.pop();
            }
            cout << endl;
            break;
        }
        default:
            cout << "Invalid choice.\n";
            break;
    }

    return 0;
}