 
#include <stdio.h>
#include <stdlib.h>
#define SIZESTUDENT 10
#define SIZETEACHER 10
#define SIZESUBJECT 10

int menuGeneral();

int menuStudentCadastre();
int studentCadastre();
int studentListCadastre();
int studentDelete();
int studentUpdate();

int menuTeacherCadastre();
int teacherCadastre();
int teacherListCadastre();
int teacherDelete();
int teacherUpdate();

int menuSubjectCadastre();
int subjectCadastre();
int subjectListCadastre();
int subjectStudentCadastre();
int subjectDelete();
int subjectUpdate();

int menuReports();
int reportStudentsGender();
int reportTeachersGender();
int reportPeopleBirthdayMonth();
int reportSubjectListName();
int reportSubjectOverForty();
//int reportPeopleStringName(); 
int reportSubjectListNameRegistred();
int reportStudentsSubject(); 
int reportStudentNameOrder();
int reportStudentBirthdateOrder();
int reportTeacherNameOrder();
int reportTeacherBirthdateOrder();


typedef struct data {
  int day;
  int month; 
  int year; 
} BirthDate; 

typedef struct student{ 
  char name[50];
  char gender;
  int registration; 
  BirthDate birthdate; 
  char CPF[15];
} Student; 

typedef struct teacher{
  char name [50];
  char gender;
  int registration; 
  BirthDate birthdate; 
  char CPF[15];
}Teacher;

typedef struct subject {
  char name[50];
  int semester;
  int code; 
  int vacancies;
  Teacher teacher;
  Student student;
}Subject; 

Student studentRegistration; 
Student listStudent[SIZESTUDENT]; 
Teacher teacherRegistration;
Teacher listTeacher[SIZETEACHER]; 
Subject subjectRegistration;
Subject listSubject[SIZESUBJECT]; 
int qty_student = 0; 
int qty_teacher = 0;
int qty_subject = 0;
int deleteRegistration;


int main() {
    int Choice, MenuCadastre;
    int exitMenu = 0;
    
    while(!exitMenu){
      
      int exitStudent = 0;
      int exitTeacher = 0;
      int exitSubject = 0;
      int exitReports = 0;
      
      printf("\nWelcome to School Project of the discipline INF029\n");
      
      MenuCadastre =  menuGeneral(Choice);
      switch(MenuCadastre){
        
        case 1:{
          
          while(!exitStudent){
            int choiceMenuStudent, menuStudent;
            menuStudent = menuStudentCadastre(choiceMenuStudent);
            
            switch(menuStudent){
              case 1:{ 
                studentCadastre();
              break;
              }
              case 2:{
                studentListCadastre();
              break;
              } 
              case 3:{
                studentDelete();
              break;
              }
              case 4:{
                studentUpdate();
              break;
              }
              case 5:{
                exitStudent = 1;
              break;
              }
            }
          }
        break;
        }
        case 2: {
          
          while(!exitTeacher){
            int choiceMenuTeacher, menuTeacher;
            menuTeacher = menuTeacherCadastre(choiceMenuTeacher);
            
            switch(menuTeacher){
              case 1:{ 
                teacherCadastre();
              break;
              }
              case 2:{
                teacherListCadastre();
              break;
              } 
              case 3:{
                teacherDelete();
              break;
              }
              case 4:{
                teacherUpdate();
              break;
              }
              case 5:{
                exitTeacher = 1;
              break;
              }
            }
          }
          
        break;
        }
        case 3: {
          while(!exitSubject){
            printf("Discipline Cadastre");
            while(!exitSubject){
            int choiceMenuSubject, menuSubject;
            menuSubject = menuSubjectCadastre(choiceMenuSubject);
            
            switch(menuSubject){
              case 1:{ 
                subjectCadastre();
              break;
              }
              case 2:{
                subjectListCadastre();
              break;
              } 
              case 3:{
                subjectDelete();
              break;
              }
              case 4:{
                subjectUpdate();
              break;
              }
              case 5:{
                subjectStudentCadastre();
              break;
              }
              case 6:{
                exitSubject = 1;
              break;
              }
            }
          }
          }
        break;
        }
        case 4: {
          while(!exitReports){
            printf("Reports");
            int choiceMenuReports, menuReport;
            menuReport = menuReports(choiceMenuReports);
            switch(menuReport){
              case 1:{
                reportStudentsGender();
              break;
              }
              case 2:{
                reportStudentNameOrder();
              break;
              }
              case 3:{
                reportStudentBirthdateOrder();

              break;
              }
              case 4:{
                reportTeachersGender();
              break;
              }
              case 5:{
                reportTeacherNameOrder();
              break;
              }
              case 6:{
                reportTeacherBirthdateOrder();
              break;
              }
              case 7:{
                reportSubjectListName();
              break;
              }
              case 8:{
                reportSubjectListNameRegistred();
              break;
              }
              case 9:{
                reportPeopleBirthdayMonth();
              break;
              }
              case 10:{
                reportSubjectOverForty();
              break;
              }
              case 11:{
               //reportPeopleStringName();
              break;
              }
              
            }
            
          }
          
        break;
        }
        case 5: {
          printf("System done...");
          exitMenu=1;
        break;
        }
      }
    }
}
  
//slowly and on 

int menuGeneral(int option){
  
    printf("\nMenu of Cadastre \n {1} Student\n {2} Teacher \n {3} Discipline  \n {4} Reports \n {5} Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    return option;
}
int menuStudentCadastre(int optionS){
    printf("\n\nMenu of Student Cadastre \n {1} Cadastre \n {2} List \n {3} Remove students by registration number \n {4} Update Students\n {5} Exit\n");
    printf("Enter your option: ");
    scanf("%d", &optionS);
    return optionS;
}
int studentCadastre(){
  setbuf(stdin, 0);
  if (qty_student<SIZESTUDENT){
    printf("\nSTUDENT CADASTRE");
    printf("\nEnter registration number: ");
    scanf("%d", &listStudent[qty_student].registration);
    for(int i =0; i<qty_student; i++){
      while (listStudent[i].registration == listStudent[qty_student].registration){
        printf("\nStudent has been registred");
        printf("\nEnter registration number: ");
        scanf("%d", &listStudent[qty_student].registration);
      }
    }
    getchar();
    printf("Enter name: ");
    fgets(listStudent[qty_student].name, 50, stdin);
    printf("Enter birthDate: ");
    printf("\nDay: ");
    scanf("%d", &listStudent[qty_student].birthdate.day);
    getchar();
      while(listStudent[qty_student].birthdate.day<=0 ||listStudent[qty_student].birthdate.day>30){
        printf("The format day is incorrect");
        printf("\nDay: ");
        scanf("%d", &listStudent[qty_student].birthdate.day);
      }
    printf("Month: ");
    scanf("%d", &listStudent[qty_student].birthdate.month);
    getchar();
     while(listStudent[qty_student].birthdate.month<=0 || listStudent[qty_student].birthdate.month>12){
      printf("The format month is incorrect");
      printf("\nMonth: ");
      scanf("%d", &listStudent[qty_student].birthdate.month);
      }
    printf("Year: ");
    scanf("%d", &listStudent[qty_student].birthdate.year);
    getchar();
      while(listStudent[qty_student].birthdate.year<1900 || listStudent[qty_student].birthdate.year>2023){
        printf("The format year is incorrect");
        printf("\nYear: ");
        scanf("%d", &listStudent[qty_student].birthdate.year);
      }
    printf("Enter gender, set F to feminine and M to masculine: ");
    scanf("%c", &listStudent[qty_student].gender);
    getchar();
    printf("Enter CPF: ");
    
    fgets(listStudent[qty_student].CPF, 11, stdin);
    qty_student++;
  }
  else{
    printf("It's not possible to register new students now, the limit has been exceeded.\n");
  }
}
int studentListCadastre(){
  printf("\nList of registered students");
  printf("\nNumber of registered students: %d", qty_student);
  if(qty_student<1){
    printf("\nIt doesn't have any students registered");
  }
  else{
    for(int i = 0; i< qty_student; i++){
      printf("\nStudent %d", i+1);
      printf("\nRegistration number: %d", listStudent[i].registration);
      printf("\nName: %s", listStudent[i].name);
      printf("Bithdate: %d/%d/%d ", listStudent[i].birthdate.day, listStudent[i].birthdate.month, listStudent[i].birthdate.year);
      printf("\nCPF: %s", listStudent[i].CPF);
      if(listStudent[i].gender == 'F' || listStudent[i].gender =='f'){
        printf("Gender: Feminine\n");
      }
      else if (listStudent[i].gender =='M' || listStudent[i].gender =='m'){
        printf("Gender: Masculine\n");
      }
    }
  }
}
int studentDelete(){
  printf("\nDelete students by registration number");
  if(qty_student < 1){
    printf("\nDoes not have any registred students");
  }
  else{
    printf("\nEnter the registration number: "); 
    scanf("%d", &deleteRegistration);
    
    for(int i = 0; i< qty_student; i++){
      if (deleteRegistration == listStudent[i].registration){
        for(int j = i; j < qty_student-1; j++){
          listStudent[j].registration = listStudent[j+1].registration;
          listStudent[j].name[i] = listStudent[j+1].name[i];
          listStudent[j].gender = listStudent[j+1].gender;
          listStudent[j].CPF[i] = listStudent[j+1].CPF[i];
          listStudent[j].birthdate.day = listStudent[j].birthdate.day ;
          listStudent[j].birthdate.month = listStudent[j+1].birthdate.month;
          listStudent[j].birthdate.year = listStudent[j+1].birthdate.year ;
        }
        qty_student--;
        printf("Student has been removed from the registration list\n");
      }
      else{
        printf("\nStudent has not been found");
      }
    }
  }
}
int studentUpdate(){
  printf("\nUpdate the informations of students");
  printf("\nEnter registration number:"); 
  scanf("%d", &deleteRegistration);
  int i, itemUpdate;      
  for(i = 0; i< qty_student; i++){
    if (deleteRegistration == listStudent[i].registration){
      printf("\nWhich item do you want to update?\n");
      printf("{1} - Registration number\n");
      printf("{2} - Birthdate\n");
      printf("{3} - Gender\n");
      printf("{4} - CPF\n");
      printf("{5} - Name\n");
      printf("{6} - Exit");
      printf("\nEnter item option: "); 
      scanf("%d", &itemUpdate);
        switch(itemUpdate){
          case 1:{
            printf("\nEnter new registration number: ");
            scanf("%d", &listStudent[i].registration);
            getchar();
            for(int j=0; i<qty_student; j++){
              while (listStudent[i].registration == listStudent[j].registration){
                printf("\nStudent has been registred");
                printf("\nEnter registration number: ");
                scanf("%d", &listStudent[i].registration);
              }
            }
            break;
          }
          
          case 2:{
            printf("Enter birthDate: ");
            printf("\nDay: ");
            scanf("%d", &listStudent[i].birthdate.day);
            getchar();
              while(listStudent[i].birthdate.day<=0 ||listStudent[i].birthdate.day>30){
                printf("The format day is incorrect");
                printf("\nDay: ");
                scanf("%d", &listStudent[i].birthdate.day);
              }
            printf("Month: ");
            scanf("%d", &listStudent[i].birthdate.month);
            getchar();
             while(listStudent[i].birthdate.month<=0 || listStudent[i].birthdate.month>12){
              printf("The format month is incorrect");
              printf("\nMonth: ");
              scanf("%d", &listStudent[i].birthdate.month);
              }
            printf("Year: ");
            scanf("%d", &listStudent[i].birthdate.year);
            getchar();
              while(listStudent[i].birthdate.year<1900 || listStudent[i].birthdate.year>2023){
                printf("The format year is incorrect");
                printf("\nYear: ");
                scanf("%d", &listStudent[i].birthdate.year);
              }
            getchar();
            break;
          }
          case 3:{
            printf("\nEnter gender, set F to feminine and M to masculine: ");
            getchar();
            scanf("%c", &listStudent[i].gender);
            getchar();
            break;
          }
          case 4:{
            printf("\nEnter CPF: ");
            fgets(listStudent[i].CPF, 11, stdin);
            break;
          }
          case 5:{
            printf("\nEnter name: ");
            getchar();
            fgets(listStudent[i].name, 50, stdin);
            getchar();
            break;
          }
          case 6:{
            break;
          }
        }
      printf("Update is done\n");
    }
    else{
      printf("\nRegistration number was not found\n");
    }
  }
}


int menuTeacherCadastre(int optionS){
    printf("\nMenu of Teacher Cadastre\n {1} Cadastre \n {2} List \n {3} Remove Teachers by registration number \n {4} Update Teachers \n {5} Exit\n");
    printf("Enter your option: ");
    scanf("%d", &optionS);
    return optionS;
}

int teacherCadastre(){
  if (qty_teacher<SIZETEACHER){
    setbuf(stdin, 0);
    printf("\nEnter registration number: ");
    scanf("%d", &listTeacher[qty_teacher].registration);
    for(int i =0; i<qty_teacher; i++){
      while (listTeacher[i].registration == listTeacher[qty_teacher].registration){
        printf("\nTeacher has been registred");
        printf("\nEnter registration number: ");
        scanf("%d", &listTeacher[qty_teacher].registration);
      }
    }
    getchar();
    printf("Enter name: ");
    fgets(listTeacher[qty_teacher].name, 50, stdin);
    printf("Enter birthDate: ");
    printf("\nDay: ");
    scanf("%d", &listTeacher[qty_teacher].birthdate.day);
    getchar();
      while(listTeacher[qty_teacher].birthdate.day<=0 ||listTeacher[qty_teacher].birthdate.day>30){
        printf("The format day is incorrect");
        printf("\nDay: ");
        scanf("%d", &listTeacher[qty_teacher].birthdate.day);
      }
    printf("Month: ");
    scanf("%d", &listTeacher[qty_teacher].birthdate.month);
    getchar();
     while(listTeacher[qty_teacher].birthdate.month<=0 || listTeacher[qty_teacher].birthdate.month>12){
      printf("The format month is incorrect");
      printf("\nMonth: ");
      scanf("%d", &listTeacher[qty_teacher].birthdate.month);
      }
    printf("Year: ");
    scanf("%d", &listTeacher[qty_teacher].birthdate.year);
    getchar();
      while(listTeacher[qty_teacher].birthdate.year<1900 || listTeacher[qty_teacher].birthdate.year>2023){
        printf("The format year is incorrect");
        printf("\nYear: ");
        scanf("%d", &listTeacher[qty_teacher].birthdate.year);
      }
    setbuf(stdin, 0);
    printf("Enter gender, set F to feminine and M to masculine: ");
    scanf("%c", &listTeacher[qty_teacher].gender);
    
    
    printf("Enter CPF: ");
    getchar();
    fgets(listStudent[qty_teacher].CPF, 11, stdin);
    qty_teacher++;
  }
  else{
    printf("It's not possible to register new teachers now, the limit has been exceeded.\n");
  }
}

int teacherListCadastre(){
  printf("\nList of registered teacher");
  printf("\nNumber of registered teacher: %d", qty_teacher);
  if(qty_teacher<1){
    printf("It doesn't have teacher registered");
  }
  else{
    for(int i = 0; i< qty_teacher; i++){
      printf("\nTeacher %d", i+1);
      printf("\nRegistration number: %d", listTeacher[i].registration);
      printf("\nName: %s", listTeacher[i].name);
      printf("Birthdate: %d/%d/%d", listTeacher[i].birthdate.day, listTeacher[i].birthdate.month, listTeacher[i].birthdate.year);
      printf("\nCPF: %s", listTeacher[i].CPF);
      if(listTeacher[i].gender == 'F' || listTeacher[i].gender =='f'){
        printf("\nGender: Feminine\n");
      }
      else if (listTeacher[i].gender =='M' || listTeacher[i].gender =='m'){
        printf("\nGender: Masculine\n");
      }
    }
  }
}

int teacherDelete(){
  printf("\nDelete teachers by registration number");
  if(qty_teacher < 1){
    printf("\nDoes not have registred teachers\n");
  }
  else{
    printf("\nEnter the registration number: "); 
    scanf("%d", &deleteRegistration);
    
    for(int i = 0; i< qty_teacher; i++){
        if (deleteRegistration == listTeacher[i].registration){
          for(int j = i; j < qty_teacher-1; j++){
            listTeacher[j].registration = listTeacher[j+1].registration;
            listTeacher[j].name[i] = listTeacher[j+1].name[i];
            listTeacher[j].gender = listTeacher[j+1].gender;
            listTeacher[j].CPF[i] = listTeacher[j+1].CPF[i];
            listTeacher[j].birthdate.day = listTeacher[j].birthdate.day ;
            listTeacher[j].birthdate.month = listTeacher[j+1].birthdate.month;
            listTeacher[j].birthdate.year = listTeacher[j+1].birthdate.year ;
          }
          qty_teacher--;
          printf("Teacher has been removed from the registration list.\n");
        }
        else{
          printf("\nTeacher has not been found.\n");
        }
    }
  }
  
}

int teacherUpdate(){
  printf("\nUpdate the informations of teachers");
  printf("\nEnter registration number:"); 
  scanf("%d", &deleteRegistration);
  int i, itemUpdate;      
  for(i = 0; i< qty_teacher; i++){
    if (deleteRegistration == listTeacher[i].registration){
      printf("\nWhich item do you want to update?\n");
      printf("{1} - Registration number\n");
      printf("{2} - Birthdate\n");
      printf("{3} - Gender\n");
      printf("{4} - CPF\n");
      printf("{5} - Name\n");
      printf("{6} - Exit");
      printf("\nEnter item option: "); 
      scanf("%d", &itemUpdate);
        switch(itemUpdate){
          case 1:{
            printf("\nEnter new registration number: ");
            scanf("%d", &listTeacher[i].registration);
            getchar();
            for(int j=0; i<qty_teacher; j++){
              while (listTeacher[i].registration == listTeacher[j].registration){
                printf("\nTeacher has been registred");
                printf("\nEnter registration number: ");
                scanf("%d", &listTeacher[i].registration);
              }
            }
            break;
          }
          
          case 2:{
            printf("Enter birthDate: ");
            printf("\nDay: ");
            scanf("%d", &listTeacher[i].birthdate.day);
            getchar();
              while(listTeacher[i].birthdate.day<=0 ||listTeacher[i].birthdate.day>30){
                printf("The format day is incorrect");
                printf("\nDay: ");
                scanf("%d", &listTeacher[i].birthdate.day);
              }
            printf("Month: ");
            scanf("%d", &listTeacher[i].birthdate.month);
            getchar();
             while(listTeacher[i].birthdate.month<=0 || listTeacher[i].birthdate.month>12){
              printf("The format month is incorrect");
              printf("\nMonth: ");
              scanf("%d", &listTeacher[i].birthdate.month);
              }
            printf("Year: ");
            scanf("%d", &listTeacher[i].birthdate.year);
            getchar();
              while(listTeacher[i].birthdate.year<1900 || listTeacher[i].birthdate.year>2023){
                printf("The format year is incorrect");
                printf("\nYear: ");
                scanf("%d", &listTeacher[i].birthdate.year);
              }
            getchar();
            break;
          }
          case 3:{
            printf("\nEnter gender, set F to feminine and M to masculine: ");
            getchar();
            scanf("%c", &listTeacher[i].gender);
            getchar();
            break;
          }
          case 4:{
            printf("\nEnter CPF: ");
            fgets(listTeacher[i].CPF, 11, stdin);
            break;
          }
          case 5:{
            printf("\nEnter name: ");
            getchar();
            fgets(listTeacher[i].name, 50, stdin);
            getchar();
            break;
          }
          case 6:{
            break;
          }
        }
      printf("Update is done\n");
    }
    else{
      printf("\nRegistration number was not found\n");
    }
  }
}

int menuSubjectCadastre(int optionS){
    printf("\nMenu of Subject Cadastre \n {1} Cadastre \n {2} List \n {3} Remove subjects by code \n {4} Update subjects\n {5} Cadastre students in a subject \n {6} Exit\n");
    printf("\nEnter your option: ");
    scanf("%d", &optionS);
    return optionS;
}
int subjectCadastre(){
  setbuf(stdin, 0);
  if (qty_subject<SIZESUBJECT){
    printf("\nEnter subject code: ");
    scanf("%d", &listSubject[qty_subject].code);
    getchar();
    printf("Enter subject name: ");
    fgets(listSubject[qty_subject].name, 50, stdin);
    getchar();
    printf("Enter the semester of subject: ");
    scanf("%d", &listSubject[qty_subject].semester);
    getchar();
    printf("Enter vacancies number: ");
    scanf("%d", &listSubject[qty_subject].vacancies);
    getchar();
    printf("Enter teacher name: ");
    fgets(listSubject[qty_subject].teacher.name, 50, stdin);
    getchar();
    qty_subject++;
  }
  else{
    printf("It's not possible to register new subjects now, the limit has been exceeded.\n");
  }
  return qty_subject;
}
int subjectListCadastre(){
  
  printf("\nList of subjects registred");
  printf("\nNumber of registered subjects: %d", qty_subject);
  if(qty_subject < 1){
    printf("\nIt doesn't have any subjects registred.");
  }
  else{
    for(int i = 0; i < qty_subject; i++){
      printf("\nSubject %d", i+1 );
      printf("\nCode: %d", listSubject[i].code);
      printf("\nName: %s", listSubject[i].name);
      printf("\nSemester: %d", listSubject[i].semester);
      printf("\nVacancies: %d", listSubject[i].vacancies);
      printf("\nSubject Teacher: %s", listSubject[qty_subject].teacher.name);
    }
  }
}
int subjectDelete(){
  printf("\nDelete subjects by code");
  if(qty_subject < 1){
    printf("Does not have registred subjects\n");
  }
  else{
    printf("\nRemove subjects");
    printf("Enter code: "); 
    scanf("%d", &deleteRegistration);
    
    for(int i = 0; i< qty_subject; i++){
        if (deleteRegistration == listSubject[i].code){
          for(int j = i; j < qty_subject-1; j++){
            listSubject[j].code = listSubject[j+1].code;
            listSubject[j].name[i] = listSubject[j+1].name[i];
            listSubject[j].semester = listSubject[j+1].semester;
            listSubject[j].vacancies = listSubject[j+1].vacancies;
            listSubject[j].teacher.name[i] = listSubject[j].teacher.name[i];
          }
          qty_subject--;
          printf("\nSubject has been removed from the registration list");
        }
        else{
          printf("\nSubject has not been found");
        }
    }
  }
}


int subjectUpdate(){
   printf("\nUpdate informations of subject");
    printf("\nEnter code:"); 
    scanf("%d", &deleteRegistration);
    int i, itemUpdate;      
    setbuf(stdin, 0);
    for(i = 0; i< qty_subject; i++){
      if (deleteRegistration == listSubject[i].code){
        printf("Which item do you want to update?\n");
        printf("{1} - Code\n");
        printf("{2} - Name of subject\n");
        printf("{3} - Semester\n");
        printf("{4} - Vacancies number\n");
        printf("{5} - TeacherName\n");
        printf("{6} - Exit");
        scanf("%d", &itemUpdate);
          switch(itemUpdate){
            case 1:{
              printf("\nEnter subject code: ");
              scanf("%d", &listSubject[qty_subject].code);
              getchar();
            break;
            }
            
            case 2:{
              printf("\nEnter subject name: ");
              fgets(listSubject[qty_subject].name, 50, stdin);
              getchar();
            break;
            }
            case 3:{
              printf("\nEnter semester of subject: ");
              scanf("%d", &listSubject[qty_subject].semester);
              getchar();
              break;
            }
            case 4:{
              printf("\nEnter vacancies number: ");
              scanf("%d", &listSubject[qty_subject].vacancies);
              getchar();
              break;
            }
            case 5:{
              printf("\nEnter teacher name: ");
              fgets(listSubject[qty_subject].teacher.name, 50, stdin);
              getchar();
              break;
            }
            case 6:{
              
              break;
            }
          }
      }
      else{
        printf("\nRegistration number was not found");
      }
    }
  
}

int subjectStudentCadastre(){
  
  int codeSuport, studentSuport;
  printf("\nEnter the subject code: ");
  scanf("%d",&codeSuport);
  for(int i =0; i<qty_subject; i++){
    if (codeSuport == listSubject[i].code){
      printf("Enter the registration number of student");
      scanf("%d", &studentSuport);
      for(int j =0; j< qty_student; j++){
        if(studentSuport == listStudent[j].registration){
           listStudent[i].name[20]  = listSubject[j].student.name[20];
          printf("%s", listSubject[j].student.name);
        }
      }
    }
  }
}

int menuReports(int optionR){
  printf("Menu of Reports\n");
  printf("{1} - List students order by gender \n");
  printf("{2} - List students order by name \n");
  printf("{3} - List students order by birthdate\n");
  printf("{4} - List teachers order by gender \n");
  printf("{5} - List teachers order by name \n");
  printf("{6} - List teachers order by birthdate\n");
  printf("{7} - List subjects\n");
  printf("{8} - List subjects and students registred\n");
  printf("{9} - List birthday peoples of the month\n");
  printf("{10} - List subjects and teachers with more than 40 vancaiens\n");
  printf("{11} - List name by search\n");
  printf("{12} - List students registred in lass than 3 subjects\n");
  printf("Enter your option: ");
  scanf("%d", &optionR);
  return optionR;
}

int reportStudentsGender(){
  printf("\nList of students order by gender\n");
  if(qty_student<1){
    printf("It doesn't have any students registered\n");
  }
  else{
    printf("\nGender Feminine\n");
    int studentGenderFem = 0; 
    for(int i = 0; i< qty_student; i++){
      if(listStudent[i].gender == 'F' || listStudent[i].gender =='f'){
        printf("\nStudent %d : %s \n", i+1, listStudent[i].name);
        studentGenderFem++;
      }
    if(studentGenderFem==0){
      printf("It doesn't have any students of masculine gender. \n");
    }
    }
    printf("Gender Masculine\n");
    int studentGenderMasc = 0; 
    for(int i = 0; i< qty_student; i++){
      if(listStudent[i].gender == 'M' || listStudent[i].gender =='m'){
        printf("\nStudent %d : %s \n", i+1, listStudent[i].name);
        studentGenderMasc++;
      }
    }
    if(studentGenderMasc==0){
      printf("It doesn't have any students of masculine gender.\n ");
    }
  }
}
int reportStudentNameOrder(){
  
}
int reportStudentBirthdateOrder(){}
int reportTeacherNameOrder(){}
int reportTeacherBirthdateOrder(){}

int reportTeachersGender(){
  printf("\nList of teachers order by gender\n");
  if(qty_teacher<1){
    printf("It doesn't have any teachers registered\n");
  }
  else{
    printf("\nGender Feminine\n");
    int teacherGenderFem = 0; 
    for(int i = 0; i< qty_teacher; i++){
      if(listTeacher[i].gender == 'F' || listTeacher[i].gender =='f'){
        printf("\nTeacher %d : %s \n", i+1, listTeacher[i].name);
        teacherGenderFem++;
      }
    if(teacherGenderFem==0){
      printf("It doesn't have any teachers of masculine gender. ");
    }
    }
    printf("Gender Masculine\n");
    int teacherGenderMasc = 0; 
    for(int i = 0; i< qty_teacher; i++){
      if(listTeacher[i].gender == 'M' || listTeacher[i].gender =='m'){
        printf("\nTeacher %d : %s \n", i+1, listTeacher[i].name);
        teacherGenderMasc++;
      }
    }
    if(teacherGenderMasc==0){
      printf("It doesn't have any teachers of masculine gender. ");
    }
  }
}


int reportPeopleBirthdayMonth(){
  printf("\nList of birthday peoples of the month\n");
  
  if(qty_student<1 && qty_teacher <1){
    printf("\nIt doesn't have any people registred\n");
  }
  else{
    printf("Enter the current month: ");
    int currrentMonth;
    scanf("%d", &currrentMonth);
    
    for(int i = 0; i< qty_teacher; i++){
      printf("\nTeachers\n");
      int teacherBirthday = 0; 
      if(listTeacher[i].birthdate.month == currrentMonth){
        printf("\nBirthday teacher:");
        printf("%s \n", listTeacher[i].name);
        teacherBirthday ++;
      }
      if(teacherBirthday ==0){
        printf("It doesn't have any birthday teacher in this month. \n");
      }
    }
    for(int i = 0; i< qty_student; i++){
      printf("\nStudent\n");
      int studentBirthday = 0; 
      if(listTeacher[i].birthdate.month == currrentMonth){
        printf("\nBirthday student:");
        printf("%s \n", listStudent[i].name);
        studentBirthday ++;
      }
      if(studentBirthday ==0){
        printf("It doesn't have any birthday student in this month. \n");
      }
    }
  }
}
int reportSubjectListName(){
  printf("List of subjects registred\n");
  if(qty_subject < 1){
    printf("It doesn't have any subjects registred");
  }
  else{
    for(int i = 0; i < qty_subject; i++){
      printf("%s --- %d", listSubject[i].name, listSubject[i].code);
    }
  }
}

int reportSubjectOverForty(){
  printf("List of subjects and teachers with more than 40 vancaiens.\n");
  if(qty_subject > 0){
    for(int i = 0; i < qty_subject; i++){
      if(listSubject[i].vacancies >=40){
        printf("%s --- %s", listSubject[i].name, listSubject[i].teacher.name);
      }
    }
  }
  else{
    printf("It doesn't have any subjects registred with this condition");
  }
}

int reportSubjectListNameRegistred(){
  printf("List of subjects registred\n");
  if(qty_subject < 1){
    printf("It doesn't have any subjects registred");
  }
  else{
    for(int i = 0; i < qty_subject; i++){
      
      printf("%s", listSubject[i].student.name);
    }
  }
}

int reportSubjectOverThree(){
  
}
