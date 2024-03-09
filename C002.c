#include <stdio.h>

int main(){
    int person[4][3]; 
    int sum[3] = {0};
    float ratio[3];
    int i, j;

    for(i = 0; i < 4; i++){
        if(i == 0){
            printf("Check room (Men)\n");
        }
        if(i == 2){
            printf("Check room (Women)\n");
        }
        for(j = 0; j < 3; j++){
            printf("Room #%d > ", (i+1)*100+j+1);
            scanf("%d", &person[i][j]);
            sum[i/2] += person[i][j];
        }
    }

    sum[2] = sum[0] + sum[1];
    
    printf("Check Result\n");
    printf("Men: %d/24 (%.1f%%)\n", sum[0], (float)sum[0]/24*100);
    printf("Women: %d/24 (%.1f%%)\n", sum[1], (float)sum[1]/24*100);
    printf("Total: %d/48 (%.1f%%)\n", sum[2], (float)sum[2]/48*100);
    return 0;   
}
