#include <stdio.h>
// For loop
void factorial() {
	// n! = 1*2*...*n-1*n
	int n, i, factorial=1;
	printf("Uing For Loop\n");
	printf("Enter value of n: \n");
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		factorial = factorial * i;
	printf("Factorial of n is: %d\n", factorial);
}
// Factorial using while loop
void whileFact() {
	int a, b=1, fact=1;
	printf("Using While loop\n");
	printf("Enter value of a: \n");
	scanf("%d", &a);
	while(b<=a) {
		fact = fact*b;
		b++;
	}	
	printf("Factorial of a is: %d\n", fact);
}

int main() {
	factorial();
	whileFact();
	return 0;
}
