//
// Created by Laith on 01/12/2021.
//211353297

#ifndef UNTITLED1_STUDENTLIST_H
#define UNTITLED1_STUDENTLIST_H

typedef struct {
    int id;
    int grade1, grade2;
}Student;

typedef struct StudentNode {
    Student* st;
    struct StudentNode* next;
}StudentNode;

typedef struct StudentList {
    struct StudentNode* head;
}StudentList;

// list functions
StudentList* createList();
void deleteList(StudentList*);
void printStudentNode(StudentNode* const);
void printStudentList(StudentList* const);
void addToList(StudentList*, Student*);



#endif //UNTITLED1_STUDENTLIST_H
