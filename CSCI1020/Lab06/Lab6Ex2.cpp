/***********************************************************************
CSCI1020 Hands-on Introduction to C++
I declare that the source code here submitted is original except for
source material explicitly acknowledged. I also acknowledge that I am
aware of University policy and regulations on honesty in academic work,
and of the disciplinary guidelines and procedures applicable to breaches
of such policy and regulations, as contained in the following University
website:
3
Student Name: Ankhbayar ENKHTAIVAN
Student ID: 1155185142
Date: 16/03/2023
***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class PersonEx2
{
private:
    string name;
    int age;

public:
    PersonEx2(string name, int age)
    {
        setInfo(name, age);
    }
    virtual void printInfo()
    {
        cout << "# Person Info #" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    void setInfo(string name, int age)
    {
        setName(name);
        setAge(age);
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }
};

class Student : public PersonEx2
{
private:
    double gpa;

public:
    Student(string name, int age, double gpa) : PersonEx2(name, age)
    {
        setInfo(name, age, gpa);
    }
    void printInfo()
    {
        cout << "# Student Info #" << endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "GPA: " << getGpa() << endl;
    }

    void setGpa(double gpa)
    {
        this->gpa = gpa;
    }

    double getGpa()
    {
        return gpa;
    }

    void setInfo(string name, int age, double gpa)
    {
        setGpa(gpa);
    }
};

int main()
{
    string name;
    int age;
    double gpa;
    cout << "Enter student information:" << endl;
    cin >> name >> age >> gpa;
    PersonEx2 person(name, age);
    Student student(name, age, gpa);
    PersonEx2 *ptr;
    ptr = &person;
    ptr->printInfo(); // same as (*ptr).printInfo();
    ptr = &student;
    ptr->printInfo(); // same as (*ptr).printInfo();
    return 0;
}