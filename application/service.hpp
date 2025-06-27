#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "../domain/student/studentservice.hpp"


namespace ApplicationService
{
    inline void addCourse() {
        StudentService::addCourse(student &ID,&input,&courselast);
    }
    inline void deleteStudentByStudentNumber() {
        StudentService::deleteStudentByStudentNumber(&roll_no);
    }

    inline void findTotalStudents() {
        StudentService::findTotalStudents(&roll_no);
    }
    inline void findStudent() {
        StudentService::findStudent(&number,&name);
    }
    inline void updateStudentDetails() {
        StudentService::updateStudentDetails(&input,&roll_no,&func);
    }
    inline void add_student() {
        StudentService::add_student(&enroll,student &newStudent,&input);
    }

};

#endif //SERVICE_HPP

