/*
* std::unordered_multiset
*   -[]An associative container that contains a set of non-unqiue objects of type key.
*   -[] <unordered_set> header file
*   -[]search,removal,insertion -O(1)
*   -[] implemented as Hash Table
*
*  template<
*   class Key,
*   class Hash=std::hash<Key>,
*   class KeyEqual=std::equal_to<Key>,
*   class Allocator=std::allocator<Key>,
*   > class unordered_multiset;
*
*
*Function:
*   -[] size()
*   -[] =
*   -[] clear()
*   -[] count(),find(),equal_range()
*   -[]empty()
*   -[]insert(key)
*       ~insert key
*       ~return iterator to inserted element
*   -[]insert(it1,it2)
*       ~insert element in range [pos1,pos2)]
*       ~return nothing
*   -[]insert(init_list)
*       ~insert element from initializer list
*       ~return nothing
*   -[]erase(it)
*       ~remove element at position pos
*       ~return iterator following last element removed
*   -[]erase(it1,it2)
*       ~remove element in range[pos1,pos2)]
*       ~return iterator following lst element removed
*   -[]erase(key)
*       ~remove element with key
*       ~return no of element removed
*   -[]bucket_count(),load_factor()
*
*
*   Insert():
*   
* */

#include <iostream>
#include <functional>
#include <unordered_set>

using namespace std;

class Student{
public:
    int id;
    string name;

    bool operator==(const Student& s) const{
        return (this->id==s.id && this->name==s.name);
    }

    void print_student() const{
        cout<<"[id= "<<id<<" , name= "<<name<<"]\n";}
};
class StudentHashFunction{
public:
    size_t operator()(const Student& s) const{
        return (hash<int>{}(s.id)+hash<string>{}(s.name));
    }
};
int main(){
    unordered_multiset<int> us={5,10,4,20,5,5,15};
    for(int x:us)
        cout<<x<<" ";
    cout<<endl;

    auto its=us.equal_range(5);
    for(auto it=its.first;it!=its.second;++it)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"size= "<<us.size()<<endl;
    cout<<"count(5)= "<<us.count(5)<<endl;
    cout<<"num erased(5)"<<us.erase(5)<<endl;
    cout<<boolalpha<<"found 16= "<<(us.find(16)!=us.end())<<endl;
    cout<<"num buckets= "<<us.bucket_count()<<endl;
    cout<<"load factor= "<<us.load_factor()<<endl;
    unordered_set<Student, StudentHashFunction> uss={{50,"Simon"},{20,"Thomas"}};
    for(auto& st: uss)
        st.print_student();

    return 0;
}
