#include <iostream>
#include <string>
#include <vector>

int systempass=12345;
int id;
int input;

struct student {
  std::string s_name;
  std::string s_sirname;
  int s_no,gpa,s_id;
 std::vector <std::string> course={"English","Math","Science","Music","Art"};


 };

student students[];

int number_of_students =0 ;
student no;
student ID;
int alreadyexist=no.s_no;
int alreadyExist=ID.s_id;


void add_student(){
 int enroll;
while(true) {
 std::cout<<"Please enter student number to enroll the student in system:\n";
 std::cin>> enroll;

 if(0>=enroll || enroll>=9999 ) {
  std::cout << "The number you entered is unavailable.";
  return;
 }
 if(alreadyexist == enroll){
  std::cout<<"This student is already exist.";
  return;
 }

 std::cout<<"Enter the first name of the student\n";
 std::cin>>students[number_of_students].s_name;


 std::cout<<"Enter the sirname of the student\n";
 std::cin>>students[number_of_students].s_name;

 std::cout<<"Enter the student number\n";
 students[number_of_students].s_no = enroll;

 std::cout<<"Enter the GPA of the student\n";
 std::cin>>students[number_of_students].gpa;

 std::cout<<"Enter the ID of the student\n";
 std::cin>>students[number_of_students].s_id;

 if(1000000000>=enroll || enroll>=19999999999 ) {
  std::cout << "The number you entered is unavailable.";
  return;
 }
 if(alreadyExist == enroll){
  std::cout<<"This student is already exist.";
  return;
 }


 std::cout<<"Enter the course ID of each course in which the student is enrolled in. For exit button 0.\n";
 std::cin>>students[number_of_students].course[input];
while(true) {
 if(input!=0)
  std::cin>>students[number_of_students].course[input];
 else {
  break;
 }

}

 number_of_students++;

}
}


bool isNumber(const std::string& input) {
 for(char c : input) {
  if (!isdigit(c)) {
   return false;
  }
 }
 return true;
}




void findStudent(){
 int number;
 std::string name;
 std::string input;
 std::cout<<"Please enter the student name or number to search in system:";
 std::cin>>input;
 bool ifit;

 if(isNumber(input)) {
  number=stoi(input);

  for (int i = 0; i < number_of_students; i++) {
   if (number == students[i].s_no) {
    ifit=false;
    std::cout<<"The Students Details are:\n";

    std::cout<<"The First name is " << students[i].s_name << "\n";
    std::cout<<"The Last name is " << students[i].s_name << "\n";
    std::cout<<"The GPA is " << students[i].gpa << "\n";
    std::cout<<"The ID is " << students[i].s_id << "\n";
    std::cout<<"The course ID of each course\n";

    for (int j = 0;j<=students[i].course.size();j++) {
     std::cout << students[i].course[j] << "\n";
    }
   }
  }
  if(!ifit){
   std::cout<<"No such student with the given student number\n";
  }
 }
 else{
  name=input;
  ifit=false;
  for (int i = 0; i <= number_of_students; i++) {
   if (input == students[i].s_name) {


    std::cout<<"The Students Details are\n";

    std::cout<<"The First name is " << students[i].s_name << "\n";
    std::cout<<"The Last name is " << students[i].s_sirname << "\n";
    std::cout<<"The GPA is " << students[i].gpa << "\n";
    std::cout<<"The ID is " << students[i].gpa << "\n";
    std::cout<<"The course ID of each course\n";

    for (int j = 0; j<=students[i].course.size(); j++) {

     std::cout << students[i].course[j] << "\n";


     std::cout<<"\n";
    }
   }

   if(!ifit){
    std::cout<<"no such student with the given first name\n";
   }
  }
 }


 void findStudentByCourseId(){
  std::cout<<"Enter the course id\n";
  std::cin>>id;

  bool foundd= false;

  for (int i = 0; i < number_of_students; i++) {

   for(int j = 0; j<=students[i].course.size(); j++){

    if(id == j) {
     std::cout<< students[i].course[j];
    }

    foundd=true;
    std::cout<<"The First name is " << students[i].s_name << "\n";
    std::cout<<"The Last name is " << students[i].s_sirname << "\n";
    std::cout<<"The CGPA is " << students[i].gpa << "\n";
    std::cout<<"\n";
   }
  }



  if(!foundd){
   std::cout<<"No such students with the given course id\n";
  }
 }

 void findTotalStudents(){
  std::cout<<"The total number Students are "<< number_of_students <<"\n";
 }

 void deleteStudentByStudentNumber(){
  int roll_no;
  std::cout<<"Enter the Student number that you want to delete\n";
  std::cin>>roll_no;

  bool control=false;
  for (int i = 0; i < number_of_students; i++) {
   if (roll_no == students[i].s_no) {
    control = true;
    for (int j = i; j < 109; j++)
     students[j] = students[j + 1];
    number_of_students--;
   }
  }

  if(control){
   std::cout<<"The student is removed Successfully\n";
  }
  else{
   std::cout<<"Student number not found in the database\n";
  }
 }



 void updateStudentDetails();{

  std::cout<<"Enter the roll number whose details you want to update\n";
  int roll_no;
  std::cin>>roll_no;

  bool booll=false;
  for (int i = 0; i < number_of_students; i++) {
   if (students[i].s_no == roll_no) {

    booll=true;
    std::cout<< "1. update First Name\n"
           "2. update  Sirname\n"
           "3. update Student Number.\n"
           "4. update GPA\n"
           "5. update Courses\n";

    int choice;
    std::cin>>choice;

    switch(choice) {
     case 1:
      std::cout<<"Enter the new first name\n";
     std::cin>>students[i].s_name;
     break;

     case 2:
      std::cout<<"Enter the new last name\n";
     std::cin>>students[i].s_sirname;
     break;

     case 3:
      std::cout<<"Enter the new student number\n";
     std::cin>>students[i].s_no;
     break;

     case 4:
      std::cout<<"Enter the new GPA\n";
     std::cin>>students[i].gpa;
     break;

     case 5:
      std::cout<<"Enter the new courses.Exit button 0. \n";
     int j;
     while(true) {
      std::cin>>j>>students[i].course[j];
      if(j==0) {
       break;
      }

     }
    }
   }
  }

  if(booll){
   std::cout<<"Details updated successfully.\n";
  }
  else{
   std::cout<<"Student not found in the database.\n";
  }
 }

 void addCourse(){
  int inputt;
  int password = 1234;
  std::cout<<"If you would like to add a new class please enter the password for Teachers only.\n";
  std::cin>>inputt;
  if(inputt==password) {
   std::string coursename;
   std::cout<<"Please enter New Class Name:";
   std::cin>>coursename;
   ID.course.emplace_back(coursename);
  }
  else {
   std::cout<<"Wrong Password.PLease try again.";
  }

 }




 int main(){
  for(int i=0;i<3;i++) {
   std::cout<<"Please enter system password to access student managment portal:";

   int pass;
   std::cin>>pass;
   if(systempass==pass) {
    int choice;
    while (true) {
     std::cout<<"Choices of the tasks that you want to perform\n";

     std::cout<<"1.Add new Student to the database\n";

     std::cout<<"2. Search Student by Student Number or First Name\n";

     std::cout<<"3. Add new Course \n";

     std::cout<<"4. Search Student by Course Id\n";

     std::cout<<"5. Count Total number of Students\n";

     std::cout<<"6. Delete the Student by Roll Number\n";

     std::cout<<"7. Update Student Details by Roll Number\n";

     std::cout<<"For Exit the program, press any non-command key.\n";

     std::cout<<"Enter your choice\n";
     std::cin>>choice;

     switch (choice) {
      case 1:
       add_student();
      break;

      case 2:
       findStudent();
      break;

      case 3:
       addCourse();
      break;

      case 4:
       findStudentByCourseId();
      break;

      case 5:
       findTotalStudents();
      break;

      case 6:
       deleteStudentByStudentNumber();
      break;

      case 7:
       updateStudentDetails();
      break;

      default:
       break;
     }
    }
   }
   else {
    std::cout<<"Please try again.";
   }
  }
  std::cout<<"UNELLIGIBLE ACCESS ATTEMPT";
 }
}




