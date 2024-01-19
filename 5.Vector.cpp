/*
Vectors:
-[]Elements stored contiguously
-[]storage is handled auto,being expanded and contracted as needed
-[]occupy more space than static array b/c memo allocated to handle future growth;
-[]they are actually dynamic arrays

Functions:
-[]size(),capacity(),max_size()
-[]=,[],at()
-[]front(),back()
-[]shrink_to_fit()
-[]empty()
-[]begin(),end(),rbegin(),rend()
-[]insert,erase()
-[]push_back(),pop_back()

*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
    vector<int> v={1,2,3};
    cout<<"size= "<<v.size()<<", capacity= "<<v.capacity()<<endl;   //3,3
    cout<<v.max_size()<<endl;
/*
size= 3, capacity= 3
4611686018427387903
*/
v.push_back(5);
cout<<"size= "<<v.size()<<", capacity= "<<v.capacity()<<endl;
/*
size= 4, capacity= 6
*/
int cap=v.capacity();
for(int i=0;i<100;++i){
    v.push_back(i);
    if(cap!=v.capacity())
        cap=v.capacity();
        cout<<"capacity= "<<cap<<endl;
        
}
// cout<<v[103]<<endl;
// cout<<v.at(104)<<endl;

cout<<"front ="<<v.front()<<",back= "<<v.back()<<endl;

v.insert(v.begin()+2,-100);
cout<<v[2]<<endl;
cout<<"size= "<<v.size()<<endl; //b/f pop.back
v.pop_back();
cout<<"size= "<<v.size()<<endl; //a/f pop.back

list<int> ll={-100,-200,-300};
v.insert(v.begin(),ll.begin(),ll.end());
cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;

v.pop_back();
v.erase(v.begin()+1);
cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
    cin.get();
}