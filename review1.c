#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*1.a*/
size_t find_first(const char s[], int c){
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == c){
			return i;
		}
	}
	return (size_t) -1;
}

/*1.b*/
void repalce_first(int a[], size_t n, int oldint, int newint){
	size_t i;
	for(i = 0; i < n; i++){
		if(a[i] == oldint){
			a[i] = newint;
			break;
		}
	}
}

/*1.c*/
void replace_last(char s[], int oldc, int newc){
	size_t index = -1;
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == oldc){
			index = i;
		}
	}
	if(index != (size_t) -1){
		s[index] = newc;
	}
	
}

/*1.d*/
size_t count(const int a[], size_t n, int x){
	size_t counter = 0;
	size_t i;
	for(i = 0; i < n; i++){
		if(a[i] == x){
			counter++;
		}
	}
	return counter;
}

/*2.a*/
size_t count_alpha(const char s[]){
	size_t counter = 0;
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if(isalpha(s[i])){
			counter++;
		}
	}
	return counter;
}

/*2.b*/
int all_digits(const char s[]){
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if( !isdigit(s[i]) ){
			return 0;
		}
	}
	return 1;
}

/*2.c*/
void lowercase_copy(char dest[], const char src[]){
	size_t i;
	for(i = 0; src[i] != '\0'; i++){
		dest[i] = tolower(src[i]);
	}
	dest[i] = '\0';
}

/*2.d*/
void reverse_copy(char dest[], const char src[]){
	size_t i, j;
	for(i = strlen(src), j = 0; i > 0; i--, j++){
		dest[j] = src[i-1];
	}
	dest[j]='\0';
}

/*
void reverse_copy(char dest[], const char src[]){
	size_t i;
	for(i = 0; src[i] != '\0'; i++){
		dest[strlen(src) - i - 1]= src[i];
	}
	dest[i] = '\0';

}
*/


/*2.e*/
void ltrim_copy(char dest[], const char src[]){
	size_t i;
	size_t j;
	for(i = 0; src[i] != '\0'; i++){
		if(!isspace(src[i])){
			break;
		}
	}
	
	for(j = 0; src[i] !='\0'; i++, j++){
		dest[j] = src[i];
	}
	
	dest[j] = '\0';
}

/*2.f*/
int is_valid_id(const char s[]){
	size_t i;
	if(s[0] != 'a' && s[0] != 'A'){
		return 0;
	}
	for(i = 1; s[i] != '\0'; i++){
		if(!isdigit(s[i])){
			return 0;
		}
	}
	if(i != 9){
		return 0;
	}
	return 1;
}

/*2.g*/
int is_valid(const char s[]){
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if( !isalpha(s[i]) && s[i] !='-'){
			return 0;
		}
	}
	
	return i >=2 && i <=20 && s[0] != '-' && s[i-1] != '-';	
}

void three(){
	/*char a[] = "hello";*/
	char b[] ="abcde";
	char *p = b;
/*
	char *p = "world";
	*/
	
	/*a*/
	/*
	p = &a[1];
	printf("%s\n",p);
	*/
	
	/*b*/
	/*
	p[1] = *a;
	printf("%s\n",p);
	*/
	
	/*c*/
	/*
	a = p;
	printf("%s\n",p);
	*/

	/*test*/
	
	*p ='1';
	printf("%s\n",p);
	
	
	
}

int main(void){
	char s1c[] = "abcdabcdabcdabcd";
	char s2a[]="    abcd0123abcd   ";
	char s2c_1[] = "   HANK abcde";
	char s2c_2[30];
	char s2d_1[] = "   HANK abcde  ";
	char s2d_2[30];	
	char s2e_1[] = "   HANK abcde  ";
	char s2e_2[30];	
	char s2g_1[] = "abcdefg-hijklmnopq";

	
	printf("1.c\n");
	replace_last(s1c, 'b', '0');
	printf("%s\n", s1c);
	
	printf("2.a\n");
	printf("%d\n",(int) count_alpha(s2a));
	
	printf("2.c\n");
	lowercase_copy(s2c_2,s2c_1);
	printf("%s\n", s2c_2);
	
	printf("2.d\n");
	reverse_copy(s2d_2,s2d_1);
	printf("%s\n", s2d_2);
	
	printf("2.e\n");
	ltrim_copy(s2e_2,s2e_1);
	printf("%s\n", s2e_2);	
	
	printf("2.g\n");
	printf("%d\n", is_valid(s2g_1));
	
	printf("three\n");
	three();
	
	
	return 0;
}




