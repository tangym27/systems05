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

char * strcpy0(char *dest, char *src){
  *dest = *src;
  while(*src){
    *dest = *src;
    dest += 1;
    src += 1;
  }
  return dest;
}

char * strncat0( char *dest, char *source, int n){
  /* printf("%s\n", dest); */
  /* printf("%c\n", dest[5]); //dest is a string * is numb */
  /* printf("%s\n", dest); */
  /* printf("%d\n", *dest); //gives me a number */
  int pos = strlen(dest);
  while (n){
    dest[pos]= *source;
    source++;
    pos++;
    n--;
  }
  return dest;
}

int strcmp0( char *s1, char *s2 ) {
	while ((*s1 && *s2) || ((*s1 == 0) && !(*s2 == 0))){
		//printf("?\n");
		if (!(*s1 == *s2)){
			return *s1-*s2;
		}
		s1+=1;
		s2+=1;
	}
	return 0;
}

int main(){
  char s1[20] = "hello";
  char s2[20] = "chair";

   printf("---Testing strlen---\n"); 
   printf("[s1]:%s\n", s1); 
   printf("[standard]: strlen(s1) is %lu\n",strlen(s1)); 
   printf("[our result]: strlen0(s1) is %d\n",strlent(s1)); 

   printf("---Testing strcpy---\n"); 
   printf("[s1 (dest)]:%s\n",s1); 
   printf("[s2 (src)]:%s\n",s2); 
   strcpy(s1,s2); 
   printf("[standard]: s1: %s s2: %s\n", s1, s2); 
   strcpy(s1,"hello"); 
   strcpy0(s1,s2); 
   printf("[our result]: s1: %s s2: %s\n", s1, s2); 
   strcpy0(s1,"hello");

  printf("---Testing strncat---\n");
  printf("[standard]: %s \n", strncat(s1, s2, 10));
  printf("[standard]: s1: %s s2: %s\n", s1, s2); 
  strcpy(s1, "hello");
  printf("[our result]: %s\n", strncat0(s1, s2, 10));
  printf("[our result]: s1: %s s2: %s\n", s1, s2); 

  printf("---Testing strcmp---\n");
  printf("Comparing \"a\" and \"b\"\n");
  printf("[standard]: %d\n", strcmp("a","b"));
  printf("[our result]: %d\n", strcmp0("a","b"));

  printf("Comparing \"b\" and \"a\"\n");
  printf("[standard]: %d\n", strcmp("b","a"));
  printf("[our result]: %d\n", strcmp0("b","a"));

  printf("Comparing \"a\" and \"a\"\n");
  printf("[standard]: %d\n", strcmp("a","a"));
  printf("[our result]: %d\n", strcmp0("a","a"));

  printf("Comparing \"A\" and \"a\"\n");
  printf("[standard]: %d\n", strcmp("A","a"));
  printf("[our result]: %d\n", strcmp0("A","a"));

  printf("Comparing \"\" and \"ab\"\n");
  printf("[standard]: %d\n", strcmp("","a"));
  printf("[our result]: %d\n", strcmp0("","a"));

  return 0;
}
