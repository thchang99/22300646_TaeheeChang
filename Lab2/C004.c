// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class{
	int code;		// class code
	char name[30]; 	// class name
	int unit;		// credites
	int grading;	// grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// Functions provided
int loadData(struct st_class* c[]); // Load all class list from data file.
void printAllClasses(struct st_class* c[], int csize); // Print all class list

// Functions for modifying
int addNewClass(struct st_class* c[], int csize); // Add a class into the list
void editClass(struct st_class* c[], int csize); // Modify a class in the list
void findClasses(char* name, struct st_class* c[], int csize); // Search a class by name from the list

// Functions for making
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); // Apply a class
void printMyClasses(int my[], int msize, struct st_class* c[], int csize); // Print my classes
void saveMyClass(int my[], int msize, struct st_class* c[], int csize); // Save my classes
void saveAllClasses(struct st_class* c[], int csize); // Save all class list


int main(void) {
	int no;	// menu number 
	struct st_class* classes[50]; // Class list (max. 50 classes)

	int myclass[10]; // My classes (max. 10 classes of code)
	int mycount = 0; // Amount of my classes

	srand(time(0)); //sets random seed
	int count = loadData(classes); //initial count of classes from loading the file
	printf("> Load %d classes.\n", count);

	while(1){
		printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
		printf(">> Menu? > ");
		scanf("%d", &no);

		//logic that selects between classes based on user input, could've been clearer if switch had been used
		if(no == 1){ 
			printf("> 1.Class list (%d classes)\n", count);
			printAllClasses(classes, count);
		}
		else if(no == 2){ 
			printf("> 2.Add a Class\n");
			count = addNewClass(classes, count);
		}
		else if(no == 3){ 
			printf("> 3.Modify a Class\n");
			editClass(classes, count);
		}
		else if(no == 4){
			printf("> 4.Search a Class\n");
			printf(">> Enter class name > ");
			char name[30];
			scanf("%s", name);
			findClasses(name, classes, count);
		}
		else if(no == 5){
			printf("> 5.Apply a class\n");
			mycount = applyMyClasses(myclass, mycount, classes, count);
			printf("%d classes has been applied.\n", mycount);
		}
		else if(no == 6){
			printf("> 6.My classes\n");
			printMyClasses(myclass, mycount, classes, count);
		}
		else if(no == 7){
			printf("> 7.Save\n");
			saveMyClass(myclass, mycount, classes, count);
			printf("\n> All my classes ware saved to my_classes.txt.\n");
			saveAllClasses(classes, count);
			printf("\n> All of class list ware saved to classes.txt.\n");
		}
		else break;
	}
	return 0;
}

int loadData(struct st_class* c[]){
	int count=0;
	FILE* file;

	file=fopen("classes.txt", "r");
	while(!feof(file)){ //this creates memory space per classes that were read on the classes.txt file
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);
	return count;
}

void printAllClasses(struct st_class* c[], int csize){
	for(int i=0; i<csize; i++){  //goes through every class data and outputs it on the console
		printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}
}

void saveAllClasses(struct st_class* c[], int csize){
	FILE* file; //this saves the classes in the format that it is read 
	file = fopen("classes.txt", "w");
	for(int i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;
	//this function uses strstr to go through every name and match it 
	printf("Searching (keyword : %s)\n", name);
	for(int i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d classes found.\n", count);
}

// You must complete these functions.
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.
	int dup = 0; 
	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));


	do{
	dup = 0;
	printf(">> code number > ");
	scanf("%d", &(p->code));
    /** Need to dissallow duplicates in class code*/
    for(int i  = 0; i  < csize; i++){
        if(p->code == c[i]->code){
            printf(">> Code duplicated! Retry.\n");
			dup = 1;
			break;
        }
    }
	} while (dup == 1); //these lines of code modify the data pointed
	printf(">> class name > ");
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}

void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;
    int check = 0;
	printf(">> Enter a code of class > ");
	scanf("%d", &code);

	
	// You must complete this section.
    /* line that gets the name and finds the appropriate index
        1. check if the code exists
        1.1 repeat for end of csize 
        1.2 match code of each code that the pointer points to the one entered
        1.3 if none matches exit
        2 take the local pointer and assign it to the pointer that was matched */

    for(int i = 0; i < csize; i++){
        if(c[i]->code == code){
            p = c[i];
            check = 1;
            break;
        }
    }

    if (!(check)){
        printf("\n*class code does not exist*\n-exiting to menu-\n");
        return;
    }
	
	printf("> Current: [%d] %s [credits %d - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("> Enter new class name > ");
	scanf("%s", p->name);
	printf("> Enter new credits > ");
	scanf("%d", &(p->unit));
	printf("> Enter new grading(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	printf("> Modified.\n");

}


// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){
	int addsize = 0;
	int rep = 1; 
	int findcode = 0;
	int code; //class code
    /*1. get class code and add it in to myclass array
        1.1 ask to enter class code
		1.2 find class with code
		1.3 add code to my list
		1.3 ask if i want to add more classes
	2.	return amount of classees added*/

	while(rep == 1){
		findcode = 0;
		printf(">> Enter a class code > ");
		scanf("%d", &code);
		for(int i = 0; i < csize; i++){
			if(c[i]->code == code){
				printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
				findcode = 1;
				my[msize++] = code;
				addsize++;
				break;
			}
		}
		if (findcode == 0){
			printf(">> Could not find matching class code\n");
		}
		printf(">> Add more?(1:yes 2:no) > ");
		scanf("%d", &rep);

	}
	return msize;

	
	return 0;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){
	int cred = 0;
	/* 1. print the classes that I applied to in order
		1.1 go through my class code list 1 by 1
		1.2 show class information
		1.3 add credits to find total
		2 show credits
		*/
	for(int k = 0; k < msize; k++){
		for(int i = 0; i < csize; i++){
			if(c[i]->code == my[k]){
				printf("%d. [%d] %s [credit %d - %s]\n",k + 1, c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
				cred += c[i]->unit;
			}
		}
	}
	printf("All : %d credits", cred);

	

}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){
	//1. print the classes applied in order with stats, same as printMyClass except onto a txt file
	FILE *f;
	int cred = 0; 
	f = fopen("my_classes.txt", "w");
	fprintf(f, "My Classes\n");
	for(int k = 0; k < msize; k++){
		for(int i = 0; i < csize; i++){
			if(c[i]->code == my[k]){
				fprintf(f, "%d. [%d] %s [credit %d - %s]\n",k + 1, c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
				cred += c[i]->unit;
			}
		}
	}
	fprintf(f, "All : %d classes, %d credits ", msize, cred);
	fclose(f);

	
}