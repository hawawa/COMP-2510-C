#include <stdio.h>
#include <math.h>



int main(void){
	unsigned long n = 1234;
	unsigned long rn = 0;
	unsigned long temp_n = n;
	
	for(; temp_n != 0;){
		rn = rn * 10 + (temp_n - temp_n / 10 * 10);
		temp_n /= 10;
		printf("%d\n", (int) rn);
	}
	

	
	
	return 0;
}