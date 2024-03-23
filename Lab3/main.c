// 22300646 Taehee Chang

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
void updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 

int main(void) {
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	return size+1;
}

void printStatistics(struct st_channel* c[], int size){
	printf("> Statistics of Channels\n");
   /* print statistics of channels of each level
    1. use for loop to go through 5 levels
    1.1 for each level the count, average number of subs, and top channel needs to be identified
    1.2 output those channesl*/
    int count = 0;
    float average;
    int sum = 0;
    int top = -1;
    for (int i = 0; i < 5 ; i++){
        for(int j = 0; j < size; j++){
            if(c[j]->level == i){
                if (top == -1){
                    top = j;
                }
                count++;
                sum += c[j]->count;
                if(c[j]->count > c[top]->count){
                    top = j;
                }

            }
        }
        printf("%s :  %d channels, Average %.1f peoples, Top channel : %s (%d peoples)\n", LNAME[i], count, sum/(float)count, c[top]->name, c[top]->count);

    }


}

void pickupRandomChannels(struct st_channel* c[], int size){
    //picking up certain amount of random channels
    //while loop that runs until certian size is reached
    // 1. while loop  
    // 1.1 randomness that selects some
    int selected[size];
    int count = 0;
    int req;
    int rando;
    for(int i = 0; i < size;i++){
        selected[i] = 0;
    }

	printf("> Pick up Channels\n");
	printf("> How much channels you want to pick up? > ");
    scanf("%d", &req);
    do{
        rando = rand()%size;
        if(selected[rando] == 0){
            count++;
            selected[rando] = 1;
            printf("[%2d] %-20s %10d peoples [%s] \n",rando+1, c[rando]->name, c[rando]->count,LNAME[c[rando]->level]);
        }
    }while(count < req);


}
void searchChannel(struct st_channel* c[], int size){
    //range of people vs names
    //1. range of people   
    //1.1 when 1 is chosen
    //1.2 repeat from 0to size and select groups and display them when it meets the requirements
	int choose;
    int min, max;
    int count = 0;
    char name[100];
    printf("> Search Channels\n");
	printf("> Choose one (1:by peoples 2:by names) > ");
    scanf("%d", &choose);
    if(choose == 1){
        printf("> Enter the range of peoples (from ~ to) > ");
        scanf("%d %d", &min, &max);
        for(int i = 0; i < size; i++){
            if(c[i]->count >= min && c[i]->count <= max)
            {
                printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
                count++;            
            }
        }
    
        printf("> %d channels are found.", count);

    }

   if(choose == 2){
        printf("> Enter a name >");
        scanf("%s", name);
        for(int i = 0; i < size; i++){
            if(strstr(c[i]->name, name))
            {
                printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
                count++;
            }
        }
    
        printf("> %d channels are found.\n", count);

    }



}

void updateChannel(struct st_channel* c[], int size){
    int number;
    char name[100];
    int count;
	printf("> Modify a new Channel\n");
	printf("> Enter a number of channel > ");
    scanf("%d", &number);
    if(number < 1 || number > size){
        printf("> Wrong Number.\n");
        return;
    }
    number --;
    printf("> Channel Info.\n");
    printf("[%2d] %-20s %10d peoples [%s] \n",number+1, c[number]->name, c[number]->count,LNAME[c[number]->level]);
    printf("> Enter a new name of channel > ");
    scanf("%s", name);
    printf("> Enter a new amount of peoples > ");
    scanf("%d", &count);
    strcpy(c[number]->name, name);
    c[number]->count = count;
    printf("> Channel is modified");


}

int deleteChannel(struct st_channel* c[], int size){
	int yesno;
    int number;
	printf("> Delete a new Channel\n");
	printf("> Enter a number of channel > ");
    scanf("%d", &number);
    if(number < 1 || number > size){
        printf("> Wrong Number.\n");
        return size;
    }
    number --;
    printf("> Channel Info.\n");
    printf("[%2d] %-20s %10d peoples [%s] \n",number+1, c[number]->name, c[number]->count,LNAME[c[number]->level]);
    printf("> Do you want to delete the channel? (1:Yes 0:No)");
    scanf("%d", &yesno);
    if(yesno){
        for(int i = number; i < size; i++){
            c[i] = c[i+1];
        }
        free(c[size-1]);
        size--;
        printf("Channel is deleted\n");
    }
    else{
        printf("Canceled");
    }
	return size;
}


void makeReport(struct st_channel* c[], int size){
    

}