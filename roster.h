#include <iostream>
#include <string>
#include <vector>
#ifndef roster_h
#define roster_h
#include "student.h"
using namespace std;
using std::string;
using std::cout;
using std::endl;
    // check requirement E

class Roster{
public:
    //Constructors
    Roster();
    //Destructor
    ~Roster();
    Student** getStudent();
     // data from studentData is added to the classRoster
    void parseArray(const std::string studentData[]);
    
   
    void add(std::string studentID,
            std::string firstName,
            std::string lastName,
            std::string emailAddress,
            int Age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram Degree);
    
    void printAll();
    
    void printAveragedaysInCourse(std::string studentID);
    
    void printInvalidEmails();
    
    void printByDegreeProgram(DegreeProgram Degree);
    
    void removeStudent(string studentID);
    
    
    const static int numStudents = 5;
    // array of pointers to hold the data that will be output in main.cpp
    Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

private:
    int studentIndex = -1;
};
#endif





