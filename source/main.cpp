#include "Database.h"
#include "Student.h"
#include <iostream>

bool login() {
    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    return username == "admin" && password == "admin";
}

bool add_student(Database &database) {
    Student student;
    std::cin >> student;

    database.addStudent(student);

    return true;
}

bool remove_student(Database &database) {
    int studentID;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;

    database.removeStudent(studentID);

    return true;
}

bool query_students(Database &database) {
    std::string condition;
    std::cout << "Enter query condition (blank for all students): ";
    std::cin.ignore();
    std::getline(std::cin, condition);

    std::vector<Student> students = database.queryStudents(condition);

    for (const Student &student : students) {
        std::cout << student << std::endl;
    }

    return true;
}

bool add_course(Database &database) {
    Course course;
    std::cin >> course;

    database.addCourse(course);

    return true;
}

bool remove_course(Database &database) {
    int courseID;
    std::cout << "Enter course ID: ";
    std::cin >> courseID;

    database.removeCourse(courseID);

    return true;
}

bool query_courses(Database &database) {
    std::string condition;
    std::cout << "Enter query condition (blank for all courses): ";
    std::cin.ignore();
    std::getline(std::cin, condition);

    std::vector<Course> courses = database.queryCourses(condition);

    for (const Course &course : courses) {
        std::cout << course << std::endl;
    }

    return true;
}

bool main_menu(Database &database) {
    std::cout << std::endl;
    std::cout << "Student Score Management System" << std::endl;
    std::cout << "1. Add student" << std::endl;
    std::cout << "2. Remove student" << std::endl;
    std::cout << "3. Query students" << std::endl;
    std::cout << "4. Add Couse" << std::endl;
    std::cout << "5. Remove Course" << std::endl;
    std::cout << "6. Query Courses" << std::endl;

    std::cout << "0. Exit program" << std::endl;

    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        add_student(database);
        break;
    case 2:
        remove_student(database);
        break;
    case 3:
        query_students(database);
        break;
    case 4:
        add_course(database);
        break;
    case 5:
        remove_course(database);
        break;
    case 6:
        query_courses(database);
        break;
    case 0:
        return true;
    default:
        std::cout << "Invalid choice" << std::endl;
    }

    return main_menu(database);
}

bool interact(Database &database) {
    if (login()) {
        std::cout << "Login successful!" << std::endl << std::endl;
        return main_menu(database);
    } else {
        std::cout << "Login failed!" << std::endl << std::endl;
        return login();
    }
}

int main() {
    Database database("database.db");
    database.createTables();

    return interact(database);
}
