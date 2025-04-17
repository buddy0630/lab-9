#ifndef DIVISION_H
#define DIVISION_H

#include <string>
using namespace std;

class Division {
private:
    string DivisionName;

public:
    string getDivisionName() const;
    void setDivisionName(string Name);
};

#endif