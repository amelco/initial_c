#include <stdio.h>

#define AHB_SB_IMPLEMENTATION
#include "ahb_sb.h"

int main() {
	String hello = string_new("Hello");
	string_append(&hello, ", World!\n");
	printf("%s\n", hello.content);
	
	size_t index = string_index_of(&hello, 'W');
	if (index == IDX_NO_MORE_ENTRIES) 
		printf("There is no 'W' in the string: %s.\n", hello.content);
	else 
		printf("Index of 'W' is %zu\n", index);
	
	size_t next_index = string_next_index(&hello);
	if (next_index == IDX_NO_MORE_ENTRIES)
		printf("There is no more 'W' in the string: %s.\n", hello.content);
	else
		printf("Next index: %zu\n", next_index);

	String sub = string_substring(hello, 2, 7);
	printf("Substring 2 - 7: %s\n", sub.content);

	// TODO: implement arena to free everything at once
	string_free(&hello);
	string_free(&sub);
	return 0;
}