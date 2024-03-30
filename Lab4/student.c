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
    printf(">> Name : ");
    scanf("%s", t->name);
    printf(">> Student ID : ");
    scanf("%s", t->id);
    printf(">> Phone number : ");
    scanf("%s", t->phone);
    printf(">> Seat number : ");
    scanf("%d", &t->seat);
    printf(">> Paid (0:NO, 1:YES): ");
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

void updateStudent(student *p[], int size){
    int num;
    student * t;
    int noyes;
    printf("\n>> Update a student's information\n");
    printf(">> Enter studnet's index number : ");
    scanf("%d", &num);
    if(num < 1 || num > size){
        printf(">> Index DNE, exiting to menu.\n");
        return;
    }
    t = p[num-1];
    printf("\n>> Selected Student\n");
    printf(">>  #  Name         StudentID   Phone       Seat Paid\n");
    printf(">> [%d] %-12s %-11s %-11s %-4d %s\n", num, t->name, t->id, t->phone, t->seat, payment[t->paid]);
    printf("\n>> Continue? (0:NO, 1:YES): ");
    scanf("%d", &noyes);
    if(noyes == 0){
        printf("\n>> Canceled");
        return;
    }
    
    printf(">> Name : ");
    scanf("%s", t->name);
    printf(">> Student ID : ");
    scanf("%s", t->id);
    printf(">> Phone number : ");
    scanf("%s", t->phone);
    printf(">> Seat number : ");
    scanf("%d", &t->seat);
    printf(">> Paid (0:NO, 1:YES): ");
    scanf("%d", &t->paid);

    printf("\n>> Updated Information\n");
    return;
    
}
int deleteStudent(student *p[], int size){
    int num;
    student * t;
    int noyes;
    printf("\n>> Delete a student's information\n");
    printf(">> Enter student's index number : ");
    scanf("%d", &num);
    if(num < 1 || num > size){
        printf(">> Index DNE, exiting to menu.\n");
        return size;
    }
    t = p[num-1];
    printf("\n>> Selected Student\n");
    printf(">>  #  Name         StudentID   Phone       Seat Paid\n");
    printf(">> [%d] %-12s %-11s %-11s %-4d %s\n", num, t->name, t->id, t->phone, t->seat, payment[t->paid]);
    printf("\n>> Continue? (0:NO, 1:YES): ");
    scanf("%d", &noyes);
    if(noyes == 0){
        printf("\n>> Canceled\n");
        return size;
    }
    for(int i = num-1; i < size; i++){
            p[i] = p[i+1];
    }
    free(t);
    printf("\n>> Succesfully deleted\n");
    return --size;
}
void searchStudent(student *p[], int size){
    char name[20];
    printf("\n>> Search for a Student\n");
    printf(">> Enter Name : ");
    scanf("%s", name);
    printf(">>  #  Name         StudentID   Phone       Seat Paid\n");
    for(int i = 0; i < size; i++){
        if(strstr(p[i]->name,name))
            printf(">> [%d] %-12s %-11s %-11s %-4d %s\n", i+1, p[i]->name, p[i]->id, p[i]->phone, p[i]->seat, payment[p[i]->paid]);
    }
}
void save(student *p[], int size){
    FILE * save;
    save = fopen("students.txt", "w");
    for(int i = 0; i < size; i++){
        fprintf(save, "%s %s %s %d %d\n", p[i]->name, p[i]->id, p[i]->phone, p[i]->seat, p[i]->paid );
    }

}
