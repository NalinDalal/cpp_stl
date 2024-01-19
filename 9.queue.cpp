/*
 * queue-FIFO
 * -[]functionality of queue
 *  -[] include <queue>
 *  -[] act as wrapper to underlying container- specific set of functions
 *  -[]push at back
 *  -[]pop at front
 *
 Queue Functions:
 -[] size()
 -[] =
 -[] front(), back()
 -[] empty()
 -[] push(), pop()
*/

#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> Q;

    cout<< std::boolalpha<<Q.empty()<<endl;
    for(int i=1;i<=5;++i)
        Q.push(i);
    //1,2,3,4,5
    cout<<"Front = "<<Q.front()<<", back= "<<Q.back()<<endl;
    cout<<"Size= "<<Q.size()<<endl;

    Q.pop();
    Q.pop();

    //3,4,5
    cout<<"front = "<<Q.front()<<", back= "<<Q.back()<<endl;
    cout<<"size= "<<Q.size()<<endl;
    cout<<std::boolalpha<<Q.empty()<<endl;
    return 0;
}
