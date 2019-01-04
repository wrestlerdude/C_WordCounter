/*
* Author: Raish Allan, 40316824
* Last Modified: 21/02/2018
* 
* This is the codefile for two bubble sorts done in the program.
*/
#pragma once
#include "wordfuncs.h"
#include <string.h>

//sort_ascii: Sorts an array of string, bubble sort
void sort_ascii(char **strarr, int size, int ignore_case)
{
  char *temp;   
  for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
          if(ignore_case == 0 && strcmp(strarr[i], strarr[j]) < 0) {
              temp = strarr[i];
              strarr[i] = strarr[j];
              strarr[j] = temp;
          //Ignores case if flag set
          }else if(ignore_case == 1 && stricmp(strarr[i], strarr[j]) < 0) {
              temp = strarr[i];
              strarr[i] = strarr[j];
              strarr[j] = temp;
          }
      }
  }
}

//sort_count: Sorts an array of struct by its count, bubble sort
void sort_count(struct Word *w, int size)
{
  char temp2[25];
  for(int i = size-2; i>=0 ; i--)
  {
    for(int j = 0; j<=i; j++)
    {
        if(w[j].count<w[j+1].count)
        {
          int temp = w[j].count;
          //Makes sure that word and count stay together in struct
          strcpy(temp2, w[j].word); 
          w[j].count = w[j+1].count;
          strcpy(w[j].word, w[j+1].word);
          w[j+1].count = temp;
          strcpy(w[j+1].word, temp2);
        }
    }
  }
}
