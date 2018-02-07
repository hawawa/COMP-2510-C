#include<stdio.h>
#define CHECK(PRED) printf("%s...%s\n", (PRED) ? "passed" : "FAILED", #PRED)
int arr_min(const int a[], size_t n){
	int min = a[0];
	size_t i;
	for (i = 0; i < n; i++){
		if(a[i] < min){
			min = a[i];
		}
	}
	return min;
}

size_t arr_count(const int a[], size_t n, int x){
	size_t count = 0;
	size_t i;
	for (i = 0; i < n; i++){
		if(a[i] == x){
			count++;
		}
	}
	return count;
}

int arr_all_even(const int a[], size_t n){
	size_t i;
	for (i = 0; i < n; i++){
		if(a[i] % 2 == 1){
			return 0;
		}
	}
	return 1;
}

size_t arr_find_last(const int a[], size_t n, int x){
	size_t i;
	size_t index = -1;
	for(i = 0; i < n; i++){
		if (a[i]==x){
			index = i;
		}
	}
	return index;
}




int main(){
	int a [] = {2, 5, 0, 4, -1, 7};
	int b [] = {-2, 5, 1, 5, -1, 10};
	int c [] = {-2, 2, 4, 4, 2, 4, -6, 10};
	
	CHECK(arr_min(a,6) == -1);
	CHECK(arr_count(a,6,7) == 1);
	CHECK(arr_all_even(a,6) == 0);
	CHECK(arr_find_last(a,6,5) == 1);
	
	CHECK(arr_min(b,6) == -2);
	CHECK(arr_count(b,6,5) == 2);
	CHECK(arr_all_even(b,6) == 0);
	CHECK(arr_find_last(b,6,-1) == 4);
	
	CHECK(arr_min(c,8) == -6);
	CHECK(arr_count(c,8,4) == 3);
	CHECK(arr_all_even(c,8) == 1);
	CHECK(arr_find_last(c,8,5) == (size_t) -1);
	printf("%d\n", (int) arr_find_last(c,8,5));
	
	return 0;
}