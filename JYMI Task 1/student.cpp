//
//  student.cpp
//  JYMI Task 1
//
//  Created by Aleksandra Laskowska on 8/15/21.
//

#include "student.h"
#include <string>
#include <iostream>
#include <map>
#include "degree.h"

using namespace std;

Student::Student(){
 ID = " ";
 First = " ";
 Last = " ";
 Mail = " ";
 Age = -1;
    for (int i = 0; i < numClasses; i++)
    {
        Days[i] = 0;
        
    }
 Program = DegreeProgram::NONE;
}
//constructor
Student::Student(string ID, string First, string Last, string Mail, int Age, int Days[], DegreeProgram Program)   {
    this->ID = ID;
    this->First = First;
    this->Last = Last;
    this->Mail = Mail;
    this->Age = Age;
    for ( int i = 0; i < numClasses; i++) {
        this->Days[i] = Days[i];}
    this->Program = Program;
}
//destructor
Student::~Student(){
}

//accessors
string Student::GetstudentID() {
    return ID;
}
    
string Student::GetfirstName() {
    return First; }
    
string Student::GetlastName(){
    return Last; }
    
string Student::GeteMail(){
    return Mail; }
    
int Student::Getage(){
    return Age;}
    

int* Student::GetdaysToCompleteClass(){
    return Days;}

DegreeProgram Student::GetdegreeProgram(){
    return Program;}

//mutators
void Student::SetstudentID(string ID){
    this->ID = ID;}

void Student::SetfirstName(string First){
    this->First = First;}

void Student::SetlastName(string Last){
    this->Last = Last;
}

void Student::SeteMail(string Mail){
    this->Mail = Mail;
}
void Student::Setage(int Age){
    this->Age = Age;
}
void Student::SetdaysToCompleteClass( int Days[]){
    for(int i = 0; i < numClasses; ++i){
        this->Days[i] = Days[i];
    }
    
}
void Student::SetdegreeProgram(DegreeProgram Program){
     this->Program = Program;
}
string Student::programString(DegreeProgram Program){
if (Program == SECURITY)
    return "SECURITY";
    else if (Program == NETWORK)
        return "NETWORK";
    else
        return "SOFTWARE";
}

// print() to print specific student data
// print in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
void Student::print() {
    cout << ID << '\t'
         << "First Name: " << First << '\t'
         << "Last Name: " << Last << '\t'
         << "Age: " << Age << '\t'
         << "daysInCourse: {" << Days[0] << ", " << Days[1] << ", " << Days[2] << '\t'
         << "}" << '\t' << "Degree Program: " << programString(Program) << endl;
}


  
    
   




