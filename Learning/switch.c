#include <stdio.h>
// Switch Statement
void switchStmt() {
	int a =1, b = 2;
	switch(a + b)
	{
		case 1:
			printf("One\n");
			break;
		case 2:
			printf("Two\n");
                        break;
		case 3:
			printf("Three\n");
                        break;
                default:
			printf("Value Not in range\n");
	}
}

int main() {
	printf("Start Switch stmt\n");
	switchStmt();
	return 0;
}
