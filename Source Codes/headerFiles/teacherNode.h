#ifndef TEACHERNODE_H
#define TEACHERNODE_H

#include "teacher.h"
#include <string>

class TeacherNode 
{
public:
// Attributes
  Teacher teacher;
  TeacherNode* next;

// Methods
  // Constructor
  TeacherNode(Teacher teacher) : teacher(teacher), next(nullptr) {};
};

#endif