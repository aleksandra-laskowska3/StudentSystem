//
//  roster.h
//  JYMI Task 1
//
//  Created by Aleksandra Laskowska on 8/15/21.
//

#ifndef roster_h
#define roster_h
#include <stdio.h>
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

//Create a Roster class
class Roster: public Student{
    
private:
    //Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    Student* classRosterArray[5] = {nullptr,nullptr,nullptr,nullptr,nullptr};
    int lastindex = -1;
    int rosterSize = 5;
    
public:
    Roster();
    
    Student** GetclassRosterArray();
    
    //Parse each set of data identified in the “studentData Table.”
    void parse(string data);
    
    //public void add, that sets the instance variables from part D1 and updates the roster
    void add(string ID, string First, string Last, string Mail, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram Program);
    
    //public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found
    void remove(string ID);
    
    //public void printAll() that prints a complete tab-separated list of student data in the provided format
    void printAll();
    
    //student’s average number of days in the three courses
    void printAverageDaysInCourse(string ID);
    
    //that verifies student email addresses and displays all invalid email addresses to the user
    void printInvalidEmails();
    
    //prints out student information for a degree program specified by an enumerated type
    void printByDegreeProgram(DegreeProgram Program);
    
    
    //destructor
    ~Roster();
    
};



#endif /* roster_h */
