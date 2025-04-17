#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string Name;
    string SSNum;
    int Age;

public:
    Person(string Name = "", string SSNum = "", int Age = 0);
    string getName() const;
    string getSSNum() const;
    int getAge() const;
    void setName(string n);
    void setSSNum(string s);
    void setAge(int a);
};

#endif