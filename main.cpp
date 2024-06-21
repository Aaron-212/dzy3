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
    std::vector<Score> scores;
};

class Student {
  public:
    std::string name;
};

class StudentClass {};

class Project {};
class Gstudent : public Student {
  public:
    class Project;
};
int main() { return 0; }
