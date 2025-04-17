#include "Employee.h"

Employee::Employee(Division* div, JobDescription jd) {
    d = div;
    jds.push_back(jd);
}

string Employee::getCompanyID() const { return CompanyID; }
string Employee::getTitle() const { return Title; }
string Employee::getStartDate() const { return StartDate; }
void Employee::setCompanyID(string id) { CompanyID = id; }
void Employee::setTitle(string t) { Title = t; }
void Employee::setStartDate(string date) { StartDate = date; }
void Employee::setSpouse(Spouse* spouse) { s = spouse; }
Spouse* Employee::getSpouse() const { return s; }
void Employee::addChild(Child c) { children.push_back(c); }
vector<Child> Employee::getChildren() const { return children; }
void Employee::setDivision(Division* div) { d = div; }
Division* Employee::getDivision() const { return d; }
void Employee::addJobDescription(JobDescription jd) { jds.push_back(jd); }
vector<JobDescription> Employee::getJobDescriptions() const { return jds; }