#include "headerFiles/student.h"
#include "headerFiles/studentGroup.h"
#include "headerFiles/studentGroupLinkedList.h"
#include "headerFiles/studentGroupNode.h"
#include "headerFiles/studentLinkedList.h"
#include "headerFiles/studentNode.h"
#include "headerFiles/subject.h"
#include "headerFiles/subjectLinkedList.h"
#include "headerFiles/subjectNode.h"
#include "headerFiles/teacher.h"
#include "headerFiles/teacherLinkedList.h"
#include "headerFiles/teacherNode.h"
#include "headerFiles/graph.h"

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

// Global Variables
vector<string> subjectLearned = {"Network", "Algorithm", "Database", "Programming", "Robotic"};
studentLinkedList studentList;
teacherLinkedList teacherList;
subjectLinkedList subjectList;
studentGroupLinkedList studentGroupList;
vector<string> studentIDList;
vector<string> studentNameList;
vector<string> teacherNameList;
vector<int> studentGroupNumberList;
vector<string> teacherIDList;
vector<string> teacherSubjectList;
vector<string> subjectIDList;
vector<string> subjectNameList;
vector<string> subjectTaughtTeacherList;
int groupAmount = 6;
int subjectAmount = subjectLearned.size();

// Filter Variabls
    // Student
string idFilterOption;
string nameFilterOption;
string genderFilterOption;
string teacherSubjectFilterOption;
int studentGroupNumberFilterOption;
pair<float, float> studentAverageFilterOption;
pair<double, double> teacherSalaryFilterOption;
string taughtTeacherFilterOption;
pair<float, float> subjectMaxScoreFilterOption;
char studentFinalRankFilterOption;




// Functions
void convertID(string& id){
    for (int i = 0; i < id.length(); i++){
        id[i] = toupper(id[i]);
    }
}
// Check Student ID Validity
bool checkStudentIDValidation(string id){
    studentNode* temp = studentList.getHead();
    for (int i = 0; i < studentIDList.size(); i++){
        if (studentIDList[i] == id){
            return true;
        }
    }
    return false;
}

bool checkTeacherIDValidation(string id){
    TeacherNode* temp = teacherList.getHead();
    for (int i = 0; i < teacherIDList.size(); i++){
        if (teacherIDList[i] == id){
            return true;
        }
    }
    return false;
}

bool checkSubjectIDValidation(string id){
    subjectNode* temp = subjectList.getHead();
    for (int i = 0; i < subjectIDList.size(); i++){
        if (subjectIDList[i] == id){
            return true;
        }
    }
    return false;
}

void capitaleChar(char& character){
    character = toupper(character);
}

bool checkStudentFinalRankValidation(char rank){
    if (rank == 'A' || rank == 'B' || rank == 'C' || rank == 'D' || rank == 'F'){
        return true;
    }
    return false;
}

bool checkGenderValidation(string gender){
    if (gender == "Male" || gender == "Female"){
        return true;
    }
    return false;
}

bool checkAverageSalaryMaxScoreValidation(pair<float, float> average){
    if (average.first <= 0 || average.second <= 0){
        return false;
    }
    if (average.first > average.second){
        return false;
    }
    return true;
}

void print(vector<string> list){
    for (int i = 0; i < list.size(); i++){
        cout << list[i] << endl;
    }
}

bool checkStudentGroupNumberValidation(int groupNumber){
    for (int i = 0; i < studentGroupNumberList.size(); i++){
        if (studentGroupNumberList[i] == groupNumber){
            return true;
        }
    }
    return false;
}

void captalizedName(string& name){
    int spaceIndex = 0;
    name[0] = toupper(name[0]);
    for (int i = 1; i < name.length(); i++){
        if (name[i] == ' '){
            spaceIndex = i;
            break;
        }
        name[i] = tolower(name[i]);
    }
    if (spaceIndex > 0){
        name[spaceIndex + 1] = toupper(name[spaceIndex + 1]);
        for (int i = spaceIndex + 2; i < name.length(); i++){
            name[i] = tolower(name[i]);
        }
    }
}

bool checkStudentNameValidation(string name){
    for (int i = 0; i < studentNameList.size(); i++){
        if (studentNameList[i] == name){
            return true;
        }
    }
    return false;
}

bool checkSubjectNameValidation(string name){
    for (int i = 0; i < subjectNameList.size(); i++){
        if (subjectNameList[i] == name){
            return true;
        }
    }
    return false;
}

bool checkSubjectTaughtTeacherValidation(string subject){
    for (int i = 0; i < subjectTaughtTeacherList.size(); i++){
        if (subjectTaughtTeacherList[i] == subject){
            return true;
        }
    }
    return false;
}

bool checkTeacherSubjectValidation(string subject){
    for (int i = 0; i < teacherSubjectList.size(); i++){
        if (studentNameList[i] == subject){
            return true;
        }
    }
    return false;
}

bool checkTeacherNameValidation(string name){
    for (int i = 0; i < studentNameList.size(); i++){
        if (studentNameList[i] == name){
            return true;
        }
    }
    return false;
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

void printHeaderWithOutInput(string text){
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
}

// Menu

int landingMenu(){
    int landingOption;
    cout << "----------------------------------------------" << endl;
    cout << "---- \033[1m Welcome to School Management System\033[0m ----" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Manage Student" << endl;
    cout << "2. Manage Teacher" << endl;
    cout << "3. Manage Subject" << endl;
    cout << "4. Display all Information" << endl;
    cout << "5. Show Schedule" << endl;
    cout << "6. Exit Program" << endl;
    cout << "\n>> Choose an option : ";
    cin >> landingOption;
    return landingOption;
}

// Student Menu
int studentMenu(){
    int studentLandingOption;
    printHeader("Managing Student");
    cout << "1. Add new student" << endl;
    cout << "2. Edit a Student" << endl;
    cout << "3. Delete a student" << endl;
    cout << "4. View students" << endl;
    cout << "5. Filter student" << endl;
    
    cout << "\n>> Choose an option : ";
    cin >> studentLandingOption;
    return studentLandingOption;
}

// Add Student Menu
int addStudentMenu(){
    int studentAddAmount;
    printHeader("Adding New Student");
    cout << "\n>> How many student do you want to add : ";
    cin >> studentAddAmount;
    return studentAddAmount;
}

// Edit student
string editStudentMenu(int& count){
    string studentEditID;
    printHeader("Editing a Student");
    if (studentList.getHead() == nullptr){
        cout << "No Student to Edit" << endl;
        return "";
    }
    cout << "List of students : " << endl;
    vector<string> labels =  studentList.coutHeader(subjectLearned);
    studentList.displayTable(labels, subjectLearned);
    
    if (count > 1){
        cout << "ID not found" << endl;
    }
    cout << "Enter student's ID that you want to edit : ";
    getline(cin, studentEditID);
    return studentEditID;
}

// Delete Student
string deleteStudentMenu(int& count){
    string studentDeleteID;
    printHeader("Deleting a Student");
    if (studentList.getHead() == nullptr){
        cout << "No Student to Delete" << endl;
        return "";
    }
    cout << "List of students : " << endl;
    vector<string> labels =  studentList.coutHeader(subjectLearned);
    studentList.displayTable(labels, subjectLearned);
    if (count > 1){
        cout << "ID not found" << endl;
    }
    cout << "Enter student's ID that you want to delete : ";
    getline(cin, studentDeleteID);
    return studentDeleteID;
}

// View Student
int viewStudentMenu(){
    int viewStudentOption;
    printHeader("Viewing All Students");
    cout << "1. Default View" << endl;
    cout << "2. View by ID (Ascending)" << endl;
    cout << "3. View by ID (Descending)" << endl;
    cout << "4. View by Group Number (Ascending)" << endl;
    cout << "5. View by Group Number (Descending)" << endl;
    cout << "6. View by Average (Ascending)" << endl;
    cout << "7. View by Average (Descending)" << endl;
    cout << "\n>> Choose an option : ";
    cin >> viewStudentOption;
    return viewStudentOption;
}

// Filter Student
int filterStudent(){
    int filterStudentOption;
    printHeader("Filter View Student");
    cout << "1. Filter by ID" << endl;
    cout << "2. Filter by Name" << endl;
    cout << "3. Filter by Group Number" << endl;
    cout << "4. Filter by Gender" << endl;
    cout << "5. Filter by Average Range" << endl;
    cout << "6. Filter by Final Rank" << endl;
    cout << "\n>> Choose an option : ";
    cin >> filterStudentOption;
    return filterStudentOption;
}

// Teacher Menu
int teacherMenu(){
    int teacherLandingOption;
    printHeader("Managing Teacher");
    cout << "1. Add new Teacher" << endl;
    cout << "2. Edit a Teacher" << endl;
    cout << "3. Delete a Teacher" << endl;
    cout << "4. View Teachers" << endl;
    cout << "5. Filter Teacher" << endl;
    
    cout << "\n>> Choose an option : ";
    cin >> teacherLandingOption;
    return teacherLandingOption;
}

// Add Teacher
int addTeacherMenu(){
    int teacherAddAmount;
    printHeader("Adding New Teacher");
    cout << "\n>> How many teacher do you want to add : ";
    cin >> teacherAddAmount;
    return teacherAddAmount;
}

// Edit teacher
string editTeacherMenu(int& count) {
    system("cls");
    string teacherEditID;
    printHeader("Editing a teacher");
    vector<string> labels =  teacherList.coutHeader();
    teacherList.displayTable(labels);
    cout << "Enter teacher id you want to edit : ";
    getline(cin, teacherEditID);
    return teacherEditID;
}

// Delete Teacher
string deleteTeacherMenu(int& count){
    string teacherDeleteID;
    printHeader("Deleting a Teacher");
    if (teacherList.getHead() == nullptr){
        cout << "No Teacher to Delete" << endl;
        return "";
    }
    cout << "List of teachers : " << endl;
    vector<string> labels =  teacherList.coutHeader();
    teacherList.displayTable(labels);
    if (count > 0){
        cout << "ID not found" << endl;
    }
    cout << "Enter teacher's ID that you want to delete : ";
    getline(cin, teacherDeleteID);
    return teacherDeleteID;
}

// View teacher
int viewTeacherMenu(){
    int viewTeacherOption;
    printHeader("Viewing All Teachers");
    cout << "1. Default View" << endl;
    cout << "2. View by ID (Ascending)" << endl;
    cout << "3. View by ID (Descending)" << endl;
    cout << "4. View by Salary (Ascending)" << endl;
    cout << "5. View by Salary (Descending)" << endl;
    cout << "\n>> Choose an option : ";
    cin >> viewTeacherOption;
    return viewTeacherOption;
}

// Filter Teacher
int filterTeacherMenu(){
    int filterTeacherOption;
    printHeader("Filter View Teacher");
    std::cout << "Filter by:\n";
    std::cout << "1. ID\n";
    std::cout << "2. Name\n";
    std::cout << "3. Gender\n";
    std::cout << "4. Subject\n";
    std::cout << "5. Salary Range\n";
    cout << "\n>> Choose an option : ";
    cin >> filterTeacherOption;
    return filterTeacherOption;
}

// Subject Menu
int subjectMenu(){
    int subjectLandingOption;
    printHeader("Managing Subject");
    cout << "1. Add new subject" << endl;
    cout << "2. Edit a subject" << endl;
    cout << "3. Delete a subject" << endl;
    cout << "4. View subject" << endl;
    cout << "5. Filter subject" << endl;
    
    cout << "\n>> Choose an option : ";
    cin >> subjectLandingOption;
    return subjectLandingOption;
}

// Asdd subject menu
int addSubjectMenu(){
    int subjectAddAmount;
    printHeader("Adding New Subject");
    cout << "\n>> How many subject do you want to add : ";
    cin >> subjectAddAmount;
    return subjectAddAmount;
}

// Edit Subject menu
string editSubjectMenu(int& count) {
    string subjectEditID;
    printHeader("Editing a subject");
    cout << "Enter subject id you want to edit : ";
    getline(cin, subjectEditID);
    return subjectEditID;
}

// Delete subject
string deleteSubjectMenu(int& count){
    string subjectDeleteID;
    printHeader("Deleting a Subject");
    if (subjectList.getHead() == nullptr){
        cout << "No subject to Delete" << endl;
        return "";
    }
    cout << "List of subjects : " << endl;
    vector<string> labels =  subjectList.coutHeader();
    subjectList.displayTable(labels);
    if (count > 1){
        cout << "ID not found" << endl;
    }
    cout << "Enter subject's ID that you want to delete : ";
    getline(cin, subjectDeleteID);
    return subjectDeleteID;
}

// View subject
int viewSubjectMenu(){
    int viewSubjectOption;
    printHeader("Viewing All Subjects");
    cout << "1. Default View" << endl;
    cout << "2. View by ID (Ascending)" << endl;
    cout << "3. View by ID (Descending)" << endl;
    cout << "4. View by Max Score (Ascending)" << endl;
    cout << "5. View by Max Score (Descending)" << endl;
    cout << "\n>> Choose an option : ";
    cin >> viewSubjectOption;
    return viewSubjectOption;
}

// Filter Subject
int filterSubjectMenu(){
    int filterSubjectOption;
    printHeader("Filter View Subjects");
    std::cout << "Filter by:\n";
    std::cout << "1. ID\n";
    std::cout << "2. Name\n";
    std::cout << "3. Teacher\n";
    std::cout << "4. Max Score Range\n";
    cout << "\n>> Choose an option : ";
    cin >> filterSubjectOption;
    return filterSubjectOption;
}

void createGroupList(vector<string>& list, int size){
    for (int i = 0; i < size; i++){
        list.push_back("G" + to_string(i + 1));
    }
}

void createSubjectList(vector<string>& list, int size){
    for (int i = 0; i < size; i++){
        list.push_back("SJ" + to_string(i + 1));
    }
}

void eventToSubject(map<string, string> subjectDetail, vector<string> result) {
    vector<string> subject(result.size());
}

vector<pair<string, string>> mapEvent(map<string, string> subjectDetail, vector<string> result){
    vector<pair<string, string>> eventDescriptionList;
    pair<string, string> temp;
    for (int i = 0; i < result.size(); i++) {
        string eventDescription = result[i].substr(0, 2) + " - ";
        string tempSubject = result[i].substr(2, 3);

        temp.first = result[i];

        map<string, string>::iterator it = subjectDetail.find(tempSubject);
        eventDescription += it->second;
        temp.second = eventDescription;
        eventDescriptionList.push_back(temp);   
    }

    return eventDescriptionList;
}

void inputSubject(int& subjectAmount, map<string, string>& subjectDetail){
    string temp, sjTemp;
    cout << "Number of subject : "; 
    cin >> subjectAmount;

    for (int i = 0; i < subjectAmount; i++){
        cout << "Enter SJ" << i + 1 << " : ";
        fflush(stdin);
        getline(cin, temp);

        sjTemp = "SJ" + to_string(i + 1);
        subjectDetail[sjTemp] = temp;
    }
}

void colorDetailSetter(map<int, string>& colorDetail){
    colorDetail[0] = "MonS1";
    colorDetail[1] = "MonS2";
    colorDetail[2] = "MonS3";
    colorDetail[3] = "TueS1";
    colorDetail[4] = "TueS2";
    colorDetail[5] = "TueS3";
    colorDetail[6] = "WedS1";
    colorDetail[7] = "WedS2";
    colorDetail[8] = "WedS3";
    colorDetail[9] = "ThuS1";
    colorDetail[10] = "ThuS2";
    colorDetail[11] = "ThuS3";
    colorDetail[12] = "FriS1";
    colorDetail[13] = "FriS2";
    colorDetail[14] = "FriS3";
}

void eventColorGenerate(vector<int> resultColor, vector<string> verticesList, vector<pair<int, string>>& eventColorList, int numVertices) {
    pair<int, string> temp;
    for (int i = 0; i < numVertices; i++){
        temp.first = resultColor[i];
        temp.second = verticesList[i];
        eventColorList.push_back(temp);
    }
}

void printDaySchedule(vector<pair<string, string>> eventDescriptionList, string day, vector<pair<int, string>> eventColorList, vector<string> labelsRow, map<int, string> colorDetail, int colorStart) {
    vector<vector<string>> sessions(3);

    string print = "| " + day;
    string space = " ";
    int sessionSpaceSize = labelsRow[1].length();
    int spaceNum = labelsRow[0].length() - 3 - day.length();
    for (int i = 0; i < spaceNum; i++){
        print += space;
    }
    print += "|";
    
    int start = colorStart;
    int end = colorStart + 3;
    for (int i = start; i < end; i++){
        int count = 0;

        for (int j = 0; j < eventColorList.size(); j++){
            if (eventColorList[j].first == i){
                sessions[i - start].push_back(eventColorList[j].second);
                count++;
            }
        }

        if (count == 1){
            sessions[i - start].push_back("None");
        }

        if (count == 0){
            sessions[i - start].push_back("None");
            sessions[i - start].push_back("None");
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            string temp = sessions[j][i];

            if (temp != "None"){
                for (int i = 0; i < eventDescriptionList.size(); i++){
                    if (eventDescriptionList[i].first == temp){
                        print += " " + eventDescriptionList[i].second;
                        spaceNum = sessionSpaceSize - 2 - eventDescriptionList[i].second.length();
                    }
                }
            }
            else{
                spaceNum = sessionSpaceSize - 1;
            }
            
            for (int i = 0; i < spaceNum; i++){
                print += space;
            }
            print += "|";
        }
        if (i == 0){
            print += " ";
            print += "A001";
            print += "    |";
            print += "\n|";
            int noneSpace = labelsRow[0].length() - 2;
            for (int i = 0; i < noneSpace; i++){
                print += space;
            }
            print += "|";
        }
        if (i == 1){
            print += " ";
            print += "A002";
            print += "    |";
        }
    }
    cout << print << endl;
}


void printSchedule(string line, vector<pair<int, string>> eventColorList, vector<string> labelsRow, map<int, string> colorDetail, vector<pair<string, string>> eventDescriptionList){
	vector<string> day = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	printDaySchedule(eventDescriptionList, "Monday", eventColorList, labelsRow, colorDetail, 0);
    cout << line << endl;
    printDaySchedule(eventDescriptionList, "Tuesday", eventColorList, labelsRow, colorDetail, 3);
    cout << line << endl;
    printDaySchedule(eventDescriptionList, "Wednesday", eventColorList, labelsRow, colorDetail, 6);
    cout << line << endl;
    printDaySchedule(eventDescriptionList, "Thursday", eventColorList, labelsRow, colorDetail, 9);
    cout << line << endl;
    printDaySchedule(eventDescriptionList, "Friday", eventColorList, labelsRow, colorDetail, 12);
    cout << line << endl;
}

vector<string> printLabelsRow(string& line){
	vector<string> labelsRow = {"| Days      |", " Session 1             |", " Session 2             |", " Session 3             |", " Rooms   |"};
	int lineSize = 0;
	for (int i = 0; i < labelsRow.size(); i++){
		lineSize += labelsRow[i].length();
	}

	for (int i = 0; i < lineSize; i++){
		line += "-";
	}

	cout << line << endl;
	for (int i = 0; i < labelsRow.size(); i++){
		cout << labelsRow[i];
	}
	cout << endl;
	cout << line << endl;
	return labelsRow;
}

// Main Function
int main()
{
    int landingOption;
    studentList.readFromFile();
    teacherList.readFromFile();
    subjectList.readFromFile();
    studentGroupList.createGroup(1, 0);
    studentGroupList.createGroup(2, 0);
    studentGroupList.createGroup(3, 0);
    studentGroupList.createGroup(4, 0);
    studentGroupList.createGroup(5, 0);
    system("cls");
    studentIDList = studentList.generateIDList();
    studentNameList = studentList.generateNameList();
    studentGroupNumberList = studentGroupList.generateIdList();
    teacherIDList = teacherList.generateIDList();
    teacherNameList = teacherList.generateNameList();
    teacherSubjectList = teacherList.generateSubjectTaughtList();
    subjectIDList = subjectList.generateIDList();
    subjectNameList = subjectList.generateNameList();
    subjectTaughtTeacherList = subjectList.generateSubjectTaughtList();
    landing:
    do{
        landingOption =  landingMenu();
        system("cls");
    } while(landingOption < 1 || landingOption > 6);

    switch(landingOption){
        case 1:{ // Managing Student
            int studentLandingOption;
            studentMenu:
            system("cls");
            do{
                studentLandingOption =  studentMenu();
                system("cls");
            } while(studentLandingOption < 0 || studentLandingOption > 5);
            if (studentLandingOption == 0){
                goto landing;
            }

            switch(studentLandingOption){
                case 1:{ // Adding new student
                    int studentAddAmount;
                    do{
                        studentAddAmount = addStudentMenu();
                        system("cls");
                    } while (studentAddAmount < 0);
                    if (studentAddAmount == 0) {
                        goto studentMenu;
                    }
                    printHeader("Adding New Student");
                    cout << endl;
                    cout << "Student Group List : ";
                    int max = studentGroupList.getSize();
                    for (int i = 1; i <= max; i++){
                        cout << i << " ";
                    }
                    
                    cout << endl;
                    cout << "Adding " << studentAddAmount << " student : " << endl;

                    for (int i = 0; i < studentAddAmount; i++){
                        cout << "---- Student " << i + 1 << " ----" << endl; 
                        Student newStudent = studentList.inputDataNewStudent(subjectLearned, subjectList, max);
                        studentGroupList.addAmount(newStudent.getGroupNumber(), 1);
                        cout << endl;
                    }
                    cout << "Successfully add new student" << endl;
                    studentList.writeToFile();
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    goto studentMenu;
                }
                case 2:{ // Edit student
                    if (studentList.getHead() == nullptr){
                        cout << "No Student to Edit" << endl;
                        #ifdef _WIN32
                        system("pause");
                        #endif
                        system("cls");
                        goto studentMenu;
                    }
                    string studentEditID;
                    int count = 0;
                    do{
                        studentEditID = editStudentMenu(count);
                        system("cls");
                        count++;
                        convertID(studentEditID);
                        if (studentEditID == "0"){
                            system("cls");
                            goto studentMenu;
                        }
                    } while (!checkStudentIDValidation(studentEditID));
                    system("cls");
                    printHeader("Editing a Student");
                    vector<string> labels =  studentList.coutHeader(subjectLearned);
                    vector<string> idList = {studentEditID};
                    studentList.displayByID(idList, labels, subjectLearned);
                    cout << "Editing student with ID : " << studentEditID << endl << endl;
                    studentList.editStudent(studentEditID, subjectLearned, subjectList, studentList);
                    cout << "Successfully Edit Student with ID : " << studentEditID << endl;
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    studentIDList = studentList.generateIDList();
                    studentNameList = studentList.generateNameList();
                    studentGroupNumberList = studentGroupList.generateIdList();
                    goto studentMenu;

                }
                case 3:{ // Delete student
                    if (studentList.getHead() == nullptr){
                        cout << "No Student to Delete" << endl;
                        #ifdef _WIN32
                        system("pause");
                        #endif
                        system("cls");
                        goto studentMenu;
                    }
                    string studentDeleteID;
                    int count = 0;
                    do{
                        studentDeleteID = deleteStudentMenu(count);
                        system("cls");
                        count++;
                        convertID(studentDeleteID);
                        if(studentDeleteID == "0"){
                            system("cls");
                            goto studentMenu;
                        }
                    } while (!checkStudentIDValidation(studentDeleteID));
                    studentList.deleteStudent(studentDeleteID);
                    cout << "Delete Sucessfully" << endl;
                    if (studentDeleteID == "0"){
                        goto studentMenu;
                    }
                    studentIDList = studentList.generateIDList();
                    studentNameList = studentList.generateNameList();
                    studentGroupNumberList = studentGroupList.generateIdList();
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    goto studentMenu;
                }
                case 4:{ // View Students
                    int viewStudentOption;
                    do{
                        viewStudentOption = viewStudentMenu();
                        system("cls");
                    } while (viewStudentOption < 0 || viewStudentOption > 7);
                    if (viewStudentOption == 0){
                        goto studentMenu;
                    }
                    switch(viewStudentOption){
                        case 1:{ // Default View
                            printHeader("Viewing All Students in Default View");
                            cout << endl;
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            studentList.displayTable(labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto studentMenu;
                        }
                        case 2:{ // ID Ascending
                            printHeader("Viewing All Students by ID (Asecending)");
                            cout << endl;
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.idInsertionSort(true);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto studentMenu;
                        }
                        case 3:{ // ID Descending
                            printHeader("Viewing All Students by ID (Descending)");
                            cout << endl;
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.idInsertionSort(false);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto studentMenu;
                        }
                        case 4:{ // Group Number Ascending
                            printHeader("Viewing All Students by Group Number (Ascending)");
                            cout << endl;
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.groupNumInsertionSort(true);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto studentMenu;
                        }
                        case 5:{ // Group Number Descending
                            printHeader("Viewing All Students by Group Number (Descending)");
                            cout << endl;
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.groupNumInsertionSort(false);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto studentMenu;
                        }
                        case 6:{ // Average Ascending
                            printHeader("Viewing All Students by Average (Ascending)");
                            cout << endl;
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.averageInsertionSort(true);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto studentMenu;
                        }
                        case 7:{ // Average Descending
                            printHeader("Viewing All Students by Average (Descending)");
                            cout << endl;
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.averageInsertionSort(false);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto studentMenu;
                        }
                    }
                }
                case 5:{ // Filter Student
                    int filterStudentOption;
                    filterMenu:
                    do{
                        filterStudentOption = filterStudent();
                        system("cls");
                    } while (filterStudentOption < 0 || filterStudentOption > 6);
                    
                    if (filterStudentOption == 0){
                        goto studentMenu;
                    }

                    switch(filterStudentOption){
                        case 1:{ // Filter by ID
                            int count = 0;
                            do{
                                printHeader("Filter Student by ID");
                                if (count > 1){
                                    cout << "ID not found" << endl;
                                }
                                cout << "Enter student's ID : ";
                                getline(cin, idFilterOption);
                                count++;
                                if (idFilterOption == "0"){
                                    system("cls");
                                    goto filterMenu;
                                }
                                convertID(idFilterOption);
                                system("cls");
                            } while (!checkStudentIDValidation(idFilterOption));
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.filterStudent("ID", idFilterOption, nameFilterOption, genderFilterOption, studentGroupNumberFilterOption, studentAverageFilterOption, studentFinalRankFilterOption);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterMenu;
                        }
                        case 2:{ // Filter by Name
                            int count = 0;
                            do{
                                printHeader("Filter Student by Name");
                                if (count > 1){
                                    cout << "Name not found" << endl;
                                }
                                cout << "Enter student's Name : ";
                                fflush(stdin);
                                getline(cin, nameFilterOption);
                                count++;
                                if (nameFilterOption == "0"){
                                    system("cls");
                                    goto filterMenu;
                                }
                                captalizedName(nameFilterOption);
                                system("cls");
                            } while (!checkStudentNameValidation(nameFilterOption));
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.filterStudent("Name", idFilterOption, nameFilterOption, genderFilterOption, studentGroupNumberFilterOption, studentAverageFilterOption, studentFinalRankFilterOption);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterMenu;
                        }
                        case 3:{ // Filter by Group Number
                            int count = 0;
                            do{
                                printHeader("Filter Student by Group Number");
                                if (count > 1){
                                    cout << "Group not found" << endl;
                                }
                                cout << "Enter student's Group Number : ";
                                fflush(stdin);
                                cin >> studentGroupNumberFilterOption;
                                count++;
                                if (studentGroupNumberFilterOption == 0){
                                    system("cls");
                                    goto filterMenu;
                                }
                                system("cls");
                            } while (!checkStudentGroupNumberValidation(studentGroupNumberFilterOption));
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.filterStudent("GroupNum", idFilterOption, nameFilterOption, genderFilterOption, studentGroupNumberFilterOption, studentAverageFilterOption, studentFinalRankFilterOption);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterMenu;
                        }
                        case 4:{ // Filter by Gender
                            int count = 0;
                            do{
                                printHeader("Filter Student by Gender");
                                if (count > 1){
                                    cout << "Invalid Gender" << endl;
                                }
                                cout << "Enter student's Gender : ";
                                fflush(stdin);
                                getline(cin, genderFilterOption);
                                count++;
                                if (genderFilterOption == "0"){
                                    system("cls");
                                    goto filterMenu;
                                }
                                captalizedName(genderFilterOption);
                                system("cls");
                            } while (!checkGenderValidation(genderFilterOption));
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.filterStudent("Gender", idFilterOption, nameFilterOption, genderFilterOption, studentGroupNumberFilterOption, studentAverageFilterOption, studentFinalRankFilterOption);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterMenu;
                        }
                        case 5:{ // Filter by Average Range
                            int count = 0;
                            do{
                                printHeader("Filter Student by Average Range");
                                if (count > 0){
                                    cout << "Invalid Average Range" << endl;
                                }
                                cout << "Enter Min Range : ";
                                cin >> studentAverageFilterOption.first;
                                if (studentAverageFilterOption.first == 0){
                                    system("cls");
                                    goto filterMenu;
                                }
                                cout << "Enter Max Range : ";
                                cin >> studentAverageFilterOption.second;
                                count++;
                                if (studentAverageFilterOption.first == 0 || studentAverageFilterOption.second == 0){
                                    system("cls");
                                    goto filterMenu;
                                }
                                captalizedName(genderFilterOption);
                                system("cls");
                            } while (!checkAverageSalaryMaxScoreValidation(studentAverageFilterOption));
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.filterStudent("Average", idFilterOption, nameFilterOption, genderFilterOption, studentGroupNumberFilterOption, studentAverageFilterOption, studentFinalRankFilterOption);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterMenu;
                        }
                        case 6:{ // Filter by Final Rank
                            int count = 0;
                            do{
                                printHeader("Filter Student by Final Rank");
                                if (count > 1){
                                    cout << "Invalid Rank" << endl;
                                }
                                cout << "Enter student's Final Rank : ";
                                cin >> studentFinalRankFilterOption;
                                count++;
                                if (studentFinalRankFilterOption == '0'){
                                    system("cls");
                                    goto filterMenu;
                                }
                                capitaleChar(studentFinalRankFilterOption);
                                system("cls");
                            } while (!checkStudentFinalRankValidation(studentFinalRankFilterOption));
                            vector<string> labels =  studentList.coutHeader(subjectLearned);
                            vector<string> idList = studentList.filterStudent("Rank", idFilterOption, nameFilterOption, genderFilterOption, studentGroupNumberFilterOption, studentAverageFilterOption, studentFinalRankFilterOption);
                            studentList.displayByID(idList, labels, subjectLearned);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterMenu;
                        }
                    }
                }
            }
        }

        case 2: { // Managing Teacher
            int teacherLandingOption;
            teacherMenu:
            system("cls");
            do {
                teacherLandingOption = teacherMenu();
                if (teacherLandingOption == 0) {
                    system("cls");
                    goto landing;
                }
            } while (teacherLandingOption < 0 || teacherLandingOption > 5);
            fflush(stdin);
            switch(teacherLandingOption){
                case 1: { // Adding Teacher
                    system("cls");
                    int teacherAddAmount;
                    do{
                        teacherAddAmount = addTeacherMenu();
                        system("cls");
                    } while (teacherAddAmount < 0);
                    if (teacherAddAmount == 0) {
                        goto teacherMenu;
                    }
                    printHeader("Adding New Teacher");
                    cout << endl;
                    cout << "Subject List : ";
                    cout << "Adding " << teacherAddAmount << " teacher : " << endl;

                    for (int i = 0; i < teacherAddAmount; i++){
                        cout << "---- Teacher " << i + 1 << " ----" << endl; 
                        Teacher newTeacher = teacherList.inputDataNewTeacher();
                        // teacherList.createTeacher(newTeacher);
                        cout << endl;
                        teacherList.writeToFile();
                    }
                    cout << "Successfully add new teacher" << endl;
                    teacherIDList = teacherList.generateIDList();
                    teacherNameList = teacherList.generateNameList();
                    teacherSubjectList = teacherList.generateSubjectTaughtList();
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    goto teacherMenu;
                }

                case 2: { // Edit a teacher
                    if (teacherList.getHead() == nullptr){
                        cout << "No Teacher to Edit" << endl;
                        #ifdef _WIN32
                        system("pause");
                        #endif
                        system("cls");
                        goto teacherMenu;
                    }
                    string teacherEditID;
                    int count = 0;
                    do{
                        teacherEditID = editTeacherMenu(count);
                        system("cls");
                        count++;
                        convertID(teacherEditID);
                        if (teacherEditID == "0"){
                            system("cls");
                            goto studentMenu;
                        }
                    } while (!checkTeacherIDValidation(teacherEditID));
                    system("cls");
                    printHeader("Editing a Teacher");
                    teacherList.editTeacher(teacherEditID);
                    teacherIDList = teacherList.generateIDList();
                    teacherNameList = teacherList.generateNameList();
                    teacherSubjectList = teacherList.generateSubjectTaughtList();
                    teacherList.overWriteToFile();
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    goto teacherMenu;
                }

                case 3: { // Delete a teacher
                    if (teacherList.getHead() == nullptr){
                        cout << "No Teacher to Delete" << endl;
                        #ifdef _WIN32
                        system("pause");
                        #endif
                        system("cls");
                        goto teacherMenu;
                    }
                    string teacherDeleteID;
                    system("cls");
                    int count = 0;
                    do{
                        teacherDeleteID = deleteTeacherMenu(count);
                        system("cls");
                        count++;
                        convertID(teacherDeleteID);
                        if(teacherDeleteID == "0"){
                            system("cls");
                            goto teacherMenu;
                        }
                    } while (!checkTeacherIDValidation(teacherDeleteID));
                    teacherList.deleteTeacher(teacherDeleteID);
                    cout << "Delete Sucessfully" << endl;
                    teacherIDList = teacherList.generateIDList();
                    teacherNameList = teacherList.generateNameList();
                    teacherSubjectList = teacherList.generateSubjectTaughtList();
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    goto teacherMenu;
                }

                case 4: { // View all teachers
                    int viewTeacherOption;
                    system("cls");
                    do{
                        viewTeacherOption = viewTeacherMenu();
                        system("cls");
                    } while (viewTeacherOption < 0 || viewTeacherOption > 5);
                    if (viewTeacherOption == 0){
                        goto teacherMenu;
                    }
                    switch(viewTeacherOption){
                        case 1:{ // Default View
                            printHeader("Viewing All Teachers in Default View");
                            cout << endl;
                            vector<string> labels =  teacherList.coutHeader();
                            teacherList.displayTable(labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto teacherMenu;
                        }
                        case 2:{ // ID Ascending
                            printHeader("Viewing All Teachers by ID (Asecending)");
                            cout << endl;
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.idInsertionSort(true);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto teacherMenu;
                        }
                        case 3:{ // ID Descending
                            printHeader("Viewing All Teachers by ID (Descending)");
                            cout << endl;
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.idInsertionSort(false);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto teacherMenu;
                        }
                        case 4:{ // Salary Ascending
                            printHeader("Viewing All Teachers by Salary (Ascending)");
                            cout << endl;
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.salaryInsertionSort(true);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto teacherMenu;
                        }
                        case 5:{ // Salary Descending
                            printHeader("Viewing All Teachers by Salary (Descending)");
                            cout << endl;
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.salaryInsertionSort(false);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto teacherMenu;
                        }
                }

                case 5: { // Filter teacher
                    system("cls");
                    int filterTeacherOption;
                    filterTeacherMenu:
                    do{
                        filterTeacherOption = filterTeacherMenu();
                        system("cls");
                    } while (filterTeacherOption < 0 || filterTeacherOption > 6);
                    
                    if (filterTeacherOption == 0){
                        goto teacherMenu;
                    }

                    switch(filterTeacherOption){
                        case 1:{ // Filter by ID
                            int count = 0;
                            do{
                                printHeader("Filter Teacher by ID");
                                if (count > 1){
                                    cout << "ID not found" << endl;
                                }
                                cout << "Enter teacher's ID : ";
                                getline(cin, idFilterOption);
                                count++;
                                if (idFilterOption == "0"){
                                    system("cls");
                                    goto filterTeacherMenu;
                                }
                                convertID(idFilterOption);
                                system("cls");
                            } while (!checkTeacherIDValidation(idFilterOption));
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.filterTeacher("ID", idFilterOption, nameFilterOption, genderFilterOption, teacherSubjectFilterOption, teacherSalaryFilterOption);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterTeacherMenu;
                        }
                        case 2:{ // Filter by Name
                            int count = 0;
                            do{
                                printHeader("Filter Teacher by Name");
                                if (count > 0){
                                    cout << "Name not found" << endl;
                                }
                                cout << "Enter teacher's Name : ";
                                fflush(stdin);
                                getline(cin, nameFilterOption);
                                count++;
                                if (nameFilterOption == "0"){
                                    system("cls");
                                    goto filterTeacherMenu;
                                }
                                captalizedName(nameFilterOption);
                                system("cls");
                            } while (!checkTeacherNameValidation(nameFilterOption));
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.filterTeacher("Name", idFilterOption, nameFilterOption, genderFilterOption, teacherSubjectFilterOption, teacherSalaryFilterOption);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterTeacherMenu;
                        }
                        case 3:{ // Filter by Gender
                            int count = 0;
                            do{
                                printHeader("Filter Teacher by Gender");
                                if (count > 1){
                                    cout << "Invalid Gender" << endl;
                                }
                                cout << "Enter teacher's Gender : ";
                                fflush(stdin);
                                getline(cin, genderFilterOption);
                                count++;
                                if (genderFilterOption == "0"){
                                    system("cls");
                                    goto filterTeacherMenu;
                                }
                                captalizedName(genderFilterOption);
                                system("cls");
                            } while (!checkGenderValidation(genderFilterOption));
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.filterTeacher("Gender", idFilterOption, nameFilterOption, genderFilterOption, teacherSubjectFilterOption, teacherSalaryFilterOption);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterTeacherMenu;
                        } 
                        case 4:{ // Filter by Subject
                            int count = 0;
                            do{
                                printHeader("Filter Teacher by Subject");
                                if (count > 1){
                                    cout << "Invalid Subject" << endl;
                                }
                                cout << "Enter teacher's Subject : ";
                                fflush(stdin);
                                getline(cin, teacherSubjectFilterOption);
                                count++;
                                if (genderFilterOption == "0"){
                                    system("cls");
                                    goto filterTeacherMenu;
                                }
                                captalizedName(teacherSubjectFilterOption);
                                system("cls");
                            } while (!checkTeacherSubjectValidation(teacherSubjectFilterOption));
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.filterTeacher("Subject", idFilterOption, nameFilterOption, genderFilterOption, teacherSubjectFilterOption, teacherSalaryFilterOption);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterTeacherMenu;
                        }     
                        case 5:{
                            int count = 0;
                            do{
                                printHeader("Filter Teacher by Salary Range");
                                if (count > 0){
                                    cout << "Invalid Average Range" << endl;
                                }
                                cout << "Enter Min Range : ";
                                cin >> teacherSalaryFilterOption.first;
                                if (teacherSalaryFilterOption.first == 0){
                                    system("cls");
                                    goto filterTeacherMenu;
                                }
                                cout << "Enter Max Range : ";
                                cin >> teacherSalaryFilterOption.second;
                                count++;
                                if (teacherSalaryFilterOption.first == 0 || teacherSalaryFilterOption.second == 0){
                                    system("cls");
                                    goto filterTeacherMenu;
                                }
                                system("cls");
                            } while (!checkAverageSalaryMaxScoreValidation(teacherSalaryFilterOption));
                            vector<string> labels =  teacherList.coutHeader();
                            vector<string> idList = teacherList.filterTeacher("Salary", idFilterOption, nameFilterOption, genderFilterOption, teacherSubjectFilterOption, teacherSalaryFilterOption);
                            teacherList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterTeacherMenu;
                        } 
                        }
                    }
                }
            break;
        }

        case 3: { // Managing Subject
            int subjectLandingOption;
            subjectMenu:
            do{
                subjectLandingOption =  subjectMenu();
                system("cls");
            } while(subjectLandingOption < 0 || subjectLandingOption > 5);
            if (subjectLandingOption == 0){
                goto landing;
            }
            switch(subjectLandingOption){
                case 1:{ // Add new subject
                    system("cls");
                    int subjectAddAmount;
                    do{
                        subjectAddAmount = addSubjectMenu();
                        system("cls");
                        if (subjectAddAmount == 0){
                            goto subjectMenu;
                        }
                    } while(subjectAddAmount < 0);
                    printHeader("Adding new Teacher");
                    cout << endl;
                    cout << "Adding " << subjectAddAmount << " subject : " << endl;

                    for (int i = 0; i < subjectAddAmount; i++){
                        cout << "---- Subject " << i + 1 << " ----" << endl; 
                        Subject newSubject = subjectList.inputDataNewSubject();
                        cout << endl;
                    }
                    cout << "Successfully add new subject" << endl;
                    subjectIDList = subjectList.generateIDList();
                    subjectNameList = subjectList.generateNameList();
                    subjectTaughtTeacherList = subjectList.generateSubjectTaughtList();
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    goto subjectMenu;
                    break;
                }
                case 2:{ // Edit a subject
                    if (subjectList.getHead() == nullptr){
                        cout << "No Subject to Edit" << endl;
                        #ifdef _WIN32
                        system("pause");
                        #endif
                        system("cls");
                        goto subjectMenu;
                    }
                    string subjectEditID;
                    int count = 0;
                    do{
                        subjectEditID = editSubjectMenu(count);
                        system("cls");
                        count++;
                        convertID(subjectEditID);
                        if (subjectEditID == "0"){
                            system("cls");
                            goto subjectMenu;
                        }
                    } while (!checkSubjectIDValidation(subjectEditID));
                    system("cls");
                    printHeader("Editing a Subject");
                    subjectList.editSubject(subjectEditID);
                    cout << "Successfully Edit a Subject" << endl;
                    subjectIDList = subjectList.generateIDList();
                    subjectNameList = subjectList.generateNameList();
                    subjectTaughtTeacherList = subjectList.generateSubjectTaughtList();
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    goto subjectMenu;
                    break;
                }
                case 3:{ //Deelte a subject
                    if (subjectList.getHead() == nullptr){
                        cout << "No Subject to Delete" << endl;
                        #ifdef _WIN32
                        system("pause");
                        #endif
                        system("cls");
                        goto subjectMenu;
                    }
                    string subjectDeleteID;
                    system("cls");
                    int count = 0;
                    do{
                        subjectDeleteID = deleteSubjectMenu(count);
                        system("cls");
                        count++;
                        convertID(subjectDeleteID);
                        if(subjectDeleteID == "0"){
                            system("cls");
                            goto subjectMenu;
                        }
                    } while (!checkSubjectIDValidation(subjectDeleteID));
                    subjectList.deleteSubject(subjectDeleteID);
                    cout << "Delete Sucessfully" << endl;
                    subjectIDList = subjectList.generateIDList();
                    subjectNameList = subjectList.generateNameList();
                    subjectTaughtTeacherList = subjectList.generateSubjectTaughtList();
                    #ifdef _WIN32
                    system("pause");
                    #endif
                    system("cls");
                    goto subjectMenu;
                    break;
                }
                case 4:{ // View subjects
                    int viewSubjectOption;
                    system("cls");
                    do{
                        viewSubjectOption = viewSubjectMenu();
                        system("cls");
                    } while (viewSubjectOption < 0 || viewSubjectOption > 5);
                    if (viewSubjectOption == 0){
                        goto subjectMenu;
                    }
                    switch(viewSubjectOption){
                        case 1:{ // Default View
                            printHeader("Viewing All Subjects in Default View");
                            cout << endl;
                            vector<string> labels =  subjectList.coutHeader();
                            subjectList.displayTable(labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto subjectMenu;
                            break;
                        }
                        case 2:{ // ID Ascennding
                            printHeader("Viewing All Subjects by ID (Asecending)");
                            cout << endl;
                            vector<string> labels =  subjectList.coutHeader();
                            vector<string> idList = subjectList.idInsertionSort(true);
                            subjectList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto subjectMenu;
                            break;
                        }
                        case 3:{ // ID Descending
                            printHeader("Viewing All Subjects by ID (Descending)");
                            cout << endl;
                            vector<string> labels =  subjectList.coutHeader();
                            vector<string> idList = subjectList.idInsertionSort(false);
                            subjectList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto subjectMenu;
                            break;;
                        }
                        case 4:{ //Max Score Ascending
                            printHeader("Viewing All Subjects by Max Score (Ascending)");
                            cout << endl;
                            vector<string> labels =  subjectList.coutHeader();
                            vector<string> idList = subjectList.maxScoreInsertionSort(true);
                            subjectList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto subjectMenu;
                            break;
                        }
                        case 5:{ // Max Score descending
                            printHeader("Viewing All Subjects by Max Score (Descending)");
                            cout << endl;
                            vector<string> labels =  subjectList.coutHeader();
                            vector<string> idList = subjectList.maxScoreInsertionSort(false);
                            subjectList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto subjectMenu;
                            break;
                        }
                    }
                    break;
                }
                case 5:{ // filter subject
                    system("cls");
                    int filterSubjectOption;
                    filterSubjectMenu:
                    do{
                        filterSubjectOption = filterSubjectMenu();
                        system("cls");
                    } while (filterSubjectOption < 0 || filterSubjectOption > 4);
                    
                    if (filterSubjectOption == 0){
                        goto subjectMenu;
                    }

                    switch(filterSubjectOption){
                        case 1:{ // Filter by ID
                            int count = 0;
                            do{
                                printHeader("Filter Subject by ID");
                                if (count > 1){
                                    cout << "ID not found" << endl;
                                }
                                cout << "Enter subject's ID : ";
                                getline(cin, idFilterOption);
                                count++;
                                if (idFilterOption == "0"){
                                    system("cls");
                                    goto filterSubjectMenu;
                                }
                                convertID(idFilterOption);
                                system("cls");
                            } while (!checkSubjectIDValidation(idFilterOption));
                            vector<string> labels =  subjectList.coutHeader();
                            vector<string> idList = subjectList.filterSubject("ID", idFilterOption, nameFilterOption, taughtTeacherFilterOption, subjectMaxScoreFilterOption);
                            subjectList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterSubjectMenu;
                            break;
                        }
                        case 2:{ //Filter by Name
                            int count = 0;
                            do{
                                printHeader("Filter Subject by Name");
                                if (count > 0){
                                    cout << "Name not found" << endl;
                                }
                                cout << "Enter subject's Name : ";
                                fflush(stdin);
                                getline(cin, nameFilterOption);
                                count++;
                                if (nameFilterOption == "0"){
                                    system("cls");
                                    goto filterSubjectMenu;
                                }
                                captalizedName(nameFilterOption);
                                system("cls");
                            } while (!checkSubjectNameValidation(nameFilterOption));
                            vector<string> labels =  subjectList.coutHeader();
                            vector<string> idList = subjectList.filterSubject("Name", idFilterOption, nameFilterOption, taughtTeacherFilterOption, subjectMaxScoreFilterOption);
                            subjectList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterSubjectMenu;
                            break;
                        }
                        case 3:{ // Filter by  Teacher
                            int count = 0;
                            do{
                                printHeader("Filter Subject by Teacher");
                                if (count > 0){
                                    cout << "Teacher not found" << endl;
                                }
                                cout << "Enter teacher's Name : ";
                                fflush(stdin);
                                getline(cin, taughtTeacherFilterOption);
                                count++;
                                if (taughtTeacherFilterOption == "0"){
                                    system("cls");
                                    goto filterTeacherMenu;
                                }
                                captalizedName(taughtTeacherFilterOption);
                                system("cls");
                            } while (!checkSubjectTaughtTeacherValidation(taughtTeacherFilterOption));
                            vector<string> labels =  subjectList.coutHeader();
                            vector<string> idList = subjectList.filterSubject("Taughtby", idFilterOption, nameFilterOption, taughtTeacherFilterOption, subjectMaxScoreFilterOption);
                            subjectList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterSubjectMenu;
                            break;
                        }
                        case 4:{ //Filter by max score range
                            int count = 0;
                            do{
                                printHeader("Filter Subject by Max Score Range");
                                if (count > 0){
                                    cout << "Invalid Max Score Range" << endl;
                                }
                                cout << "Enter Min Range : ";
                                cin >> subjectMaxScoreFilterOption.first;
                                if (subjectMaxScoreFilterOption.first == 0){
                                    system("cls");
                                    goto filterSubjectMenu;
                                }
                                cout << "Enter Max Range : ";
                                cin >> subjectMaxScoreFilterOption.second;
                                count++;
                                if (subjectMaxScoreFilterOption.first == 0 || subjectMaxScoreFilterOption.second == 0){
                                    system("cls");
                                    goto filterSubjectMenu;
                                }
                                system("cls");
                            } while (!checkAverageSalaryMaxScoreValidation(subjectMaxScoreFilterOption));
                            vector<string> labels =  subjectList.coutHeader();
                            vector<string> idList = subjectList.filterSubject("MaxScore", idFilterOption, nameFilterOption, taughtTeacherFilterOption, subjectMaxScoreFilterOption);
                            subjectList.displayByID(idList, labels);
                            #ifdef _WIN32
                            system("pause");
                            #endif
                            system("cls");
                            goto filterSubjectMenu;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }

        case 4: { // Display All Information
            // Amount of teacher, student groups, students in each group, subject
            string text = "Showing All Information";
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
            cout << endl;

            cout << "Number of Student Groups : " << groupAmount << endl;
            cout << "Number of Students : " << studentList.getSize() << endl;
            cout << "Number of Teachers : " << teacherList.getSize() << endl;
            cout << "Number of Subjects : " << subjectList.getSize() << endl;
            cout << "Number of Subjects Learn : " << subjectLearned.size() << endl;
            for(int i = 0; i < subjectLearned.size(); i++){
                cout << "- " << subjectLearned[i] << endl;
            }
            #ifdef _WIN32
            system("pause");
            #endif
            system("cls");
            goto landing;
            break;
        }

        case 5: { // Show Schedule
            string text = "Showing Schedule";
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
            cout << endl;
            map<string, string> subjectDetail;

            for (int i = 0; i < subjectAmount; i++){
                    string sjTemp = "SJ" + to_string(i + 1);
                    subjectDetail[sjTemp] = subjectLearned[i];
                }

            vector<string> groups;
            vector<string> subject;
            createGroupList(groups, groupAmount);
            createSubjectList(subject, subjectAmount);

            int numVertices = groups.size() * subject.size();

            vector<string> verticesList(numVertices);
            vector<int> verticeMapping(numVertices);

            for (int i = 0; i < groups.size(); i++){
                for (int j = 0; j < subject.size(); j++){
                    int index = i * subject.size() + j;
                    verticesList[index] = groups[i] + subject[j];
                    verticeMapping[index] = index;
                }
            }

            vector<int> resultColor(numVertices);
            vector<int> colorCount(numVertices, 0);
            map<int, string> colorDetail;
            vector<pair<int, string>> eventColorList;
            
            GraphColoring g1(numVertices);
            g1.addConflictEdge(verticesList);
            g1.greedyColoring(resultColor, colorCount);
            vector<pair<string, string>> eventDescriptionList = mapEvent(subjectDetail, verticesList);
            colorDetailSetter(colorDetail);
            eventColorGenerate(resultColor, verticesList, eventColorList, numVertices);
            string line;
            vector<string> labelsRow;
            vector<string> labelsCol = {"| Monday    |", "|           |", "| Tuesday   |", "|           |", "| Wednesday |", "|           |", "| Thursday  |", "|           |",  "| Friday    |", "|           |"};
            labelsRow = printLabelsRow(line);
            printSchedule(line, eventColorList, labelsRow, colorDetail, eventDescriptionList);

            #ifdef _WIN32
            system("pause");
            #endif
            system("cls");
            goto landing;
            break;
        }

        case 6: { // Exit Program
            studentList.overWriteToFile();
            teacherList.overWriteToFile();
            subjectList.overWriteToFile();
            printHeaderWithOutInput("Program Ended, Thank You!!!");
            return 0;
        }
        }
    }
}