/*
std::deque {pronounciation is deck}
    -[]sequence container,support push,pop from both ends
    -[]random access
    -[]no contiguous storage

Functions:
    -[] size()
    -[] =[]
    -[] front(),back()
    -[] empty()
    -[] begin(), end(), rbegin(), rend()
    -[] insert(), erase()
    -[] clear()
    -[] push_back(), push_front(), pop_back(), pop_front()

*/

#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> d={1,2,3,4,5};
    cout<<"size= "<<d.size()<<endl;

    cout<<"Third element= "<<d[2]<<endl;
    cout<<d.front()<<", "<<d.back()<<endl;

    for(deque<int>::iterator it=d.begin(); it!=d.end(); ++it)
        cout<< *it<<"\t";
    cout<<endl;
    
    for(deque<int>::reverse_iterator it=d.rbegin(); it!=d.rend(); ++it)
        cout<<*it<<"\t";
    cout<<endl;

    d.push_back(100);
    d.push_back(200);

    d.push_front(-100);
    d.push_front(-200);

    d.pop_back();
    d.pop_front();

    return 0;
}

/*
Member Function                     Operation
void assign(iterator first,         Remove all the elements in the deque and insert into it the ele-
iterator last)                      ments from the range indicated by iterators first and last

void assign(size_type n,            Remove all the elements in the deque and insert into it n copies of el
const T& el = T())

T& at(size_type n)                  Return the element in position n of the deque

const T& at(size_type n) const      Return the element in position n of the deque

T& back()                           Return last element in deque

const T& back() const               Return last element in deque

iterator begin()                    Return an iterator that references the first element of the deque.

const_iterator begin() const        Return an iterator that references the first element of the deque.

void clear()                        Remove all the elements in the deque.

deque()                             Construct an empty deque

deque(size_type n,const T& el = T())    Construct a deque with n copies of el of type T (if el is not provided, a default constructor T() is used)

deque(const deque <T>& dq)          Copy Constructor

deque(iterator first,iterator last)     Construct a deque and initialize it with values from the range indicated by iterators first and last.

bool empty() const                  Return true if deque include no element and false otherwise

iterator end()                      Return iterator that is past last element of deque

const_iterator end() const          Return an iterator that is past the last element of the deque.

iterator erase(iterator i)          Remove the element referenced by iterator i and return an iterator referencing the element after the one removed

iterator erase(iterator first, iterator last)   Remove the elements in the range indicated by iterators first and last and return an iterator referencing the element after the last one removed.

T& front()             Return the first element in the deque.

const T& front() const      Return the first element in the deque.

iterator insert(iterator i,const T& el = T())     Insert el before the element indicated by iterator i and return an iterator referencing the newly inserted element

void insert(iterator i,size_type n, const T& el)        Insert n copies of el before the element referenced by iterator i.

void insert(iterator i,iterator first, iterator last)   Insert elements from the location referenced by first to the location referenced by last before the element referenced by iterator i.

size_type max_size() const          Return the maximum number of elements for the deque.

T& operator[]       Subscript operator.

void pop_back()     Remove the last element of the deque.

void pop_front()        Remove the first element of the deque.

void push_back(const T& el)     Insert el at the end of the deque.

void push_front(const T& el)        Insert el at the beginning of the deque.

reverse_iterator rbegin()       Return an iterator that references the last element of the deque.

const_reverse_iterator rbegin() const       Return an iterator that references the last element of the deque

reverse_iterator rend()         Return an iterator that is before the first element of the deque.

const_reverse_iterator rend() const     Return an iterator that is before the first element of the deque.

void resize(size_type n,const T& el = T())      Make the deque have n positions by adding n - size() more positions with element el or by discarding overflowing size() - n positions from the end of the deque.

size_type size() const              Return the number of elements in the deque.

void swap(deque<T>& dq)             Swap the content of the deque with the content of another deque dq.
*/