#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    float marks;
};

int main() {

    vector<Student> students;

    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Add Student
        if (choice == 1) {

            Student student;

            cout << "Enter roll number: ";
            cin >> student.rollNumber;

            cin.ignore();

            cout << "Enter student name: ";
            getline(cin, student.name);

            cout << "Enter marks: ";
            cin >> student.marks;

            students.push_back(student);

            cout << "Student added successfully!\n";
        }

        // Display Students
        else if (choice == 2) {

            if (students.empty()) {
                cout << "No students available.\n";
            }
            else {

                cout << "\n===== STUDENT LIST =====\n";

                for (const Student& student : students) {

                    cout << "Roll Number: " << student.rollNumber << endl;
                    cout << "Name: " << student.name << endl;
                    cout << "Marks: " << student.marks << endl;
                    cout << "-------------------------\n";
                }
            }
        }

        // Search Student
        else if (choice == 3) {

            int rollNumber;
            bool found = false;

            cout << "Enter roll number to search: ";
            cin >> rollNumber;

            for (const Student& student : students) {

                if (student.rollNumber == rollNumber) {

                    cout << "\nStudent Found!\n";
                    cout << "Roll Number: " << student.rollNumber << endl;
                    cout << "Name: " << student.name << endl;
                    cout << "Marks: " << student.marks << endl;

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        // Update Student
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

                    cout << "Student updated successfully!\n";

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        // Exit
        else if (choice == 5) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}