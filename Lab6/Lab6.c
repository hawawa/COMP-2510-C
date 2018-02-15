#include <stdio.h>
#include <math.h>
void min_max(const int a[], size_t n, int *pmin, int *pmax){
	size_t i;
	*pmin = a[0];
	*pmax = a[0];
	for(i = 0; i < n; i++){
		if(a[i] < *pmin){
			*pmin = a[i];
		}
		if(a[i] > *pmax){
			*pmax = a[i];
		}
		
	}
	
}


size_t num_digits(unsigned long n){
	size_t i = 1;
	for(; n/10 != 0;i++){
		n /= 10;
	}
	
	return i;
}


int is_reversible(unsigned long n){
	unsigned long rn = 0;
	unsigned long temp_n = n;
	
	for(; temp_n != 0;){
		rn = rn * 10 + temp_n % 10;
		temp_n /= 10;
		
	}
	
	
	return n == rn;
}




int main(void){
	int array[] = {5,4,6,7,8,3};
	int array_max;
	int array_min;
	min_max(array, 6, &array_min, &array_max);
	
	printf("max:%d min:%d\n", array_max, array_min);
	
	printf("num_digits(0):%d\n", (int) num_digits(0));
	printf("num_digits(32768):%d\n", (int) num_digits(32768));
	

	printf("is_reversible(327686723):%d\n", is_reversible(327686723));
	printf("is_reversible(3):%d\n", is_reversible(3));
	printf("is_reversible(12):%d\n", is_reversible(12));
	
	

	
	
	return 0;
}