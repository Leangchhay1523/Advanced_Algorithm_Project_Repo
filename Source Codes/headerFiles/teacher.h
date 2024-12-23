// Sathya Task

#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

class Teacher {
  private:
// Attributes
  std::string ID; // Ex: TC001
  std::string name;
  std::string gender;
  std::string subjectTaught;
  float salary;

  public:

    Teacher(const std::string& id, const std::string& name, const std::string& gender, const std::string& subjectTaught, float salary)
        : ID(id), name(name), gender(gender), subjectTaught(subjectTaught), salary(salary) {}

// Methods
    void writeToFile() const {
        std::ofstream file("teacherData.txt", std::ios::app);
        if (!file) {
            std::cout << "Failed to open the file!" << std::endl;
            return;
        }
        file << ID << std::endl;
        file << name << std::endl;
        file << gender << std::endl;
        file << subjectTaught << std::endl;
        file << salary << std::endl;
        file << "---" << std::endl;
    }

    float getSalary(){
      return salary;
    }

    string getID(){
      return ID;
    }

    void overWriteToFile() {
      std::ofstream file("teacherData.txt");
      if (!file) {
        std::cout << "Failed to open file!" << std::endl;
        return;
      }
      file << ID << std::endl;
      file << name << std::endl;
      file << gender << std::endl;
      file << subjectTaught << std::endl;
      file << salary << std::endl;
      file << "---" << std::endl;
    }
    


    std::string getId() const { return ID; }

    std::string getName() const { return name; }

    std::string getGender() const { return gender; }

    std::string getSubject() const { return subjectTaught; }

    float getSalary() const { return salary; }

    void setName(const std::string& newName) { name = newName; }

    void setGender(const std::string& newGender) { gender = newGender; }

    void setSubject(const std::string& newSubjectTaught) { subjectTaught = newSubjectTaught; }

    void setSalary(float newSalary) { salary = newSalary; }

    void setTeacher(const std::string& newID, const std::string& newName, const std::string& newGender, const std::string& newSubjectTaught, float newSalary) 
    {
      if (!newID.empty()) ID = newID;
      if (!newName.empty()) name = newName;
      if (!newGender.empty()) gender = newGender;
      if (!newSubjectTaught.empty()) subjectTaught = newSubjectTaught;
      if (newSalary > 0) salary = newSalary;
    }


    std::string printTeacher() 
    {
      return  "ID : " + ID + "\nName : " + name + "\nGender : " + gender + "\nSubject : " + subjectTaught + "\nSalary : " + std::to_string(salary);
    }

    string convertFloattoString(float value) {
        ostringstream num;
        num << fixed << setprecision(2) << value; 
        return num.str();
    }

    void coutRecord(vector<string> labels){
      string records = "|";
      string space = " ";
      int spaceSize;

      // ID
      records += " " + ID;
      spaceSize = labels[0].length() - 1 - ID.length();
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

      // Subject Taught 
      records += " " + subjectTaught;
      spaceSize = labels[3].length() - 1 - subjectTaught.length();
      for (int i = 0; i < spaceSize; i++) {
          records += space;
      }
      records += "|";

      // Salary
      string salaryStr = convertFloattoString(salary); // Format the float to 2 decimal places
      records += " " + salaryStr;
      spaceSize = labels[4].length() - 1 - salaryStr.length();
      for (int i = 0; i < spaceSize; i++) {
          records += space;
      }
      records += "|";

      cout << records << endl;
  }

  
};

#endif