#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"
#include <vector>
using namespace std;

class Employee : public Person {
private:
    string CompanyID;
    string Title;
    string StartDate;
    Spouse* s = nullptr;
    vector<Child> children;
    Division* d = nullptr;
    vector<JobDescription> jds;

public:
    Employee(Division* div, JobDescription jd);
    string getCompanyID() const;
    string getTitle() const;
    string getStartDate() const;
    void setCompanyID(string id);
    void setTitle(string t);
    void setStartDate(string date);
    void setSpouse(Spouse* spouse);
    Spouse* getSpouse() const;
    void addChild(Child c);
    vector<Child> getChildren() const;
    void setDivision(Division* div);
    Division* getDivision() const;
    void addJobDescription(JobDescription jd);
    vector<JobDescription> getJobDescriptions() const;
};

#endif