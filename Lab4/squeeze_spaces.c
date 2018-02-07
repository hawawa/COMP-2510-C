#include <stdio.h>

void squeeze_spaces(void){
	int c;
	int old = 'A';
	while((c = getchar())!= EOF){	
		if(old != ' ' || (c != '\t' && c != ' ')){
			if(c == '\t'){
				putchar(' ');
				old = ' ';
			} else {
				putchar(c);
				old = c;
			}
		}		
	}
}

int main(void){
	squeeze_spaces();
	
	return 0;
}