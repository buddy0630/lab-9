#ifndef SPOUSE_H
#define SPOUSE_H

#include "Person.h"

class Spouse : public Person {
private:
    string AnniversaryDate;

public:
    string getAnniversaryDate() const;
    void setAnniversaryDate(string date);
};

#endif