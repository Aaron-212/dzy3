#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <stdexcept>

enum class ScoreType {
    Percentage, // 0-100
    Letter,     // A, B, C, D, F
    PassFail    // pass, fail
};

enum class LetterGrade { A, B, C, D, F };

enum class PassFail { Fail, Pass };

class Score {
  public:
    int courseID;   // The course in which the score was obtained
    int studentId;  // The student who obtained the score
    ScoreType type; // The type of score
    union ScoreValue {
        int percentage; // Used for Percentage and translated Letter and PassFail scores
        LetterGrade letter;
        PassFail passFail;

        ScoreValue() : percentage(0) {}
    } value;

    // Constructors
    Score() : courseID(0), studentId(0), type(ScoreType::Percentage) { value.percentage = 0; }

    Score(int courseID, int studentId, int percentage)
        : courseID(courseID), studentId(studentId), type(ScoreType::Percentage) {
        if (percentage < 0 || percentage > 100) {
            throw std::invalid_argument("Percentage score must be between 0 and 100");
        }
        value.percentage = percentage;
    }

    Score(int courseID, int studentId, LetterGrade letter)
        : courseID(courseID), studentId(studentId), type(ScoreType::Letter) {
        value.letter = letter;
    }

    Score(int courseID, int studentId, PassFail passFail)
        : courseID(courseID), studentId(studentId), type(ScoreType::PassFail) {
        value.passFail = passFail;
    }

    // Operator overload
    bool operator==(const Score &other) const {
        if (type != other.type)
            return false;
        switch (type) {
        case ScoreType::Percentage:
            return value.percentage == other.value.percentage;
        case ScoreType::Letter:
            return value.letter == other.value.letter;
        case ScoreType::PassFail:
            return value.passFail == other.value.passFail;
        default:
            return false;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Score &score) {
        os << "Course ID: " << score.courseID << ", Student ID: " << score.studentId;
        switch (score.type) {
        case ScoreType::Percentage:
            os << ", Score Value: " << score.value.percentage << "%";
            break;
        case ScoreType::Letter:
            os << ", Score Value: Grade " << score.letterToString(score.value.letter);
            break;
        case ScoreType::PassFail:
            os << ", Score Value: " << score.passFailToString(score.value.passFail);
            break;
        }
        return os;
    }

    // Function to convert letter grades to percentage for storage
    static int letterToPercentage(LetterGrade letter) {
        switch (letter) {
        case LetterGrade::A:
            return 100;
        case LetterGrade::B:
            return 82;
        case LetterGrade::C:
            return 72;
        case LetterGrade::D:
            return 60;
        case LetterGrade::F:
            return 0;
        default:
            throw std::invalid_argument("Invalid letter grade");
        }
    }

    // Function to convert LetterGrade to string for display
    static const char *letterToString(LetterGrade letter) {
        switch (letter) {
        case LetterGrade::A:
            return "A";
        case LetterGrade::B:
            return "B";
        case LetterGrade::C:
            return "C";
        case LetterGrade::D:
            return "D";
        case LetterGrade::F:
            return "F";
        default:
            throw std::invalid_argument("Invalid letter grade");
        }
    }

    // Function to convert PassFail to percentage for storage
    static int passFailToPercentage(PassFail passFail) {
        switch (passFail) {
        case PassFail::Pass:
            return 82;
        case PassFail::Fail:
            return 0;
        default:
            throw std::invalid_argument("Invalid pass/fail value");
        }
    }

    // Function to convert PassFail to string for display
    static const char *passFailToString(PassFail passFail) {
        switch (passFail) {
        case PassFail::Pass:
            return "Pass";
        case PassFail::Fail:
            return "Fail";
        default:
            throw std::invalid_argument("Invalid pass/fail value");
        }
    }

    int percentage() const {
        switch (type) {
        case ScoreType::Percentage:
            return value.percentage;
        case ScoreType::Letter:
            return letterToPercentage(value.letter);
        case ScoreType::PassFail:
            return passFailToPercentage(value.passFail);
        default:
            throw std::invalid_argument("Invalid score type");
        }
    }
};

#endif // SCORE_H
