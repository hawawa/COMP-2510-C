#include <stdio.h>
#include <string.h>
#define LINESIZE 512
 
int get_word(const char prompt[], char word[], size_t n){
	
	while(1){
		char line[LINESIZE];
		char w[LINESIZE];
		
		printf("%s\n",prompt);

		if(!fgets(line, LINESIZE, stdin)){
			clearerr(stdin);
			return 0;
		}
		
		if(sscanf(line, "%s", w) ==1){
			if(strlen(w) < n){
				strcpy(word,w);
				return 1;
			}	
			
			
		}
		
	}
	
	
	
}



int main(void){
	size_t n = 10;
	char word[10]="\n";
	char prompt[] = "Please enter a word";

	if(get_word(prompt, word ,n)){
		printf("%s\n", word);
	}

	
	
	return 0;	
}