#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 1000
#define MAX_NAME 8

/*Lab 3*/
/*This code is incorrect. I don't have time to finish it.*/
int lines;
long stdnum[MAX_LINE];
char stdfn[MAX_LINE][MAX_NAME];
char stdln[MAX_LINE][MAX_NAME];
char cmd[MAX_NAME]; 
int fin[MAX_LINE];
int midt[MAX_LINE];
float q1[MAX_LINE];
float q2[MAX_LINE];
float q3[MAX_LINE];
float mark[MAX_LINE];


int main(){
  onInit();
  return 0;
}

onInit(){
  
  scanf("%d", &lines);	/*get number of lines*/
  int i;
  for ( i = 0; i < lines; ++i){
    readLine(i);
  }
  
/*get command*/
  scanf("%s", &cmd);
  executeCommand(cmd);
  for (i = 0; i <= MAX_NAME; ++i){
    cmd[i] = 0;
  }
    
}

readLine(int i){
  
  scanf("%ld", stdnum[i]);/*scan std number*/
  
  scanf("%s", stdfn[i]);/*scan student first name*/
  
  scanf("%s", stdln[i]);/*scan student last name*/
  
  scanf("%d", fin[i]);/*scan final grade*/
  
  scanf("%d", midt[i]);/*scan midterm grade*/
  
  scanf("%f", q1[i]);/*scan 3 quizzes*/
  
  scanf("%f", q2[i]);
  
  scanf("%f", q3[i]);
  
  mark[i] = 0.6*fin[i] + 0.25*midt[i] + 0.05*q1[i] + 0.05*q2[i] + 0.05*q3[i];
  
}

executeCommand(char command[]){
  if (strcmp(command, "F") == 0){
    fail();
  }else if(strcmp(command, "top") == 0){
    top();
  }else if(strcmp(command, "A") == 0)	{
    gradeA();
  }else if(strcmp(command, "perA") == 0){
    perA();
  }else if(strcmp(command, "anomaly") == 0){
    anomaly();
  }else if((strcmp(command, "q") == 0) || (strcmp(command, "Q") == 0)){
    quit();
		/*do something to exit program.*/
  }else{
    printf("Not a valid command.\n");
  }
}

fail(){
  int c;
  for(c = 0; c < lines; c++){
    if(mark[c] < 50){
      printf("%ld\n", stdnum[c]);
    }
  }
}

top(){
  float maxscore = 0;
  int c;
  for(c = 0; c < lines; c++){
    if(mark[c] > maxscore){
      maxscore = mark[c];
    }
  }
  for(c = 0; c < lines; c++){
    if(mark[c] == maxscore){
      printf("%ld  %s\n", stdnum[c], stdln[c]);
    }
  }
}

gradeA(){
  int c;
  for(c = 0; c < lines; c++){
    if(mark[c] >= 80){
      printf("%ld  %s\n", stdnum[c], stdln[c]);
    }
  }
}

perA(){
  int count = 0;
  int c;
  for(c = 0; c < lines; c++){
    if(mark[c] >= 80){
      count++;
    }
  }
  double tbp = (double)count / (double)lines;  
  
  printf("Percentage of students with an average of A:%.2f%%\n", tbp);	
  
}

anomaly(){
  if(lines > 15){
    printf("NO\n");
  }else{
    int count = 0;
    int c;
    for(c = 0; c < lines; c++){
      if(mark[c] >= 80 || mark[c] < 50){
	count++;
      }
    }
    double tbp = (double)count / (double)lines; 
    if(tbp > 0.3){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
    
  }
}

quit(){
  printf("Thanks\n");
}
