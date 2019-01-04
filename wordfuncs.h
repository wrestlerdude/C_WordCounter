/*
*	Author: Raish Allan, 40316824
*	Last Modified: 21/02/2018
*
*	Declarations for program.
*/
struct Word
{
	char word[20];
	unsigned int count;
};

void sort_ascii(char **strarr, int size, int ignore_case);
void sort_count(struct Word *w, int size);
int readfile(char **buffer, char *input);
void writefile(char *output, struct Word *w, int size, int total, int ignore_case);
int tokenize(char **word_data, char **tokens);
int struct_tokens(struct Word **w, char **tokens, int size, int ignore_case);