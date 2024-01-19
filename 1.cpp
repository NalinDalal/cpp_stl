/*
Standard Template Library:

-A Set of Tools in c++ programming platforms
-code quickly, efficiently nd in generic way

Generic type:Templates

-generic programming enabled by means of special constructs called Templates.

template <typename T>
T area(T a,T b){
    T result=a*b;
    return result;
}

4parts:Containers,Iterators,Algorithms,Functors
*/

#include <iostream>
using namespace std;

template <typename T>
T area(T a,T b){
    T result=a*b;
    return result;
}

int main(){
    int x1=area<int>(10.5,5);
    int x2=area<double>(10.5,5);
    int x3=area<float>(10.5,5);
    cout<<"data type is int:";
    cout<<x1<<", "<<x2<<", "<<x3<<endl;

    cout<<"original data type:";
    double x2a=area<double>(10.5,5);
    float x3a=area<float>(10.5,5);
    cout<<x1<<", "<<x2a<<", "<<x3a<<endl;
    return 0;
}