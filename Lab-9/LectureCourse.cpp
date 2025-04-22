#include <iostream>
#include "LectureCourse.h"
using namespace std;

void LectureCourse::calculateGrade() {
    cout << "Calculating grade based on exams (70%) + assignments (30%)\n";
}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << " (" << credits << " credits)\n";
}