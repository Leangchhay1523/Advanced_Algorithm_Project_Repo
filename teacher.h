// Sathya Task

#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>

class Teacher {
// Attributes
  std::string ID; // Ex: TC001
  std::string name;
  std::string gender;
  float salary;
  std::vector<std::string> subjectTaught;
  bool isAssign; // True : Teacher is assigned to a subject, False : Teacher is not

public:
// Methods
};

#endif