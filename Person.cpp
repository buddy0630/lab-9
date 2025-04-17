#include "Person.h"

Person::Person(string Name, string SSNum, int Age) : Name(Name), SSNum(SSNum), Age(Age) {}

string Person::getName() const { return Name; }
string Person::getSSNum() const { return SSNum; }
int Person::getAge() const { return Age; }
void Person::setName(string n) { Name = n; }
void Person::setSSNum(string s) { SSNum = s; }
void Person::setAge(int a) { Age = a; }