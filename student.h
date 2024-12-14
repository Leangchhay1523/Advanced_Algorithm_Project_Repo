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
  std::vector<std::string> subjectLearned; // Store strings of subjects ID, Ex: [SJ0001, SJ0002, etc]
  std::map<std::string, float> subjectScores; // Store key which is string of subjects ID along with the value
  float average;
  char finalRank; // A, B, C, D, F
  std::string rankDescription; // Excellent, Very Good, Average, Good, Fail

public:
  Student(std::string id, std::string name, std::string gender, int groupNumber, std::vector<std::string> subjectLearned, 
  std::map<std::string, float> subjectScores){
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->groupNumber = groupNumber;
    this->subjectLearned = subjectLearned;
    this->subjectScores = subjectScores;
    average = calculatAverage();
    calculateFinalRank();
  }

  // Calculate Average
  float calculatAverage(){
    int size = subjectScores.size();
    float sum = 0;

    for (auto score : subjectScores)
    {
      sum += score.second;
    }
    
    float average = sum / size;
    return average;
  }

  // Calculate Final Rank
  void calculateFinalRank(){
    if (average >= 90 && average <= 100)
      finalRank = 'A';
    else if (average >= 80 && average <= 89)
      finalRank = 'B';
    else if (average >= 70 && average <= 79 )
      finalRank = 'C';
    else if (average >= 60 && average <= 69)
      finalRank = 'D';
    else if 
  }
};

#endif