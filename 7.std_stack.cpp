/*
std::stack
-[]Container adapter with functionality of a stack
-[]Need to 'include<stack>' header file
-[]Class template acts as a wrapper to underlying container-specific set of function provided
-[]Pushes and Pops element from one end of underlying container(top of stack)
*/

/*
Stack Functions
-[]size()
-[]=
-[]top()
-[]empty()
-[]push(),pop()
*/

#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> S;

	for(int i=0;i<5;++i)
		S.push(i);
	
	cout<<"Size= "<<S.size()<<endl;
	cout<<"Top= "<<S.top()<<endl;
	
	S.pop();
	S.pop();

	cout<<"Size= "<<S.size()<<endl;
        cout<<"Top= "<<S.top()<<endl;

	if(S.empty())
		cout<<"Stack is empty\n";
	else
		cout<<"Not Empty\n";

	return 0;
}

/*
Member Function						Operation
bool empty() const					Return true if the stack includes no element and false otherwise.
void pop()							Remove the top element of the stack.
void push(const T& el)				Insert el at the top of the stack.
size_type size() const				Return the number of elements on the stack.
stack()								Create an empty stack.
T& top()							Return the top element on the stack.
const T& top() const				Return the top element on the stack.

*/