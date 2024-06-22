#include "Student.h"
#include <iostream>
class Graduate_Student : public Student {
  public:
    Project GStudent_Project;
    Graduate_Student() : GStudent_Project() {
        id = 0;
        name = " ";
    }
    Graduate_Student(int id, const std::string &name, std::string Project_name, std::string Project_number,
                     std::string Project_member_num)
        : GStudent_Project(Project_name, Project_number, Project_member_num) {
        this->id = id;
        this->name = name;
    }
};
class Project {
  public:
    std::string Project_name;
    std::string Project_number;
    std::string Project_member_num;
    Project() {
        Project_name = " ";
        Project_number = "00001";
        Project_member_num = "one";
    }
    Project(std::string Project_name, std::string Project_number, std::string Project_member_num) {
        Project_name = Project_name;
        Project_number = Project_number;
        Project_member_num = Project_member_num;
    }
    std::string Get_Project_name() { return Project_name; }
    std::string Get_Project_number() { return Project_number; }
    std::string Get_Project_member_num() { return Project_member_num; }
    void Display_Project() {
        std::cout << "Project Name:" << Get_Project_name() << std::endl;
        std::cout << "Project Number:" << Get_Project_number() << std::endl;
        std::cout << "Project Member Num:" << Get_Project_member_num() << std::endl;
    }
}; // Graduate_Student Project