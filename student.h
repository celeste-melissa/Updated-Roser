#include <iostream>
#include <string>
#ifndef student_h
#define student_h
#include "degree.h"
using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::left;


class Student {
public:
    const static int totalDaysArray = 3;
  
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int Age;
    DegreeProgram Degree;
    int courseDuration[totalDaysArray];
    // constructor of column header found in the data table
    // check requirement D1
    public:
    Student();
    
    Student(string studentID, string firstName, string lastName, string emailAddress, int Age, DegreeProgram Degree, int courseDuration[]);
    
    // accessors applied for each instance variable from D1
    // check requirement D2
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemailAddress();
    int getAge();
    DegreeProgram getDegree();
    int* getcourseDuration();
    
    
    //mutator applied for each instance variable from D1
    //check requirement D2
    void setstudentID(string studentID);
    void setfirstName(string firstName);
    void setlastName(string lastName);
    void setemailAddress(string emailAddress);
    void setAge(int Age);
    void setDegreeProgram(DegreeProgram Degree);
    void setcourseDuration(int courseDuration[]);
    
    //static method to display categories
    //static is shared by all objects
    static void printHeader();
    
    //print() to print specific student data
    //check requirement D2
    void print();
   
    
    //destructor is required to release memory
    ~Student();
};
 
#endif

