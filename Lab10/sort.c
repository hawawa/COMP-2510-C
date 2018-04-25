#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "sort.h"


static int strcmp_name(const name p, const name q){
	const name *pp = &p;
	const name *qq = &q;
	int n = strcmp(pp->last, qq->last);
	if(n!=0){
		return n;
	}
	return strcmp(pp->first, qq->first);
}

static int cmp_score_desc_id_asc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = qq->score - pp->score;
	if(n!=0){
		return n;
	}
	return strcmp(pp->id, qq->id);
}

static int cmp_name_asc_id_desc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = strcmp_name(pp->name, qq->name);
	if(n!=0){
		return n;
	}
	return strcmp(qq->id, pp->id);
}

static int cmp_score_desc_name_asc_id_asc(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = qq->score - pp->score;
	int m;
	if(n!=0){
		return n;
	}
	m = strcmp_name(pp->name, qq->name);
	if(m!=0){
		return m;
	}
	return strcmp(pp->id, qq->id);
}



void sort_score_desc_id_asc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_score_desc_id_asc);
}

void sort_name_asc_id_desc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_name_asc_id_desc);
}
 
void sort_score_desc_name_asc_id_asc(record a[], size_t n){
	qsort(a,n,sizeof(a[0]),cmp_score_desc_name_asc_id_asc);
}


