// Prof. Rigas, 
//
// I understand that this is completely overkill for this assignment, but
// as I am starting to consider more seriously the kernel from scratch project
// I am trying to push myself to write as secure of C code as possible. In my 
// work I spend a lot of time with C++ which handles a lot of what we have to
// do manually in C for me, and I am trying to develop good practices and to
// think about things that otherwise I would leave to the langauge itself. These
// little projects give me a good opportunity to practice these concepts even if
// it results in a bit of over engineering. I hope you don't mind. 
//
// In class, I am a slow coder as we are doing a lot of stuff that
// C++ handles for me (string manipulation etc), but with these exercises I can take
// the time to slow down and really consider all the options that the C language
// provides for us - so I appreciate you assigning then, taking the time to review our
// code, and sharing your thoughts/knowledge with us. 
//
// I've tried to ensure that I leave notes and comments throughout if I use something
// we have not yet learned in class so that you at least know my thought
// process - and that I am undersetanding what I am using/why and not merely copying
// random things from the internet. I've also tried to include some thoughts for
// later research etc so if you happen to have any thoughts on these I would
// absolutely love to hear them. Believe it or not, I revist these exercises 
// to refactor them and improve them haha. For example, I hope to no longer need
// the string.h library for this one once I rewrite a bzero, etc.
//
// Almost all of the funcationality that is not defined within the individual exercise
// files themselves are found in the lib/my-lib.c file. I have tried to comment them 
// extensively so if you want to delve into anything that is not obvious I hope you
// find that document helpful. I've also included run-<program_name> binaries for
// each of the exercises to make it easier to compile without having to remember to
// include lib/my-lib.c each time. Perhaps I could make a makefile but that seems
// excessive even for me with such small projects hahaha.
//
// I also apologise for not taking as much time with the Python exercises as I
// do with the C exercises. To be honest, I don't very much care for the language
// as it just feels messy to me, and I don't have a lot of use for it in my personal
// life...but hey...at least it's not Java! 
//
// Best wishes, 
//
// Sophia W. 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/my-lib.h"

int main()
{
	printf("Please enter your first name: ");
	char* first_name = safely_get_input();
	printf("Please enter your surname: ");
	char* surname = safely_get_input();
	printf("Please enter your title: ");
	char* title = safely_get_input();

	printf("Hello %s %s %s!\n", title, first_name, surname);

	bzero(first_name, str_len(first_name));
	free(first_name);
	first_name = NULL;

	bzero(surname, str_len(surname));
	free(surname);
	surname = NULL;
	
	bzero(title, str_len(title));
	free(title);
	title = NULL;

	return 0;
}
