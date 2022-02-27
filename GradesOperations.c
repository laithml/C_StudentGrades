//
// Created by Laith on 02/12/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "StudentList.h"

StudentList *FileToList() {
    FILE *F = fopen("StudentsGrades.txt", "r");

    StudentList *list = (StudentList *) malloc(sizeof(StudentList));
    list = createList();
    while (!feof(F)) {
        int id, g1, g2;
        Student *TempSt = (Student *) malloc(sizeof(Student));
        StudentNode *TempNode = (StudentNode *) malloc(sizeof(StudentNode));
        fscanf(F, "%d %d %d", &id, &g1, &g2);
        TempSt->id = id;
        TempSt->grade1 = g1;
        TempSt->grade2 = g2;
        TempNode->st = TempSt;
        TempNode->next = NULL;
        addToList(list, TempSt);
    }
    fclose(F);
    return list;
}

void Report(StudentList *list) {
    StudentNode *temp = (StudentNode *) malloc(sizeof(StudentNode));
    temp = list->head;
    int StudentNumber = 0, oneExam = 0, noOne = 0;
    double Af = 0, Bf = 0;
    int sumA = 0, sumB = 0;
    int max = 0, min = 100, maxSt=0, minSt=0;
    int A=0,B=0;
    while (temp != NULL) {
        if ((temp->st->grade1 == -1 && temp->st->grade2 != -1) ||
            (temp->st->grade1 != -1 && temp->st->grade2 == -1))
            oneExam++;
        if (temp->st->grade1 == -1 && temp->st->grade2 == -1) noOne++;
        if(temp->st->grade1!=-1) A++;
        if(temp->st->grade2!=-1) B++;
        if (temp->st->grade1 < 60 && temp->st->grade1 != -1) Af++;
        if (temp->st->grade2 < 60 && temp->st->grade2 != -1) Bf++;
        if (temp->st->grade1 > max&&temp->st->grade1!=-1) {
            maxSt = temp->st->id;
            max = temp->st->grade1;
        }
        if (temp->st->grade2 > max&&temp->st->grade2!=-1) {
            maxSt = temp->st->id;
            max = temp->st->grade2;
        }
        if (temp->st->grade1 < min&&temp->st->grade1!=-1) {
            min = temp->st->grade1;
            minSt = temp->st->id;
        }
        if (temp->st->grade2 < min&&temp->st->grade2!=-1) {
            min = temp->st->grade2;
            minSt = temp->st->id;
        }
        sumA += temp->st->grade1;
        sumB += temp->st->grade2;
        StudentNumber++;
        temp = temp->next;
    }
    double percentA=(Af/A)*100.00;
    double percentB=(Bf/B)*100.00;
    int avgA=(sumA/A);
    int avgB=(sumB/B);


    FILE *FR=fopen("Report.txt","w");
    fputs("Total Students Number: ",FR);
    fprintf(FR,"%d\n",StudentNumber);
    fputs("Students only enter to one exam: ",FR);
    fprintf(FR,"%d\n",oneExam);
    fputs("Students don't enter to any exams: ",FR);
    fprintf(FR,"%d\n",noOne);
    fputs("Fault percent of Students in exam A: ",FR);
    fprintf(FR,"%.2f\n",percentA);
    fputs("Fault percent of Students in exam B: ",FR);
    fprintf(FR,"%.2f\n",percentB);
    fputs("Avg marks  in exam A: ",FR);
    fprintf(FR,"%d\n",avgA);
    fputs("Avg marks  in exam B: ",FR);
    fprintf(FR,"%d\n",avgB);
    fputs("The student who received the highest mark : ",FR);
    fprintf(FR,"%d\n",maxSt);
    fputs("The student who received the lowest mark : ",FR);
    fprintf(FR,"%d\n",minSt);


    fclose(FR);
}