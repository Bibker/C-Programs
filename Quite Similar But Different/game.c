#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
char name1[15], name2[15], que1[15], que2[15], ans[15], replay;
int i=1 ,check,check1,c,score1=0,score2=0,words,wordsP,wordsR,wordsD,total,wrongHint1,wrongHint2,comparee;
void step1(){
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
void step2(){
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
void gamePlay(){
    score1=0;
    score2=0;
    wordsP=0;
    wordsR=0;
printf("\nHow many words do you want to play(10 to 20)? \nENTER===> ");
scanf("%d",&words);
system("cls");
}
void playTime(){
    int con1=1;
    total=words;
    printf("TOtal Words:%d",total);
    while(con1<27){
            printf(" ");
            con1 ++;
    }
    printf("Words Played: %d       Words Remain..: %d\n",wordsP,wordsR);
}
void score(){
    int con=1;
    while(con<40){
            printf(" ");
            con ++;
    }
    printf("%s's score:%d       %s's score: %d",name1,score1,name2,score2);
}

void step3(){

    wordsR=words-wordsP;
    system("cls");
    playTime();
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
playTime();
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
playTime();
score();
}
}
void step4(){
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
playTime();
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
void exit1(){
system("cls");
wordsR=words-wordsP;
playTime();
score();
printf("\n\n\n\nGame Over\nPress Enter..");
getch();}

int main(){
    step1();
    step2();


    do{
    gamePlay();
    for(c=0;c<words;c++){
    step3();
    step4();
    }
    exit1();
    getch();
    system("cls");
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
    printf("\nDO you want to play again(y/n)?\n");
    replay=getche();
    }
    while(replay=='y');
}
