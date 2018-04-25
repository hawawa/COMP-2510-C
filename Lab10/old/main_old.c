#include <stdio.h>
#include "io.h"
#include "list.h"
#include "sort.h"

int main(int argc, char*argv[]){
	record a[100];
	record x;
	record *p = a;
	
	size_t counter = 0;
	size_t i;
	
	FILE *fp;
	
	if(argc != 2){
		fprintf(stderr, "usage: %s {source file}\n", argv[0]);
		return 1;
	}
	
	if((fp = fopen(argv[1], "rb")) ==0 ) {
		perror("fopen");
		return 2;
	}
	
	
	while(read_record(fp, &x)==1 && counter < 100){
		a[counter]=x;
		counter++;
	}
	
	
	if(counter!=0){
		
		printf("Please enter an integer for sorting.\n");
		sort_score_desc_id_asc(a, counter);
		sort_name_asc_id_desc(a, counter);
		sort_score_desc_name_asc_id_asc(a, counter);
		/*
		if(strcmp(argv[1],"s-i+")==0){
			sort_score_desc_id_asc(a, counter);
		}else if(strcmp(argv[1],"n+i-")==0){
			sort_name_asc_id_desc(a, counter);
		} else if(strcmp(argv[1],"s-n+i+")==0){
			sort_score_desc_name_asc_id_asc(a, counter);
		} else {
			return 0;
		}
		*/
		
		
		for(i = 0; i<counter; i++){
			print_record(fp,p+i);
		}
		

	}
	
	
	
	
	if( fclose(fp)!=0) {
		perror("fclose");
		return 4;
	}
	
	
	
	
	

	
	
	return 0;
}