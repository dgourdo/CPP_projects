#include "Subject.h"
#include "Student.h"

#include <iostream> 
#include <string.h>
#include <iterator>
#include <fstream>

int main(int argc,char **argv)
   {
       cout<<"\tΕΡΓΑΣΙΑ 3"<<endl<<"\tΣχέσεις κλάσεων, Υπερφόρτωση Τελεστών"<<endl<<endl;
    
    char *AAM = new char[15];  
    strcpy(AAM,"ice20390043");
    string name1="Δημήτριος Γουρδομιχάλης";
    /*Student A=Student(AAM,name1,6);
    cout<<"AM:"<<A.getAM()<<"  "<<"Name:"<<A.getName()<<"  "<<"Semester:"<<A.getSemester()<<endl;
    cout<<endl;
    */
    
    char *BAM = new char[15];  
    strcpy(BAM,"ice22390043");
    string name2="Γρηγόριος Αντωνίου";
    Student B=Student(BAM,name2);
    cout<<"AM:"<<B.getAM()<<"  "<<"Name:"<<B.getName()<<"  "<<"Semester:"<<B.getSemester()<<endl;
    cout<<endl;
    
  
    cout<<"Copy Constructor"<<endl;
    Student C=B;
    cout<<"AM:"<<C.getAM()<<"  "<<"Name:"<<C.getName()<<"  "<<"Semester:"<<C.getSemester()<<endl;
	cout<<endl;
    
    
    Student E=B; //Copy Constructor
    cout<<"Setters-Getters"<<endl;
    char *EAM = new char[15];  
    strcpy(EAM,"ice183900005");
    
    E.setAM(EAM);                     
    cout<<E.getAM()<<endl;         
    E.setName("Αναστάσιος Γεωργιάδης");
    cout<<E.getName()<<endl;
    E.setSemester(5);	
    cout<<E.getSemester()<<endl<<endl; 
    
    
    cout<<"Εκτύπωση σε κανάλι,όλων των χαρακτηριστικών σε μία γραμμή."<<endl; 
    char *FAM = new char[15];  
    strcpy(FAM,"ice20390003");
    string name3="Στέλιος Νίκας";
    Student F=Student(FAM,name3,3);
    F.Print(cout);
     
    cout<<"Αύξηση του τρέχοντος εξαμήνου κατά 1 με χρήση του τελεστή προαύξησης."<<endl;
    cout<<"Εξάμηνο πριν την αλλαγή:"<<B.getSemester()<<endl;
    B.IncreaseSem();
    cout<<"Εξάμηνο μετά την αλλαγή->";
    cout<<"Τρέχον εξάμηνο φοιτητή:"<<B.getSemester()<<endl<<endl;
    
    /*cout<<"Αλλαγή του εξαμήνου με την χρήση των τελεστών “+=” και “-=”."<<endl;
    cout<<"1)Εξάμηνο πριν την αλλαγή:"<<F.getSemester()<<endl;
    F-=2;
    cout<<"Εξάμηνο μετά την αλλαγή->";
    cout<<"Τρέχον εξάμηνο φοιτητή:"<<F.getSemester()<<endl<<endl;
    

    cout<<"2)Εξάμηνο πριν την αλλαγή:"<<A.getSemester()<<endl;
    A+=4;
    cout<<"Εξάμηνο μετά την αλλαγή->";
    cout<<"Τρέχον εξάμηνο φοιτητή:"<<A.getSemester()<<endl;
    */
    // -------------------------------------------------------------------------
    //Exercise3
    
    string SubSem1="Χειμερινό";
    string SubSem2="Εαρινό";
    
    string SubCode1="0001";
    string LSub1="Αντικειμενοστρεφής Προγραμματισμός";
    Subject CPP(SubCode1,LSub1,4,SubSem2);
    
    string SubCode2="0002";
    string LSub2="Μεθοδολογίες Ανάπτυξης Εφαρμογών";
    Subject MAE(SubCode2,LSub2,3,SubSem1);
    
    
    string SubCode3="0003";
    string LSub3="Ψηφιακές Επικοινωνίες";
    Subject PSE(SubCode3,LSub3,4,SubSem2);
    PSE.setHours_per_week(4);
    
    
    string SubCode4="0004";
    string LSub4="Ασφάλεια";
    Subject Security(SubCode4,LSub4,5,SubSem2);
    
    vector<Subject*> DeclaredSubjects1;
    DeclaredSubjects1.push_back(&PSE);
    DeclaredSubjects1.push_back(&Security);
    
    vector<PassedSubjectsAndTheirGrades> PassedSubjects1;
    
    PassedSubjectsAndTheirGrades sub1;
    sub1.subject_name="Αντικειμενοστρεφής Προγραμματισμός";
    sub1.grade=5.0;
    PassedSubjects1.push_back(sub1);
    
    PassedSubjectsAndTheirGrades sub2;
    sub2.subject_name="Μεθοδολογίες Ανάπτυξης Εφαρμογών";
    sub2.grade=9.0;
    PassedSubjects1.push_back(sub2);
    
    Student A=Student(AAM,name1,6,DeclaredSubjects1,PassedSubjects1);
    
    //-------------------------------------------------------------------------
       
    string SubCode5="0005";
    string LSub5="Κατανεμημένα Συστήματα";
    Subject DS(SubCode5,LSub5,3,SubSem2);
    
    string SubCode6="0006";
    string LSub6="ΑΣΠΣ";
    Subject ASPS(SubCode6,LSub6,4,SubSem1);
    
    string SubCode7="0007";
    string LSub7="Αλγόριθμοι και Πολυπλοκότητα";
    Subject AP(SubCode7,LSub7,4,SubSem1);
    
    vector<Subject*> DeclaredSubjects10;
    DeclaredSubjects10.push_back(&DS);
    
    vector<PassedSubjectsAndTheirGrades> PassedSubjects10;
    
    PassedSubjectsAndTheirGrades sub10;
    sub10.subject_name="ΑΣΠΣ";
    sub10.grade=7.5;
    PassedSubjects10.push_back(sub10);
    
    PassedSubjectsAndTheirGrades sub11;
    sub11.subject_name="Αλγόριθμοι και Πολυπλοκότητα";
    sub11.grade=6.0;
    PassedSubjects10.push_back(sub11);
    
    char *ZAM = new char[15];  
    strcpy(ZAM,"ice20390255");
    string name10="Γεώργιος Γεωργίου";
    Student Z=Student(ZAM,name10,8,DeclaredSubjects10,PassedSubjects10);
    
    string SubCode8="0008";
    string LSub8="Μεταγλωττιστές";
    Subject Compilers(SubCode8,LSub8,5,SubSem2);
    Z+=&Compilers;
    
    
    Student CopyOfZ=Z;
    
    if(Z==A)
     cout<<"Student A and Student Z are in the same Semester."<<endl;
    else if(Z>A)
     cout<<"Semester of Student Z > Semester of Student A."<<endl;
    else if(Z<A)
     cout<<"Semester of Student Z < Semester of Student A."<<endl;
    
    cout<<endl;
     cout<<A<<endl;
    cout<<endl;
     cout<<Z<<endl;
     cout<<endl;
     
    cout<<"Information of Student CopyOfZ(checks if operator works)."<<endl;
    cout<<CopyOfZ.getAM()<<endl; 
    cout<<CopyOfZ.getName()<<endl; 
    cout<<CopyOfZ.getSemester()<<endl; 
    cout<<CopyOfZ<<endl;
    
    
      /*
        vector<Subject*>::const_iterator it1; 
        for(it1=CopyOfZ.getDeclaredSubjects().begin();it1!=CopyOfZ.getDeclaredSubjects().end();it1++){
              cout<<"Subject name: "<<(*it1)->getTitle() <<endl;
        }    
      
      
        vector<PassedSubjectsAndTheirGrades>::const_iterator it; 
        for(it=CopyOfZ.getPassedSubjects().begin();it!=CopyOfZ.getPassedSubjects().end();it++){
              cout<<"Subject name: "<<it->subject_name<<"-> Subject Grade: "<<it->grade<<endl;
        }    
    */
    
    
    vector<Subject*> subjects;
    subjects.push_back(&CPP);
    subjects.push_back(&MAE);
    subjects.push_back(&PSE);
    subjects.push_back(&Security);
    subjects.push_back(&ASPS);
    subjects.push_back(&AP);
    subjects.push_back(&Compilers);
    subjects.push_back(&DS);
    
    
    ofstream file1("/home/dgour/Desktop/C++/2023/erg3/subjects.csv");
    
    if(!file1.is_open()){
        cout<<"ERROR!Cannot open the file.";
    }
    
    file1<<"Subject Code,Subject Name,Hours per week,Semester"<<endl; //This is the header of the file
    
    vector<Subject*>::iterator subject_iterator;
    for(subject_iterator=subjects.begin();subject_iterator!=subjects.end();subject_iterator++){
              file1<<(*subject_iterator)->getSubjectcode()<<","<<(*subject_iterator)->getLSubject()<<","<<(*subject_iterator)->getHours_per_week()<<","<<(*subject_iterator)->getSubjectSemester()<<","<<endl;
    }
              
    file1.close();
    
    
    vector<Student*> students;
    students.push_back(&A);
    students.push_back(&Z);
    
    
    ofstream file2("/home/dgour/Desktop/C++/2023/erg3/students.csv");
    
    if(!file2.is_open()){
        cout<<"ERROR!Cannot open the file.";
    }
    
    file2<<"AM,Name,Semester,Declared Subjects,Passed Subjects"<<endl; //This is the header of the file
    
        
    vector<Student*>::iterator student_iterator;
    for(student_iterator=students.begin();student_iterator!=students.end();student_iterator++){
              file2<<(*student_iterator)->getAM()<<","<<(*student_iterator)->getName()<<","<<(*student_iterator)->getSemester()<<",";
    }
        
        const vector<Subject*>& Declared_Subjects = (*student_iterator)->getDeclaredSubjects();
        for (auto it1 = Declared_Subjects.begin(); it1 != Declared_Subjects.end(); ++it1) {
            file2 << (*it1)->getSubjectcode()<<",";
        }

        file2 << ",";

        const vector<PassedSubjectsAndTheirGrades>& passedSubjects = (*student_iterator)->getPassedSubjects();
        for (auto it2 = passedSubjects.begin(); it2 != passedSubjects.end(); ++it2) {
            file2 << it2->subject_name << ":" << it2->grade<<",";
        }

        file2 << endl;
        
    file2.close();
    
    
    
 return 0;       
}


/*Terminal:
 g++ -c Subject.cpp -o Subject.o
 g++ -c Student.cpp -o Student.o
 g++ Student.o Subject.o exercise3.cpp -o exercise3
 ./exercise3
*/
