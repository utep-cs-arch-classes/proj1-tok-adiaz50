#include <stdio.h>

int main(){
  char string[100];
  char input;
  short i = 0;
  printf("Please enter a string:\n");

  //scanf("%[^\n]", input);

  putchar('>');
  for(input; (input = getchar()) != '\n'; i++){
    string[i] = input;
    putchar(input);
  }
  putchar('\n');
  
  return 0;
}
