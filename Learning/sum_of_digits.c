#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of the digits of a number
int sum_digits(int n) {
    int d, sum = 0;

    n = abs(n);

    while (n > 0) {
        d = n % 10;
        sum = sum + d;
        n = n / 10;
    }

    return sum;
}

int main() {
    int n, result;

    printf("Enter a number to get the sum of its digits: \n");
    scanf("%d", &n);

    result = sum_digits(n);

    printf("The sum of digits in %d is: %d\n", n, result);

    return 0;
}

