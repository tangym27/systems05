
#include <string.h>

// Returns the length of a string
int strlen0( char *s){
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

// Compares two strings: returns a -# if s1 < s2, +# if s1 > s2, 0 is equali
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

// Locates char in a string, returns null if it's not there
char * strchr0(char *s, char c){
  // Continues until string is at terminating null
  while(*s){
    //  Compares the char from s with c
    if(*s == c){
      return s;
    }
    s += 1;
  }
  // If c is not in s 
  return NULL;
}
