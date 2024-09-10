#include "Student.h"
#include <iostream> 
#include <string.h>

//Constructors//
        Student::Student(char* A_M,const string& FullName,unsigned int Sem){
            AM = new char [strlen(A_M) +1];
            strcpy(AM,A_M);
            Name=FullName;
            Semester=Sem;
        }
    
        Student::Student(char* A_M,const string& FullName){
            AM = new char [strlen(A_M) +1];
            strcpy(AM,A_M);
            Name=FullName;
            Semester=1;
        }
    

        Student::Student(const Student& x) {
            AM = new char [strlen(x.AM) +1];
            strcpy(AM,x.AM);
            Name=x.Name;
            Semester=x.Semester;
        }
        
        Student::Student(char* A_M,const string& FullName,unsigned int Sem,vector<Subject*> Declared_Subjects,vector<PassedSubjectsAndTheirGrades> Passed_Subjects){
            AM = new char [strlen(A_M) +1];
            strcpy(AM,A_M);
            Name=FullName;
            Semester=Sem;
            this->Declared_Subjects=Declared_Subjects;
            
            vector<PassedSubjectsAndTheirGrades>::iterator it2;
            for(it2=Passed_Subjects.begin();it2!=Passed_Subjects.end();it2++){
              if(it2->grade>10.0 || it2->grade<5.0 ) { //Exception to not have 10.1 or 4.9 or 7.01 ...   || (int)(it2->grade*10)%10!=0
                 throw invalid_argument("Grades of passed subjects must be between 5.0 and 10.0!");}
                this->Passed_Subjects.push_back(*it2);  
            }
    }
        
  //Destructor//      
         Student::~Student(){
	 	    delete AM;	
        }
     
        void Student::setAM(char* A_M){
            if (AM != nullptr) {    // To not have the error:free():double free detected in tcache 2 Aborted (core dumped)
            delete[] AM; 
        }
            AM = new char[strlen(A_M) + 1];
            strcpy(AM, A_M);
        }
	 
	 
	 //Getters-Setters//
	char* Student::getAM() const
        {return AM;}	 
	
	
	void Student::setName(const string& Name)
	    {this->Name=Name;}
	
	string Student::getName() const
        {return Name;}
     	
    
	 void Student::setSemester(unsigned int Semester)	
        {this->Semester=Semester;}
     	
     unsigned int Student::getSemester()const
        {return Semester;}   
        
        
     void Student::setDeclaredSubjects(const vector<Subject*>& Declared_Subjects){
            this->Declared_Subjects=Declared_Subjects;
     }  
        
     
     const vector<Subject*>& Student::getDeclaredSubjects() const{
         return Declared_Subjects;
     }
     
    void Student::setPassedSubjects(const vector<PassedSubjectsAndTheirGrades>& Passed_Subjects){
              vector<PassedSubjectsAndTheirGrades>::const_iterator it2;
            for(it2=Passed_Subjects.begin();it2!=Passed_Subjects.end();it2++){
              if(it2->grade>10.0 || it2->grade<5.0 ){  //Exception to not have 10.1 or 4.9 or ... ,  if we do not want this:7.01->  || (int)(it2->grade*10)%10!=0
                 throw invalid_argument("Grades of passed subjects must be between 5.0 and 10.0!");
              }else{
                this->Passed_Subjects.push_back(*it2);  
            }
        }    
     }  
        
     
     const vector<PassedSubjectsAndTheirGrades>& Student::getPassedSubjects() const{
         return Passed_Subjects;
     }
     
     
        
    void Student::Print(ostream& ch) const{
            ch<<AM<<"    "<<Name<<"     "<<Semester<<endl<<endl;
    }     
     
     void Student::IncreaseSem(){
        ++Semester;
    }    
        
        
    /*    
    Student& Student::operator+=(int i){
        Semester+=i;
        return *this;
    }    
        
        
    Student& Student::operator-=(int i){
        Semester-=i;
        return *this;
    }    
    */
    
    
    //Operators Overloading//
     Student& Student::operator+=(Subject* Sub){
        for(const auto& s:Declared_Subjects){ //for-each Java style(we can also use an iterator such as the beneath function)
            if(s!=Sub){
                Declared_Subjects.push_back(Sub);}
        }
        return *this;
     }
    
     Student& Student::operator=(const Student& obj){
        if(this!=&obj){
            delete[] AM;
            AM=new char[strlen(obj.AM)+1];
            strcpy(AM,obj.AM);
            
            Name=obj.Name;
            Semester=obj.Semester;
            
        Declared_Subjects.clear();
        //for with iterator,to traverse the vector
        vector<Subject*>::const_iterator it;
        for(it=obj.Declared_Subjects.begin();it!=obj.Declared_Subjects.end();it++){
            Declared_Subjects.push_back(*it); //the **it it's the Subject object, and the *it it's a copy of the object
        }    
            
        Passed_Subjects.clear();
        //for with iterator,to traverse the vector
        vector<PassedSubjectsAndTheirGrades>::const_iterator it2;
        for(it2=obj.Passed_Subjects.begin();it2!=obj.Passed_Subjects.end();it2++){
              PassedSubjectsAndTheirGrades passedSubjects;
              passedSubjects.subject_name=it2->subject_name;
              
              if(it2->grade>10.0 || it2->grade<5.0 ){  
                 throw invalid_argument("Grades of passed subjects must be between 5.0 and 10.0!");
              }else{
                  passedSubjects.grade=it2->grade;
            }
              
              Passed_Subjects.push_back(passedSubjects);
        }    
    }
     return *this;
     }
    
     
        bool Student::operator==(const Student &obj)const{
        if(Semester==obj.Semester)
            return true;
        else
                return false;
        }
    
        bool Student::operator!=(const Student &obj)const{
        if(Semester!=obj.Semester)
            return true;
        else
                return false;
        }
        
        
        bool Student::operator<(const Student &obj)const{
        if(Semester<obj.Semester)
            return true;
        else
                return false;
        }
     
        bool Student::operator<=(const Student &obj)const{
        if(Semester<=obj.Semester)
            return true;
        else
                return false;
        }
        
        
        bool Student::operator>(const Student &obj)const{
        if(Semester>obj.Semester)
            return true;
        else
                return false;
        }
        
        bool Student::operator>=(const Student &obj)const{
        if(Semester>=obj.Semester)
            return true;
        else
                return false;
        }
        
        
        ostream& operator<<(ostream& cout,const Student& J){
        cout<<"ΑΜ του φοιτητή: "<<J.getAM()<<".\n"<<"--- Αναλυτική Βαθμολογία: ---"<<endl;
        
        vector<PassedSubjectsAndTheirGrades>::const_iterator it; 
        for(it=J.getPassedSubjects().begin();it!=J.getPassedSubjects().end();it++){
              cout<<"Subject name: "<<it->subject_name<<"-> Subject Grade: "<<it->grade<<endl;
        }    
        
        double sum=0.0;
        double average_value=0.0;
        
        for(it=J.getPassedSubjects().begin();it!=J.getPassedSubjects().end();it++){
              sum+=it->grade;
        }    
        
        average_value=sum/(J.getPassedSubjects().size());
        cout<<"Average value of passed subjects: "<<average_value<<endl;
        
        return cout;
        }
        
        
