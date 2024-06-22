#ifndef STUDENT_H
#define STUDENT_H

#include "Score.h"
#include <iostream>
#include <map>

class Student {
  public:
    int id;                      // Unique identifier for the student
    std::string name;            // Student's name
    std::map<int, Score> scores; // Course ID mapped to Score objects

    // Constructor
    Student() {
        id = 0;
        name = "";
    }
    Student(int id, const std::string &name) {
        this->id = id;
        this->name = name;
    }

    // Mutators
    void addScore(const Score &score) { scores[score.courseID] = score; }
    void removeScore(int courseId) { scores.erase(courseId); }
    Score &getScore(int courseId) { return scores[courseId]; }

    // Operator overload
    bool operator==(const Student &other) const { return id == other.id; }
    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "Student ID: " << student.id << ", Name: " << student.name;
        return os;
    }
};

#endif // STUDENT_H
