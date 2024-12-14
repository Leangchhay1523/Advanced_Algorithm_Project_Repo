#ifndef SUBJECT_NODE_H
#define SUBJECT_NODE_H

#include "subject.h"

class subjectNode{
public:
// Attributes
    Subject subject;
    subjectNode* next;

// Methods
    // Constructor
    subjectNode(Subject subject) : subject(subject), next(nullptr) {}

};


#endif 