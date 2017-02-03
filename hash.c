#include <stdio.h>
#include <stdlib.h>

/*problem unsolved: fgetc(fp) keep getting the first char of the file.*/

int main(){
  FILE *fp;
  int c;
  int k = 0;
  int sum = 0;
  int re;
  
   /*get hashtable size*/
  scanf("%d", &k);
  int colli = 0;
  int unused = 0;
  
  /*initialize hashtable*/
  int hashtable[k];
  int i;
  for(i = 0; i < k; ++i){
    hashtable[i] = 0;
  }
  
  /*open file*/
  fp = fopen("input.txt", "r");
  if(fp == NULL) {
      perror("Error in opening file");
      return(-1);
   }
  
  /*read stream*/
  for(c = fgetc(fp); c != EOF;){
    printf("%c", c);
    if(c != '\n'){
      /*add up to sum*/
      sum = sum + c;
    }else{
      /*store in hashtable and go to next line*/
      re = (sum % k);
      ++hashtable[re];
      sum = 0;
    }
  }
  
  fclose(fp);
  
  /*EOF; calculate collisions and unused*/
    for(i = 0; i < k; ++i){
      
      if(hashtable[i] == 0){
	++unused;
      }else if(hashtable[i] > 1){
	++colli;
      }
      
    }
  
  /*display*/
  printf("The number of entries with collision is %5d\n", colli);
  printf("The number of unused entries is %5d\n", unused);
  return 0;
}
