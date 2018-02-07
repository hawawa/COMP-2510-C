#include<stdio.h>
#include <ctype.h>
#include <string.h>
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "passed" : "FAILED", #PRED)


size_t str_replace_all(char s[], int oldc, int newc){
	size_t i;
	size_t counter = 0;
	for (i = 0; s[i] != '\0'; i++){
		if(s[i] == oldc){
			s[i] = newc;
			counter++;
		}
	}
	return counter;
}

int str_replace_last(char s[], int oldc, int newc){
	size_t i;
	size_t index = -1;
	for(i = 0; s[i] != '\0'; i++){
		if (s[i] == oldc){
			index = i;
		}
	}
	if(index != (size_t)-1){
		s[index] = newc;
		return 1;
	}		
	return 0;
}

int str_all_digits(const char s[]){
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if(!isdigit(s[i])){
			return 0;
		}
	}
	return 1;
}

int str_equal(const char s[], const char t[]){
	size_t i;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] != t[i]){
			return 0;
		}
	}
	return t[i] == '\0';
}

int main(){
	/*declare 1*/
	char s1_1[] = "hello world";
	char s1_2[] = "hello world";
	char s1_3[] = "hello world";
	char s1_4[] = "hello world";
	char t1[] = "hello world";

	/*declare 2*/
	char s2_1[] = "12345678";
	char s2_2[] = "12345678";
	char s2_3[] = "12345678";
	char s2_4[] = "12345678";
	char t2[] = "1234567890";
	
	/*declare 3*/
	char s3_1[] = "123hello world";
	char s3_2[] = "123hello world";
	char s3_3[] = "123hello world";
	char s3_4[] = "123hello world";
	char t3[] = "123hello ";
	
	/*check 1*/
	CHECK(str_replace_all(s1_1,'l','x') == 3);
	CHECK(strcmp(s1_1, "hexxo worxd") ==0);
	CHECK(str_replace_last(s1_2,'l','x') == 1);
	CHECK(strcmp(s1_2, "hello worxd") ==0);
	CHECK(str_all_digits(s1_3) == 0);
	CHECK(str_equal(s1_4, t1) == 1);
	
	/*check 2*/
	CHECK(str_replace_all(s2_1,'5','x') == 1);
	CHECK(strcmp(s2_1, "1234x678") ==0);
	CHECK(str_replace_last(s2_2,'5','x') == 1);
	CHECK(strcmp(s2_2, "1234x678") ==0);
	CHECK(str_all_digits(s2_3) == 1);
	CHECK(str_equal(s2_4, t2) == 0);
	
	/*check 3*/
	CHECK(str_replace_all(s3_1,'a','x') == 0);
	CHECK(strcmp(s3_1, "123hello world") ==0);
	CHECK(str_replace_last(s3_2,'a','x') == 0);
	CHECK(strcmp(s3_2, "123hello world") ==0);
	CHECK(str_all_digits(s3_3) == 0);
	CHECK(str_equal(s3_4, t3) == 0);
	
	
	return 0;
}