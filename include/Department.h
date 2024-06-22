#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Course.h"
#include "Student.h"
#include <map>
#include <string>

class Department {
  public:
    std::string name;                // Name of the department
    std::map<int, Student> students; // Students belonging to the department
    std::map<int, Course> courses;   // Courses offered by the department

    // Constructor
    Department(const std::string &name) : name(name) {}

    // Mutators
    void addStudent(const Student &student) { students[student.id] = student; }
    void removeStudent(const Student &student) { students.erase(student.id); }
    Student &getStudent(int studentId) { return students[studentId]; }

    void addCourse(const Course &course) { courses[course.id] = course; }
    void removeCourse(const Course &course) { courses.erase(course.id); }
    Course &getCourse(int courseId) { return courses[courseId]; }
};

#endif // DEPARTMENT_H
