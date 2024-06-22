#ifndef GRADUATE_STUDENT_H
#define GRADUATE_STUDENT_H

#include "Project.h"
#include "Student.h"
#include <iostream>

class Graduate_Student : public Student {
  public:
    Project GStudent_Project;
};

#endif // GRADUATE_STUDENT_H
