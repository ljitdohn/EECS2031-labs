#include <stdio.h>
#include <stdlib.h>

// incomplete c file

int main();

int main(){
  
  struct data{
    char title[60];
    char author[50];
    char publisher[50];
    float price;
    
  };
  FILE *fp;
  
  fp = fopen("book_dat.txt", "a+");
  if(fp == NULL){
      perror("Error opening file");
      return(-1);
    }
  
  struct data rec[40];
  
  
  
  
  
  
  
  return 0;
}
