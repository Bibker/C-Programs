#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
char p1[15],p2[15],que[10],halfWord[20],ans[10],rematch;
int i=1,wordcount=1,check,score1=0,score2=0;
void step1(){

    while(i<25){
            printf("   ");
            i++;

    }
    printf("____WElcome to Guess Challange Game____\n");
    printf("Enter name of First player\n--->");
    scanf("%s",&p1);
    printf("\nEnter name of Second player\n--->");
    scanf("%s",&p2);
    printf("\nPRESS ANY KEY TO CONTINUE...");
    getch();
    system("cls");
}

void step2(){
    printf("GAME INSTRUCTIONS OF GAME ARE...\n");
    getch();
    printf("1. This is a multiplayer game.\nAt first player1 should input a word which is to be guessed by player2.\n");getch();
    printf("2. Then press enter and again enter the same word.\n But this time place some '_' in between letters.\n");getch();
    printf("3. Again press enter and within 1 minute player 2 should guess the word.\n");getch();
    printf("4. If the player guess it correct.He/She gets the score.\n");getch();
    printf("5. Same process is repeated by the other player.\n\n\n\n");getch();
    printf("AFTER 15 WORDS THE USER HAVING HIGHEST SCORE WILL WIN THE GAME\n");getch();
    int i=1;
    while(i<25){
            printf(" ");
            i++;
            }
    printf("Lets start the game...\n");
    printf("Press Enter...");
    getch();
    system("cls");

}
void score(){
     while(i<50){
            printf(" ");
            i++;
            }

printf("%s's SCORE: %d             %s's SCORE: %d",p1,score1,p2,score2);



}
void p1playing(){
    system("cls");
    score();
    printf("\n%s, Enter the word.\n",p2);
    scanf("%s",&que);
    printf("\nPRESS ENTER\n");
    getch();
    system("cls");
    score();
    printf("\n Your word has been stored sucessfully..\n");
    printf("Now Enter the same word with '_' in the middle\nEnter it ====>");
    scanf("%s",&halfWord);
    printf("Press Enter..");
    getch();
    system("cls");
    score();
    printf("\n%s, have entered %s for you\nNow guess the word, %s\nEnter here===>",p2,halfWord,p1);
    scanf("%s",&ans);
    check= strcmp(que,ans);
       if(check==0){
        printf("YOU ARE CORRECT, %s.\n",p1);
        score1=score1+10;
        getch();
    }
    else {
        printf("It is incorrect, %s.\nThe Correct word is %s.\n",p1,que);
        getch();

    }
    getch();
    system("cls");
    score();
}
void p2playing(){
    printf("\n%s, Enter the word.\n",p1);
    scanf("%s",&que);
    printf("\nPRESS ENTER\n");
    getch();
    system("cls");
    score();
    printf("\n Your word has been stored sucessfully..\n");
    printf("Now Enter the same word with '_' in the middle\nEnter it ====>");
    scanf("%s",&halfWord);
    printf("Press Enter..");
    getch();
    system("cls");
    score();
    printf("\n%s, have entered %s for you\nNow guess the word, %s\nEnter here===>",p1,halfWord,p2);
    scanf("%s",&ans);
    check= strcmp(que,ans);
    if(check==0){
        printf("YOU ARE CORRECT, %s\n",p2);
        score2=score2+10;
        getch();
    }
    else {
        printf("It is incorrect, %s.\nThe Correct word is %s.",p2,que);
        getch();

}
system("cls");
score();
}





int main()
 {
     do{
step1();
step2();
do{
score();
p1playing();
p2playing();
wordcount++;
}
while(wordcount<3);
system("cls");
printf("Final Scores\n%s:%d\n%s:%d",p1,score1,p2,score2);
if(score1>score2){
    printf("%s have won the game.\nCOngratulation\n",p1);
    printf("\nPress any key...");
    getch();
}
else if(score1==score2){
    printf("\nThe match is draw.\nCongratulation to both!!\n");
    printf("\nPress any key...\n\n\n");
getch();
}
else{
         printf("\n%s have won the game.\nCOngratulation\n",p2);

printf("Press any key...\n\n\n");
getch();
}
printf("DO YOU WANT TO PLAY A NEW GAME?(y/n)..");
rematch=getche();

}

while(rematch=='y');
return 0;
}
