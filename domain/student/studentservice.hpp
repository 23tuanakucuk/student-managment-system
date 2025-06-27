#ifndef STUDENT_SERVICE_HPP
#define STUDENT_SERVICE_HPP
#include <iostream>
#include <csignal>
#include <string>
#include <pqxx/pqxx>
#include "student.hpp"
#include "student-repository.hpp"

namespace StudentService
{

    pqxx::connection inline conn("dbname=mydata user=postgres password=postgres hostaddr=127.0.0.1 port=5432");

    inline bool isNumber(const std::string &input) {
        for (char c: input) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    inline void add_student(int enroll,student newStudent,int input) {

        int alreadyExist = newStudent.citizenid;
        int alreadyexist = newStudent.no;
        bool control = true;
        while (control==true) {
            std::cout << "Please enter student number to enroll the student in system:\n";
            std::cin >> enroll;

            if (enroll >= 9999) {

                std::cout << "The number you entered is unavailable.";
                return;
            }
            if (alreadyexist == enroll) {
                std::cout << "This student is already exist.";
                return;

            }

                enroll=newStudent.no;




                std::cout << "Enter the first name of the student\n";
                std::cin >> newStudent.name;


                std::cout << "Enter the sirname of the student\n";
                std::cin >> newStudent.sirname;



                std::cout << "Enter the GPA of the student\n";
                std::cin >> newStudent.gpa;


                std::cout << "Enter the ID of the student\n";
                std::cin >> newStudent.citizenid;
                if (1000000000 >= newStudent.citizenid || newStudent.citizenid >= 99999999999) {
                    std::cout << "The number you entered is unavailable.";
                    return;
                }
                if (alreadyExist == newStudent.citizenid) {
                    std::cout << "This student is already exist.";
                    return;
                }


                    StudentRepository::add_student2(conn,input,newStudent);



            StudentRepository::add_student(conn,newStudent);
            std::cout<<"The student enrolled successfully.";
                  control=false;  //will it work without infinite loop?

        }

    }

    inline void addCourse(student ID,int input,int courselast) {
        std::string password = "1234";
        std::cout << "If you would like to add a new class please enter the password for Teachers only.\n";
        std::cin >> input;
        if (std::to_string(input) == password) {
            std::string coursename;
            std::cout << "Please enter New Class Name:";
            std::cin >> coursename;

            ID.course.emplace_back(coursename);
            courselast = ID.course.size();
            StudentRepository::addCourse(conn,courselast,ID);

        } else {
            std::cout << "Wrong Password.PLease try again.";
        }
    }

    inline void deleteStudentByStudentNumber(int roll_no) {

        std::cout << "Enter the Student number that you want to delete\n";
        std::cin >> roll_no;

        bool control = false;
            if ( roll_no >= 9999) {
                control = true;
                StudentRepository::deleteStudentByStudentNumber(conn,roll_no);

            }


        if (control) {
            std::cout << "The student is removed Successfully\n";
        } else {
            std::cout << "Student number not found in the database\n";
        }
    }

   inline void findTotalStudents(int roll_no) {
        StudentRepository::findTotalStudents(conn);

    }

    inline void findStudentByCourseId(student theStudent) {
        int input;
        std::cout << "Enter the course id\n";
        std::cin >> input;


                std::cout << "The Students Details are:\n";
                StudentRepository::findStudentByCourseId(conn, input,theStudent);

        if (input<=0) {
            std::cout << "No such students with the given course id\n";
        }
    }


inline void findStudent(int number,std::string name) {
    std::string input;
    std::cout << "Please enter the student name or number to search in system:";
    std::cin >> input;
    bool ifit;

    if (isNumber(input)) {
         number = stoi(input);
        ifit = false;



            if (number >= 9999) {
                ifit = true;
                std::cout << "The Students Details are:\n";
                StudentRepository::findStudent1(conn,number);

            }

        if (!ifit) {
            std::cout << "No such student with the given student number\n";
        }
    } else {
          name = input ;
        ifit = false;

            if (name!= "a") {
                ifit = true;
                std::cout << "The Students Details are:\n";
                StudentRepository::findStudent2(conn,name);
            }

            if (!ifit) {
                std::cout << "no such student with the given first name\n";
            }

    }
}
    inline void updateStudentDetails(int input,int roll_no,int func) {
        std::cout << "Enter the roll number whose details you want to update\n";
        std::cin >> roll_no;
         student theStudent;
        bool booll = false;

                std::cout << "1. update First Name\n"
                        "2. update  Sirname\n"
                        "3. update Student Number.\n"
                        "4. update GPA\n"
                        "5. update Courses.Press any non command key for exit\n";


                int choice;
                std::cin >> choice;




                switch (choice) {
                    case 1:
                        std::cout << "Enter the new first name\n";
                    std::cin >> theStudent.name;
                    StudentRepository::updateStudentDetails(conn, theStudent,input,roll_no,func);
                    booll = true;
                    break;

                    case 2:
                        std::cout << "Enter the new last name\n";
                    std::cin >> theStudent.sirname;
                    StudentRepository::updateStudentDetails(conn, theStudent,input,roll_no,func);
                    booll = true;
                    break;

                    case 3:
                        std::cout << "Enter the new student number\n";
                    std::cin >> theStudent.no;
                    StudentRepository::updateStudentDetails(conn, theStudent,input,roll_no,func);
                    booll = true;
                    break;

                    case 4:
                        std::cout << "Enter the new GPA\n";
                    std::cin >> theStudent.gpa;
                    StudentRepository::updateStudentDetails(conn, theStudent,input,roll_no,func);
                    booll = true;
                    break;

                    case 5:
                    StudentRepository::updateStudentDetails2(conn, theStudent,input,roll_no,func);
                    booll = true;
                    break;
                    default:
                        break;
                }

        if (booll) {
            std::cout << "Details updated successfully.\n";
        } else {
            std::cout << "Student not found in the database.\n";
        }
    }

};
#endif //STUDENT_SERVICE_HPP

