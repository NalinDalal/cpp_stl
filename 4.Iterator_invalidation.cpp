/*
Iterator Invalidation
    -[]Due to update(Insert/Delete) of container that is using iterators.
    -[]No runtime error but iterator no longer guaranteed to have access to same element a/f update
    -[]well documented
    -[]depends on container implementation

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v={1,2,3,4,5,6,7};
    auto it=v.begin()+4;    //5
    cout<<"it :=> "<<*it<<endl;
    cout<<"it-begin :=> "<<it-v.begin()<<endl;

    it=v.insert(it, 100); //{1,2,3,4,100,5,6,7}
    cout<<"it :=> "<<*it<<endl;
    cout<<"it-begin :=> "<<it-v.begin()<<endl;

    /*
    it :=> 5
it-begin :=> 4
it :=> 5
it-begin :=> -268
*/
    cout<<"v[4]="<<v[4]<<endl;
    return 0;
}