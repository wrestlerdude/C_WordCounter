/*
*	Author: Raish Allan, 40316824
*	Last Modified: 26/02/2018
*	
*	Built for Windows x86, x64 (XP and later) programmed on Windows 10 64bit.
*	This is the main codefile for a program that counts the occurrence of words and displays 
*	their count to the screen. It is a console based application. This is the main that calls functions
*	and also reads in the arguments and the flags.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordfuncs.h"

//args_reader: Reads in arguments and sets the appropiate flags depending on the user input, also sets input and output file.
void args_reader(int argc, char *argv[], char **input, char **output, int *ignore_case)
{
	char check[5] = ".txt\0";
	//Max filename size in windows
	char substr[255];

	//Go through all arguments
	for (int i = 1; i < argc; ++i)
	{
		if (strcmp("-c", argv[i]) == 0)
			*ignore_case = 1;
		
		if (i != argc-1)
		{
			//These two lines gets the last 4 characters of an argument ahead of the current iteration and copies it into substr 
			int len = strlen(argv[i+1]);
			strncpy(substr, argv[i+1]+(len-4), len);
			//This compares the last 4 characters with ".txt" to check if the input was a textfile
			if (strcmp(substr, check) == 0)
			{
				if (strcmp("-o", argv[i]) == 0)
					*output = argv[i+1];
				else if (strcmp("-i", argv[i]) == 0)
					*input = argv[i+1];
			}

		}
	}
}

int main(int argc, char *argv[])
{
	//Initialise argument identifiers
	char *input = "";
	char *output = "";
	int ignore_case = 0;

	//Argument identifiers set by function
	args_reader(argc, argv, &input, &output, &ignore_case);

	char *word_data;
	//Readfile function returns size of file or input to bytes
	int bytes = readfile(&word_data, input);
	char **tokens = (char**)malloc(bytes*sizeof(char*));
	if(tokens == NULL)
	{
        fprintf(stderr, "Not enough memory\n");
        return 0;
	}

	//Tokenize function returns the size of the array of string
	int size = tokenize(&word_data, tokens);
	int total = size;
	sort_ascii(tokens, size, ignore_case);
	struct Word *w;
	//Structure the tokens function returns the size of the array of struct
	size = struct_tokens(&w, tokens, size, ignore_case);
	
	for (int i = 0; i < total; ++i)
		free(tokens[i]);
	free(tokens);

	sort_count(w, size);

	writefile(output, w, size, total, ignore_case);
	return 0;
}