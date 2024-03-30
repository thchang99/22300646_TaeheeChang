#include "student.h"
char payment[2][20] = {"No", "Yes"};

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
int newStudent(student *p[], int size){
    printf("\n>> Enter new student info\n");
    student *t = (student *)malloc(sizeof(student));
    printf("Name : ");
    scanf("%s", t->name);
    printf("Student ID : ");
    scanf("%s", t->id);
    printf("Phone number : ");
    scanf("%s", t->phone);
    printf("Seat number : ");
    scanf("%d", &t->seat);
    printf("Paid (0:NO, 1:YES): ");
    scanf("%d", &t->paid);
    p[size] = t;
    return ++size;
}
void viewStudent(student *p[], int size){
    printf("\n>> View all students\n");
    printf(">>  #  Name         StudentID   Phone       Seat Paid\n");
    for(int i = 0; i < size; i++){
        printf(">> [%d] %-12s %-11s %-11s %-4d %s\n", i+1, p[i]->name, p[i]->id, p[i]->phone, p[i]->seat, payment[p[i]->paid]);
    }
    printf("\n>> %d students are in the list", size);
}

void updateStudent(student *p[], int size);
int deleteStudent(student *p[], int size);
void searchStudent(student *p[], int size);
void save(student *p[], int size);
