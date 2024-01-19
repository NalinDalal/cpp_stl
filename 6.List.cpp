/*
std::list
-[]Sequence conatiners,optimized for rapid insert and delete operations
-[]non-contiguous storage
-[]no random access
-[]bidirectional iteration

Functions
    size(),max_size()
    =
    front(),back()
    empty()
    begin(),end(),rbegin(),rend(){r is for rear}
    insert(),erase(),remove()
    clear()
    push_back(),push_front(),pop_back(),pop_front()
*/

#include <iostream>
#include <list>

using namespace std;

void print_list(list<int>& ll){
    for(list<int>::iterator it =ll.begin(); it!=ll.end();++it)
        cout<<*it<<"\t";
    cout<<endl;
}
int main(){
    list<int> nums={1,2,3,4,5};
    print_list(nums);
    cout<<"Size= "<<nums.size()<<endl;
    list<int> nums2=nums;
    print_list(nums2);
    //make changes to one of them

    cout<<"fornt= "<<nums.front()<<",back= "<<nums.back()<<endl;
    cout<<nums.empty()<<endl;
    cout<<std::boolalpha<<nums.empty()<<endl;

    //derefrence
    cout<<*nums.begin()<<", "<<*nums.rbegin()<<endl;

    vector<int> vec={1,2,3,4,5};
    vec.insert(vec.begin()+2,100);
    cout<<vec[2]<<endl;

    print_list(nums);
    list<int>::iterator it=nums.begin();
    while(*it !=3 && it!=nums.end())
        it++; //checking for values
    nums.insert(it,100);    //can't go directly to 3rd element
    print_list(nums);

    nums.erase(it);
    print_list(nums);

    nums.remove(4);
    print_list(nums);

    nums.clear();
    print_list(nums);
    cout<<std::boolalpha<<nums.empty()<<endl;

    print_list(nums2);

    //other functions
    nums2.push_back(-100);
    nums2.push_front(-200);
    print_list(nums2);

    nums2.pop_back();
    nums2.pop_front();
    print_list(nums2);

    return 0;
}