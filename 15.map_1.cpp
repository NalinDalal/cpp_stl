#include <iostream>
#include <map>
using namespace std;
class Person {
public:
  string name;
  int age;

  Person(const string &n, int a) : name(n), age(a) {}

  // Overloaded operator< for sorting in maps
  bool operator<(const Person &p) const { return age < p.age; }

  friend ostream &operator<<(ostream &os, const Person &p) {
    return os << '(' << p.name << ',' << p.age << ')';
  }
};
int main() {
  pair<Person, char *> p[] = {
      pair<Person, char *>(Person("Gregg", 25), "Pittsburgh"),
      pair<Person, char *>(Person("Ann", 30), "Boston"),
      pair<Person, char *>(Person("Bill", 20), "Belmont")};
  map<Person, char *> cities(p, p + 3);
  cities[Person("Kay", 40)] = "New York";
  // cities["Jenny"] = "Newark";
  cities[Person("Jenny", 0)] = "Newark";
  cities.insert(map<Person, char *>::value_type(Person("Kay", 40), "Detroit"));
  cities.insert(pair<Person, char *>(Person("Kay", 40), "Austin"));
  map<Person, char *>::iterator i;
  for (i = cities.begin(); i != cities.end(); i++)
    cout << (*i).first << ' ' << (*i).second << endl;
  // output:
  //   (Ann,30) Boston
  //   (Bill,20) Belmont
  //   (Gregg,25) Pittsburgh
  //   (Jenny,0) Newark
  //   (Kay, 40) New York
  cities[p[1].first] = "Chicago";
  for (i = cities.begin(); i != cities.end(); i++) {
    cout << (*i).first << ' ' << (*i).second << endl;
  }
  // output:
  //   (Ann,30) Chicago
  //   (Bill,20) Belmont
  //   (Gregg,25) Pittsburgh
  //   (Jenny,0) Newark
  //   (Kay, 40) New York
  multimap<Person, char *> mCities(p, p + 3);
  mCities.insert(pair<Person, char *>(Person("Kay", 40), "Austin"));
  mCities.insert(pair<Person, char *>(Person("Kay", 40), "Austin"));
  mCities.insert(pair<Person, char *>(Person("Kay", 40), "Detroit"));
  multimap<Person, char *>::iterator mi;
  for (mi = mCities.begin(); mi != mCities.end(); mi++) {
    cout << (*mi).first << ' ' << (*mi).second << endl;
    // output:
    //   (Ann,30) Boston
    //   (Bill,20) Belmont
    //   (Gregg,25) Pittsburgh
    //   (Kay, 40) Austin
    //   (Kay, 40) Austin
    //   (Kay, 40) Detroit
    (*(mCities.find(Person("Kay", 40)))).second = "New York";
  }
  for (mi = mCities.begin(); mi != mCities.end(); mi++) {
    cout << (*mi).first << ' ' << (*mi).second << endl;
  }
  // output:
  //   (Ann,30) Boston
  //   (Bill,20) Belmont
  //   (Gregg,25) Pittsburgh
  //   (Kay, 40) New York
  //   (Kay, 40) Austin
  //   (Kay, 40) Detroit
  return 0;
}
