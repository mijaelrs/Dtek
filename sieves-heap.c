//Skriven av Marie Kindblom - 2015-09-21

#include <stdio.h>
#include <stdlib.h>

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

void print_sieves(int n) { //number of primes

	int number = n;
	int i = 0;
	int length = number - 2;				//length of array is number - 2
	char *myBuff = malloc(sizeof(char)*length);		//declare buffer/heap of length 'length'
	

	for (i = 2; i <= number; i++) {				//loop from i=2 to i==number (n)
		int index = i-2;					//index position will be i-2 (because we started at 2)
		myBuff[index] = i;					//put value of i into the array at index 'index'
	}

	
	//the loop of magic maths
	for (i = 0; i <= length; i++) {			//loop through array
		if (myBuff[i] != 0)	{		//if value in array is not 0 (0 means we have "marked it" in this loop)
			int p = i+2;			//then set p to the value of that index+2
			int x = p+p;			//we shall not mark the number, so we double it and subtract 2 (to get right index)
			int index;			
			while(x <= number) {		//while x is less than or equal than number
				index = x-2;				
				myBuff[index] = 0;		//set the index to 0
				x = x + p;			//get next value by adding p to x
			}
		}
		else						//else, we got a value of 0 (not supposed to loop that one)
			continue;
	}
	int prime;
	for (i = 0; i <= length; i++) {	//print what we've got
		if (myBuff[i] != 0) {
			prime = i + 2;
			print_number(prime);
		}
	}
	free(myBuff);
}

//ca 200 000 på två sek.
int main(int argc, char *argv[]) {

  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;

//thizz shizz is gonna be amazeballzz

//create
}




//create list from 2 .. n
//first p = 2
//move to multiples of p (do not mark p), going to 4p, 6p, 8p and so on..
//move p to the first number greater than p, in this case 3. repeat from the previous line
