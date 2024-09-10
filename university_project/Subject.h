#ifndef Subject_h
#define Subject_h

#include <iostream> 
#include <string.h>


using namespace std ;


class Subject
	   {
       	private:
   		string Subjectcode;
  		string LSubject;
        unsigned int Hours_per_week;
        string SubjectSemester;
			   
			   
		public:
		Subject(const string&,const string&,unsigned int,const string&);
		~Subject();
        
        
		/////Setters - Getters//////
			void setSubjectcode(const string&);
	        string getSubjectcode()const;
		
		   	void setLSubject(const string&);
	        string getLSubject()const;
		
		    void setHours_per_week(unsigned int);
	        unsigned int getHours_per_week()const;
            
            void setSubjectSemester(const string&);
	        string getSubjectSemester()const;
            
     
	   };


#endif
