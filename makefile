build: compile partialclean

test:
	wordcount -i sentences_test.txt -o sentences_output.txt
	wordcount -i single_words_test.txt -o single_words_output.txt
testcase:
	wordcount -i sentences_test.txt -o sentences_case.txt -c 
	wordcount -i single_words_test.txt -o single_words_case.txt -c
compile:
	cl wordcount.c sort.c filehandle.c tokens.c
clean:
	del *.exe
	del *.obj
partialclean:
	del *.obj