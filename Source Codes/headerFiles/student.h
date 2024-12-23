#ifndef STUDENT_H
#define STUDENT_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

class Student {
  std::string id; // Student ID, Ex: SD001
  std::string name;
  std::string gender;
  int groupNumber;
  std::vector<std::string> subjectLearned; 
  std::map<std::string, float> subjectScores; 
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
    calculateFinalRankAndDescription();
  }

  Student(std::string id, std::string name, std::string gender, int groupNumber, std::vector<std::string> subjectLearned, 
  std::map<std::string, float> subjectScores, float average, char finalRank, std::string rankDescription){
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->groupNumber = groupNumber;
    this->subjectLearned = subjectLearned;
    this->subjectScores = subjectScores;
    this->average = average;
    this->finalRank = finalRank;
    this->rankDescription = rankDescription;
  }

  // Calculate Average
  float calculatAverage(){
    int size = subjectLearned.size();
    float sum = 0;

    for (auto score : subjectScores)
    {
      sum += score.second;
    }
    
    float average = sum / size;
    return average;
  }

  // void setValue
  void changeValue(string newName, string newGender, int newGroupNum, map<string, float> newSubjectScore){
    this->name = newName;
    this->gender = newGender;
    this->groupNumber = newGroupNum;
    this->subjectScores = newSubjectScore;
    average = calculatAverage();
    calculateFinalRankAndDescription();
  }

  // Calculate Final Rank & Description
  void calculateFinalRankAndDescription(){
    if (average >= 90 && average <= 100){
      finalRank = 'A';
      rankDescription = "Excellent";
    }
    else if (average >= 80 && average <= 89){
      finalRank = 'B';
      rankDescription = "Very Good";
    }   
    else if (average >= 70 && average <= 79 ){
      finalRank = 'C';
      rankDescription = "Satisfactory";
    }
    else if (average >= 60 && average <= 69){
      finalRank = 'D';
      rankDescription = "Needs Improvement";
    }
    else if (average < 60){
      finalRank = 'F';
      rankDescription  = "Fail";
    }
  }

  std::string getID(){
    return id;
  }

  int getGroupNumber(){
    return groupNumber;
  }
  
  std::string getName(){
    return name;
  }

  float getAverage(){
    return average;
  }

  std::string getGender(){
    return gender;
  }

  char getFinalRank(){
    return finalRank;
  }

  // Write to File
  void writeToFile(){
    ofstream file("studentData.txt", ios::app);
    if (!file) {
        cout << "Failed to open the file!" << endl;
        return;
    }

    file << id << endl;
    file << name << endl;
    file << gender << endl;
    file << groupNumber << endl;
    for (int i = 0; i < subjectLearned.size(); i++){
      file << subjectLearned[i];
      if (i != subjectLearned.size() - 1){
        file << ",";
      }
    }
    file << endl;
    
    for (auto element = subjectScores.begin(); element != subjectScores.end(); ++element) {
      file << "\"" << element->first << "\":" << element->second;

      if (std::next(element) != subjectScores.end()) {
          file << ",";
      }
    }
    file << endl;

    file << average << endl;
    file << finalRank << endl;
    file << rankDescription << endl;
    file << "---" << endl;
  }

  // Overwrite
  void overWriteToFile(){
    ofstream file("studentData.txt");
    if (!file) {
        cout << "Failed to open the file!" << endl;
        return;
    }

    file << id << endl;
    file << name << endl;
    file << gender << endl;
    file << groupNumber << endl;
    for (int i = 0; i < subjectLearned.size(); i++){
      file << subjectLearned[i];
      if (i != subjectLearned.size() - 1){
        file << ",";
      }
    }
    file << endl;
    
    for (auto element = subjectScores.begin(); element != subjectScores.end(); ++element) {
      file << "\"" << element->first << "\":" << element->second;

      if (std::next(element) != subjectScores.end()) {
          file << ",";
      }
    }
    file << endl;

    file << average << endl;
    file << finalRank << endl;
    file << rankDescription << endl;
    file << "---" << endl;
  }

  // Display 
  void display(){
    cout << id << endl;
    cout << name << endl;
    cout << gender << endl;
    cout << groupNumber << endl;
    for (int i = 0; i < subjectLearned.size(); i++){
        cout << subjectLearned[i];
        if (i != subjectLearned.size() - 1){
            cout << ",";
        }
    }
    cout << endl;
    for (auto pair : subjectScores){
        cout << pair.first << ":" << pair.second << endl;
    }
    cout << average << endl;
    cout << finalRank << endl;
    cout << rankDescription << endl;
  }

  string formatFloat(float value) {
        ostringstream num;
        num << fixed << setprecision(2) << value; 
        return num.str();
  }

  void coutRecord(vector<string> labels, vector<string> subjectLearned){
    string records = "|";
    string space = " ";
    int spaceSize;

    // ID
    records += " " + id;
    spaceSize = labels[0].length() - 1 - id.length();
    for (int i = 0; i < spaceSize; i++) {
        records += space;
    }
    records += "|";

    // Name
    records += " " + name;
    spaceSize = labels[1].length() - 1 - name.length();
    for (int i = 0; i < spaceSize; i++) {
        records += space;
    }
    records += "|";

    // Gender
    records += " " + gender;
    spaceSize = labels[2].length() - 1 - gender.length();
    for (int i = 0; i < spaceSize; i++) {
        records += space;
    }
    records += "|";

    // Group Number
    records += " " + to_string(groupNumber);
    spaceSize = labels[3].length() - 1 - to_string(groupNumber).length();
    for (int i = 0; i < spaceSize; i++) {
        records += space;
    }
    records += "|";

    // Subject Scores
    for (int i = 0; i < subjectLearned.size(); i++) {
        auto temp = subjectScores.find(subjectLearned[i]);
        string subjectScore = "0"; 
        if (temp != subjectScores.end()) {
            subjectScore = formatFloat(temp->second); 
        }
        records += " " + subjectScore;
        spaceSize = labels[3 + i + 1].length() - 1 - subjectScore.length();
        for (int j = 0; j < spaceSize; j++) {
            records += space;
        }
        records += "|";
    }

    // Average
    string avgStr = formatFloat(average); 
    records += " " + avgStr;
    spaceSize = labels[3 + subjectLearned.size() + 1].length() - 1 - avgStr.length();
    for (int i = 0; i < spaceSize; i++) {
        records += space;
    }
    records += "|";

    // Rank
    string rank(1, finalRank);
    records += " " + rank;
    spaceSize = labels[3 + subjectLearned.size() + 2].length() - 1 - rank.length();
    for (int i = 0; i < spaceSize; i++) {
        records += space;
    }
    records += "|";

    // Rank Description
    records += " " + rankDescription;
    spaceSize = labels[3 + subjectLearned.size() + 3].length() - 1 - rankDescription.length();
    for (int i = 0; i < spaceSize; i++) {
        records += space;
    }
    records += "|";

    cout << records << endl;
  }
};

#endif