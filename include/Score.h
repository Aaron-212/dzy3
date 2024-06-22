#ifndef SCORE_H
#define SCORE_H

#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <variant>

enum MarkType {
    Percentage, // 0-100
    Letter,     // A, B, C, D, F
    PassFail    // pass, fail
};

class Mark {
  public:
    MarkType type;
    std::variant<int, char, bool> value;

    // Constructor
    Mark() : type(MarkType::Percentage), value(0) {}
    Mark(MarkType t) : type(t) {}

    // Set value for percentage type
    void setValue(int percentage) {
        if (type == MarkType::Percentage && percentage >= 0 && percentage <= 100) {
            value = percentage;
        } else {
            throw std::invalid_argument("Invalid percentage value");
        }
    }

    // Set value for letter type
    void setValue(char letter) {
        if (type == MarkType::Letter &&
            (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'F')) {
            value = letter;
        } else {
            throw std::invalid_argument("Invalid letter value");
        }
    }

    // Set value for pass/fail type
    void setValue(bool passFail) {
        if (type == MarkType::PassFail) {
            value = passFail;
        } else {
            throw std::invalid_argument("Invalid pass/fail value");
        }
    }

    // Operator overload
    friend std::ostream &operator<<(std::ostream &os, const Mark &mark) {
        switch (mark.type) {
        case MarkType::Percentage:
            os << std::to_string(std::get<int>(mark.value)) + "%";
        case MarkType::Letter:
            os << std::string(1, std::get<char>(mark.value));
        case MarkType::PassFail:
            os << (std::get<bool>(mark.value) ? "Pass" : "Fail");
        default:
            os << "Unknown";
        }
        return os;
    }
};

class Score {
  public:
    Course course;   // The course in which the score was obtained
    Student student; // The student who obtained the score
    Mark mark;       // The score/mark obtained by the student

    // Constructor
    Score(const Course &course, const Student &student, Mark mark) {
        this->course = course;
        this->student = student;
        this->mark = mark;
    }

    // Operator overload
    bool operator==(const Score &other) const { return course == other.course && student == other.student; }
    friend std::ostream &operator<<(std::ostream &os, const Score &score) {
        os << score.course << " " << score.student << " " << score.mark;
        return os;
    }
};

#endif // SCORE_H
