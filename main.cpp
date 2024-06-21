#include <fstream>
#include <iostream>
#include <vector>

// pre-declare
class Student;

class Score {
  public:
    Student *student;
    int score;

    // Constructors
    Score() {
        this->student = nullptr;
        this->score = 0;
    }

    Score(Student *student, int score) {
        this->student = student;
        this->score = score;
    }
};

class Subject {
  public:
    std::string name;
    std::vector<Score> scores;

    // Constructors
    Subject() { }
    Subject(std::string name) { this->name = name; }
    Subject(std::string name, std::vector<Score> scores) {
        this->name = name;
        this->scores = scores;
    }
};

class Student {
  public:
    std::string name;
    int id;
    int age;

    // Constructors
    Student() {
        this->id = 0;
        this->age = 0;
    }
    Student(std::string name, int id, int age) {
        this->name = name;
        this->id = id;
        this->age = age;
    }
};

class StudentClass {
  public:
    int class_num;
    std::vector<Student> Students;
    StudentClass(int class_num) { this->class_num = class_num; }
    StudentClass(int class_num, std::vector<Student> Students) {
        this->class_num = class_num;
        this->Students = Students;
    };
};

class Project {};

class Gstudent : public Student {
  public:
    class Project;
};

int main() { return 0; }
