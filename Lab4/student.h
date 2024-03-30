#ifndef _CLASSES_H_
#define _CLASSES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
typedef struct{
    char name[20];
    char id[20];
    char phone[20];
    int seat;
    int paid;

}student;

int loadfile(student *p[]); //returns size read;
int menu();
int newStudent(student *p[], int size);
void viewStudent(student *p[], int size);
void updateStudent(student *p[], int size);
int deleteStudent(student *p[], int size);
void searchStudent(student *p[], int size);
void save(student *p[], int size);
void unpaid(student *p[], int size);
void seatStatus(student *p[], int size);
#endif