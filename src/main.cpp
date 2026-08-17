#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "student.h"

using namespace std;

int main() {

    vector<Student> students;

    loadStudents(students);

    int choice;

    do {

        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Student Statistics\n";
        cout << "7. Sort Students\n";
        cout << "8. Exit\n";
    while (true) {

    cout << "Enter your choice: ";
    cin >> choice;

    if (cin.fail()) {

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Please enter a number.\n";
        continue;
    }

    if (choice < 1 || choice > 8) {

        cout << "Invalid choice! Please select a number between 1 and 8.\n";
        continue;
    }

    break;
}

        if (choice == 1) {

            Student student;

            while (true) {

    cout << "Enter roll number: ";

    cin >> student.rollNumber;

    if (cin.fail()) {

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Please enter a number.\n";
        continue;
    }

    if (student.rollNumber <= 0) {

        cout << "Invalid roll number! Please enter a positive number.\n";
        continue;
    }

    if (rollNumberExists(students, student.rollNumber)) {

        cout << "Roll number already exists! Please enter a different roll number.\n";
        continue;
    }

    break;
}

            cin.ignore();

            cout << "Enter student name: ";
            getline(cin, student.name);

            while (true) {

    cout << "Enter marks (0-100): ";

    cin >> student.marks;

    if (cin.fail()) {

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Invalid input! Please enter a number.\n";
        continue;
    }

    if (student.marks < 0 || student.marks > 100) {

        cout << "Invalid marks! Please enter a value between 0 and 100.\n";
        continue;
    }

    break;
}

            students.push_back(student);

            saveStudents(students);

            cout << "Student added successfully!\n";
        }

        else if (choice == 2) {

            if (students.empty()) {

                cout << "No students available.\n";
            }
            else {

                cout << "\n===== STUDENT LIST =====\n";

                for (const Student& student : students) {

                    cout << "Roll Number: "
                         << student.rollNumber << endl;

                    cout << "Name: "
                         << student.name << endl;

                    cout << "Marks: "
                         << student.marks << endl;

                    cout << "-------------------------\n";
                }
            }
        }

        else if (choice == 3) {

            int rollNumber;
            bool found = false;

            cout << "Enter roll number to search: ";
            cin >> rollNumber;

            for (const Student& student : students) {

                if (student.rollNumber == rollNumber) {

                    cout << "\nStudent Found!\n";
                    cout << "Roll Number: "
                         << student.rollNumber << endl;
                    cout << "Name: "
                         << student.name << endl;
                    cout << "Marks: "
                         << student.marks << endl;

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 4) {

            int rollNumber;
            bool found = false;

            cout << "Enter roll number of student to update: ";
            cin >> rollNumber;

            for (Student& student : students) {

                if (student.rollNumber == rollNumber) {

                    cin.ignore();

                    cout << "Enter new name: ";
                    getline(cin, student.name);

                    cout << "Enter new marks: ";
                    cin >> student.marks;

                    saveStudents(students);

                    cout << "Student updated successfully!\n";

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 5) {

            int rollNumber;
            bool found = false;

            cout << "Enter roll number of student to delete: ";
            cin >> rollNumber;

            for (auto it = students.begin();
                 it != students.end();
                 ++it) {

                if (it->rollNumber == rollNumber) {

                    students.erase(it);

                    saveStudents(students);

                    cout << "Student deleted successfully!\n";

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 6) {

            if (students.empty()) {

                cout << "No students available "
                     << "to calculate statistics.\n";
            }
            else {

                float totalMarks = 0;
                float highestMarks = students[0].marks;
                float lowestMarks = students[0].marks;

                for (const Student& student : students) {

                    totalMarks += student.marks;

                    if (student.marks > highestMarks) {
                        highestMarks = student.marks;
                    }

                    if (student.marks < lowestMarks) {
                        lowestMarks = student.marks;
                    }
                }

                float averageMarks =
                    totalMarks / students.size();

                cout << "\n===== STUDENT STATISTICS =====\n";
                cout << "Total Students: "
                     << students.size() << endl;
                cout << "Average Marks: "
                     << averageMarks << endl;
                cout << "Highest Marks: "
                     << highestMarks << endl;
                cout << "Lowest Marks: "
                     << lowestMarks << endl;
            }
        }

        else if (choice == 7) {

            if (students.empty()) {

                cout << "No students available to sort.\n";
            }
            else {

                int sortChoice;

                cout << "\n===== SORT STUDENTS =====\n";
                cout << "1. Highest marks to lowest\n";
                cout << "2. Lowest marks to highest\n";
                cout << "3. Back\n";
                cout << "Enter your choice: ";

                cin >> sortChoice;

                if (sortChoice == 1) {

                    sort(
                        students.begin(),
                        students.end(),
                        [](const Student& a,
                           const Student& b) {
                            return a.marks > b.marks;
                        }
                    );

                    saveStudents(students);

                    cout << "Students sorted from "
                         << "highest to lowest marks.\n";
                }

                else if (sortChoice == 2) {

                    sort(
                        students.begin(),
                        students.end(),
                        [](const Student& a,
                           const Student& b) {
                            return a.marks < b.marks;
                        }
                    );

                    saveStudents(students);

                    cout << "Students sorted from "
                         << "lowest to highest marks.\n";
                }

                else if (sortChoice == 3) {

                    cout << "Returning to main menu.\n";
                }

                else {

                    cout << "Invalid choice.\n";
                }
            }
        }

        else if (choice == 8) {

            saveStudents(students);

            cout << "Data saved successfully.\n";
            cout << "Exiting program...\n";
        }

        else {

            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}