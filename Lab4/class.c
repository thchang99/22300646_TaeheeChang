#include "student.h"

int loadfile(student *p[]){
    FILE *fp;
    fp = fopen("students.txt", "r");
    int no = 0;

    while(!feof(fp)){
        student *t = (student *)malloc(sizeof(student));
        fscanf(fp, "%s %s %s %d %d", t->name, t->id, t->phone, &t->seat, &t->paid );
        p[no] = t;
        no++;
    }
    return no;
} //returns size read;
int menu(student *p[]);
int newStudent(student *p[], int size);
void viewStudent(student *p[], int size){
    for(int i = 0; i < size; i++){
        printf("%s %s %s %d %d\n", p[i]->name, p[i]->id, p[i]->phone, p[i]->seat, p[i]->paid);
    }
}
void updateStudent(student *p[], int size);
int deleteStudent(student *p[], int size);
void searchStudent(student *p[], int size);
void save(student *p[], int size);