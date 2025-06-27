#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>


struct student {
    std::string name;
    std::string sirname;
    int no, citizenid;
    double gpa;
    std::vector<std::string> course = {{},"English", "Math", "Science", "Music", "Art"};
};



#endif //STUDENT_HPP

