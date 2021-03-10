#include <stdio.h>
#include <stdlib.h>
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

// use this to copy the words between start and end!!!
char *copy_str(char *inStr, short len){
  char *Cstr;
  int i;
  Cstr = (char*)malloc(sizeof(char) * (len+1));

  for(i = 0; i <= len; i++){
    *(Cstr+i) = *(inStr+i);
  }
  return Cstr;
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

char **tokenize(char* str){
  char wordCount = count_words(str);
  char **tokens;
  char *pStart;// = word_start(str);
  char *pEnd = word_end(str);
  int wordLength, i = 0, w = 0;

  tokens = (char**)malloc(sizeof(char*) * (wordCount + 1));

  while( w < wordCount ){
    pStart = word_start(str);
    
    wordLength =(int)(pEnd - pStart);
    
    *(tokens+i) = copy_str(pStart, wordLength);
    pEnd = word_end(str);
    i++;
    w++;
  }

  return tokens;
}

void print_tokens(char **tokens){
  int i;
  for(i = 0; *(tokens+i) != NULL; i++){
    printf("HERE: %c", tokens[i]);
  }
  printf("\n");
}

void free_tokens(char **tokens){
  free(tokens);
}
