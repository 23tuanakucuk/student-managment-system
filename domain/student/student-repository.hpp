#ifndef STUDENT_REPOSITORY_HPP
#define STUDENT_REPOSITORY_HPP

#include "student.hpp"
#include <pqxx/pqxx>
#include <pqxx/result>

namespace StudentRepository {
    inline void add_student(pqxx::connection& conn, student const& newStudent) {
        pqxx::work txn_insert(conn);
        std::string query = "INSERT INTO student (name, lastname, number, GPA, citizenid) VALUES ('" + newStudent.name + "', '" + newStudent.sirname + "', " + std::to_string(newStudent.no) + ", " + std::to_string(newStudent.gpa) + ", '" + std::to_string(newStudent.citizenid) +  "');";
        txn_insert.exec(query);
        txn_insert.commit();
    }
    inline void add_student2(pqxx::connection& conn,int& input,student const& newStudent) {
        pqxx::work txn_insert(conn);
        std::cout <<"Enter that how many course you will add:";
        int many;
        std::cin >> many;

        std::cout << "Enter the course ID of each course in which the student is enrolled in. For exit button 0.\n";

        for(int i=0;i<many;i++){
            std::cin >> input;
            if (0<input) {
                std::string query = "INSERT INTO student (course) VALUES ('" + newStudent.course[input] + "');";
                txn_insert.exec(query);
            }
            else {
                std::cout << "The course ID you entered is unavailable.";
            }
        }

        txn_insert.commit();
    }
    inline void addCourse(pqxx::connection& conn,int const& courselast,student const& ID){
        pqxx::work txn_insert(conn);
        txn_insert.exec("INSERT INTO student (course) VALUES ("  + ID.course[courselast] + ");");
        txn_insert.commit();
    }
    inline void deleteStudentByStudentNumber(pqxx::connection& conn,int const& roll_no){
        pqxx::work txn_delete(conn);
        txn_delete.exec("DELETE FROM student WHERE number =" + std::to_string(roll_no) +  ";");
        txn_delete.commit();
    }
    inline void findStudentByCourseId(pqxx::connection& conn, const int& input,student const& theStudent){
        pqxx::work txn_select(conn);
        pqxx::result result = txn_select.exec("SELECT * FROM student WHERE course = " + theStudent.course[input] +  ";");
        for (const auto &row : result) {
            std::cout << "The First name is " << row[1].as<std::string>() << "\n";
            std::cout << "The Last name is " << row[2].as<std::string>() << "\n";
            std::cout << "The Student number is " << row[3].as<int>() << "\n";
            std::cout << "The GPA is " << row[4].as<double>() << "\n";
            std::cout << "The ID is " << row[5].as<int>() << "\n";
            std::cout << "\n";
        }
        txn_select.commit();
    }
    inline void findStudent1(pqxx::connection& conn,int const& number) {
        pqxx::work txn_select(conn);
        pqxx::result result = txn_select.exec("SELECT * FROM student WHERE number = " + std::to_string(number) +  ";");

        for (const auto &row : result){
            std::cout << "The First name is " << row[1].as<std::string>() << "\n";
            std::cout << "The Last name is " << row[2].as<std::string>() << "\n";
            std::cout << "The Student number is " << row[3].as<int>() << "\n";
            std::cout << "The GPA is " << row[4].as<double>() << "\n";
            std::cout << "The ID is " << row[5].as<int>() << "\n";
            std::cout << "The courses are " << row[6].as<std::string>() << "\n";

        }
        txn_select.commit();
    }
    inline void findStudent2(pqxx::connection& conn,std::string const& name) {
        pqxx::work txn_select(conn);
        pqxx::result result = txn_select.exec("SELECT * FROM student WHERE name = " + name + ";");
        std::cout << "The Students Details are\n";

        for (const auto &row : result) {
            std::cout << "The First name is " << row[1].as<std::string>() << "\n";
            std::cout << "The Last name is " << row[2].as<std::string>() << "\n";
            std::cout << "The Student number is " << row[3].as<int>() << "\n";
            std::cout << "The GPA is " << row[4].as<double>() << "\n";
            std::cout << "The ID is " << row[5].as<int>() << "\n";
            std::cout << "The courses are " << row[6].as<std::string>() << "\n";

        }
        txn_select.commit();
    }
    inline void updateStudentDetails(pqxx::connection& conn, student const& theStudent,int& input,int const& roll_no,int& func) {
        pqxx::work txn_select(conn);
        pqxx::result result = txn_select.exec("SELECT * FROM student WHERE number = " + std::to_string(roll_no) + ";");
        for (const auto &row : result) {
             func = row[0].as<int>();
        }
        txn_select.commit();

        pqxx::work txn_update(conn);
        txn_update.exec("UPDATE student SET name =" + theStudent.name + " WHERE number =" + std::to_string(roll_no) + ";");
        txn_update.exec("UPDATE student SET name =" + theStudent.sirname + " WHERE number =" + std::to_string(roll_no) + ";");
        txn_update.exec("UPDATE student SET name =" + std::to_string(theStudent.no) + " WHERE name =" + std::to_string(roll_no) + ";");
        txn_update.exec("UPDATE student SET GPA =" + std::to_string(theStudent.gpa) + " WHERE number =" + std::to_string(roll_no) + ";");


        txn_update.commit();
    }

inline void updateStudentDetails2(pqxx::connection& conn, student const& theStudent,int& input,int const& roll_no,int& func){
    pqxx::work txn_select(conn);
    pqxx::result result = txn_select.exec("SELECT * FROM student WHERE number = " + std::to_string(roll_no) + ";");
    for (const auto &row : result) {
        func = row[0].as<int>();
    }
    txn_select.commit();

    pqxx::work txn_update(conn);
    std::cout <<"Enter that how many course you will add:";
    int many;
    std::cin >> many;

    std::cout << "Enter the course ID of each course in which the student is enrolled in. For exit button 0.\n";

    for(int i=0;i<many;i++){
        std::cin >> input;
        if (0<input) {
            txn_update.exec("UPDATE student SET course=" + theStudent.course[input] + " WHERE number =" + std::to_string(roll_no) + ";");
        }
        else {
            std::cout << "The course ID you entered is unavailable.";
        }
    }
    txn_update.commit();
}


    inline void findTotalStudents(pqxx::connection& conn) {
        pqxx::work txn_select(conn);
        pqxx::result result = txn_select.exec("SELECT * FROM students WHERE id = (SELECT MAX(id) FROM students)");

        for (const auto &row : result) {
            std::cout << "The total number Students: " << row[0].as<int>()  << std::endl;
        }

        txn_select.commit();
    }

};

#endif //STUDENT_REPOSITORY_HPP

