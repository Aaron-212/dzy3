#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>

class Project {
  public:
    int id;
    std::string name;
    std::vector<int> members; // Member IDs of Graduate Students

    // Constructors
    Project() {
        id = 1;
        name = "Project";
    }
    Project(int id, std::string name) {
        this->id = id;
        this->name = name;
    }

    friend std::ostream &operator<<(std::ostream &os, const Project &project) {
        std::cout << "Project ID:" << project.id << std::endl;
        std::cout << "Name:" << project.name << std::endl;
        std::cout << "Member Count:" << project.members.size() << std::endl;
    }
};

#endif // PROJECT_H
