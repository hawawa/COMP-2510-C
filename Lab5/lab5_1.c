#include <stdio.h>
#include <string.h>
#define LINESIZE 512
 
int get_int(const char prompt[], int min, int max){
	
	while(1){
		char line[LINESIZE];
		int n = 0;
		
		printf("%s\n",prompt);

		if(!fgets(line, LINESIZE, stdin)){
			clearerr(stdin);
			return -1;
		}
		
		if(sscanf(line, "%d", &n) != EOF){
			if(n >= min && n <= max){
				return n;
			}	
			
		}
		
	}
	
	
	
}



int main(void){
	char prompt[] = "Please enter a integer";
	int min = 1;
	int max = 10;

	
	printf("%d\n", get_int(prompt, min ,max));
	

	
	
	return 0;	
}