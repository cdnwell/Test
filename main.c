#include <stdio.h>
#include <string.h>

enum{
    EXIT,INSERT,SEARCH,DELETE,UPDATE
};

typedef struct{
    char name[20];
    char phone[20];
}Member;

Member arr[20] = {
    {"홍길동","010-1234-1234"},
    {"이한주","010-2345-2345"},
    {"정상동","010-3456-3456"},
    {"이철수","010-4567-4567"}
};

int idx = 4;

void InsertMember(){
    printf("이름 입력 :");
    scanf("%s",arr[idx].name);
    printf("전화번호 입력 : ");
    scanf("%s",arr[idx].phone);
    idx++;
}

void SearchMember(){
    char name[20];

    printf("검색할 이름 입력 : ");
    scanf("%s",name);

    for(int i=0;i<idx;i++){
        if(!strcmp(name,arr[i].name)){
            printf("%s %s\n",arr[i].name, arr[i].phone);
            return;
        }
    }

    printf("검색한 이름이 정보가 없습니다.\n");
}

void DeleteMember(){
    char name[20];

    printf("삭제할 이름 입력 : ");
    scanf("%s",name);

    for(int i=0;i<idx;i++){
        if(!strcmp(name,arr[i].name)){
            for(int j=i;j<idx-1;j++){
                arr[j] = arr[j+1];
            }
            idx--;
            return;
        }
    }
    printf("삭제할 이름이 정보가 없습니다.\n");
}

void UpdateMember(){
    char name[20];

    printf("연락처에서 수정할 이름 입력 : ");
    scanf("%s",name);

    for(int i=0;i<idx;i++){
        if(!strcmp(name,arr[i].name)){
            char name_chn[20];
            char phone_chn[20];
            printf("변경할 이름 : ");
            scanf("%s",name_chn);
            printf("변경할 연락처 : ");
            scanf("%s",phone_chn);
            
            int j =0;
            while(arr[i].name[j]!='\0'){
                arr[i].name[j]=name_chn[j];
                j++;
            }

            j=0;
            while(arr[i].phone[j]!='\0'){
                arr[i].phone[j]=phone_chn[j];
                j++;
            }

            printf("변경 완료\n");
            return;
        }
    }

    printf("검색한 이름이 주소록에 없습니다.\n");
    return;
}

int main(void){
    int n = -1;

    while(n != 0){
        printf("---연락처 등록 시스템---\n");
        printf("1. 연락처 입력\n");
        printf("2. 연락처 조회\n");
        printf("3. 연락처 삭제\n");
        printf("4. 연락처 수정\n");
        printf("0. 조회 종료\n");
        printf("- 메뉴 입력 : ");
        scanf(" %d",&n);

        switch(n){
        case INSERT:
            InsertMember();
            break;
        case SEARCH:
            SearchMember();
            break;
        case DELETE:
            DeleteMember();
            break;
        case UPDATE:
            UpdateMember();
            break;
        case EXIT:
        default:
            break;
        }

    }

    return 0;
}