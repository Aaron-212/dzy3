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
        os << "Project ID:" << project.id << ", Name:" << project.name << ", Member Count:" << project.members.size();
        return os;
    }
};

#endif // PROJECT_H
