#ifndef Student_h
#define Student_h

#include <iostream> 
#include <string.h>
#include <vector>
#include <iterator> 

#include "Subject.h"

using namespace std ;

struct PassedSubjectsAndTheirGrades{
        string subject_name;
        double grade;
};
//Also we can use vector pair(such as dictionary in Python:key-value)

class Student{
    private:
        char *AM;
        string Name;
        unsigned int Semester;
        vector<Subject*> Declared_Subjects;
        vector<PassedSubjectsAndTheirGrades> Passed_Subjects;
        
    public:   
        Student(char*,const string&,unsigned int);
        Student(char*,const string&);
        Student(const Student &); 
        Student(char*,const string&,unsigned int,vector<Subject*>,vector<PassedSubjectsAndTheirGrades>);     
        ~Student();
                
        void setAM(char*);
	    char* getAM()const;
	
        void setName(const string&);
	    string getName()const;
     	
        void setSemester(unsigned int);
        unsigned int getSemester()const;

        void setDeclaredSubjects(const vector<Subject*>&);
        const vector<Subject*>& getDeclaredSubjects() const;
        
        void setPassedSubjects(const vector<PassedSubjectsAndTheirGrades>&);
        const vector<PassedSubjectsAndTheirGrades>& getPassedSubjects() const;
        
        void Print(ostream &) const;
        void IncreaseSem();
        //Student operator+=(int i);
        //Student operator-=(int i); 
         
         Student& operator+=(Subject*) ;
         Student& operator=(const Student&);
         bool operator<(const Student &)const;
         bool operator>(const Student &)const;
         bool operator==(const Student &)const;
         bool operator<=(const Student &)const;
         bool operator>=(const Student &)const;
         bool operator!=(const Student &)const;
	     friend ostream& operator<<(ostream& ,const Student&);
    
};

#endif
