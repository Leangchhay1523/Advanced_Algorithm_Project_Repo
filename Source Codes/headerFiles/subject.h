#ifndef SUBJECT_H
#define SUBJECT_H

#include <map>
#include <string>
using namespace std;

class Subject {
    string ID;
    string name;
    string taughtBy;
    float maxScore;
public:
    Subject(string id, string name, string taughtBy, float maxScore){
        this->ID = id;
        this->name = name;
        this->taughtBy = taughtBy;
        this->maxScore = maxScore;
    }

    Subject(string id, string name, float maxScore){
        this->ID = id;
        this->name = name;
        this->maxScore = maxScore;
    }

    std::string getID() const { return ID;}
    std::string getName() const { return name;}
    std::string getTaughtBy() const { return taughtBy;}
    float getMaxScore() const { return maxScore;}

    void setName(const std::string& newName) { name = newName;}
    void setTaughtBy( const std::string& newTaugtBy) { taughtBy = newTaugtBy;}
    void setMaxScore( float newMaxScore) { maxScore = newMaxScore;}
    void setSubject(const std::string& newID, const std::string& newName, const std::string& newTaughtBy, float newMaxScore) 
    {
      if (!newID.empty()) ID = newID;
      if (!newName.empty()) name = newName;
      if (!newTaughtBy.empty()) taughtBy = newTaughtBy;
      if (newMaxScore > 0) maxScore = newMaxScore;
    }

    void writeToFile(){
        ofstream file("subjectData.txt", ios::app);
        if (!file) {
            cout << "Failed to open the file!" << endl;
            return;
        }

        file << ID << endl;
        file << name << endl;
        file << taughtBy << endl;
        file << maxScore << endl;
        file << "---" << endl;
    }

    string convertFloattoString(float value) {
        ostringstream num;
        num << fixed << setprecision(2) << value; 
        return num.str();
    }

    void overWriteToFile(){
        ofstream file("subjectData.txt");
        if (!file) {
            cout << "Failed to open the file!" << endl;
            return;
        }

        file << ID << endl;
        file << name << endl;
        file << taughtBy << endl;
        file << maxScore << endl;
        file << "---" << endl;
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

      // taught by
      records += " " + taughtBy;
      spaceSize = labels[2].length() - 1 - taughtBy.length();
      for (int i = 0; i < spaceSize; i++) {
          records += space;
      }
      records += "|";

      // Max Score
      string maxScoreStr = convertFloattoString(maxScore); // Format the float to 2 decimal places
      records += " " + maxScoreStr;
      spaceSize = labels[3].length() - 1 - maxScoreStr.length();
      for (int i = 0; i < spaceSize; i++) {
          records += space;
      }
      records += "|";

      cout << records << endl;
    }
    std::string printSubject() 
    {
      return  "ID :" + ID + "\nName :" + name + "\nTaught by :" + taughtBy + "\nMaximum score :" + std::to_string(maxScore);
    }
};


#endif 