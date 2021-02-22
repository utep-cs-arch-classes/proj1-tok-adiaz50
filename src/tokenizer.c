#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  if( c == ' ' || c == '\t'){
    return 1;
  }else return 0;
}

int non_space_char(char  c){
  if( c != ' ' || c == '\t'){
    return 1;
  }else return 0;
}

char *word_start (char *str){
  int i = 0;
  while(str[i] != '\0' && i <= 100){
    if(non_space_char(str[i])){
      return str;
    }
    i++;
  }
  return 0;
}

char *word_end(char *word){
  int i = 1;
  char *wordEnd;

  while( word[i] != '\0' && i <= 100){
    if( space_char(word[i]) && non_space_char(word[i-1])){
      wordEnd = &word[i];

      return wordEnd;
    }
    i++;
  }
  return 0;
}

int count_words(char *str){
  int i = 1;
  int wordCount = 0;

  while(str[i] != '\0' && i <= 100){
    if(non_space_char(str[i]) && space_char(str[i - 1]) ){
      wordCount++;
    }
    i++;
  }
  if(wordCount == 1){
    return wordCount;
  }else
    return wordCount + 1;
}
