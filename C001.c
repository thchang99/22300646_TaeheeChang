#include <stdio.h>

void pStar(int);
void pBlank(int);

int main(){
    int size; // 크기
    int stars, blank1, blank2; // 별의 갯수, 빈칸1의 갯수, 빈칸2의 갯수 
    int i, j;

    scanf("%d", &size);

    stars = 2;
    blanks = (size-1)*2;
    for(i = 0; i < size; i++){
        pStar(1);
        
        pStar(1);
    }


    return 0;
}

void pStar(int rep){
    for (int i  = 0; i < rep, i++){
      printf("*");
    }
}

void pBlank(int rep){
    for (int i  = 0; i < rep, i++){
      printf(" ");
    }
}