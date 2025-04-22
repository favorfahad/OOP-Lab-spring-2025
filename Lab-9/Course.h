// Name: Fahad Qureshi
// Roll No: 24K-0824

#ifndef COURSE_H
#define COURSE_H

class Course {
    protected:
    string courseCode;
    int credits;
    public:
    Course(string code, int cr) : courseCode(code), credits(cr) {}
    virtual void calculateGrade() = 0;
    virtual void displayInfo() = 0;
};

#endif