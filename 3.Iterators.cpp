/*
Iterators:
-[]Objects that enable traversal of containers in some order, for either reading or writing
-[]Iterators are defined as templates and must comply with a very specific set of rules in order to qualify as one of many types of iterators
-[]higher abstraction for elements used to traverse 'containers'

Types:
1.Input
    -[]only accessing,not assigning
    -[]moves only forward
    -[]can be incremented[++it,it++]
    -[]only one pass possible
    -[]suitable for input,read-only files
2.Output
    -[]only write
    -[]moves only forward
    -[]one pass only
    -[]suitable for output stream,screen test etc
3.Forward
    -[]both input,output
    -[]read,write
    -[]moves only forward
    -[]support multiple passes of container
    -[]suitable for linked list
4.Bidirectional
    -[]Forward+reverse iterator capabilities combined
    -[]suitable for doubly ll
5.Random-Access
    -[]Bidirectional+Random
    -[]for Vectors and similar container ex array
*/

/*
Iterators Function:

1. begin():
    -[]Return iterator to beginning of container
2. end():
    -[]Return iterator to element following last element of container
    -[]element act as placeholder;access result in error  
3.rebegin():
    -[]Return iterator to last element of container
4.rend():
    -[]return reverse iterator pointing to theoritical element right b/f first element in array container
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v({1,2,3,4,5,6,7});

    cout<<"v.begin() => "<<*v.begin()<<endl;

    int *x=&v[6];
    x++;
    *x=-50;

    cout<<"v.end() => "<<*(v.end()-1)<<endl;

    cout<<"v.rbegin() => "<<*v.rbegin()<<endl;
    cout<<"v.rend() => "<<*(v.rend()-1)<<endl;

    cin.get();
}