
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "student.h"
#include "roster.h"

using namespace std;
// this file checks requirement E
// declare array for students
const static int numStudents = 5;
Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

//Constructor
Roster::Roster() {};
//Destructor
Roster::~Roster() {
    for (int i = 0; i < numStudents; i++){
        cout << "Dynamic descructor called for " << classRosterArray[i]->getstudentID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
};

Student** Roster::getStudent(){
    return classRosterArray;
}
// using regular expresions as a parsing method
void Roster::parseArray(const std::string studentData[]){
    regex regex("\\,");
    
    for (int i = 0; i < 5; i++) {
        string tempString = studentData[i];
        std::vector<string> studentDataElements(
                                     std::sregex_token_iterator(tempString.begin(), tempString.end(), regex, -1), std::sregex_token_iterator());
        DegreeProgram dp = DegreeProgram::UNDECIDED;
        if (studentDataElements.at(8).back() == 'Y') dp = DegreeProgram::SECURTIY;
            if (studentDataElements.at(8).back() == 'K') dp = DegreeProgram::NETWORK;
            if (studentDataElements.at(8).back() == 'E') dp = DegreeProgram::SOFTWARE;
            add(studentDataElements.at(0),
                studentDataElements.at(1),
                studentDataElements.at(2),
                studentDataElements.at(3),
                stoi(studentDataElements.at(4)),
                stoi(studentDataElements.at(5)),
                stoi(studentDataElements.at(6)),
                stoi(studentDataElements.at(7)),
                dp);
    }
};


void Roster::add(std::string studentID,
                 std::string firstName,
                 std::string lastName,
                 std::string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram Degree){
    int courseDuration[Student::totalDaysArray]{daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++studentIndex] = new Student(Student(studentID, firstName, lastName, emailAddress, age, Degree, courseDuration));
    
};

void Roster::printAll() {
    
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i] == nullptr){}
        else { classRosterArray[i]->print();
        }
    }
};

void Roster::printInvalidEmails() {
    cout << endl << "Invalid email address(s) format: " << endl << endl;
        for (int i = 0; i < numStudents; i++) {
            if ( (classRosterArray[i]->getemailAddress()).find('@') == -1) {
                cout << classRosterArray[i]->getemailAddress() << endl;
            }
            else if ( (classRosterArray[i]->getemailAddress()).find('.') == -1) {
                cout << classRosterArray[i]->getemailAddress() << endl;
            }
            else if ( (classRosterArray[i]->getemailAddress()).find(' ') != -1) {
                cout << classRosterArray[i]->getemailAddress() << endl;
            }
        }
};

void Roster::printAveragedaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i]->getstudentID() == studentID) {
            cout << studentID << " : ";
            cout << ((classRosterArray[i]->getcourseDuration()[0]
                + classRosterArray[i]->getcourseDuration()[1]
                + classRosterArray[i]->getcourseDuration()[2])
                / 3) << endl;
        }
    }
};

void Roster::printByDegreeProgram(DegreeProgram Degree) {
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (Roster::classRosterArray[i]->getDegree() == Degree) classRosterArray[i]->print();
    }
    cout << endl;
};

void Roster::removeStudent(string studentID) {
    bool REMOVE = false;
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (classRosterArray[i]->getstudentID() == studentID) {
            REMOVE = true;
            if (i < 5 - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[5 - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::studentIndex--;
        }

    }
    if (REMOVE) {
        cout << studentID << " removed." << endl << endl;
        this->printAll();
    }
    else cout << studentID << " was not found in roster." << endl << endl;
};
