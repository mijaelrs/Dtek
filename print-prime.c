/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

int i = 0; // startvalue of i

void print_number(int n){
	printf("%10d ", n);
	if(i == 5){		//controls so we don't print out more then six columns.
		printf("\n");	//if i = 5 then we start a new column.
		i = 0;
	}
	else{			
	i++;			//we increament i as long as i < 5
	}
}


void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
	int i = 2;
	while (i <= n) {
		int isPrime = is_prime(i);
		if (isPrime == 1) {
			print_number(i);
			i++;
		}
		else {
			i++;
		}
	}

}




// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
	if(argc == 2) {
	print_primes(atoi(argv[1]));
}
  else
    printf("Please state an interger number.\n");
  return 0;
}


//Written by Marie Kindblom
int is_prime(int n){
	//number n = the number we will evaluate
	int number = n;
	int inc	= 2;	//inc for increment, we will divide n by this value
	int prime =  0;
/*while increment is less than our own number (everthing above n will be less than 1 = not to be evaluated*/
	while (inc < number) {
	if (number % inc != 0) {	//if we dont receive rest value, it's not a prime 
		prime++;
	}
	inc++;
	}
int loops = number-2;	//loops holds number-2, which is the number of loops that we have made 
if (loops==prime)	//if it is a prime number, we will have received maximum amount of rests, EVERY TIME WE LOOP, hence loops == prime
			//other divisions may have rests, but not for every loop because otherwise it qualifies as a primenumber.
	return 1;
else	
	return 0;
}
