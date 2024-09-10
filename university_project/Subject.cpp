#include "Subject.h"
#include <iostream> 
#include <string.h>


 Subject::Subject(const string& SubCode,const string& LSub,unsigned int Hours,const string& Sem)
{
    Subjectcode=SubCode;
    LSubject=LSub;
    Hours_per_week=Hours;
    
    if(Sem!="Χειμερινό" && Sem!="Εαρινό"){
                throw invalid_argument("Invalid value for Subject Semester,the Semester of each subject is either 'Χειμερινό' or 'Εαρινό'!");
                
            }else{
    SubjectSemester=Sem;
    }
}

Subject::~Subject(){};

    
    void Subject::setSubjectcode(const string& Subjectcode)
    {this->Subjectcode=Subjectcode;}
	
    string Subject::getSubjectcode()const
    {return Subjectcode;}
		
    void Subject::setLSubject(const string& LSubject)
    {this->LSubject=LSubject;}
	
    string Subject::getLSubject()const
    {return LSubject;}
    
    void Subject::setHours_per_week(unsigned int Hours_per_week)	
    {this->Hours_per_week=Hours_per_week;}
     	
     unsigned int Subject::getHours_per_week()const
    {return Hours_per_week;}   
		
	 void Subject::setSubjectSemester(const string& SubjectSemester){
            if(SubjectSemester!="Χειμερινό" && SubjectSemester!="Εαρινό"){
                throw invalid_argument("Invalid value for Subject Semester,the Semester of each subject is either 'Χειμερινό' or 'Εαρινό'!");
                
            }
        this->SubjectSemester=SubjectSemester;
     }
	 
    string Subject::getSubjectSemester()const
    {return SubjectSemester;}
