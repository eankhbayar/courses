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
class Student
{
private:
    string name;
    double examScore; // Assume to be from 0 to 100
public:
    void init(string name, double examScore)
    {
        this->name = name;
        this->examScore = examScore;
    }
    string getName()
    {
        return name;
    }
    double getExamScore()
    {
        return examScore;
    }
};
int main()
{
    Student studentArray[5];
    int numOfStudents;
    cout << "Enter the number of students:" << endl;
    // Assume the input is an integer between 1 and 5 inclusively
    cin >> numOfStudents;
    cout << "Enter information for all students:" << endl;
    // TODO : Complete the main function

    Student max;
    max.init("", 0);
    for (int i = 0; i < numOfStudents; i++)
    {
        string name;
        double examScore;
        cin >> name >> examScore;
        studentArray[i].init(name, examScore);
        if (studentArray[i].getExamScore() > max.getExamScore())
        {
            max = studentArray[i];
        }
    }
    cout << "List of student(s) with the highest score: " << max.getExamScore() << endl;
    for (int i = 0; i < numOfStudents; i++)
    {
        if (studentArray[i].getExamScore() == max.getExamScore())
        {
            cout << studentArray[i].getName() << endl;
        }
    }

    return 0;
}