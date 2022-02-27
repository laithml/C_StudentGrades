//
// Created by Laith on 01/12/2021.
//211353297
#include <stdio.h>
#include <stdlib.h>
#include "StudentList.h"

StudentList *createList() {
    StudentList *list = (StudentList *) malloc(sizeof(StudentList));
    list->head=NULL;
    return list;

}

void deleteList(StudentList *list) {
    if(list==NULL) return;
    StudentNode *current = list->head;
    StudentNode *temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    list->head=NULL;

}

void printStudentNode(StudentNode *node ) {
    if(node==NULL)
        return;

    printf("Student ID: %d\n", node->st->id);
    if(node->st->grade1!=-1)
    printf("Grade 1: %d\n", node->st->grade1);
    if(node->st->grade2!=-1)
    printf("Grade 2: %d\n", node->st->grade2);
}

void printStudentList(StudentList *list) {
    if(list->head==NULL)
        return;

    StudentNode *current = list->head;
    while (current!= NULL) {
        printStudentNode(current);
        current = current->next;
    }

}

void addToList(StudentList *list, Student *student) {
    StudentNode *new = (StudentNode *) malloc(sizeof(StudentNode));
    new->st = student;
    new->next = NULL;
    if (list->head == NULL) {
        list->head = new;
    } else {
        StudentNode *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}
