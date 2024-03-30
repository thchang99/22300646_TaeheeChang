#include "student.h"
/*4. 프로그램 시작 시, 데이터 파일로부터 읽어들인 내용으로 초기 데이터 목록을 로딩해야 한다.
5. [필수기능] main() 에서는 무한반복문을 사용하여 다음 메뉴별로 적절한 작업이 수행되어야 한다.
- Create 기능 – 새로운 데이터셋을 목록에 추가한다.
- Read 기능 – 전체 데이터 목록을 화면에 표시한다.
- Update 기능 – 현재 데이터 목록 중에 하나의 데이터셋을 선택하여 내용을 변경한다.
- Delete 기능 – 현재 데이터 목록 중에 하나의 데이터셋을 선택하여 제거한다.
- Search 기능 – 현재 데이터 목록 중에 특정 조건에 맞는 데이터셋들을 찾아 표시한다.
- Save 기능 - 현재 변경된 데이터 목록을 데이터 파일로 저장한다.
(이때 저장된 파일이 프로그램을 다시 시작할 때 데이터 목록 구축을 위해 읽혀진다.)
6. [선택기능] 위 내용 외에 원하는 기능은 얼마든지 추가 */

int main(){
    student *p[SIZE];
    int size;
    int input;
    size = loadfile(p);

    printf(">> Handong Live Ticketing Assistant");
    do{
    menu();
    printf("\n>> Enter number : ");
    scanf("%d", &input);


    switch(input){
        case 1:
            viewStudent(p, size);
            break;
        case 2:
            size = newStudent(p, size);
            break;
        case 3:
            searchStudent(p, size);
            break;
        case 4:
            updateStudent(p, size);
            break;
        case 5:
            size = deleteStudent(p, size);
            break;
        case 6: 
            seatStatus(p, size);
            break;
        case 7:
            unpaid(p, size);
            break;
        case 8:
            save(p, size);
            break;
        default:
            break;
    }

    }while(input != 0 );
    printf("\n>> Exiting Program..");
    return 0;
}
