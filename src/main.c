#include <stdio.h>
#include "tokenizer.h"

int main(){
  char string[100];
  char input;
  char counter = 0;
  short i = 0;
  int j = 0;
  printf("Please enter a string:\n");

  //scanf("%[^\n]", input);

  putchar('>');
  for(input; input != '\n'; i++){
    input = getchar();
    string[i] = input;
  }
  printf(string);
  putchar('\n');

  j = count_words(string);
  printf("Number of words: %d", j);
  
  return 0;
}
