/*
Last In First Out

Container adapter with the functionality of a queue.
    Need to include ‹ queue> header file.
    The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.
    Pushes elements at one end (front) and pops from other end (back) of underlying container.

Queue Functions:
    -[]size()
    -[] =
    -[] front(),back()
    -[] empty()
    -[]push(),pop()

*/

#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main(){
    cout<<"Simple Queue Library implemented: ";
    queue<int> Q;

    cout<<std::boolalpha<<Q.empty()<<endl;

    for(int i=1;i<=5;++i){
        Q.push(i);  //1,2,3,4,5
    }

    cout<<"front of Queue originally= "<<Q.front()<<", back of Queue originally= "<<Q.back()<<endl;
    cout<<"size of Queue originally= "<<Q.size()<<endl;
    
    cout<<endl;
    cout<<endl;
    
    Q.pop();
    Q.pop();
    //3,4,5

    cout<<"front a/f 2 delete= "<<Q.front()<<", back a/f 2 delete= "<<Q.back()<<endl;
    cout<<"size a/f 2 delete= "<<Q.size()<<endl;
    
    cout<<endl;
    cout<<endl;
    cout<<"Simply member function applied:";
    cout<<endl;
    queue<int> q1;
    queue<int,list<int> > q2; //leave space between angle brackets > >
    q1.push(1); q1.push(2); q1.push(3);
    q2.push(4); q2.push(5); q2.push(6);
    q1.push(q2.back());
    
    cout<<"Enter choice(a for q1,b for q2): ";
    char choice;
    cin>>choice;
    switch(choice){
        case 'a':
            cout<<"Members of q1: ";
            while (!q1.empty()) {
                cout << q1.front() << ' ';  //1 2 3 6
                q1.pop();
                }
            break;
        case 'b':
            cout<<"Members of q2: ";
            while (!q2.empty()) {
                cout << q2.front() << ' ';  //4 5 6
                q2.pop();
                }
            break;
    }
    cout<<endl;

    return 0;
}

/*
Member Function                     Operation
T& back()                           Return the last element in the queue.
const T& back() const               Return the last element in the queue.
bool empty() const                  Return true if the queue includes no element and false otherwise. 
T& front()                          Return the first element in the queue.
const T& front() const              Return the first element in the queue.
void pop()                          Remove the first element in the queue.
void push(const T& el)              Insert el at the end of the queue.
queue()                             Create an empty queue.
size_type size() const              Return the number of elements in the queue.
*/