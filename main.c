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

	String lo = string_substring(hello, 3, 5);
	String l = string_substring(hello, 10, 11);
	string_append(&lo, l.content);
	printf("==> %s\n", lo.content);

	char* cstr = string_to_cstr(lo);
	printf("String to cstr: %s\n", cstr);

	String list = string_new("apple, banana, butter");
	StringList sl = string_split(list, ',');
	for (int i = 0; i < sl.size; ++i) {
		printf("item[%d]: %s\n", i, sl.items[i].content);
	}

	// TODO: implement arena to free everything at once
	stringlist_free(&sl);
	string_free(&list);
	string_free(&hello);
	string_free(&lo);
	string_free(&l);
	return 0;
}