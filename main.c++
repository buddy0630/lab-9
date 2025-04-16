#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
// Base Class
class Person {
protected:
    string Name;
    string SSNum;
    int Age;
 
public:
    Person(string Name = "", string SSNum = "", int Age = 0)
        : Name(Name), SSNum(SSNum), Age(Age) {}
 
    string getName() const { return Name; }
    string getSSNum() const { return SSNum; }
    int getAge() const { return Age; }
 
    void setName(string n) { Name = n; }
    void setSSNum(string s) { SSNum = s; }
    void setAge(int a) { Age = a; }
};
 
 
// Spouse class (inherits from Person)
class Spouse : public Person {
private:
    string AnniversaryDate;
 
public:
    string getAnniversaryDate() const { return AnniversaryDate; }
    void setAnniversaryDate(string date) { AnniversaryDate = date; }
};
 
// Child class (inherits from Person)
class Child : public Person {
private:
    string FavoriteToy;
 
public:
    string getFavoriteToy() const {
        return FavoriteToy; }
    void setFavoriteToy(string toy) {
        FavoriteToy = toy; }
};
 
// Division class
class Division {
private:
    string DivisionName;
 
public:
    string getDivisionName() const {
        return DivisionName; }
    void setDivisionName(string Name) {
        DivisionName = Name; }
};
 
// JobDescription class
class JobDescription {
private:
    string Description;
 
public:
    string getDescription() const {
        return Description; }
    void setDescription(string desc) {
        Description = desc; }
};
 
// Employee class (inherits from Person)
class Employee : public Person {
private:
    string CompanyID;
    string Title;
    string StartDate;
 
    Spouse *s; // 0..1    
    vector<child> children; // 0..n or child **c;
    Division *d; // 1
    vector<*jd> jds; // 1..n
    employee(Division dd, jd j){
        this->d = &dd;
        this->jds.push_back(&j);
    }
 
public:
    string getCompanyID() const {
        return CompanyID; }
    string getTitle() const {
        return Title; }
    string getStartDate() const {
        return StartDate; }
 
    void setCompanyID(string id) {
        CompanyID = id; }
    void setTitle(string t) {
        Title = t; }
    void setStartDate(string date) {
        StartDate = date; }
 
    void setDivision(Division d) {
        division = d; }
    Division getDivision() const {
        return division; }
 
    void addJobDescription(JobDescription jd) {
        jobDescriptions.push_back(jd); }
    vector<JobDescription> getJobDescriptions() const {
        return jobDescriptions; }
}
 
 
 
;