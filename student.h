#ifndef STUDENT_H
#define STUDENT_H

#include <map>
#include <string>
#include <vector>

class Student {
  std::string id; // Student ID, Ex: SD001
  std::string name;
  std::string gender;
  int groupNumber;
  std::vector<std::string>
      subjectLearned; // Store strings of subjects ID, Ex: [SJ0001, SJ0002, etc]
  std::map<std::string, float>
      subjectScores; // Store key which is string of subjects ID along with the
                     // value
  float average;
  char finalRank;              // A, B, C, D, F
  std::string rankDescription; // Excellent, Very Good, Average, Good, Fail

public:
  Student(std::string id, std::string name, std::string gender, int groupNumber,
          std::vector<std::string> subjectLearned,
          std::map<std::string, float> subjectScores);
};

#endif