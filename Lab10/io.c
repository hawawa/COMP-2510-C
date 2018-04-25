#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "io.h"

int read_record(FILE *fp, record *prec){
	char line[LINESIZE];
	size_t i;
	char id[LINESIZE];
	char last[LINESIZE];
	char first[LINESIZE]; 
	int score;
	int id_counter = 0;

	
	if( !fgets(line, LINESIZE, fp) ){
		clearerr(stdin);
		return 0;
	}
	
	if(sscanf(line, "%s %s %s %d", id, first, last, &score) < 4){
		return -1;
	}
	
	/*id check*/
	if(id[0] != 'a'){
		return -1;
	}
	
	for(i = 0; id[i] != '\0'; i++){
		id_counter++;
	}
	if(id_counter != IDSIZE - 1){
		return -1;
	}
	
	/*save to prec*/
	strcpy((*prec).id, id);
		
	if(strlen(first) >= NAMESIZE){
		return -1;
	}
	
	if(strlen(last) >= NAMESIZE){
		return -1;
	}
		
	for(i = 0; first[i] != '\0'; i++){
		(*prec).name.first[i] = tolower(first[i]);
	}
	(*prec).name.first[i] = '\0';
	

	for(i = 0; last[i] != '\0'; i++){
		(*prec).name.last[i] = tolower(last[i]);
	}
	(*prec).name.last[i] = '\0';

	
	(*prec).score = score;

	return 1;
	
}


void print_record(FILE *fp, const record *prec){
	fprintf(fp,"%s : %s, %s : %d\n",(*prec).id,(*prec).name.last,(*prec).name.first,(*prec).score);
}


	