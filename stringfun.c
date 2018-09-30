#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Returns the length of a string
int strlent( char *s){
  // Counts length
  int len = 0;
  // Update character, stops when you reach the end (terminating 0)
  while(*s++){
    // Update counter
    len ++;
  }
  // Returns length
  return len;
}


// Copies src into the destination, returns destination
char * strcpy0(char *dest, char *src){
  *dest = *src;
  while(*src){
    *dest = *src;
    dest += 1;
    src += 1;
  }
  return dest;
}

// Concatenate destination and n characters of source, returns destination
char * strncat0( char *dest, char *source, int n){
  // Indicates position to start at
  int pos = strlen(dest);
  // Runs n times 
  while (n){
    // Attaches source to dest 
    dest[pos]= *source;
    source++;
    pos++;
    n--;
  }
  return dest;
}

// Compares two strings: returns a -# if s1 < s2, +# if s1 > s2, 0 is equal
int strcmp0( char *s1, char *s2 ) {
  // Will run when s1 AND s2 is not 0 OR s1 xor s2 is at the end (diff in length)  
	while ((*s1 && *s2) || ((*s1 == 0) && !(*s2 == 0))){
    // Compares the char
		if (!(*s1 == *s2)){
			return *s1-*s2;
		}
    // Moves on to next char of string if previous were equal
		s1+=1;
		s2+=1;
	}
  // Will only return when both strings are at the end & equivalent
	return 0;
}

char * strchar(char *s, char c){
  while(*s){
    if(*s == c){
      return s;
    }
    s += 1;
  }
  return NULL;
}

int main(){
  char s1[20] = "hello";
  char s2[20] = "chair";

  printf("---Testing strlen---\n"); 
  printf("[s1]:%s\n", s1); 
  printf("[standard]: strlen(s1) is %lu\n",strlen(s1)); 
  printf("[our result]: strlen0(s1) is %d\n",strlent(s1)); 

  printf("---Testing strcpy---\n"); 
  printf("[s1 (dest)]: %s, [s2 (src)]: %s\n", s1 ,s2); 
  strcpy(s1,s2); 
  printf("[standard]: s1: %s s2: %s\n", s1, s2); 
  // Reset s1 
  strcpy(s1,"hello"); 
  strcpy0(s1,s2); 
  printf("[our result]: s1: %s s2: %s\n", s1, s2); 
  // Reset s1
  strcpy0(s1,"hello");

  printf("---Testing strncat---\n");
  printf("[s1 (dest)]: %s, [s2 (src)]: %s\n", s1 ,s2); 
  printf("[standard]: %s \n", strncat(s1, s2, 10));
  printf("[standard]: s1: %s s2: %s\n", s1, s2); 
  // Reset s1
  strcpy(s1, "hello");
  printf("[our result]: %s\n", strncat0(s1, s2, 10));
  printf("[our result]: s1: %s s2: %s\n", s1, s2); 

  printf("---Testing strcmp---\n");
  printf("Comparing \"a\" and \"b\", expecting negative \n");
  printf("[standard]: %d\n", strcmp("a","b"));
  printf("[our result]: %d\n", strcmp0("a","b"));

  printf("Comparing \"b\" and \"a\", expecting positive \n");
  printf("[standard]: %d\n", strcmp("b","a"));
  printf("[our result]: %d\n", strcmp0("b","a"));

  printf("Comparing \"a\" and \"a\", expecting zero \n");
  printf("[standard]: %d\n", strcmp("a","a"));
  printf("[our result]: %d\n", strcmp0("a","a"));

  printf("Comparing \"A\" and \"a\", expecting negative \n");
  printf("[standard]: %d\n", strcmp("A","a"));
  printf("[our result]: %d\n", strcmp0("A","a"));

  printf("Comparing \"\" and \"ab\", expecting negative \n");
  printf("[standard]: %d\n", strcmp("","a"));
  printf("[our result]: %d\n", strcmp0("","a"));

  char s3[20] = "hell";
  char s4[20] = "chair and Tables";
  char s5[20] = "HEHEXDDDD";
  char s6[20] = "dAnKmEmEs";
  printf("---Testing strchr---\n"); 
  printf("[s3]:%s\n", s3);
  printf("[standard]: strchr(s3) is %lu\n",strchr(s3,'e')); 
  printf("[our result]: strchr(s3) is %d\n",strchar(s3,'e'));

  printf("[s4]:%s\n", s4);
  printf("[standard]: strchr(s4) is %lu\n",strchr(s4,'T')); 
  printf("[our result]: strchr(s4) is %d\n",strchar(s4,'T'));

  printf("[s5]:%s\n", s5);
  printf("[standard]: strchr(s5) is %lu\n",strchr(s5,'H')); 
  printf("[our result]: strchr(s5) is %d\n",strchar(s5,'H'));

  printf("[s6]:%s\n", s6);
  printf("[standard]: strchr(s6) is %lu\n",strchr(s6,'e')); 
  printf("[our result]: strchr(s6) is %d\n",strchar(s6,'e')); 

  return 0;
}
