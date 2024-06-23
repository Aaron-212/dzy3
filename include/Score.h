#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <sqlite3.h>
#include <stdexcept>
#include <string>

class Score {
  public:
    int courseID;  // The course in which the score was obtained
    int studentId; // The student who obtained the score
    int score;     // The score obtained by the student

    // Constructors
    Score() : courseID(0), studentId(0), score(0) {}

    Score(int courseID, int studentId, int percentage) : courseID(courseID), studentId(studentId), score(percentage) {}
    Score(int courseID, int studentId, char letter)
        : courseID(courseID), studentId(studentId), score(letterToPercentage(letter)) {}
    Score(int courseID, int studentId, const std::string &pf)
        : courseID(courseID), studentId(studentId), score(passFailToPercentage(pf)) {}

    // Operator overload
    bool operator==(const Score &other) const { return score == other.score; }

    friend std::ostream &operator<<(std::ostream &os, const Score &score) {
        os << "Course ID: " << score.courseID << ", Student ID: " << score.studentId << ", Score: " << score.score;
        return os;
    }

    // Function to convert letter grades to percentage for storage
    static int letterToPercentage(char letter) {
        switch (letter) {
        case 'A':
            return 100;
        case 'B':
            return 82;
        case 'C':
            return 72;
        case 'D':
            return 60;
        case 'F':
            return 0;
        default:
            throw std::invalid_argument("Invalid letter grade");
        }
    }

    static int passFailToPercentage(const std::string &pf) {
        if (pf == "Pass") {
            return 82;
        } else if (pf == "Fail") {
            return 0;
        } else {
            throw std::invalid_argument("Invalid pass/fail grade");
        }
    }

    // Method to convert the score object to a database string
    std::string to_db_string() const {
        std::string result = std::to_string(courseID) + ", " + std::to_string(studentId) + ", " + std::to_string(score);
        return result;
    }

    // cin overload
    friend std::istream &operator>>(std::istream &is, Score &score) {
        std::string type;
        std::cout << "Enter course ID: ";
        is >> score.courseID;
        std::cout << "Enter student ID: ";
        is >> score.studentId;
        std::cout << "Enter score type: ";
        is >> type;
        if (type == "Percentage") {
            std::cout << "Enter percentage: ";
            is >> score.score;
        } else if (type == "Letter") {
            std::string grade;
            std::cout << "Enter letter grade (A,B,C,D,F): ";
            is >> grade;
            score.score = letterToPercentage(grade[0]);
        } else if (type == "PassFail") {
            std::string pf;
            std::cout << "Enter Pass/Fail: ";
            is >> pf;
            score.score = passFailToPercentage(pf);
        } else {
            throw std::invalid_argument("Invalid ScoreType");
        }
        return is;
    }
};

#endif // SCORE_H
