#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H

#include "student.h"

#include <vector>
#include <map>
#include <string>

class studentNode{
public:
// Attributes
    Student student;    
    studentNode* next;
// Methods
    // Constructor
    studentNode(Student student) : student(student), next(nullptr) {}
};
#endif 