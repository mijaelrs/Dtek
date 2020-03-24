/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>

//Written by Marie Kindblom	2015-09-21

int is_prime(int n){		//number n = the number we will evaluate
	int number = n;
	int inc	= 2;		//inc for increment, we will divide n by this value
	int not_prime =  0;

/*while increment is less than our own number (everthing above n will be less than 1 = not to be evaluated*/
	while (inc < number && not_prime == 1) {
	if (number % inc == 0) {	//if we dont receive rest value, it's not a prime 
		not_prime == 1;
	}
	inc++;
	}
if (not_prime == 1)	//if it is a prime number, we will have received maximum amount of rests, EVERY TIME WE LOOP, hence loops == prime
			//other divisions may have rests, but not for every loop because otherwise it qualifies as a primenumber.
	return 0;
else	
	return 1;
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
