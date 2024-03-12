#include <stdio.h>

void pStar(int);
void pBlank(int);

int main(){
    int size; // 크기
    int stars, blank1, blank2; // 별의 갯수, 빈칸1의 갯수, 빈칸2의 갯수 
    int i, j;

    scanf("%d", &size);
    blank1 = 0;
    blank2 = (size-1)*2;
    for(i = 0; i < size; i++){
        pBlank(blank1);
        pStar(1);
        pBlank(blank2);
        pStar(1);
        blank1++;
        blank2-= 2;
        printf("\n\n");
    }
    stars = size * 2;
    for(i = 0; i < size; i++){
      pStar(stars);
      printf("\n\n");
    }
  blank1 = 0;
for(i = 0; i < size; i++){
      pBlank(blank1);
      pStar(stars);
      printf("\n\n");

      stars -= 2;
      blank1++;
    }
  pStar(size*2);
  printf("\n");
    return 0;
}

void pStar(int rep){
    for (int i  = 0; i < rep; i++){
      printf("*");
    }
}

void pBlank(int rep){
    for (int i  = 0; i < rep; i++){
      printf(" ");
    }
}

