/*
* std::set
* -[]An associative container that contains a sorted set of unique objects of type key
*  -[] #include <set>
*  -[] user provided Compare can be supplied to change ordering
*  -[] search,removal,insertion-O(log n)
*  -[] Implemented as red-black tree
*           template<
*               class Key,
*               class Compare=std::less<Key>,
*               class Allocator=std::allocator<Key>,
*           > class set;
* Functions:
* -[] size()
*  -[] =
*  -[] clear()
*  -[] count(), find()
*  -[] empty()
*  -[] insert(key), insert(it1,it2), insert(init_list)
*  -[]erase(it), erase(it1, it2), erase(key)
*  -[]upper_bound(key), lower_bound(key)
*
*  Insert()
*   -[]insert(Key key)
*       insert key
*       return pair consisting of iterator to insert element and bool set to true if insertion took place
*   -[]insert(iterator pos1,iterator pos2)
*       insert element in range[pos1,pos2)
*       return nothing
*   -[]insert(initializer_list l)
*       insert element from initializer list
*       return nothing(void)
*
*  Erase()
*   -[]erase(iterator pos)
*       remove element at position pos
*       return iterator following last element removed
*   -[]erase(iterator pos1,iterator pos2)
*       remove element with Key(if present) key
*       return number of element removed
* */

#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s={10,20,5,10,15,20,4};
    cout<<"size= "<<s.size()<<endl;
    s.insert(100);
    s.insert(10);
    cout<<"size= "<<s.size()<<endl;

    for(auto& el:s)
        cout<<el<<" ";
    cout<<endl;
    
    auto it=s.erase(s.find(10));
    cout<<*it<<endl;

    int num_erased=s.erase(10);
    std::cout <<"num_erased="<< num_erased<<std::endl;
    
    for(auto& el:s)
        cout<<el<<" ";
    cout<<endl;

    auto ub=s.upper_bound(7);
    cout<<"ub= "<<*ub<<endl;
    return 0;
};

