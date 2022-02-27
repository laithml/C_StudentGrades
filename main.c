#include <stdio.h>
#include <stdlib.h>
//211353297


#include "StudentList.h"
#include "GradesOperations.h"
int main() {
    StudentList* lst=FileToList();
    Report(lst);
    printStudentList(lst);
    deleteList(lst);


}
