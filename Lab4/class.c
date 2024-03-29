#include "main.h"

int loadfile(student *p); //returns size read;
int menu(student *p);
int newStudent(student *p, int size);
void viewStudent(student *p, int size);
void updateStudent(student *p, int size);
int deleteStudent(student *p, int size);
void searchStudent(student *p, int size);
void save(student *p, int size);