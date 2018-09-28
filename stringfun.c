#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int strlent( char *s){
  int len = 0;
  while(*s++){
    len ++;
  }
  return len;
}

char * strcopy(char *dest, char *sour){
  *dest = *sour;
  while(*sour){
    *dest = *sour;
    dest += 1;
    sour++;
  }
  return *sour;
}
int main(){
  char s1[10] = "byee";
  char s2[10] = "hello";
  printf("Testing strlen(s1)\n");
  printf("[standard]%d\n",strlen(s1));
  printf("[not standard]%d\n",strlent(s1));

  printf("Testing strcopy(s1)\n");
  printf("[s1]%s\n",s1);
  printf("[s2]%s\n",s2);
  strcopy(s1,s2);
  printf("[s1]%s\n",s1);
  printf("[s2]%s\n",s2);
  return 0;
}
