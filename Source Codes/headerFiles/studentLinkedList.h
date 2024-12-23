#ifndef STUDENT_LINKED_LIST_H
#define STUDENT_LINKED_LIST_H

#include "student.h"
#include "studentNode.h"
#include "subjectLinkedList.h"
#include "studentGroup.h"
#include "studentGroupNode.h"
#include "studentGroupLinkedList.h"
#include "subject.h"
#include "subjectNode.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

class studentLinkedList{
// Attributes
    studentNode* head;
    int size;
public:
// Methods
    //Constructor 
    studentLinkedList() : head(nullptr), size(0) {}

    ~studentLinkedList() {
        while (head != nullptr) {
            studentNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Create New Student
    void createStudent(Student student){
        if (head == nullptr){
            head = new studentNode(student);
        }
        else{
            studentNode* newnode = new studentNode(student);
            
            studentNode* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        size++;
    }

    int findMaxStudentGroup(){
        studentNode* temp = head;
        int max = temp->student.getGroupNumber();
        while (temp != nullptr){
            if (max < temp->student.getGroupNumber()){
                max = temp->student.getGroupNumber();
            }
            temp = temp->next;
        }
        return max;
    }
    // Managing Data for New Student
    Student inputDataNewStudent(vector<string> subjectLearned, subjectLinkedList subjectList, int maxGroupNum)
    {
        string id, name, gender;
        int groupNum;
        map<string, float> subjectScore;
        float tempScore;
        int subjectSize = subjectLearned.size();

        idAgain:
        cout << "Enter student's ID (SD###) : ";
        fflush(stdin);
        getline(cin, id);

        studentNode* temp1 = head;
        while (temp1 != nullptr){
            if (id == temp1->student.getID()){
                cout << "ID exist, Please enter a new ID" << endl;
                goto idAgain;
            }
            temp1 = temp1->next;
        } 

        cout << "Enter student's Name : ";
        fflush(stdin);
        getline(cin, name);
        cout << "Enter student's Gender : ";
        fflush(stdin);
        getline(cin, gender); 
        groupNumber:
        cout << "Enter student's Group Number : ";
        cin >> groupNum;
        if (groupNum < 0 || groupNum > maxGroupNum){
            cout << "Invalid Group Number" << endl;
            goto groupNumber;
        }

        subjectNode* temp = subjectList.getHead();
        for (int i = 0; i < subjectSize; i++){
            cout << "Enter " << subjectLearned[i] << "'s score : ";
            cin >> tempScore;
            
            subjectScore[subjectLearned[i]] = tempScore;
        }

        Student student(id, name, gender, groupNum, subjectLearned, subjectScore);
        student.writeToFile();
        createStudent(student);
        return student;
    }

    void editStudent(string id, vector<string> subjectLearned, subjectLinkedList subjectList, studentLinkedList studentList) {
        string newName, newGender;
        int newGroupNum;
        map<string, float> subjectScore;
        float tempScore;
        int subjectSize = subjectLearned.size();

        cout << "Edit name: ";
        cin.ignore();
        getline(cin, newName);

        cout << "Edit gender: ";
        getline(cin, newGender);

        cout << "Edit group number: ";
        cin >> newGroupNum;

        for (int i = 0; i < subjectSize; i++) {
            cout << "Edit " << subjectLearned[i] << "'s score: ";
            cin >> tempScore;

            subjectScore[subjectLearned[i]] = tempScore;
        }

        studentNode* temp1 = studentList.getHead(); 
        while (temp1 != nullptr) {
            if (temp1->student.getID() == id) {
                break;
            }
            temp1 = temp1->next;
        }

        if (temp1 != nullptr) {
            temp1->student.changeValue(newName, newGender, newGroupNum, subjectScore);
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }

        studentList.overWriteToFile(); 
    }

    // Delete a Student
    bool deleteStudent(string id){
        studentNode* temp = head;
        studentNode* previous = head;
        // Check for head
        if (head->student.getID() == id){
            head = temp->next;
            delete temp;
            temp = nullptr;
            size--;
            overWriteToFile();
            return true;
        }
        while (temp != nullptr){
            if (temp->student.getID() == id){
                previous->next = temp->next;
                delete temp;
                temp = nullptr;
                size--;
                overWriteToFile();
                return true;
            }
            previous = temp;
            temp = temp->next;
        }
        return false;   
    }

    void viewStudent(){

    }

    // Small Methods
    int getSize(){
        return size;
    }

    studentNode* getHead(){
        return head;
    }

    // Read from File
    void readFromFile(){
        // Declare Attributes Variables
        ifstream file("studentData.txt");
        if (!file){
            cout << "Cannot Open File" << endl;
            return;
        }
        string data, name, id, gender, subject, keyVal, key;
        vector<string> subjectLearned;
        map<string, float> subjectScores;
        int num;
        string value, rankDetail;
        float average;
        char rank;

        while (getline(file, data)){
            if (data == "---"){
                continue;
            }

            id = data;
            getline(file, name);
            getline(file, gender);
            getline(file, data);
            num = stoi(data);

            getline(file, data);
            stringstream subjectStream(data);
            while(getline(subjectStream, subject, ',')){
                subjectLearned.push_back(subject);
            }

            getline(file, data);
            stringstream scoreStream(data);
            while (getline(scoreStream, keyVal, ',')){
                size_t colonPosition = keyVal.find(':');
                if (colonPosition != std::string::npos){
                    key = keyVal.substr(0, colonPosition);
                    value = keyVal.substr(colonPosition + 1);
                    key.erase(remove(key.begin(), key.end(), '"'), key.end());
                    subjectScores[key] = stof(value);
                }
            }

            getline(file, data);
            average = stof(data);

            getline(file, data);
            rank = data[0];

            getline(file, rankDetail);

            Student student(id, name, gender, num, subjectLearned, subjectScores, average, rank, rankDetail);
            createStudent(student);
        }
        cout << "Read Successfully" << endl;
    }

    // Write to File
    void writeToFile(){
        if (head == nullptr)
            return;
        else{
            studentNode* temp = head;

            while(temp != nullptr){
                temp->student.writeToFile();
                temp = temp->next;
            }
        } 
    }

    // Overwrite to File
    void overWriteToFile(){
        if (head == nullptr){
            ofstream file("studentData.txt");
            if (!file) {
                cout << "Failed to open the file!" << endl;
                return;
            }
            file << "";
            return;
        }
        else{
            head->student.overWriteToFile();

            if (head->next == nullptr){
                return;
            }
            else{
                studentNode* temp = head->next;

                while(temp != nullptr){
                    temp->student.writeToFile();
                    temp = temp->next;
                }
            }
        } 
    }

    // Diplay
    void display(){
        studentNode* temp = head;
        while (temp != nullptr){
            temp->student.display();
            temp = temp->next;
            cout << endl;
        }
    }

    void displayTable(vector<string> labels, vector<string> subjectLearned){
        if (size == 0){
            cout << "No Records" << endl;
            return;
        }
        studentNode* temp = head;

        while (temp != nullptr){
            temp->student.coutRecord(labels, subjectLearned);
            temp = temp->next;
            cout << endl;
        }
    }

    vector<string> coutHeader(vector<string> subjectLearned){
        if (head == nullptr){
            return {};
        }
        string line = "-";
        vector<string> labels = {" Student ID ", " Name            ", " Gender    ", " Group Number "};
        for (int i = 0; i < subjectLearned.size(); i++){
            string temp = " ";
            temp += subjectLearned[i] + " ";
            labels.push_back(temp);
        }
        labels.push_back(" Average ");
        labels.push_back(" Final Rank ");
        labels.push_back(" Description       ");
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

    int countDigit(int num){
        return to_string(abs(num)).length();
    }

    vector<string> generateIDList(){
        if (head == nullptr){
            return {};
        }
        vector<string> idList;
        studentNode* temp = head;
        while (temp != nullptr){
            idList.push_back(temp->student.getID());
            temp = temp->next;
        }
        return idList;
    }

    vector<string> generateNameList(){
        if (head == nullptr){
            return {};
        }
        vector<string> nameList;
        studentNode* temp = head;
        while (temp != nullptr){
            nameList.push_back(temp->student.getName());
            temp = temp->next;
        }
        return nameList;
    }

    vector<int> generateGroupNumberList(){
        if (head == nullptr){
            return {};
        }
        vector<int> groupNumberList;
        studentNode* temp = head;
        while (temp != nullptr){
            groupNumberList.push_back(temp->student.getGroupNumber());
            temp = temp->next;
        }
        return groupNumberList;
    }


    vector<string> filterStudent(string variable, string id, string name, string gender, int groupNumber, pair<float, float> average, char finalRank){
        vector<string> idList;
        studentNode* temp = head;

        if (variable == "ID"){
            while (temp != nullptr){
                if (temp->student.getID() == id){
                    idList.push_back(temp->student.getID());
                }
                temp = temp->next;
            }
        }
        else if (variable == "Name"){
            while (temp != nullptr){
                if (temp->student.getName() == name){
                    idList.push_back(temp->student.getID());
                }
                temp = temp->next;
            }
        }
        else if (variable == "Gender"){
            while (temp != nullptr){
                if (temp->student.getGender() == gender){
                    idList.push_back(temp->student.getID());
                }
                temp = temp->next;
            }
        }
        else if (variable == "GroupNum"){
            while (temp != nullptr){
                if (temp->student.getGroupNumber() == groupNumber){
                    idList.push_back(temp->student.getID());
                }
                temp = temp->next;
            }
        }
        else if (variable == "Average"){
            while (temp != nullptr){
                if (temp->student.getAverage() >= average.first && temp->student.getAverage() <= average.second){
                    idList.push_back(temp->student.getID());
                }
                temp = temp->next;
            }
        }
        else if (variable == "Rank"){
            while (temp != nullptr){
                if (temp->student.getFinalRank() == finalRank){
                    idList.push_back(temp->student.getID());
                }
                temp = temp->next;
            }
        }
        return idList;
    }


// Sorting Methods
    // Sorting ID
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
                    idList[j + 1] = "SD00" + to_string(currentValue);
                }
                else if (countDigit(currentValue) == 2){
                    idList[j + 1] = "SD0" + to_string(currentValue);
                }
                else{
                    idList[j + 1] = "SD" + to_string(currentValue);
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
                    idList[j + 1] = "SD00" + to_string(currentValue);
                }
                else if (countDigit(currentValue) == 2){
                    idList[j + 1] = "SD0" + to_string(currentValue);
                }
                else{
                    idList[j + 1] = "SD" + to_string(currentValue);
                }
            }
            return idList;
        }
        
    }

    // Sorting Group Number
    vector<string> groupNumInsertionSort(bool ascending) {
        //your code here
        vector<pair<int, string>> groupId;

        studentNode* temp = head;

        while (temp != nullptr){
            groupId.push_back({temp->student.getGroupNumber(), temp->student.getID()});
            temp = temp->next;
        }

        int size = groupId.size();

        if (ascending){
            for (int i = 1; i <= size - 1; i++){
                pair<int, string> currentPair = groupId[i];
                int j = i - 1;

                while (j >= 0 && groupId[j].first > currentPair.first)
                {
                    groupId[j + 1] = groupId[j];
                    j--;
                }
                groupId[j + 1] = currentPair;
            }
        }
        else{
            for (int i = 1; i <= size - 1; i++){
                pair<int, string> currentPair = groupId[i];
                int j = i - 1;

                while (j >= 0 && groupId[j].first < currentPair.first)
                {
                    groupId[j + 1] = groupId[j];
                    j--;
                }
                groupId[j + 1] = currentPair;
            }
        }
        
        
        vector<string> idList;
        for (int i = 0; i < groupId.size(); i++){
            idList.push_back(groupId[i].second);
        }
        return idList;
    }

    // Sorting Average
    vector<string> averageInsertionSort(bool ascending) {
        //your code here
        vector<pair<int, string>> averageId;

        studentNode* temp = head;

        while (temp != nullptr){
            averageId.push_back({temp->student.getAverage(), temp->student.getID()});
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

// Display Method
    // Display Sort ID
    void displayByID(vector<string> idList, vector<string> labels, vector<string> subjectLearned){
        if (size == 0){
            cout << "No Records" << endl;
            return;
        }
        for (int i = 0; i < idList.size(); i++){
            studentNode* temp = head;
            while (temp != nullptr){
                if (temp->student.getID() == idList[i]){
                    temp->student.coutRecord(labels, subjectLearned);
                    cout << endl;
                    break;
                }
                temp = temp->next;
            }
        }
    }
};

#endif 