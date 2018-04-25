/*gcc -o my_app *.c*/

#include <stdio.h>
#include "record.h"
#include "io.h"
#include "list.h"
#include "sort.h"

int main(int argc, char*argv[]){
	record_list list;

	FILE *ifp, *ofp;
	
	int m;
	record r;
	
	size_t i;

	int sort_require;

	
	
	list_init(&list);

	/*check file names*/
	if(argc != 3){
		fprintf(stderr, "usage: %s {source file} {{destination  file}\n", argv[0]);
		return 1;
	}
	
	
	/*open files*/
	if((ifp = fopen(argv[1], "rb")) ==0 ) {
		perror("fopen");
		return 2;
	}
	
	if((ofp = fopen(argv[2], "wb")) ==0 ) {
		perror("fopen");
		return 3;
	}
	
	
	/*reading file*/
	while((m = read_record(ifp, &r)) != 0) {
		if (m == 1) {
			if (!list_insert(&list, &r)) {
				break;
			}
		}
	}


	/*sorting*/
	if( list.nused !=0){
		while(1){
			char line[LINESIZE];
			
			printf("Please enter an integer for sorting.(1, 2, 3)\n");

			if(!fgets(line, LINESIZE, stdin)){
				clearerr(stdin);
			}

			if(sscanf(line, "%d", &sort_require) != EOF){
				if(sort_require >= 1 || sort_require <= 3){
					break;
				}	
			}
		
		}
	}

	if(sort_require == 1){
		sort_score_desc_id_asc(list.data, list.nused);
	} else if(sort_require == 2){
		sort_name_asc_id_desc(list.data, list.nused);
	} else if(sort_require == 3){
		sort_score_desc_name_asc_id_asc(list.data, list.nused);
	}
	
		
		
	/*printing*/
	
	for(i=0;i<list.nused;i++){
		r = *(list.data + i);
		print_record(ofp, &r);
	}
	

	/*close files*/
	if( fclose(ifp)!=0) {
		perror("fclose");
		return 4;
	}
	
	if( fclose(ofp)!=0) {
		perror("fclose");
		return 5;
	}
	

	
	return 0;
}