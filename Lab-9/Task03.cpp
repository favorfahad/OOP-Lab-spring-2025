// Name: Fahad Qureshi
// Roll No: 24K-0824

#include "LectureCourse.h"
#include "LabCourse.h"
#include "iostream"
using namespace std;

int main() {
    Course* courses[] = {
        new LectureCourse("CL-1004", 3),
        new LabCourse("CL-2001", 4)
    };

    for(Course* c : courses) {
        c->displayInfo();
        c->calculateGrade();
        cout << endl;
        delete c;
    }
    return 0;
}