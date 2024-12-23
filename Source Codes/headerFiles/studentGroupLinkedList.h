#ifndef STUDENT_GROUP_LINKED_LIST_H
#define STUDENT_GROUP_LINKED_LIST_H

#include "studentGroup.h"
#include "studentGroupNode.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

class studentGroupLinkedList{
// Attributes
    studentGroupNode* head;
    int size;
// Methods
public:
    studentGroupLinkedList() : head(nullptr), size(0) {}

    ~studentGroupLinkedList() {
        while (head != nullptr) {
            studentGroupNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Create group
    void createGroup(studentGroup studentgroup){
        if (head == nullptr){
            head = new studentGroupNode(studentgroup);
        }
        else{
            studentGroupNode* newnode = new studentGroupNode(studentgroup);
            
            studentGroupNode* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        size++;
    }

    void createGroup(int id, int amount){
        studentGroup studentgroup(id, amount);
        if (head == nullptr){
            head = new studentGroupNode(studentgroup);
        }
        else{
            studentGroupNode* newnode = new studentGroupNode(studentgroup);
            
            studentGroupNode* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        size++;
    }

    int getSize(){
        return size;
    }

    // display
    void display(){
        studentGroupNode* temp = head;
        while (temp != nullptr){
            temp->studentgroup.display();
            temp = temp->next;
            cout << endl;
        }
    }

    // Generate Group ID List
    vector<int> generateIdList(){
        if (head == nullptr){
            return {};
        }
        vector<int> idList;
        studentGroupNode* temp = head;
        while (temp != nullptr){
            idList.push_back(temp->studentgroup.getId());
            temp = temp->next;
        }
    }

    // Increment Student Amount
    void addAmount(int id, int size){
        studentGroupNode* temp = head;
        while (temp != nullptr){
            if (temp->studentgroup.getId() == id){
                break;
            }
            temp = temp->next;
        }
        temp->studentgroup.incrementAmount(size);
    }
};

#endif