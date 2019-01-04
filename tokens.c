/*
*	Author: Raish Allan, 40316824
*	Last Modified: 26/02/2018
*
*	This is the codefile for tokenising and structuring the tokens.
*/
#pragma once
#include "wordfuncs.h"
#include <stdio.h>
#include <string.h>

//tokenize: Tokenizes a char array to an array of string with a delimiter.
int tokenize(char **word_data, char **tokens)
{
	int i = 0;
	//Sets all characters to delimit by
	char *delim = " ,.-?!/0123456789\n\t";
	char *p = strtok(*word_data, delim);
	//Destrutive tokenization until no tokens are left
	while (p != NULL)
	{
		tokens[i] = (char*)malloc(strlen(p));
		tokens[i++] = p;
		p = strtok(NULL, delim);
	}
	//Free of word_data not needed as strtok has already cleared it
	return i;
}

//struct_tokens: Puts unique tokens into an array of struct with their occurrence.
int struct_tokens(struct Word **w, char **tokens, int size, int ignore_case)
{
	//Calloc required otherwise junk data left in array of struct
	*w = (struct Word*)calloc(size, sizeof(struct Word));

	if(*w == NULL)
	{
        fprintf(stderr, "Not enough memory\n");
        exit(0);
	}

	int n = 0;
	//Algorithm for counting unique tokens into struct
	for (int i = 0; i < size; ++i)
	{
		int check1 = strlen((*w)[n].word);
		int check2;
		
		//Changes check based on case flag
		if(ignore_case)
			check2 = stricmp((*w)[n].word, tokens[i]);
		else
			check2 = strcmp((*w)[n].word, tokens[i]);
		//First condition checks if the first struct is empty (not a new occurring word)
		//Second condition checks if the token and the word are not the same
		if (check1 == 0 || check2 != 0)
		{
			//If the struct is not empty
			if (check1 != 0 && check2 != 0)
				n++;
			//New word found
			strcpy((*w)[n].word, tokens[i]);
			(*w)[n].count += 1;

		}else if (ignore_case == 0 && strcmp(tokens[i-1], tokens[i]) == 0)
			(*w)[n].count += 1;
		else if (ignore_case && stricmp(tokens[i-1], tokens[i]) == 0)
			(*w)[n].count += 1;
		else
			n++;
	}
	//Offset of 2 needs to be compensated for
	n++;
	return n++;
}

