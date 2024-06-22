#ifndef GRADUATE_STUDENT_H
#define GRADUATE_STUDENT_H

#include "Student.h"

class Graduate_Student : public Student {
  public:
    int projectID;

    Graduate_Student() : Student() { projectID = -1; }

    Graduate_Student(int id, std::string n, int pID) : Student(id, n) { projectID = pID; }

    friend std::ostream &operator<<(std::ostream &os, const Graduate_Student &gs) {
        os << "Graduate Student ID: " << gs.id << " Name: " << gs.name << " Project ID: " << gs.projectID;
        return os;
    }
};

#endif // GRADUATE_STUDENT_H
