#include <stdio.h>

// If Statement
void ifStmt() {
	int n = 3;
	if (n > 1) {
		printf("Condition met, n : %d > 1\n", n);
	} else {
		printf("If you see this output alone, condition not met\n");
	}
}

// If-Else Statement
void ifElse() {
	int n = 3;
	if (n % 2 == 0) {
        printf("Even\n");
	} else {
		printf("Odd\n");
	}
}

// Nested if and if else stmt are if and else if stmt within if stmt
void nestedStmt() {
	int x, y, z, max;
	printf("Enter 3 values to start :\n");
	scanf("%d %d %d", &x, &y, &z);
	if (x > y) {
		if(x > z)
			max = x;
		else
			max = z;
	} else {
		if (y > z)
			max = y;
		else
			max = z;
	}
	printf("Max value is: %d\n", max);
}

int main() {
    ifStmt();
    ifElse();
    nestedStmt();
    return 0;
}

