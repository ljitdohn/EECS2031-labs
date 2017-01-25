#include <stdio.h>
#include <stdlib.h>

/*Lab 3*/
/*This code is not completed*/

int lines;
long stdnum[lines];
char stdfn[lines][8];
char stdln[lines][8];
char cmd[8]; 
int fin[lines];
int midt[lines];
float q1[lines];
float q2[lines];
float q3[lines];
float mark[lines];


int main(){
  onInit();
  return 0;
}

onInit(){
  
  scanf("%d", &lines);	/*get number of lines*/
  
  for (int i = 0; i < lines; ++i){
    readLine(i);
  }
  
  /*get command*/
  int c;
  for(c = 0; scanf("%c", &cmd[c]) != EOF, ++c){
	  if (cmd[c] == '\n'){
		  executeCommand(cmd);
		  for (i = 0; i <= c; ++i){
			  cmd[c] = 0;
		  }
	  }
  }
  
}

readLine(int i){
  
  int c;
  
  scanf("%ld", stdnum[i]);/*scan std number*/
  
  for(c = 0; c < 8 && scanf("%c", stdfn[i][c]) != ' '; ++c);	/*scan student first name*/
  
  for(c = 0; c < 8 && scanf("%c", stdln[i][c]); ++c);	/*scan student last name*/
  
  scanf("%d", fin[i]); /*scan final grade*/
  
  scanf("%d", midt[i]); /*scan midterm grade*/
  
  scanf("%f", q1[i]); /*scan 3 quizzes*/
  
  scanf("%f", q2[i]);
  
  scanf("%f", q3[i]);
  
  mark[i] = 0.6*fin[i] + 0.25*midt[i] + 0.05*q1[i] + 0.05*q2[i] + 0.05*q3[i];
  
}

executeCommand(char command[]){
	if (strcmp(command, "F") = 0){
		fail();
	}else if(strcmp(command, "top")){
		top();
	}else if(strcmp(command, "A"){
		gradeA();
	}else if(strcmp(command, "perA"){
		perA();
	}else if(strcmp(command, "anomaly"){
		anomaly();
	}else if((strcmp(command, "q") == 0) or ((strcmp(command, "Q")) == 0){
		quit();
		/*do something to exit program.*/
	}else{
		printf("Not a valid command.\n")
	}
}

fail(){
  for(int c = 0; c < lines; c++){
    if(mark[c] < 50){
      printf("%ld\n", stdnum[c]);
    }
  }
}

top(){
  
}

gradeA(){
  for(int c = 0; c < lines; c++){
    if(mark[c] >= 80){
      printf("%ld  %s\n", stdnum[c], stdln[c]);
    }
}

perA(){
  int count = 0;
  for(int c = 0; c < lines; c++){
    if(mark[c] >= 80){
      count++;
    }
  double tbp = (double)count / (double)lines;  
  
  printf("Percentage of students with an average of A:%.2f%%\n", tbp);	
  
}

anomaly(){

  if(lines > 15){
    printf("NO");
  }else{
    int count = 0;
    for(int c = 0; c < lines; c++){
      if(mark[c] >= 80 or mark[c] < 50){
	count++;
      }
    double tbp = (double)count / (double)lines; 
    if(tbp > 0.3){
      printf("YES");
    }else{
      printf("NO");
    }
    
  }
}

quit(){
  printf("Thanks");
}
