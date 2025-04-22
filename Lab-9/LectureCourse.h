// Name: Fahad Qureshi
// Roll No: 24K-0824

#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H
#include "Course.h"
#include "iostream"
using namespace std;

class LectureCourse : public Course {
    public:
    LectureCourse(string code, int cr) : Course(code, cr) {}
    void calculateGrade() override;
    void displayInfo() override;
};

#endif