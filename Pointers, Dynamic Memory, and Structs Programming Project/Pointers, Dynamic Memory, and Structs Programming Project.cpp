#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int idNum;
    int* tests;
    double average;
    char grade;
};

Student* getData(ifstream& file, int& studentCnt, int& testsCnt);
void calcAverage(Student students[], int studentCnt, int testsCnt);
void displayReport(const Student students[], int studentCnt);
char calculateGrade(double average);

int main() {
    string filename = "grades.txt";
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int numStudents, numTests;
    Student* students = getData(inFile, numStudents, numTests);
    calcAverage(students, numStudents, numTests);
    displayReport(students, numStudents);

    for (int i = 0; i < numStudents; i++) {
        delete[] students[i].tests;
    }
    delete[] students;

    return 0;
}

Student* getData(ifstream& file, int& studentCnt, int& testsCnt) {
    file >> studentCnt >> testsCnt;
    Student* students = new Student[studentCnt];

    for (int i = 0; i < studentCnt; i++) {
        file >> students[i].name >> students[i].idNum;
        students[i].tests = new int[testsCnt];
        for (int j = 0; j < testsCnt; j++) {
            file >> students[i].tests[j];
        }
    }
    return students;
}

void calcAverage(Student students[], int studentCnt, int testsCnt) {
    for (int i = 0; i < studentCnt; i++) {
        int total = 0;
        for (int j = 0; j < testsCnt; j++) {
            total += students[i].tests[j];
        }
        students[i].average = static_cast<double>(total) / testsCnt;
        students[i].grade = calculateGrade(students[i].average);
    }
}

void displayReport(const Student students[], int studentCnt) {
    cout << left << setw(10) << "Name" << setw(10) << "ID" << setw(10) << "Average" << "Grade" << endl;
    for (int i = 0; i < studentCnt; i++) {
        cout << left << setw(10) << students[i].name << setw(10) << students[i].idNum
            << setw(10) << fixed << setprecision(2) << students[i].average << students[i].grade << endl;
    }
}

char calculateGrade(double average) {
    if (average >= 91) return 'A';
    if (average >= 81) return 'B';
    if (average >= 71) return 'C';
    if (average >= 61) return 'D';
    return 'F';
}
