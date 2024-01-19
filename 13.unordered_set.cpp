/*
*std::unordered_set
-[]associative container that containes a set of unique objects of type key
-[] <unordered_set>
-[] search,removal,insertion times are constant
-[]implemented as Hash Table

template<
    class Key,
    class Hash=std::hash<Key>,
    class KeyEqual=std::equal_to<Key>,
    class Allocator=std::allocator<Key>,
> class unordered_set;

Unordered_Set Function:
    -[] size()
    -[] =
    -[] clear()
    -[] count(), find()
    -[] empty()
    -[] insert(key),insert(it1,it2),insert(init_list)
    -[]erase(it),erase(it1,it2),erase(key)
    -[]bucket_count(),load_factor()


    ->insert(Key Key)
        -insert key(if not present)
        -return pair-iterator to inserted(present) element & bool denoting if insertion took place
    ->insert(iterator pos1, iterator pos2)
        -insert elements in range [pos1,pos2)
        -return void
    ->insert(initializer_list l)
        -insert element from initializer list
        -return nothing (void)
    ->erase(iterator pos)
        -remove element at position pos
        -return iterator following last element
    ->erase(iterator pos1, iterator pos2)
        -remove element in range [pos1,pos2)
        -return no of element removed]
*/

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
        cout<<"[id= "<<id<<" , name= "<<name<<"]\n";
    }
};

class StudentHashFunction(){
public:
    size_t operator()(const Student& s) const{
        return (hash<int>{}(s.id)+hash<string>{}(s.name));
    }
};

int main(){
    size_t h1=hash<string>{}("Hello");
    size_t h2=hash<string>{}("World");
    cout<<h1<<", "<<h2<<endl;
    cout<<hash<int>{}(100)<<endl;
    cout<<hash<float>{}(100.5)<<endl;

    unordered_set<int> us={5,10,4,20,5,5,15};
    for(int x:us)
        cout<<x<<" ";
    cout<<endl;

    cout<<"size= "<<us.size()<<endl;
    cout<<"count(5)= "<<us.count(5)<<endl;
    cout<<"num erased(5)"<<us.erase(5)<<endl;
    cout<<boolalpha<<"found 16= "<<(us.find(16)!=us.end())<<endl;
    cout<<"num buckets= "<<us.bucket_count()<<endl;
    cout<<"load factor= "<<us.load_factor()<<endl;

    unordered_set<Student, StudentHashFunction> uss={{50,'Simon'},{20,'Thomas'}};

    return 0;
}
