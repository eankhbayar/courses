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
class PersonEx1
{
private:
    string name;
    int age;

public:
    PersonEx1(string name, int age)
    {
        setInfo(name, age);
    }
    void printInfo()
    {
        cout << "# Person Info #" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    // TODO 1 : Define a member function setInfo(...) here
    void setInfo(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};
int main()
{
    string name;
    int age;
    cout << "Enter person information:" << endl;
    cin >> name >> age;
    PersonEx1 person(name, age);
    person.printInfo();
    return 0;
}