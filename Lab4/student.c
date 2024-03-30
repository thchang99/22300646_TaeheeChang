#include "student.h"
char payment[2][20] = {"No", "Yes"};
char menus[8][20] = {"View List", "Add New", "Find", "Edit", "Delete", "Seats", "Billing", "Save"};
int loadfile(student *p[]){
    FILE *fp;
    fp = fopen("students.txt", "r");
    int no = 0;

    while(!feof(fp)){
        student *t = (student *)malloc(sizeof(student));
        if(fscanf(fp, "%s %s %s %d %d", t->name, t->id, t->phone, &t->seat, &t->paid) != 5)
            break;
        p[no] = t;
        no++;
    }
    return no;
} //returns size read;
void menu(){
    char dummy;

    printf("\n\n>> Press Enter to view Menu\n");
    fflush(stdin);
    while (getchar() != '\n');

    printf("\n>> Menu\n");

    for(int i = 0; i < 8; i++){
        printf(">> [%d] %s\n", i+1, menus[i]);
    }
    printf(">> [0] Exit\n");

    return;
}

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

    printf("\n>> Succesfully added new student\n");
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
    printf(">> Succesfully saved data to student.txt");
    fclose(save);

}

void unpaid(student *p[], int size){
    printf("\n>> Show list of students that have not paid\n");
    printf(">>  #  Name         StudentID   Phone       Seat Paid\n");
    for(int i = 0; i < size; i++){
        if(p[i]->paid == 0)
            printf(">> [%d] %-12s %-11s %-11s %-4d %s\n", i+1, p[i]->name, p[i]->id, p[i]->phone, p[i]->seat, payment[p[i]->paid]);
    }
}
void seatStatus(student *p[], int size){
    int seats[SIZE] = {0};

    printf("\n>>Show status on seats\n");
    for(int i = 0; i < size; i++){
        seats[p[i]->seat] += 1;
    }

    for(int i = 0; i < SIZE / 10; i++){
        printf(">> ");
        for(int j = 0; j < 10; j++){
            printf("%2d [%c]", i*10+j, (seats[i*10 + j] > 0) ? '*' : ' ');
        }
        printf("\n");
    }

    printf("\n>> Seats with conflicts : ");
    for(int i = 0; i < SIZE; i++){
        if(seats[i] > 1){
            printf(" [%d]", i);
        }
    }
}
