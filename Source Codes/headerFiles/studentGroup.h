#ifndef STUDENT_GROUP_H
#define STUDENT_GROUP_H

#include <string>

class studentGroup{
    int groupId;
    std::string name = "Group " + std::to_string(groupId);
    int studentAmount;
public:
    studentGroup(int groupid, int amount) : groupId(groupid), studentAmount(amount) {}

    void incrementAmount(int size){
        studentAmount += size;
    }

    int getId(){
        return groupId;
    }

    // Display
    void display(){
        cout << "ID : " << groupId << endl;
        cout << "Name : " << name << endl;
        cout << "Student Amount : " << studentAmount << endl;
    }
};


#endif 