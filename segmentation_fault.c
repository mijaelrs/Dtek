


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


	if(is_prime(n) == 1 && n){
		while(n > 0){
			print_number(n);
			n--;
			print_primes(n);
		}
	}
	else{
		n--;
		print_primes(n);
	}
