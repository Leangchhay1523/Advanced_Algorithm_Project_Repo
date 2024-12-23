#ifndef STUDENT_GROUP_NODE_h
#define STUDENT_GROUP_NODE_h

#include "studentGroup.h"

class studentGroupNode{
public:
// Attributes
    studentGroup studentgroup;
    studentGroupNode* next;
// Methods
    studentGroupNode(studentGroup studentgroup) : studentgroup(studentgroup), next(nullptr) {}
};

#endif 