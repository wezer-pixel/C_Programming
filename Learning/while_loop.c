#include <stdio.h>
// While loop
void whileLoop() {
	int i = 1;
	while (i <= 10) {
		printf("I = %d\n", i);
		i++;
	}
}

void arithDig() {
	int n, d, sum=0, prod=1;
	printf("Enter value of n :\n");
	scanf("%d", &n);
	while(n > 0) {
		d = n%10;
		sum = sum + d;
		prod = prod * d;
		n = n/10;
	}
	printf("Sum of digits :%d\n", sum);
	
	printf("Product of digits :%d\n", prod);
}

int main() {
	whileLoop();
	arithDig();
	return 0;
}
