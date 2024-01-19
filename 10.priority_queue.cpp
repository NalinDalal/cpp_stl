#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main() {
    int choice;
    cout<<"Enter your choice:";
    cout<<endl;
    cout<<"Choice 1-ways to initialize, populate priority queues, showcase the effects of different comparison functions,output emphasizes the differences in ordering due to the choice of comparison functions";
    cout<<endl;
    cout<<"Choice 2-use of custom comparator with a lambda function, affects the ordering of elements in the priority queue,output showcases the flexibility of defining custom comparators";
    cin>>choice;
    switch(choice){
    case 1:{    
    
    priority_queue<int> pq1; // plus vector<int> and less<int>
    priority_queue<int,vector<int>,greater<int> > pq2;
    pq1.push(3); pq1.push(1); pq1.push(2);  //void push(const T& el)-Insert el in a proper location on the priority queue.
    pq2.push(3); pq2.push(1); pq2.push(2);
    int a[] = {4,6,5};
    priority_queue<int> pq3(a,a+3);
    while (!pq1.empty()) {
        cout << pq1.top() << ' ';   //3 2 1
        pq1.pop();      //void pop()-Remove an element in the queue with the highest priority.
    }
    while (!pq2.empty()) {
        cout << pq2.top() << ' ';   //1 2 3 //T& top() -Return the element in the priority queue with the highest priority
        pq2.pop();
    }
    while (!pq3.empty()) {
        cout << pq3.top() << ' ';   //6 5 4
        pq3.pop();
    }
    break;
    }
    case 2:{
        priority_queue<int> Q1;
    vector<int> v1= {8, 1, 6, 4, 0, 7, 2, 9};
    for(int x : v1) Q1.push(x);
    while(!Q1.empty()){
        std::cout << Q1.top()<<" ";
        Q1.pop();
    }
    cout<<endl;
    cout<<"----------------------------------------------------------------";
    auto cmp=[](int a,int b){
        return a<b;
    };

    priority_queue<int, vector<int>,  decltype(cmp)> Q2(cmp);
    vector<int> v2={8,1,6,4,0,7,2,9};
    for(int x:v2) Q2.push(x);
    while(!Q2.empty()){
        cout<<Q2.top()<<" ";
        Q2.pop();
    }
    cout<<endl;
    break;
        
    }
}
    return 0;
}

/*
Member Function     Operation
bool empty() const                    Return true if the queue includes no element and false otherwise.
void pop()                    Remove an element in the queue with the highest priority.
void push(const T& el)                     Insert el in a proper location on the priority queue.
priority_queue(comp f())                   Create an empty priority queue that uses a two-argument Boolean function f to order elements on the queue.
priority_queue(iterator first,iterator last, comp f())  Create a priority queue that uses a two-argument Boolean function f to order elements on the queue; initialize the queue with elements from the range indicated by iterators first and last                  
size_type size() const                  Return the number of elements in the priority queue.
T& top()                    Return the element in the priority queue with the highest priority.
const T& top() const                    Return the element in the priority queue with the highest priority.
*/