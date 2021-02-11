#include <stdio.h>

int main(){
  char input[100];

  printf("Please enter a string:\n>");
  
  scanf("%[^\n]", input);
  
  printf("Your input: %s\n", input);
  
  return 0;
}
