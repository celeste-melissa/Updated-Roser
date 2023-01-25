#include <iostream>
#include <string>
#include <vector>
#include "roster.h"
#include "student.h"


using namespace std;

int main() {
    
    cout << "Scripting and Programming Applications(C867)" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 001482560" << endl;
    cout << "Programmer Name: Celeste Catala" << endl << endl;
    // input student data from scenerio
    // check requirement A
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Celeste,Catala,ccata13@wgu.edu,25,60,45,18,SOFTWARE"
    };
    const int numStudents = 5;
    // function call from roster.cpp
    // check requirement F3
    
    Roster classRoster;
    classRoster.parseArray(studentData);
    
    cout << "Student Data Table:" << endl;
    // outprint the printAll() within student.cpp and roster.cpp
    // check requirement F4
    classRoster.printAll();
    cout << endl;
    // print invalid email formats
    // check requirement F4
    classRoster.printInvalidEmails();
    cout <<endl;
    // output student array
    // check requirement F4
    cout << "Average days spent in each course: " << endl;
    for (int i=0; i < numStudents; i++) classRoster.printAveragedaysInCourse(classRoster.getStudent()[i]->getstudentID());
    cout << endl;
    // display software degree programs only
    //check rquirement F4
    cout << "Software Degrees: " << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    // print message of A3 removal and remove student
    // check requirement F4
    cout << "Removing Student A3" << endl;
    classRoster.removeStudent("A3");
    cout << endl;
   // release allocated memory
   // check requirement F5
    cout << "Destructors will be called upon exit." << endl;
    return 0;
}
  
