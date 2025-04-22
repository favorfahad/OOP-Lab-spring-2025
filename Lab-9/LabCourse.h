// Name: Fahad Qureshi
// Roll No: 24K-0824

#ifndef LABCOURSE_H
#define LABCOURSE_H
#include "Course.h"
#include "iostream"
using namespace std;

class LabCourse : public Course {
    public:
    LabCourse(string code, int cr) : Course(code, cr) {}
    void calculateGrade() override;
    void displayInfo() override;
};

#endif