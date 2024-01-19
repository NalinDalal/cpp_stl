/*
std::multimap
-[]An associative container that contains sorted list of key-value pairs allowing multiple entries with same keys.
-[] include<map>
-[]A user-provided Compare can be supplied to change the ordering(sorting).
-[]Implemented as RB Trees.
    template<
        class Key,
        class T,
        class Compare=std::less<Key>,
        class Allocator=std::allocator<std::pair<const Key,T>>,
    >class multimap;

-[]Functions:
    - size()
    - =
    - [], at()
    - clear()
    - count(), find()
    - empty()
    - insert(key),insert(it1,it2),insert(init_list)
    -erase(it),erase(it1,it2),erase(key)
    -upper_bound(key), lower_bound(key)
    -equal_range(key)
*/

#include <iostream>
#include <map>

using namespace std;

int main(){
    multimap<int,string> m={{10,"cat"}, {20,"dog"},{5,"bat"}};
    cout<<"size= "<<m.size();

    for(auto& p: m)
        cout<<"{"<<p.first<<", "<<p.second<<"} ";
    cout<<endl;

    m.insert({100,"rabbit"});
    m.insert({10,"fish"});
    m.insert({{10,"cat"}, {12,"bat"}});
    m.insert(make_pair<int, string>(12, "bat_2"));

    for(auto& p: m)
        cout<<"{"<<p.first<<","<<p.second<<"}";
    cout<<endl;

    map<int, string> m2={{10,"aa"},{20,"bb"},{15,"cc"},{5,"dd"}};
    m.insert(m2.begin(),m2.end());

    for(auto& p: m)
        cout<<"{"<<p.first<<", "<<p.second<<"}";
    cout<<endl;

    cout<<"size= "<<m.size()<<endl;
    auto it=m.erase(m.find(10));
    cout<<it->first<<endl;
    cout<<"size= "<<m.size()<<endl;

    auto it2=m.erase(10);
    cout<<"size= "<<m.size()<<endl;

    auto ub=m.upper_bound(15);
    auto lb=m.lower_bound(15);
    cout<<"ub= "<<ub->first<<endl;
    cout<<"lb= "<<lb->first<<endl;

    auto range=m.equal_range(10);
    for(auto it=range.first;it!=range.second;++it)
        cout<<it->second<<" ";
    cout<<endl;
}