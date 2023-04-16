#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int board[5][5];
char print_board[5][5]={0};
int duplicate_num[25]={0};
int answer,a, i, j, bingo=0;
//함수선언 뭐 이리 많누
void setting_game();
int is_duplicate();
int mark_num();
int print_num();
int checking_bingo();
int check_duplicate();
//메인함수
int main(){
    int num,count=0,b;
    setting_game();
    while(1){
        
        while(1){
        printf("숫자를 내놓아라 닝겐 : ");
        scanf("%d", &b);
        if(check_duplicate(b)){
                if(0<b||b<=25){
                duplicate_num[count] = b;
                count++;
                break;
            }
        }
        duplicate_num[count] = 0;
        printf("다시 입력하렴^^");
        }
        mark_num(b);
        if(mark_num(num)){
            print_num();
        }
        checking_bingo();
        if(bingo <3){
            bingo =0;
        }else if(bingo ==3){
            break;
        }
    }
    printf("끝나버렸네 잘해써");
}

//----------------------함수 선언------------------------------------
int check_duplicate(int b){
    for(i=0;i<26;i++){
        if(duplicate_num[i]==b){
        return 0;
        }
        else{
        return 1;}
    }
        
}
int checking_bingo(){
int how = 0;
//가로줄
for(i=0;i<5;i++){
    how = 0;
    for(j=0;j<5;j++){
    if(board[i][j]==-1){
        how++;}
        }
    if(how == 5){
    bingo ++;
    how = 0;}
}
//세로줄
for(j=0;j<5;j++){
    how = 0;
    for(i=0;i<5;i++){
    if(board[i][j]==-1){
        how++;}
        }
    if(how == 5){
    bingo ++;
    how = 0;}
}
//대각선
how= 0;
for(j=0;j<5;j++){
    if(board[j][4-j]==-1){
    how++;}
}if(how == 5){
    bingo ++;
}
//대각선2
how= 0;
for(j=0;j<5;j++){
    if(board[j][j]==-1){
    how++;}
}if(how == 5){
    bingo ++;
}
}
int mark_num(int a){
    for(i =0; i<5; i++){
        for(j=0; j<5; j++){
            if(board[i][j]==a){
                board[i][j]= -1;
            }
        }
    }return 1;
}
int print_num(){
    for(i =0; i<5; i++){
        for(j=0; j<5;j++){
            if(board[i][j] == -1){
                print_board[i][j] = 'x';
                printf("%3c", print_board[i][j]);
            }else{
                printf("%3d", board[i][j]);
            }
        }printf("\n");
    }
}
//--------------feat by GPT-----------------------
void setting_game() {
    int i, j, num;
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            while (1) {
                num = rand() % 25 + 1;
                if (!is_duplicate(num)) {
                    board[i][j] = num;
                    break;
                }
            }
        }
    }
}
int is_duplicate(int num) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (board[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}