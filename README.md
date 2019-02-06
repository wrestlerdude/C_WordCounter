# About wordcount:
This program counts the number of words from a textfile
or commandline input and outputs every word with 
its occurrence and the total number of words. This output
 can be on the commandline or in a custom textfile.

# How-to of wordcount:
Usage: wordcount (followed by flags)

# Flags:
-i : reads in a textfile for input, omit for commandline
-o : reads in a textfile for output, omit for commandline
-c : ignores the case of every word in the file.

## Example:
wordcount -i helloworld.txt -o output.txt -c

## TOOLCHAIN COMPILED WITH:
Visual Studio 2017 Microsoft C Compiler x86

# How to build:
Using the makefile type "nmake build" in the program's
source through the commandline.

# To use tests:
Using "nmake test" if the program has been built will
output the results of single_words_test and sentences_test
to two textfiles named "sentences_output" and "single_words_output".

For the ignore case tests use "nmake testcase". This will
output the results to two textfiles named "sentences_case" and
"single_words_case".
