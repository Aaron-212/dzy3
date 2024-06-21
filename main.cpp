#include <iostream>

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

class Subject {};

class Student {
  public:
    std::string name;
};

class StudentClass {};

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Hello, World again!" << std::endl;
    return 0;
}
