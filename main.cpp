#include "Person.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"
#include "Employee.h"
#include <iostream>
using namespace std;

//Class: Person

class Person {
protected:
    string Name;                
    string SSNum;               
    int Age;                    

public:
    // Байгуулагч функц
    Person(string Name = "", string SSNum = "", int Age = 0)
        : Name(Name), SSNum(SSNum), Age(Age) {}

    // Getter for Name
    string getName() const { return Name; }

    // Getter for SSNum
    string getSSNum() const { return SSNum; }

    // Getter for Age
    int getAge() const { return Age; }

    // Setter for Name
    void setName(string n) { Name = n; }

    // Setter for SSNum
    void setSSNum(string s) { SSNum = s; }

    // Setter for Age
    void setAge(int a) { Age = a; }
};


// Spouse Class (Person-оос удамшина)
class Spouse : public Person {
private:
    string AnniversaryDate;    

public:
    // Getter for AnniversaryDate
    string getAnniversaryDate() const { return AnniversaryDate; }

    // Setter for AnniversaryDate
    void setAnniversaryDate(string date) { AnniversaryDate = date; }
};


// Child Class (Person-оос удамшина)
class Child : public Person {
private:
    string FavoriteToy;        

public:
    // Getter for FavoriteToy
    string getFavoriteToy() const { return FavoriteToy; }

    // Setter for FavoriteToy
    void setFavoriteToy(string toy) { FavoriteToy = toy; }
};


// Division Class
class Division {
private:
    string DivisionName;      

public:
    // Getter for DivisionName
    string getDivisionName() const { return DivisionName; }

    // Setter for DivisionName
    void setDivisionName(string Name) { DivisionName = Name; }
};


// JobDescription Class
class JobDescription {
private:
    string Description;

public:
    // Getter for Description
    string getDescription() const { return Description; }

    // Setter for Description
    void setDescription(string desc) { Description = desc; }
};


// Employee Class (inherits from Person)
class Employee : public Person {
private:
    string CompanyID;                      
    string Title;                          
    string StartDate;                      

    Spouse* s = nullptr;                   // Spouse объектын заагч (0 эсвэл 1 байж болно)
    vector<Child> children;                // Хүүхдийн объектуудын жагсаалт (0-ээс олон байж болно)
    Division* d = nullptr;                 // Хэлтсийн объектыг заагч (заавал оноох ёстой)
    vector<JobDescription> jds;            // Ажлын тодорхойлолтын жагсаалт (1 ба түүнээс дээш)

public:
    // Division болон JobDescription оноох байгуулагч
    Employee(Division* div, JobDescription jd) {
        d = div;                           // Хэлтсийн заагч оноох
        jds.push_back(jd);                 // Ажлын тодорхойлолтыг жагсаалт руу нэмэх
    }

    // Getter for CompanyID
    string getCompanyID() const { return CompanyID; }

    // Getter for Title
    string getTitle() const { return Title; }

    // Getter for StartDate
    string getStartDate() const { return StartDate; }

    // Setter for CompanyID
    void setCompanyID(string id) { CompanyID = id; }

    // Setter for Title
    void setTitle(string t) { Title = t; }

    // Setter for StartDate
    void setStartDate(string date) { StartDate = date; }

    // Spouse-ийн объектыг оноох
    void setSpouse(Spouse* spouse) { s = spouse; }

    // Spouse-ийн объектыг буцаах
    Spouse* getSpouse() const { return s; }

    // Хүүхдийг жагсаалтад нэмэх
    void addChild(Child c) { children.push_back(c); }

    // Хүүхдийн жагсаалтыг буцаах
    vector<Child> getChildren() const { return children; }

    // Set Division pointer
    void setDivision(Division* div) { d = div; }

    // Return Division pointer
    Division* getDivision() const { return d; }

    // Ажлын тодорхойлолт нэмэх
    void addJobDescription(JobDescription jd) { jds.push_back(jd); }

    // Бүх ажлын тодорхойлолтыг буцаах
    vector<JobDescription> getJobDescriptions() const { return jds; }
};

int main() {
    // Division объектууд үүсгэх
    Division div1;
    div1.setDivisionName("Engineering");

    Division div2;
    div2.setDivisionName("Marketing");

    Division div3;
    div3.setDivisionName("Finance");

    // JobDescription объектууд үүсгэх
    JobDescription jd1;
    jd1.setDescription("Develop software");

    JobDescription jd2;
    jd2.setDescription("Create marketing campaigns");

    JobDescription jd3;
    jd3.setDescription("Manage company finances");

    // Employee объектууд үүсгэх
    Employee emp1(&div1, jd1);
    emp1.setName("Alice Johnson");
    emp1.setCompanyID("E001");
    emp1.setTitle("Software Engineer");

    Employee emp2(&div2, jd2);
    emp2.setName("Bob Smith");
    emp2.setCompanyID("E002");
    emp2.setTitle("Marketing Specialist");

    Employee emp3(&div3, jd3);
    emp3.setName("Charlie Brown");
    emp3.setCompanyID("E003");
    emp3.setTitle("Financial Analyst");

    // Spouse объектууд үүсгэх ба Employee-д тохируулах
    Spouse spouse1;
    spouse1.setName("John Johnson");
    spouse1.setAnniversaryDate("01/01/2010");
    emp1.setSpouse(&spouse1);

    Spouse spouse2;
    spouse2.setName("Mary Smith");
    spouse2.setAnniversaryDate("05/15/2015");
    emp2.setSpouse(&spouse2);

    Spouse spouse3;
    spouse3.setName("Emily Brown");
    spouse3.setAnniversaryDate("08/20/2020");
    emp3.setSpouse(&spouse3);

    // Child объектууд үүсгэх ба Employee-д тохируулах
    Child child1;
    child1.setName("Sophia Johnson");
    child1.setFavoriteToy("Lego");
    emp1.addChild(child1);

    Child child2;
    child2.setName("James Smith");
    child2.setFavoriteToy("Action Figure");
    emp2.addChild(child2);

    Child child3;
    child3.setName("Olivia Brown");
    child3.setFavoriteToy("Doll");
    emp3.addChild(child3);

    // Объектуудын мэдээллийг хэвлэх
    cout << "Employee 1: " << emp1.getName() << ", Title: " << emp1.getTitle()
         << ", Division: " << emp1.getDivision()->getDivisionName()
         << ", Job Description: " << emp1.getJobDescriptions()[0].getDescription()
         << ", Spouse: " << emp1.getSpouse()->getName()
         << ", Child: " << emp1.getChildren()[0].getName() << " (Favorite Toy: " << emp1.getChildren()[0].getFavoriteToy() << ")" << endl;

    cout << "Employee 2: " << emp2.getName() << ", Title: " << emp2.getTitle()
         << ", Division: " << emp2.getDivision()->getDivisionName()
         << ", Job Description: " << emp2.getJobDescriptions()[0].getDescription()
         << ", Spouse: " << emp2.getSpouse()->getName()
         << ", Child: " << emp2.getChildren()[0].getName() << " (Favorite Toy: " << emp2.getChildren()[0].getFavoriteToy() << ")" << endl;

    cout << "Employee 3: " << emp3.getName() << ", Title: " << emp3.getTitle()
         << ", Division: " << emp3.getDivision()->getDivisionName()
         << ", Job Description: " << emp3.getJobDescriptions()[0].getDescription()
         << ", Spouse: " << emp3.getSpouse()->getName()
         << ", Child: " << emp3.getChildren()[0].getName() << " (Favorite Toy: " << emp3.getChildren()[0].getFavoriteToy() << ")" << endl;

    return 0;
}

