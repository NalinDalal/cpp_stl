/*
 * std::multiset
-[] an associative container that contains a sorted set of unique on=bjects of type key
-[] include <set>
-[]user provided compare can be supplied to change ordering
-[]search,removal, and insertion times are logarithmic
-[]implementation: Red Black Tree

syntax:
    template<
        class Key,
        class Compare=std::less<Key>,
        class Allocator=std::allocator<Key>,
    > class multiset;

MultiSet Functions
-[]size()
-[]=
-[]clear()
-[]count(),find()
-[]empty()
-[]insert(key)
    ~insert key
    ~return iterator to inserted element
-[]insert(it1,it2)
    ~insert element in range[pos1,pos2]
    ~return nothing(void)
-[]insert(init_list)
    ~insert element from initializer list
    ~return nothing(void)
-[]erase(it)
    ~remove element at position pos
    ~return iterator following last element removed
-[]erase(it1,it2)
    ~removes element in range[pos1,pos2)
    ~return iterator following last element removed]
-[]erase(key)
    ~remove all element with key(if present) key
    ~return number of element removed
-[]upper_bound(key),lower_bound(key)

* */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Student{
public:
    int id;
    string name;

    void print_student() const{
        cout<<"[name= "<<name<<" ,id= "<<id<<"]\n";
    }

    bool operator <(const Student& other) const {
        return (this->id > other.id);
    }
};

int main(){
    set<int> s={10,20,5,10,15,20,4};
    cout<<"size= "<<s.size()<<endl;
    s.insert(100);
    s.insert(10);
    cout<<"size= "<<s.size()<<endl;

    for(auto& el:s)
        cout<<el<<" ";
    cout<<endl;

    int num_erased=s.erase(10);
    cout<<"num_erased= "<<num_erased<<endl;

    for(auto& el: s)
        cout<<el<<" ";
    cout<<endl;

    auto ub=s.upper_bound(10);
    auto lb=s.lower_bound(10);
    cout<<"ub= "<<*ub<<endl;
    cout<<"lb= "<<*lb<<endl;

    s.insert({-10,-20,-30});
    for(auto& el:s)
        cout<<el<<" ";
    cout<<endl;

    vector<int> v={10,20,15,5,4};
    s.insert(v.begin(), v.end());
    for(auto& el: s)
        cout<<el<<" ";
    cout<<endl;

    set<Student> sst={{50,"Simon"},{20,"Thomas"}};
    for(auto& st: sst)
        st.print_student();

    return 0;
}
