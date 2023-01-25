#include <iostream>
#include <string>
#include <array>
#include "student.h"
#include "degree.h"
#include "roster.h"


// full constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int Age, DegreeProgram Degree, int courseDuration[]){
    //'this' keyword seperates the field from the parameter
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->Age = Age;
    this->Degree = Degree;
    for (int index = 0; index < totalDaysArray; index++) {
        this->courseDuration[index] = courseDuration[index];
    }
}

Student::~Student()
{

}

//Accessors (Getters)
string Student::getstudentID()
{
    return studentID;
}

string Student::getfirstName()
{
    return firstName;
}

string Student::getlastName()
{
    return lastName;
}

string Student::getemailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return Age;
}

DegreeProgram Student::getDegree()
{
    return Degree;
}

int* Student::getcourseDuration()
{
    return  courseDuration;
}


//Mutators (Setters)
void Student::setstudentID(string studentID) {this->studentID = studentID;}
void Student::setfirstName(string firstName) {this->firstName = firstName;}
void Student::setlastName(string lastName) {this->lastName = lastName;}
void Student::setemailAddress(string emailAddress) {this->emailAddress = emailAddress;}
void Student::setAge(int Age) {this->Age = Age;}
void Student::setDegreeProgram(DegreeProgram Degree) {this->Degree = Degree;}
void Student::setcourseDuration(int courseDuration[])
{
    for (int index = 0; index < totalDaysArray; index++)
    {
        this->courseDuration[index] = courseDuration[index];
    }
}
//output header for organizational display
void Student::printHeader() {
    cout << "studentID\t";
    cout << "firstName\t";
    cout << "lastName\t";
    cout << "emailAddress\t";
    cout << "Age\t";
    cout << "DegreeProgram";
    cout << "courseDuration";
    cout << endl;
}

//Method to print
void Student::print() {
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << Age << "\t";
    cout << "Total days in course: ";
    cout << "{";
    cout << courseDuration[1] << ", ";
    cout << courseDuration[2] << ", ";
    cout << courseDuration[1] << "}\t";
    cout << "Degree Program: ";
    switch (Degree)
    {
        case DegreeProgram::SECURTIY:
        cout << "Security";
        break;
    case DegreeProgram::NETWORK:
        cout << "Network";
        break;
    case DegreeProgram::SOFTWARE:
        cout << "Software";
        break;
        
        case DegreeProgram::UNDECIDED:
        
            break;
    }
    cout << endl;
}

