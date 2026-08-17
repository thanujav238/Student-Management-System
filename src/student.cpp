#include "student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void saveStudents(const vector<Student>& students) {

    ofstream file("data/students.txt");

    if (!file) {
        cout << "Error: Could not open file for saving.\n";
        return;
    }

    for (const Student& student : students) {

        file << student.rollNumber << "|"
             << student.name << "|"
             << student.marks << endl;
    }

    file.close();
}


void loadStudents(vector<Student>& students) {

    ifstream file("data/students.txt");

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        size_t firstSeparator = line.find('|');
        size_t secondSeparator =
            line.find('|', firstSeparator + 1);

        if (firstSeparator == string::npos ||
            secondSeparator == string::npos) {
            continue;
        }

        Student student;

        student.rollNumber =
            stoi(line.substr(0, firstSeparator));

        student.name =
            line.substr(
                firstSeparator + 1,
                secondSeparator - firstSeparator - 1
            );

        student.marks =
            stof(line.substr(secondSeparator + 1));

        students.push_back(student);
    }

    file.close();
}


bool rollNumberExists(const vector<Student>& students, int rollNumber) {

    for (const Student& student : students) {

        if (student.rollNumber == rollNumber) {
            return true;
        }
    }

    return false;
}