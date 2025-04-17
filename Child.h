#ifndef CHILD_H
#define CHILD_H

#include "Person.h"

class Child : public Person {
private:
    string FavoriteToy;

public:
    string getFavoriteToy() const;
    void setFavoriteToy(string toy);
};

#endif