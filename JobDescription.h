#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H

#include <string>
using namespace std;

class JobDescription {
private:
    string Description;

public:
    string getDescription() const;
    void setDescription(string desc);
};

#endif