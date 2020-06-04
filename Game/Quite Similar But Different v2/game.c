#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <dos.h>


void welcome(void);
void instructions(void);
void gamePlay(void);
void wordsCounter(void);
void score(void);
void firstPlayerTurn(void);
void secondPlayerTurn(void);
void winner(void);
void exitGame(void);




char name1[15], name2[15], que1[15], que2[15], ans[15], replay;
int i=1 ,check,check1,c,score1=0,score2=0,words,wordsP,wordsR,wordsD,total,wrongHint1,wrongHint2,comparee;

int main(){

    welcome();
    instructions();


    do{
    gamePlay();
    for(c=0;c<words;c++){
    firstPlayerTurn();
    secondPlayerTurn();
    }
    exitGame();
    getch();
    system("cls");
    winner();
    printf("\nDO you want to play again(y/n)?\n");
    replay=getche();
    }
    while(replay=='y');
}

//********************************************************************************************
                                  //Functions are Defined Here
//********************************************************************************************


//1
void welcome(){
 while(i<20){
        printf(" ");
        i++;
        }
printf("WELCOME TO PUZZEL GAME.........\n");
printf("Enter 1st player name:");
scanf("%s",&name1);
printf("\n Enter 2nd player name:");
scanf("%s",&name2);
printf("\n Press any key to continue....");
getch();
system("cls");
}

//2

void instructions(){
    int i=1;
 while(i<20){
        printf(" ");
        i++;
        }
printf("Instruction for the game are given below:\n");
printf("\n 1. First player should enter a word in right order....\n");
printf(" 2. Press enter key \n Then first player should write the same word in wrong order \n the word should be guessed by second player....\n");
printf(" 3. And then the same process is repeated by second player...\n");
printf("\n \n \n \n \n \n Press any key to continue...");
getch();
system("cls");
}

//3

void gamePlay(){
    score1=0;
    score2=0;
    wordsP=0;
    wordsR=0;
    wordsCheck:
printf("\nHow many words do you want to play(1 to 20)? \nENTER===> ");
scanf("%d",&words);
if(words>20||words<1){
    printf("You have entered %d/nPlease Enter from 1 to 20.",words);
    goto wordsCheck;
}
system("cls");
}

//4

void wordsCounter(){
    int con1=1;
    total=words;
    printf("TOtal Words:%d",total);
    while(con1<27){
            printf(" ");
            con1 ++;
    }
    printf("Words Played: %d       Words Remain..: %d\n",wordsP,wordsR);
}

//5

void score(){
    int con=1;
    while(con<40){
            printf(" ");
            con ++;
    }
    printf("%s's score:%d       %s's score: %d",name1,score1,name2,score2);
}

//6

void firstPlayerTurn(){

    wordsR=words-wordsP;
    system("cls");
    wordsCounter();
    score();
printf("\nEnter the correct word, %s:",name1);
scanf("%s",&que1);
hint:
printf("\n Now again enter the word in wrong order:");
scanf("%s",&que2);
wrongHint1=strlen(que1);
wrongHint2=strlen(que2);
comparee=strcmp(que1,que2);
if(wrongHint1!=wrongHint2||comparee==0){
    printf("\nWrong, same or unnecessary hint entered. Enter again..\nPress Enter.");
    getch();
    goto hint;
}

else{
printf("\n\n\n\n\n\nPress any key to continue....");
getch();
system("cls");
wordsCounter();
score();
printf("\nHint:%s\n",que2);
printf("\nGuess the word,%s:\nIf you cant guess type 'pass' and press enter.\nEnter==> ",name2);
scanf("%s",&ans);
check=strcmp(que1,ans);
check1=strcmp(ans,"pass");
if (check==0){
    printf("\nYou are correct......");
    score2=score2+10;
}
else if(check1==0){
    printf("\nThe correct word is %s.",que1);
    score2=score2-5;
}
else{
    printf("\nYou are wrong.......");
    printf("\nThe correct word is %s.",que1);
    score2=score2-5;
}
getch();
system("cls");
wordsCounter();
score();
}
}

//7

void secondPlayerTurn(){
printf("\nEnter the correct word, %s:",name2);
scanf("%s",&que1);
hint:
printf("\n Now again enter the word in wrong order:");
scanf("%s",&que2);
wrongHint1=strlen(que1);
wrongHint2=strlen(que2);
comparee=strcmp(que1,que2);
if(wrongHint1!=wrongHint2||comparee==0){
    printf("\nWrong, same or unnecessary hint entered. Enter again..\nPress Enter.");
    getch();
    goto hint;
}
else{
printf("\n\n\n\n\n\nPress any key to continue....");
getch();
system("cls");
wordsCounter();
score();
printf("\nHint:%s\n",que2);
printf("\nGuess the word,%s:\nIf you cant guess type 'pass' and press enter.\nEnter==> ",name1);
scanf("%s",&ans);
check=strcmp(que1,ans);
check1=strcmp(ans,"pass");
if (check==0){
    printf("\nYou are correct......");
    score1=score1+10;
}
else if(check1==0){
    printf("\nThe correct word is %s.",que1);
    score1=score1-5;
}
else{
    printf("\nYou are wrong.......");
    printf("\nThe correct word is %s.",que1);
    score1=score1-5;
}
wordsP++;
getch();
}
 }

//8

void winner(){

  printf("FInal Score\n%s:%d\n%s:%d\n",name1,score1,name2,score2);
    if(score1<score2){
        printf("%s won the game.",name2);

    }
    else if(score1==score2){
        printf("The match is tie.");
    }
    else{
        printf("%S won the game.",name1);

    }
    printf("\nPress enter to continue.");
    getch();
    system("cls");
}

//9

void exitGame(){
system("cls");
wordsR=words-wordsP;
wordsCounter();
score();
printf("\n\n\n\nGame Over\nPress Enter..");
getch();
}
//function definitions ends here