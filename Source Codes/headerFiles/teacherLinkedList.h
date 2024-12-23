// Sathya Task
#ifndef TEACHER_LINKED_LIST_H
#define TEACHER_LINKED_LIST_H

#include "teacherNode.h"
#include "teacher.h"
#include <string>
#include <vector>
using namespace std; 

class teacherLinkedList{
// Attributes
  TeacherNode* head;
  int size;
public:
// Methods
  // Constructor 
  teacherLinkedList() : head(nullptr), size(0){}

  // Create a new teacher record
  void createTeacher( const Teacher& teacher){
    TeacherNode* newNode = new TeacherNode(teacher);
    if ( head == nullptr)
    {
      newNode->next = head;
      head = newNode;
    }
    else
    {
      TeacherNode* temp = head;   
      while (temp->next != nullptr)
      {
        temp = temp-> next;
      }
        temp->next = newNode;
    }
    size ++;
  }
  // input data for new teacher
  Teacher inputDataNewTeacher(){
    string id, name, gender, subjectTaught;
    float salary;
    idAgain:
    cout << "Enter teacher ID (TC###) : ";
    fflush(stdin);
    getline(cin, id);

    TeacherNode* temp = head;
    while (temp != nullptr) {
      if (temp->teacher.getId() == id) {
        cout << "Id Exist" << endl;
        goto idAgain;
      }
      temp = temp->next;
    }
    cout << "Enter teacher name : ";
    getline(cin, name);
    cout << "Enter teacher gender : ";
    getline(cin, gender);
    cout << "Enter subject assigns to teacher (Subject's name) : ";
    getline(cin, subjectTaught);
    cout << "Enter teacher salary : ";
    cin >> salary;

    Teacher teacher(id, name, gender, subjectTaught, salary);
    createTeacher(teacher);
  }
  // Edit a teacher record
  void editTeacher(const std::string& ID){
    TeacherNode* current = head;
    while ( current)
    {
      if ( current->teacher.getId() == ID)
      {
        std::cout << "\n Teacher found" << std::endl;
        std::cout << current->teacher.printTeacher() << std::endl;

        std::string newName, newGender, newSubject;
        float newSalary;

        std::cout << "\n Enter new name (or press Enter to keep current): ";
        std::getline(std::cin, newName);  
        if (!newName.empty())
        {
          current->teacher.setName(newName);
        }
        std::cout << "Enter new gender (or press Enter to keep current): ";
        std::getline(std::cin, newGender);
        if (!newGender.empty()) 
        {
          current->teacher.setGender(newGender);
        }
        std::cout << "Enter new subject (or press Enter to keep current): ";
        std::getline(std::cin, newSubject);
        if (!newSubject.empty()) 
        {
          current->teacher.setSubject(newSubject);
        }
        std::cout << "Enter new salary (or 0 to keep current): ";
        std::cin >> newSalary;
        if (newSalary > 0) 
        {
          current->teacher.setSalary(newSalary);
        }
        std::cin.ignore(); 
        std::cout << "\n Teacher record updated successfully.\n";
        return;
      }
      current = current->next;
    }
    std::cout << "\n Teacher not found!" << std::endl;
  }  

  // Delete a teacher record
  void deleteTeacher( const std::string& ID){
    TeacherNode* temp = head;
    TeacherNode* previous = head;
    // Check for head
    if (head->teacher.getID() == ID){
        head = temp->next;
        delete temp;
        temp = nullptr;
        size--;
        overWriteToFile();
    }
    while (temp != nullptr){
        if (temp->teacher.getID() == ID){
            previous->next = temp->next;
            delete temp;
            temp = nullptr;
            size--;
            overWriteToFile();
        }
        previous = temp;
        temp = temp->next;
    } 
  }

  // View all teachers
  void viewTeacher(){
    if ( !head)
    {
      std::cout << "\n Teacher list is empty." << std::endl;
      return;
    }
    TeacherNode* temp = head;
    while (temp)
    {
      std::cout << temp->teacher.printTeacher() << std::endl;
      temp = temp->next;
    }
    
  }

  vector<string> generateNameList(){
        if (head == nullptr){
            return {};
        }
        vector<string> nameList;
        TeacherNode* temp = head;
        while (temp != nullptr){
            nameList.push_back(temp->teacher.getName());
            temp = temp->next;
        }
        return nameList;
    }

  vector<string> generateSubjectTaughtList(){
        if (head == nullptr){
            return {};
        }
        vector<string> nameList;
        TeacherNode* temp = head;
        while (temp != nullptr){
            nameList.push_back(temp->teacher.getSubject());
            temp = temp->next;
        }
        return nameList;
    }

  // Filter View : 
    // Options  : Filter by
      // 1. Gender : If user choose male then only show male teachers, if user choose female then only show female teachers
      // 2. Subject : If user choose a subject then show all teachers who teach that subject
      // 3. Salary Range : If user choose a salary range then show all teachers who have salary between that range
      // 4. Name or ID : If user choose a name or ID then show the teacher who have that name or ID (Similar to search)
  vector<string> filterTeacher(string variable, string id, string name, string gender, string subject,  pair<float, float> salary){
    vector<string> idList;
    TeacherNode* temp = head;

    if (variable == "ID"){
        while (temp != nullptr){
            if (temp->teacher.getID() == id){
                idList.push_back(temp->teacher.getID());
            }
            temp = temp->next;
        }
    }
    else if (variable == "Name"){
        while (temp != nullptr){
            if (temp->teacher.getName() == name){
                idList.push_back(temp->teacher.getID());
            }
            temp = temp->next;
        }
    }
    else if (variable == "Gender"){
        while (temp != nullptr){
            if (temp->teacher.getGender() == gender){
                idList.push_back(temp->teacher.getID());
            }
            temp = temp->next;
        }
    }
    else if (variable == "Salary"){
        while (temp != nullptr){
            if (temp->teacher.getSalary() >= salary.first && temp->teacher.getSalary() <= salary.second){
                idList.push_back(temp->teacher.getID());
            }
            temp = temp->next;
        }
    }
    else if (variable == "Subject"){
        while (temp != nullptr){
            if (temp->teacher.getSubject() == subject){
                idList.push_back(temp->teacher.getID());
            }
            temp = temp->next;
        }
    }
    return idList;
  }

  void readFromFile() {
    std::ifstream file("teacherData.txt");
    if (!file){
        std::cout << "Cannot Open File" << std::endl;
        return;
    }

    std::string data, id, name, gender, subjectTaught;
    float salary;

    while (getline(file, data)) {
      if (data == "---"){
        continue;
      }
      id = data;
      getline(file, name);
      getline(file, gender);
      getline(file, subjectTaught);
      getline(file, data);
      salary = stof(data);

      Teacher teacher(id, name, gender, subjectTaught, salary);
      createTeacher(teacher);
    }
  }

  int getSize() {
    return size;
  }

  void writeToFile() {
    TeacherNode* temp = head;
    while (temp != nullptr) {
      temp->teacher.writeToFile();
      temp = temp->next;
    }
  }

  void overWriteToFile(){
        if (head == nullptr){
            std::ofstream file("teacherData.txt");
            if (!file) {
                std::cout << "Failed to open the file!" << std::endl;
                return;
            }
            file << "";
            return;
        }
        else{
            head->teacher.overWriteToFile();

            if (head->next == nullptr){
                return;
            }
            else{
                TeacherNode* temp = head->next;

                while(temp != nullptr){
                    temp->teacher.writeToFile();
                    temp = temp->next;
                }
            }
        } 
    }

    void display() {
      if (head == nullptr){
        std::cout << "Fail" << std::endl;
        return;
      }
      TeacherNode* temp = head;
      while (temp != nullptr){
        std::cout << temp->teacher.printTeacher() << std::endl;
        temp = temp->next;
      }
    }

    void displayByID(vector<string> idList, vector<string> labels){
        if (size == 0){
            cout << "No Records" << endl;
            return;
        }
        for (int i = 0; i < idList.size(); i++){
            TeacherNode* temp = head;
            while (temp != nullptr){
                if (temp->teacher.getId() == idList[i]){
                    temp->teacher.coutRecord(labels);
                    cout << endl;
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void displayTable(vector<string> labels){
        if (size == 0){
            cout << "No Records" << endl;
            return;
        }
        TeacherNode* temp = head;

        while (temp != nullptr){
            temp->teacher.coutRecord(labels);
            temp = temp->next;
            cout << endl;
        }
    }

    vector<string> generateIDList(){
      TeacherNode* temp = head;
      vector<string> idList;
      while (temp != nullptr) {
        idList.push_back(temp->teacher.getId());
        temp = temp->next;
      }
      return idList;
    }

    vector<string> coutHeader(){
    string line = "-";
    vector<string> labels = {" Teacher ID ", " Name            ", " Gender ", " Subject Taught ", " Salary  "};
    string labelLine = "|";
    for (int i = 0; i < labels.size(); i++){
        labelLine += labels[i] + "|";
    }
    int lineSize = labelLine.length();
    for (int i = 0; i < lineSize; i++){
        cout << line;
    }
    cout << endl;
    cout << labelLine << endl;
    for (int i = 0; i < lineSize; i++){
        cout << line;
    }
    cout << endl;
    return labels;
  }

  TeacherNode* getHead() {
    return head;
  }

  int countDigit(int num){
        return to_string(abs(num)).length();
  }
  // sort
  vector<string> idInsertionSort(bool ascending){
        vector<string> idList = generateIDList();
        int size = idList.size();
        if (ascending){
            for (int i = 1; i <= size - 1; i++)
            {
                int currentValue = stoi(idList[i].substr(2));
                int j = i - 1;

                while (j >= 0 && stoi(idList[j].substr(2)) > currentValue)
                {
                    idList[j + 1] = idList[j];
                    j--;
                }
                if (countDigit(currentValue) == 1){
                    idList[j + 1] = "TC00" + to_string(currentValue);
                }
                else if (countDigit(currentValue) == 2){
                    idList[j + 1] = "TC0" + to_string(currentValue);
                }
                else{
                    idList[j + 1] = "TC" + to_string(currentValue);
                }
            }
            return idList;
        }
        else{
            for (int i = 1; i <= size - 1; i++)
            {
                int currentValue = stoi(idList[i].substr(2));
                int j = i - 1;

                while (j >= 0 && stoi(idList[j].substr(2)) < currentValue)
                {
                    idList[j + 1] = idList[j];
                    j--;
                }
                if (countDigit(currentValue) == 1){
                    idList[j + 1] = "TC00" + to_string(currentValue);
                }
                else if (countDigit(currentValue) == 2){
                    idList[j + 1] = "TC0" + to_string(currentValue);
                }
                else{
                    idList[j + 1] = "TC" + to_string(currentValue);
                }
            }
            return idList;
        }
        
    }

    vector<string> salaryInsertionSort(bool ascending) {
        //your code here
        vector<pair<float, string>> averageId;

        TeacherNode* temp = head;

        while (temp != nullptr){
            averageId.push_back({temp->teacher.getSalary(), temp->teacher.getID()});
            temp = temp->next;
        }

        int size = averageId.size();

        if (ascending){
            for (int i = 1; i <= size - 1; i++){
                pair<int, string> currentPair = averageId[i];
                int j = i - 1;

                while (j >= 0 && averageId[j].first > currentPair.first)
                {
                    averageId[j + 1] = averageId[j];
                    j--;
                }
                averageId[j + 1] = currentPair;
            }
        }
        else{
            for (int i = 1; i <= size - 1; i++){
                pair<int, string> currentPair = averageId[i];
                int j = i - 1;

                while (j >= 0 && averageId[j].first < currentPair.first)
                {
                    averageId[j + 1] = averageId[j];
                    j--;
                }
                averageId[j + 1] = currentPair;
            }
        }
        
        
        vector<string> idList;
        for (int i = 0; i < averageId.size(); i++){
            idList.push_back(averageId[i].second);
        }
        return idList;
    }

    
void printHeader(string text){
    int textLength = text.length();
    int sizeToPrint = textLength + 10;
    
    for (int i = 0; i < sizeToPrint; i++)
    {
        cout << "-";
    }
    cout << endl;
    
    cout << "---- " << "\033[1m" << text << "\033[0m" << " ----" << endl;
    
    for (int i = 0; i < sizeToPrint; i++)
    {
        cout << "-";
    }
    cout << endl << "Note : Input 0 to go back" << endl << endl;
}
};

#endif 