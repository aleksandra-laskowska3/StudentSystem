//
//  student.h
//  JYMI Task 1
//
//  Created by Aleksandra Laskowska on 8/15/21.
//

#ifndef student_h
#define student_h
#include <string>
#include <stdio.h>
#include <iostream>
#include "degree.h"
using namespace std;

class Student {
    
public:
    const static int numClasses = 3;
    
    Student();
    //constructor
    Student(string ID, string First, string Last, string Mail, int Age, int Days[], DegreeProgram Program) ;
    
    //destructor
    ~Student();
    
    string programString(DegreeProgram Program);
    
// accessors
    string GetstudentID();
    string GetfirstName();
    string GetlastName();
    string GeteMail();
    int Getage();
    int* GetdaysToCompleteClass();
    DegreeProgram GetdegreeProgram();
    
//mutators
    void SetstudentID(string ID);
    void SetfirstName(string First);
    void SetlastName(string Last);
    void SeteMail(string Mail);
    void Setage(int Age);
    void SetdaysToCompleteClass(int Days[numClasses]);
    void SetdegreeProgram(DegreeProgram Program);
    
    //print student date
    void print();
    
private:
    string ID;
    string First;
    string Last;
    string Mail;
    int Age;
    int Days[numClasses];
    DegreeProgram Program;
    
};


#endif 


