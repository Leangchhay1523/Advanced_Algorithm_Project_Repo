#ifndef SUBJECT_LINKED_LIST_H
#define SUBJECT_LINKED_LIST_H

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

class subjectLinkedList{
// Attributes
    subjectNode* head;
    int size;
public:
// Methods
    subjectLinkedList() : head(nullptr), size(0) {}

    ~subjectLinkedList() {
        while (head != nullptr) {
            subjectNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Subject inputDataNewSubject(){
        string id, name, teacher;
        float maxScore;
        
        idAgain:
        cout << "Enter subject's ID (SJ###) : ";
        fflush(stdin);
        getline(cin, id);

        subjectNode* temp1 = head;
        while (temp1 != nullptr){
            if (id == temp1->subject.getID()){
                cout << "ID Exist, Plean enter a new ID" << endl;
                goto idAgain;
            }
            temp1 = temp1->next;
        }

        nameAgain:
        cout << "Enter subject's Name : ";
        fflush(stdin);
        getline(cin, name);
        temp1 = head;
        while (temp1 != nullptr){
            if (name == temp1->subject.getName()){
                cout << "Subject already exist" << endl;
                goto nameAgain;
            }
            temp1 = temp1->next;
        }

        cout << "Enter max score : ";
        cin >> maxScore;

        Subject subject(id, name, maxScore);
        createSubject(subject);
        overWriteToFile();
    }

    void createSubject(Subject& subject)
    {
        subjectNode* newNode = new subjectNode(subject);
        if ( head == nullptr)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            subjectNode* temp = head;   
            while (temp->next != nullptr)
            {
                temp = temp-> next;
            }
                temp->next = newNode;
        }
        size ++;

    }

    void deleteSubject( const std::string& ID){
        subjectNode* temp = head;
        subjectNode* previous = head;
        // Check for head
        if (head->subject.getID() == ID){
            head = temp->next;
            delete temp;
            temp = nullptr;
            size--;
            overWriteToFile();
        }
        while (temp != nullptr){
            if (temp->subject.getID() == ID){
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

    subjectNode* getHead(){
        return head;
    }

    int getSize(){
        return size;
    }

    void readFromFile() {
        std::ifstream file("subjectData.txt");
        if (!file){
            std::cout << "Cannot Open File" << std::endl;
            return;
        }

        std::string data, id, name, taughyby;
        float maxScore;

        while (getline(file, data)) {
            if (data == "---"){
                continue;
            }
            id = data;
            getline(file, name);
            getline(file, taughyby);
            getline(file, data);
            maxScore = stof(data);

            Subject subject(id, name, taughyby, maxScore);
            createSubject(subject);
        }
    }

    void displayTable(vector<string> labels){
        if (size == 0){
            cout << "No Records" << endl;
            return;
        }
        subjectNode* temp = head;

        while (temp != nullptr){
            temp->subject.coutRecord(labels);
            temp = temp->next;
            cout << endl;
        }
    }

    vector<string> coutHeader(){
        string line = "-";
        vector<string> labels = {" Subject ID ", " Name            ", " Taught By    ", " Max Score "};
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

    vector<string> generateIDList(){
        if (head == nullptr){
            return {};
        }
        vector<string> idList;
        subjectNode* temp = head;
        while (temp != nullptr){
            idList.push_back(temp->subject.getID());
            temp = temp->next;
        }
        return idList;
    }

    vector<string> generateNameList(){
        if (head == nullptr){
            return {};
        }
        vector<string> nameList;
        subjectNode* temp = head;
        while (temp != nullptr){
            nameList.push_back(temp->subject.getName());
            temp = temp->next;
        }
        return nameList;
    }

    vector<string> generateSubjectTaughtList(){
        if (head == nullptr){
            return {};
        }
        vector<string> nameList;
        subjectNode* temp = head;
        while (temp != nullptr){
            nameList.push_back(temp->subject.getTaughtBy());    
            temp = temp->next;
        }
        return nameList;
    }

    vector<string> filterSubject(string variable, string id, string name, string taughtTeacher, pair<float, float> maxScore){
        vector<string> idList;
        subjectNode* temp = head;

        if (variable == "ID"){
            while (temp != nullptr){
                if (temp->subject.getID() == id){
                    idList.push_back(temp->subject.getID());
                }
                temp = temp->next;
            }
        }
        else if (variable == "Name"){
            while (temp != nullptr){
                if (temp->subject.getName() == name){
                    idList.push_back(temp->subject.getID());
                }
                temp = temp->next;
            }
        }
        else if (variable == "Taughtby"){
            while (temp != nullptr){
                if (temp->subject.getTaughtBy() == taughtTeacher){
                    idList.push_back(temp->subject.getID());
                }
                temp = temp->next;
            }
        }
        else if (variable == "MaxScore"){
            while (temp != nullptr){
                if (temp->subject.getMaxScore() >= maxScore.first && temp->subject.getMaxScore() <= maxScore.second){
                    idList.push_back(temp->subject.getID());
                }
                temp = temp->next;
            }
        }
        return idList;
    }

    void writeToFile() {
        subjectNode* temp = head;
        while (temp != nullptr) {
            temp->subject.writeToFile();
            temp = temp->next;
        }
    }

    void editSubject(const std::string& ID)
    {
        subjectNode* current = head;
        while ( current)
        {
        if ( current->subject.getID() == ID)
        {
            std::cout << "\n Subject found" << std::endl;
            std::cout << current->subject.printSubject() << std::endl;

            std::string newName, newTaughtBy;
            float newMaxScore;

            std::cout << "\n Enter new name (or press Enter to keep current): ";
            std::getline(std::cin, newName);  
            if (!newName.empty())
            {
            current->subject.setName(newName);
            }
            std::cout << "Enter new taught by (or press Enter to keep current): ";
            std::getline(std::cin, newTaughtBy);
            if (!newTaughtBy.empty()) 
            {
            current->subject.setTaughtBy(newTaughtBy);
            }
            
            std::cout << "Enter new salary (or 0 to keep current): ";
            std::cin >> newMaxScore;
            if (newMaxScore > 0) 
            {
            current->subject.setMaxScore(newMaxScore);
            }
            std::cin.ignore(); 
            std::cout << "\n Subject record updated successfully.\n";
            return;
        }
        current = current->next;
        }
        std::cout << "\n Subject not found!" << std::endl;
    }

    void overWriteToFile(){
        if (head == nullptr){
            std::ofstream file("subjectData.txt");
            if (!file) {
                std::cout << "Failed to open the file!" << std::endl;
                return;
            }
            file << "";
            return;
        }
        else{
            head->subject.overWriteToFile();

            if (head->next == nullptr){
                return;
            }
            else{
                subjectNode* temp = head->next;

                while(temp != nullptr){
                    temp->subject.writeToFile();
                    temp = temp->next;
                }
            }
        } 
    }

    int countDigit(int num){
        return to_string(abs(num)).length();
    }

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
                    idList[j + 1] = "SJ00" + to_string(currentValue);
                }
                else if (countDigit(currentValue) == 2){
                    idList[j + 1] = "SJ0" + to_string(currentValue);
                }
                else{
                    idList[j + 1] = "SJ" + to_string(currentValue);
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
                    idList[j + 1] = "SJ00" + to_string(currentValue);
                }
                else if (countDigit(currentValue) == 2){
                    idList[j + 1] = "SJ0" + to_string(currentValue);
                }
                else{
                    idList[j + 1] = "SJ" + to_string(currentValue);
                }
            }
            return idList;
        }
        
    }

    vector<string> maxScoreInsertionSort(bool ascending) {
        //your code here
        vector<pair<int, string>> averageId;

        subjectNode* temp = head;

        while (temp != nullptr){
            averageId.push_back({temp->subject.getMaxScore(), temp->subject.getID()});
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

    void displayByID(vector<string> idList, vector<string> labels){
        if (size == 0){
            cout << "No Records" << endl;
            return;
        }
        for (int i = 0; i < idList.size(); i++){
            subjectNode* temp = head;
            while (temp != nullptr){
                if (temp->subject.getID() == idList[i]){
                    temp->subject.coutRecord(labels);
                    cout << endl;
                    break;
                }
                temp = temp->next;
            }
        }
    }
};


#endif 