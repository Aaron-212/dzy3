#pragma once
#include "Course.h"
#include "Score.h"
#include "Student.h"
#include <sqlite3.h>
#include <string>
#include <vector>

class Database {
  private:
    sqlite3 *db;
    std::string db_name;

    void executeQuery(const std::string &query) {
        char *errorMsg;
        int rc = sqlite3_exec(db, query.c_str(), 0, 0, &errorMsg);
        if (rc != SQLITE_OK) {
            // Handle SQL error
            sqlite3_free(errorMsg);
        }
    }

    static int callback(void *data, int argc, char **argv, char **azColName) {
        auto rows = static_cast<std::vector<std::vector<std::string>> *>(data);
        std::vector<std::string> row;
        for (int i = 0; i < argc; i++) {
            row.push_back(argv[i] ? argv[i] : "NULL");
        }
        rows->push_back(row);
        return 0;
    }

  public:
    Database(const std::string &db_name) : db_name(db_name) {
        int rc = sqlite3_open(db_name.c_str(), &db);
        if (rc) {
            // Handle error
        }
    }

    ~Database() { sqlite3_close(db); }

    void createTables() {
        std::string studentTable =
            "CREATE TABLE IF NOT EXISTS students (id INTEGER PRIMARY KEY, name TEXT, department TEXT);";
        std::string courseTable =
            "CREATE TABLE IF NOT EXISTS courses (id INTEGER PRIMARY KEY, name TEXT, credits INTEGER);";
        std::string scoreTable = "CREATE TABLE IF NOT EXISTS scores (student_id INTEGER, course_id INTEGER, "
                                 "score_value INTEGER, PRIMARY KEY(student_id, course_id));";

        executeQuery(studentTable);
        executeQuery(courseTable);
        executeQuery(scoreTable);
    }

    void addStudent(const Student &student) {
        std::string query = "INSERT INTO students (id, name, department) VALUES (" + student.to_db_string() + ");";
        executeQuery(query);
    }

    void addCourse(const Course &course) {
        std::string query = "INSERT INTO courses (id, name, credits) VALUES (" + course.to_db_string() + ");";
        executeQuery(query);
    }

    void addScore(const Score &score) {
        std::string query =
            "INSERT INTO scores (student_id, course_id, score_value) VALUES (" + score.to_db_string() + ");";
        executeQuery(query);
    }
    void removeStudent(int student_id) {
        std::string query = "DELETE FROM students WHERE id = " + std::to_string(student_id) + ";";
        executeQuery(query);
    }

    void removeCourse(int course_id) {
        std::string query = "DELETE FROM courses WHERE id = " + std::to_string(course_id) + ";";
        executeQuery(query);
    }

    void removeScore(int student_id, int course_id) {
        std::string query = "DELETE FROM scores WHERE student_id = " + std::to_string(student_id) +
                            " AND course_id = " + std::to_string(course_id) + ";";
        executeQuery(query);
    }

    std::vector<Student> queryStudents(const std::string &condition = "") {
        std::string query = "SELECT * FROM students";
        if (!condition.empty()) {
            query += " WHERE " + condition;
        }
        query += ";";

        std::vector<std::vector<std::string>> rows;
        char *errMsg = nullptr;
        int rc = sqlite3_exec(db, query.c_str(), callback, &rows, &errMsg);
        if (rc != SQLITE_OK) {
            sqlite3_free(errMsg);
        }

        std::vector<Student> students;
        for (const auto &row : rows) {
            students.emplace_back(std::stoi(row[0]), row[1], row[2]);
        }

        return students;
    }

    std::vector<Course> queryCourses(const std::string &condition = "") {
        std::string query = "SELECT * FROM courses";
        if (!condition.empty()) {
            query += " WHERE " + condition;
        }
        query += ";";

        std::vector<std::vector<std::string>> rows;
        char *errMsg = nullptr;
        int rc = sqlite3_exec(db, query.c_str(), callback, &rows, &errMsg);
        if (rc != SQLITE_OK) {
            sqlite3_free(errMsg);
        }

        std::vector<Course> courses;
        for (const auto &row : rows) {
            courses.emplace_back(std::stoi(row[0]), row[1], std::stoi(row[2]));
        }

        return courses;
    }

    std::vector<Score> queryScores(const std::string &condition = "") {
        std::string query = "SELECT * FROM scores";
        if (!condition.empty()) {
            query += " WHERE " + condition;
        }
        query += ";";

        std::vector<std::vector<std::string>> rows;
        char *errMsg = nullptr;
        int rc = sqlite3_exec(db, query.c_str(), callback, &rows, &errMsg);
        if (rc != SQLITE_OK) {
            sqlite3_free(errMsg);
        }

        std::vector<Score> scores;
        for (const auto &row : rows) {
            scores.emplace_back(std::stoi(row[0]), std::stoi(row[1]), std::stoi(row[2]));
        }
        return scores;
    }

    void updateScore(int student_id, int course_id, const Score &score) {
        std::string query = "UPDATE scores SET score_value = " + std::to_string(score.score) +
                            " WHERE student_id = " + std::to_string(student_id) +
                            " AND course_id = " + std::to_string(course_id) + ";";
        executeQuery(query);
    }
};
