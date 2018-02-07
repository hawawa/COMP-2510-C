#include <stdio.h>
#include <ctype.h>

void format_words(void){
	int c;
	int old = ' ';
	while((c = getchar())!= EOF){
		if(isspace(old) || old == '"'){
			putchar(toupper(c));
		} else {
			putchar(tolower(c));
		}
		old = c;
	}
	
}


int main(void){
	format_words();
	
	return 0;
}