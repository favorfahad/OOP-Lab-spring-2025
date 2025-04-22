#include <iostream>
#include "LabCourse.h"
using namespace std;

void LabCourse::calculateGrade() {
    cout << "Calculating grade based on lab work (60%) + reports (40%)\n";
}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << " (" << credits << " credits)\n";
}