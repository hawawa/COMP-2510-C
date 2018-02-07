#include <stdio.h>
#include <ctype.h>

void squeeze_spaces(void){
	int c;
	int old = 'A';
	while((c = getchar())!= EOF){	
		if(old != ' ' || (c != '\t' && c != ' ')){
			if(c=='\t'){
				putchar(' ');
				old = ' ';
			} else {
				putchar(c);
				old = c;
			}
		}		
	}
}

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
	printf("%s\n","squeeze_spaces function:");
	squeeze_spaces();
	
	printf("%s\n","format_words function:");
	format_words();
	
	return 0;
}