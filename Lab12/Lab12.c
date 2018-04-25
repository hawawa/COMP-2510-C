#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IDSIZE 10
#define NAMESIZE 20
#define LINESIZE 1024

typedef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typedef struct {
	char id[IDSIZE];
	name name;
	int score;
} record;

typedef struct node node;
struct node {
	record data;
	node *next;
};

typedef node *record_list;

void list_init(record_list *plist){
	*plist = 0;
}

void list_destroy(record_list *plist){
	node *p;
	node *q;
	for(p=*plist;p!=0;p=q){
		q=p->next;
		free(p);
	}
	*plist = 0;
}

int list_insert(record_list *plist, const record *prec){
	node *newnode = malloc(sizeof(node));
	if(newnode == 0){
		return 0;
	}
	newnode->data = *prec;
	newnode->next = *plist;
	*plist = newnode;
	return 1;
}




int read_record(FILE *fp, record *prec){
	char line[LINESIZE];
	size_t i;
	char id[LINESIZE];
	char last[LINESIZE];
	char first[LINESIZE]; 
	int score;
	int id_counter = 0;

	/*
	if(fscanf(fp, "%s %s %s %d", id, first, last, &score) < 4){
		return -1;
	}
	*/
	
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





int main(int argc, char*argv[]){
	FILE *fp;
	int m;
	record_list list;
	record r;
	list_init(&list);
	

	
	if(argc != 2){
		fprintf(stderr, "usage: %s {source file}\n", argv[0]);
		return 1;
	}
	

	
	if((fp = fopen(argv[1], "rb")) ==0 ) {
		perror("fopen");
		return 2;
	}
	
	
	while((m = read_record(fp, &r)) != 0) {
		if (m == 1) {
			if (!list_insert(&list, &r)) {
				break;
			}
		}
	}

	/*print*/

	if(list !=0){
		node *p = list;
		
		while(p!=0){
			printf("%s : %s, %s : %d\n", (*p).data.id, (*p).data.name.last,(*p).data.name.first,(*p).data.score);
			p = p->next;
		}
		
	}

	
	
	if( fclose(fp)!=0) {
		perror("fclose");
		return 4;
	}

	
	return 0;
}