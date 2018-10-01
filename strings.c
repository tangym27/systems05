#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stringfun.h"

int main(){
  char s1[20] = "hello";
  char s2[20] = "chair";
  char s3[30] = "HEHE XDDDD";

  printf("---Testing strlen---\n"); 
  printf("[s1]:%s\n", s1); 
  printf("[standard]:   strlen(s1) is %lu\n",strlen(s1)); 
  printf("[our result]: strlen0(s1) is %d\n",strlen0(s1)); 

  printf("---Testing strcpy---\n"); 
  printf("[s1 (dest)]: %s, [s2 (src)]: %s\n", s1 ,s2); 
  strcpy(s1,s2); 
  printf("[standard]:   s1: %s s2: %s\n", s1, s2); 
  strcpy(s1,"hello");   
  strcpy0(s1,s2);       // Reset s1 
  printf("[our result]: s1: %s s2: %s\n", s1, s2); 
  strcpy0(s1,"hello");  // Reset s1

  printf("---Testing strncat---\n");
  printf("[s1 (dest)]: %s, [s2 (src)]: %s, n=3 \n", s1 ,s2); 
  printf("[standard]:   %s \n", strncat(s1, s2, 3));
  strcpy(s1, "hello");  // Reset s1
  printf("[our result]: %s\n", strncat0(s1, s2, 3));

  printf("---Testing strcmp---\n");
  printf("Comparing \"a\" and \"b\", expecting negative \n");
  printf("[standard]:   %d\n", strcmp("a","b"));
  printf("[our result]: %d\n", strcmp0("a","b"));

  printf("Comparing \"b\" and \"a\", expecting positive \n");
  printf("[standard]:   %d\n", strcmp("b","a"));
  printf("[our result]: %d\n", strcmp0("b","a"));

  printf("Comparing \"a\" and \"a\", expecting zero \n");
  printf("[standard]:   %d\n", strcmp("a","a"));
  printf("[our result]: %d\n", strcmp0("a","a"));

  printf("Comparing \"A\" and \"a\", expecting negative \n");
  printf("[standard]:   %d\n", strcmp("A","a"));
  printf("[our result]: %d\n", strcmp0("A","a"));

  printf("Comparing \"\" and \"ab\", expecting negative \n");
  printf("[standard]:   %d\n", strcmp("","a"));
  printf("[our result]: %d\n", strcmp0("","a"));

  printf("---Testing strchr---\n"); 
  printf("s1: %s, s2: %s, s3: %s \n", s1 ,s2, s3); 

  printf("[standard]:   strchr(s1, 'e') is %p\n",strchr(s1,'e')); 
  printf("[our result]: strchr(s1, 'e') is %p\n",strchr0(s1,'e'));

  printf("[standard]:   strchr(s2, 'r') is %p\n",strchr(s2,'r')); 
  printf("[our result]: strchr(s2, 'r') is %p\n",strchr0(s2,'r'));

  printf("[standard]:   strchr(s3, 'e') is %p\n",strchr(s3,'e')); 
  printf("[our result]: strchr(s3, 'e') is %p\n",strchr0(s3,'e'));
  return 0;
}