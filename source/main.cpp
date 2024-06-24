#include "Course.h"
#include "Database.h"
#include "Student.h"
#include <iostream>

// Login function
bool login() {
    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    return username == "admin" && password == "admin";
}

// Student Operations
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

bool student_menu(Database &database) {
    std::cout << "\nStudent Operations" << std::endl;
    std::cout << "1. Add student" << std::endl;
    std::cout << "2. Remove student" << std::endl;
    std::cout << "3. Query students" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
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
    case 0:
        return true;
    default:
        std::cout << "Invalid choice" << std::endl;
    }

    return student_menu(database);
}

// Course Operations
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

bool course_menu(Database &database) {
    std::cout << "\nCourse Operations" << std::endl;
    std::cout << "1. Add course" << std::endl;
    std::cout << "2. Remove course" << std::endl;
    std::cout << "3. Query courses" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        add_course(database);
        break;
    case 2:
        remove_course(database);
        break;
    case 3:
        query_courses(database);
        break;
    case 0:
        return true;
    default:
        std::cout << "Invalid choice" << std::endl;
    }

    return course_menu(database);
}

// Score Menu
bool add_score(Database &database) {
    Score score;

    std::cin >> score;

    database.addScore(score);
    return true;
}

bool remove_score(Database &database) {
    int studentID;
    int courseID;
    std::cout << "Enter student ID: ";
    std::cin >> studentID;
    std::cout << "Enter course ID: ";
    std::cin >> courseID;

    database.removeScore(studentID, courseID);
    return true;
}

bool query_scores(Database &database) {
    std::string condition;
    std::cout << "Enter query condition (blank for all scores): ";
    std::cin.ignore();
    std::getline(std::cin, condition);

    std::vector<Score> scores = database.queryScores(condition);
    for (const Score &score : scores) {
        std::cout << score << std::endl;
    }

    return true;
}

bool update_score(Database &database) {
    Score score;
    std::cin >> score;
    database.updateScore(score.studentID, score.courseID, score);
    return true;
}

bool score_menu(Database &database) {
    std::cout << "\nScore Operations" << std::endl;
    std::cout << "1. Add score" << std::endl;
    std::cout << "2. Remove score" << std::endl;
    std::cout << "3. Query scores" << std::endl;
    std::cout << "4. Update scores" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        add_score(database);
        break;
    case 2:
        remove_score(database);
        break;
    case 3:
        query_scores(database);
        break;
    case 4:
        update_score(database);
    case 0:
        return true;
    default:
        std::cout << "Invalid choice" << std::endl;
    }

    return score_menu(database);
}

// Main Menu
bool main_menu(Database &database) {
    std::cout << "\nStudent Score Management System" << std::endl;
    std::cout << "1. Student Operations" << std::endl;
    std::cout << "2. Course Operations" << std::endl;
    std::cout << "3. Score Operations" << std::endl;
    std::cout << "0. Exit program" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        student_menu(database);
        break;
    case 2:
        course_menu(database);
        break;
    case 3:
        score_menu(database);
        break;
    case 0:
        return false;
    default:
        std::cout << "Invalid choice" << std::endl;
    }

    return main_menu(database);
}

// Interaction with the user
bool interact(Database &database) {
    if (login()) {
        std::cout << "Login successful!" << std::endl;
        return main_menu(database);
    } else {
        std::cout << "Login failed!" << std::endl;
        return interact(database);
    }
}

// Main function
int main() {
    Database database("database.db");
    database.createTables();

    return interact(database) ? 0 : 1;
}
