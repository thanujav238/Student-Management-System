#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    int rollNumber;
    std::string name;
    float marks;
};

void saveStudents(const std::vector<Student>& students);

void loadStudents(std::vector<Student>& students);

bool rollNumberExists(const std::vector<Student>& students, int rollNumber);

#endif