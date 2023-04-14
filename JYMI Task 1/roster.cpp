//
//  roster.cpp
//  JYMI Task 1
//
//  Created by Aleksandra Laskowska on 8/15/21.
#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

//constructor
Roster::Roster(){
Student* classRosterArray[5];
    for(int i = 0; i < 5; i++){
        classRosterArray[i] = new Student();}
    
}
//destructor
Roster::~Roster(){
        for (int i = 0; i < rosterSize; i++){
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
}
}
Student** Roster::GetclassRosterArray(){
    return Roster::classRosterArray;}


//Parse each set of data identified in the “studentData Table.”
void Roster::parse(string data) {
    

        size_t rhs = data.find(",");
        string ID = data.substr(0, rhs); // Student ID
        
        size_t lhs = rhs + 1;
        rhs = data.find(",", lhs);
        string First = data.substr(lhs, rhs - lhs); //First Name
        
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        string Last = data.substr(lhs, rhs - lhs); //Last Name
        
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        string Mail = data.substr(lhs, rhs - lhs); //Email Address
        
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int Age = stoi(data.substr(lhs, rhs - lhs)); // Age
    
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));//Days in course 1
    
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));//Days in course 2
    
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs)); //Days in course 3
    
        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        string strProgram = data.substr(lhs, rhs - lhs); //Degree Program
    
    DegreeProgram Program;
    if(strProgram == "SECURITY") {
        Program = DegreeProgram::SECURITY;
    }
    else if(strProgram == "NETWORK"){
        Program = DegreeProgram::NETWORK;
    }
    else {
        Program = DegreeProgram::SOFTWARE;
    }
   
   
    add(ID, First, Last, Mail, Age, daysInCourse1, daysInCourse2, daysInCourse3, Program);
   }

//sets the instance variables from part D1 and updates the roster
void Roster::add(string ID, string First, string Last, string Mail, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram Program)
{   int Days[3];
    Days[0] = daysInCourse1;
    Days[1] = daysInCourse2;
    Days[2] = daysInCourse3;
    
    classRosterArray[++lastindex] = new Student( ID, First, Last, Mail, Age, Days, Program);
}

//that removes students from the roster by student ID
void Roster::remove(string ID){
    cout << endl;
    
    for( int i = 0; i < rosterSize; ++i){
        if (classRosterArray[i]->GetstudentID() == ID){
            delete classRosterArray[i];
            for (; i <rosterSize - 1; i++) classRosterArray[i] = classRosterArray[i + 1];
            classRosterArray[rosterSize - 1] = nullptr;
            rosterSize--;
            return;
         }
    }
    
    //If the student ID does not exist, the function prints an error message indicating that the student was not found
    cout << "Student with ID " << ID << " has not been found." << endl;
}

//The printAll() function should loop through all the students in classRosterArray and call the print() function for each student
void Roster::printAll() {
    cout << "Class Roster: " << endl;
    for (int i = 0; i < rosterSize; ++i){
        classRosterArray[i]->print();
    }
}

//correctly prints a student’s average number of days in the three courses and the student is identified by the studentID parameter
void Roster::printAverageDaysInCourse(string ID){
    float average;
    for(int i = 0; i < rosterSize; ++i){
    if( classRosterArray[i]->GetstudentID()== ID){
            int* arrayDays = classRosterArray[i]->GetdaysToCompleteClass();
             average = (arrayDays[0] + arrayDays[1] + arrayDays[2]) / 3.0;
            cout << "Average days per class for student " << classRosterArray[i]->GetstudentID() << " are: " << average << endl;
        return;
        }
    }
    }

//that verifies student email addresses and displays all invalid email addresses to the user
void Roster::printInvalidEmails() {
    bool invalid = false;
    cout << "Invalid email addresses: " << endl;
    for(int i = 0; i < 5; i++){
        string address = classRosterArray[i]->GeteMail();
        if((address.find('.') == string::npos) || (address.find('@') == string::npos) || !(address.find(' ') == string::npos))
        {
            invalid = true;
            cout << address;
            cout << endl;
        }
    }
    if( invalid == false){
        cout << "All email addresses are valid." << endl;
    }
}

// prints out student information for a degree program specified by an enumerated typ
void Roster::printByDegreeProgram(DegreeProgram Program){
    cout << "The students that are in " << programString(Program) << " are:" << endl;
    
    for( int i = 0; i < rosterSize; ++i){ 
        if (classRosterArray[i]->GetdegreeProgram() == Program){
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}
