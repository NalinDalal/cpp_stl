/*
*std::map
-[]associative container that contains key-value pairs with unique keys(sorted).
-[] use include<map>
-[]A user provided Compare can be supplied to change the ordering(sorting).
-[]search,removal,insertion-O(log n)
-[] Implemented as Red-Black Tress

template<class Key,
    class T,
    class Compare=std::less<Key>,
    class Allocator=std::allocator<std::pair<const Key,T>>,
    >class map;

Map functions():
    -[]size()
    -[]=
    -[] [],at()
    -[] clear()
    -[] count(),find()
    -[]empty()
    -[]insert(p)
        ~insert pair p 
        ~return pair consisting of iterator to inserted element and bool set to ture if insertion took place
    -[]insert(it1,it2)
        ~insert element in range[pos1,pos2)]
        ~return nothing(void)
    -[]insert(init_list)
        ~insert element fron initializer ist
        ~return void
    -[]erase(it)
        ~remove element at position pos
        ~return iterator following last element removed
    -[]erase(it1,it2)
        ~remove element in range [pos1,pos2)
        ~return iterator following last element removed]
    -[]erase(key)
        ~remove element with Key(if present) key
        ~return no of element removed
    -[]upper_bound(key),lower_boubd(key)

* */

#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, string> m={{10,"cat"},{20,"dog"},{5,"bat"}};
    cout<<"size= "<<m.size()<<endl;

    for(auto& p: m)
        cout<<"{"<<p.first<<" ,"<<p.second<<"}";
    cout<<endl;
    m.insert({100,'rabbit'});
    m.insert({10,"fish"});
    
    for(auto& p:m)
        cout<<"{"<<p.first<<" ,"<<p.second<<"}";
    cout<<endl;

    auto it=m.erase(m.find(10));
    cout<<it->first<<endl;

    int num_erased=m.erase(15);
    cout<<"num_erased= "<<num_erased<<endl;

    auto ub=m.upper_bound(10);
    auto lb=m.lower_bound(10);

    cout<<"ub= "<<ub->first<<endl;
    cout<<"lb= "<<lb->first<<endl;

    m.insert({{-10,"apple"},{-30,"orange"},{-20,"mango"}});
    for(auto& p: m)
        cout<<"{"<<p.first<<", "<<p.second<<"}";
    cout<<endl;

    map<int,string> m2={{10,"aa"},{20,"bb"},{15,"cc"},{5,"dd"}};
    m.insert(m2.begin(),m2.end());

    for(auto& p: m)
        cout<<"{"<<p.first<<", "<<p.second<<"}";
    cout<<endl;

    return 0;
}
