#include <iostream>
#include "domain/student/studentservice.hpp"
#include <pqxx/pqxx>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <crow.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <string>

using json = nlohmann::json;
crow::SimpleApp app;

std::string name, sirname;
int no, citizenId, gpa, input, choice,courselast;


void script() {
    std::cout << "Choices of the tasks that you want to perform\n";

    std::cout << "1.Add new Student to the database\n";

    std::cout << "2. Search Student by Student Number or First Name\n";

    std::cout << "3. Add new Course \n";

    std::cout << "4. Search Student by Course Id\n";

    std::cout << "5. Count Total number of Students\n";

    std::cout << "6. Delete the Student by Roll Number\n";

    std::cout << "7. Update Student Details by Roll Number\n";

    std::cout << "For Exit the program, press 0.\n";

    std::cout << "Enter your choice\n";
}

void mainmenu() {

    constexpr  int TIME_LIMIT_SECONDS = 1200; // Time limit in seconds

                auto start = std::chrono::steady_clock::now(); // Get the initial time
    CROW_ROUTE(app, "/").methods("POST"_method)([](const crow::request& req) {
        return script();
    });
    app.port(18080).run();
    std::cin >> choice;
                    usleep(1200);

                    auto end = std::chrono::steady_clock::now();
                    auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

                    // Check if the elapsed time has exceeded the time limit
                    if (elapsed_seconds >= TIME_LIMIT_SECONDS) {
                        std::cout << "Time's up! Exited by system." << std::endl;

                    }


}


void openingscreen(int systempassword = 12345,int pass) {
    for (int i = 0; i <= 3; i++) {
            if(i==3) {
                std::cout << "UNELLIGIBLE ACCESS ATTEMPT";
                break;
            }
            std::cout << "Please enter system password to access student managment portal:";

            std::cin >> pass;
            if (systempassword == pass) {
                mainmenu();
            } else {
                std::cout << "Please try again.";
            }
        }
}

json student_to_json(const student &newStudent) {
    json j;
    j["name"] = newStudent.name;
    j["sirname"] = newStudent.sirname;
    j["no"] = newStudent.no;
    j["citizenId"] = newStudent.citizenid;
    j["gpa"] = newStudent.gpa;
    return j;
}


   int main() {
    openingscreen();

    using json = nlohmann::json;
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });
    CROW_ROUTE(app, "/get")([](){
    return "GET Request!";
});
  /*  CROW_ROUTE(app, "/post").methods("POST"_method)([](const crow::request& req){
        auto json_data = json::parse(req.body);
        int choice = json_data["choice"];
        std::cin >> choice;
        usleep(1200);

             switch (choice) {
                  case 1:
                      StudentService::add_student();
                      break;
                  case 2:
                      StudentService::findStudent();
                      break;
                  case 3:
                       StudentService::addCourse();
                       break;

                  case 4:
                       StudentService::findStudentByCourseId();
                       break;

                 case 5:
                      StudentService::findTotalStudents();
                      break;

                 case 6:
                       StudentService::deleteStudentByStudentNumber();
                       break;
                 case 7:
                       StudentService::updateStudentDetails();
                       break;
                 case 0:
                       std::cout<<"See you later.\n";
                       break;
                 default:
                       break;
                          }
});
*/
    CROW_ROUTE(app, "/add_student").methods("POST"_method)([](const crow::request& req) {
            auto json_data = json::parse(req.body);
            std::string name= json_data["name"].get<std::string>();
            std::string sirname = json_data["sirname"].get<std::string>();
            double gpa = json_data["gpa"].get<double>();
            int citizenid = json_data["citizenId"].get<int>();
            int input = json_data["input"].get<int>();
            int enroll = json_data["enroll"].get<int>();
            student newStudent = { name, sirname, enroll, citizenid, gpa };
            StudentService::add_student(enroll,newStudent,input);

    });

    CROW_ROUTE(app, "/findStudent").methods("POST"_method)([](const crow::request& req) {
            auto json_data = json::parse(req.body);

            std::string name= json_data["name"].get<std::string>();
            std::string sirname = json_data["sirname"].get<std::string>();
            double gpa = json_data["gpa"].get<double>();
            int citizenid = json_data["citizenId"].get<int>();
            int enroll = json_data["enroll"].get<int>();
            int number = json_data["number"].get<int>();
            student newStudent = { name, sirname, enroll, citizenid, gpa };
            StudentService::findStudent(number , name);

    });

    CROW_ROUTE(app, "/addCourse").methods("POST"_method)([](const crow::request& req) {
            auto json_data = json::parse(req.body);

            std::string name= json_data["name"].get<std::string>();
            std::string sirname = json_data["sirname"].get<std::string>();
            double gpa = json_data["gpa"].get<double>();
            int citizenid = json_data["citizenId"].get<int>();
            int input = json_data["input"].get<int>();
            int enroll = json_data["enroll"].get<int>();
            int courselast = json_data["courselast"].get<int>();
            student newStudent = { name, sirname, enroll, citizenid, gpa };
            StudentService::addCourse(newStudent.citizenid, input,courselast);

    });

    CROW_ROUTE(app, "/findStudentByCourseId").methods("POST"_method)([](const crow::request& req) {
            auto json_data = json::parse(req.body);

            std::string name= json_data["name"].get<std::string>();
            std::string sirname = json_data["sirname"].get<std::string>();
            double gpa = json_data["gpa"].get<double>();
            int citizenid = json_data["citizenId"].get<int>();
            int enroll = json_data["enroll"].get<int>();
            student newStudent = { name, sirname, enroll, citizenid, gpa};
            StudentService::findStudentByCourseId(newStudent);

    });

    CROW_ROUTE(app, "/findTotalStudents").methods("POST"_method)([](const crow::request& req) {
            auto json_data = json::parse(req.body);

            std::string name= json_data["name"].get<std::string>();
            std::string sirname = json_data["sirname"].get<std::string>();
            double gpa = json_data["gpa"].get<double>();
            int citizenid = json_data["citizenId"].get<int>();
            int enroll = json_data["enroll"].get<int>();
            student newStudent = { name, sirname, enroll, citizenid, gpa };
            StudentService::findTotalStudents(newStudent);

    });

    CROW_ROUTE(app, "/deleteStudentByStudentNumber").methods("POST"_method)([](const crow::request& req) {
            auto json_data = json::parse(req.body);

            std::string name= json_data["name"].get<std::string>();
            std::string sirname = json_data["sirname"].get<std::string>();
            double gpa = json_data["gpa"].get<double>();
            int citizenId = json_data["citizenId"].get<int>();
            int enroll = json_data["enroll"].get<int>();
            int number = json_data["number"].get<int>();
            student newStudent = { name, sirname, enroll, citizenId, gpa};
            StudentService::deleteStudentByStudentNumber(number);

    });

    CROW_ROUTE(app, "/updateStudentDetails").methods("POST"_method)([](const crow::request& req) {
            auto json_data = json::parse(req.body);

            std::string name= json_data["name"].get<std::string>();
            std::string sirname = json_data["sirname"].get<std::string>();
            double gpa = json_data["gpa"].get<double>();
            int citizenId = json_data["citizenId"].get<int>();
            int input = json_data["input"].get<int>();
            int enroll = json_data["enroll"].get<int>();
            int number = json_data["number"].get<int>();
            int func = json_data["func"].get<int>();
            student newStudent = { name, sirname, enroll, citizenId, gpa};
            StudentService::updateStudentDetails(input,number,func);

    });

    CROW_ROUTE(app, "/exit").methods("POST"_method)([](const crow::request& req){
    return "See you later";
});



    app.port(18080).run();
}



