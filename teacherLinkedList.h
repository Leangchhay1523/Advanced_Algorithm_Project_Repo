// Sathya Task

#ifndef TEACHER_LINKED_LIST_H
#define TEACHER_LINKED_LIST_H

#include "teacherNode.h"
#include "teacher.h"
#include <string>
#include <vector> 

class TeacherLinkedList{
// Attributes
  TeacherNode* head;
public:
// Methods
  // Constructor 
  TeacherLinkedList() : head(nullptr);

  // Create a new teacher record
  void createTeacher(){
    
  }

  // Edit a teacher record
  void editTeacher(){
    
  }

  // Delete a teacher record
  void deleteTeacher(){
    
  }

  // View all teachers
  void viewTeacher(){
    
  }

  // Filter View : 
    // Options  : Filter by
      // 1. Gender : If user choose male then only show male teachers, if user choose female then only show female teachers
      // 2. Subject : If user choose a subject then show all teachers who teach that subject
      // 3. Salary Range : If user choose a salary range then show all teachers who have salary between that range
      // 4. Name or ID : If user choose a name or ID then show the teacher who have that name or ID (Similar to search)
  void filterTeacher(){
    
  }
};

#endif 