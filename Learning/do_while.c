#include <stdio.h>
//do while loop
void do_while() {
	int i=1, n, sum=0;
	printf("Enter value of n: \n");
	scanf("%d", &n);
	do {
		sum = sum + i;
		i = i + 1;
	} while(i <= n);
	printf("Sum is: %d\n", sum);
}

int main() {
	do_while();
	return 0;
}
