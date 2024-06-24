#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <sqlite3.h>
#include <stdexcept>
#include <string>

class Score {
  public:
    int studentID; // The student who obtained the score
    int courseID;  // The course in which the score was obtained
    int score;     // The score obtained by the student

    // Constructors
    Score() : courseID(0), studentID(0), score(0) {}

    Score(int studentID, int courseID, int percentage) : courseID(courseID), studentID(studentID), score(percentage) {}
    Score(int studentID, int courseID, char letter)
        : courseID(courseID), studentID(studentID), score(letterToPercentage(letter)) {}
    Score(int studentID, int courseID, const std::string &pf)
        : courseID(courseID), studentID(studentID), score(passFailToPercentage(pf)) {}

    // Operator overload
    bool operator==(const Score &other) const { return score == other.score; }

    friend std::ostream &operator<<(std::ostream &os, const Score &score) {
        os << "Student ID: " << score.studentID << ", Course ID: " << score.courseID << ", Score: " << score.score;
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
        return std::to_string(studentID) + ", " + std::to_string(courseID) + ", " + std::to_string(score);
    }

    // cin overload
    friend std::istream &operator>>(std::istream &is, Score &score) {
        std::string type;
        std::cout << "Enter student ID: ";
        is >> score.studentID;
        std::cout << "Enter course ID: ";
        is >> score.courseID;
        std::cout << "Enter score type (Percentage/Letter/PassFail): ";
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
            std::cout << "Enter Pass or Fail: ";
            is >> pf;
            score.score = passFailToPercentage(pf);
        } else {
            throw std::invalid_argument("Invalid ScoreType");
        }
        return is;
    }
};

#endif // SCORE_H
