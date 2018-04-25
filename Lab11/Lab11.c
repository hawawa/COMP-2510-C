#include <stdio.h>
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "passed" : "FAILED", #PRED)


int *arr_first_max(const int *a, size_t n){
	const int *p;
	const int *max = a;
	for(p=a; p<a+n;p++){
		if(*p>*max){
			max = p;
		}
	}
	return (int *)max;
}

int *arr_last_max(const int *a, size_t n){
	const int *p;
	const int *max = a;
	for(p=a; p<a+n;p++){
		if(*p>=*max){
			max = p;
		}
	}
	return (int *)max;
}

size_t str_replace_all(char *s, int oldc, int newc){
	char *p;
	size_t counter=0;
	for(p=s; *p!='\0';p++){
		if(*p==oldc){
			*p = newc;
			counter++;
		}
	}
	return counter;
	
}

char *str_find_last(const char *s, int c){
	const char *p;
	const char *find = 0;
	for(p=s; *p!='\0';p++){
		if(*p==c){
			find=p;
		}
	}
	return (char *)find;
}





int main(void){
	int array[]={5,7,9,11,2,3,11};
	char string[]="Hello world";
	int *p = array;
	char *q;
	
	printf("%d\n",(int)(p-array));
	p=arr_first_max(array, 7);
	printf("%d\n",*p);
	printf("%d\n",(int)(p-array));
	p=arr_last_max(array, 7);
	printf("%d\n",*p);
	printf("%d\n",(int)(p-array));




	CHECK(str_replace_all(string, 'o', 'x') == 2);
	printf("%s\n",string);
	
	q=str_find_last(string, 'l');
	printf("%c\n",*q);
	printf("%d\n",(int)(q-string));
	
	return 0;
}