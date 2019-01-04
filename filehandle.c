/*
*	Author: Raish Allan, 40316824
*	Last Modified: 26/02/2018
*	
*	This is the codefile for filehandling, read and writing for the main application.
*/
#pragma once
#include "wordfuncs.h"
#include <stdio.h>
#include <string.h>

//readfile: Determines to use a textfile or stdin for reading into buffer char arrray
int readfile(char **buffer, char *input)
{
	int bytes = 0;
	//Checks if there was a filename given
	if (strlen(input) != 0)
	{
		//Open file for read
		FILE *file = fopen(input, "r");
		if (file == NULL)
		{
			fprintf(stderr, "could not open %s for reading: %s\n", input,
				strerror(errno));
			exit(0);
		}
		//Counts the number of bytes in a file and rewinds to the start.
		for(bytes; getc(file) != EOF; ++bytes);
		rewind(file);

		*buffer = (char*)malloc(bytes+1);
		if(*buffer == NULL)
		{
			fprintf(stderr, "Not enough memory\n");
			exit(0);
		}
		//Reads in entire textfile into buffer
		if(fread(*buffer, bytes, 1, file) != 1)
		{
			fprintf(stderr, "could not read\n");
			free(*buffer);
			*buffer = NULL;
			exit(0);
		}
		//Sets the null byte at the end of the buffer to make it a null terminated string
		(*buffer)[bytes] = 0;
		fclose(file);
		printf("\nSuccessful read from %s\n-----------------------------------\n", input);
	//If no file name then read from stdin
	}else{
		printf("Enter your text: \n");
		//Max commandline input length on Windows XP and later.
		char str[8191];
		fgets(str, 8191, stdin);
		fflush(stdin);
		//Allocates size of buffer, used instead of directly reading into buffer from fgets so that it uses less memory if possible
		int size = strlen(str);
		//Checks if any input, 1 compensates for the newline character
		
		if(size <= 1)
		{
			fprintf(stderr, "No input detected!\n");
			exit(0);
		}

		*buffer = (char*)malloc(size);
		strcpy(*buffer, str);
		
		printf("\n");
		bytes = size+1;
	}

	return bytes;
}

//writefile: Writes to stdin or a specified file by the user
void writefile(char *output, struct Word *w, int size, int total, int ignore_case)
{	
	//Checks if there was a filename given
	if(strlen(output) != 0)
	{
		//Open file for rewrite
		FILE *file = fopen(output, "w");
		
		if (ignore_case)
			fprintf(file, "Ignore case: On\n");
		else
			fprintf(file, "Ignore case: Off\n");
		
		fprintf(file, "Total word count: %d\n\n", total);
		for (int i = 0; i < size; ++i)
			fprintf(file, "%s: %d\n", w[i].word, w[i].count);
		fclose(file);
		printf("Successful write to %s\n", output);
	//If no file name then write to stdout
	}else
	{
		if (ignore_case)
			printf("Ignore case: On\n");
		else
			printf("Ignore case: Off\n");

		printf("Total word count: %d\n\n", total);	
		for (int i = 0; i < size; ++i)
			printf("%s, count = %d\n", w[i].word, w[i].count);
	} 

	free(w);
}