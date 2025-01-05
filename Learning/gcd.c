#include <stdio.h>

// Function to find the GCD of two numbers
int find_gcd(int m, int n) {
    int res, i, min;

    // Determine the smaller of the two numbers (m or n)
    min = m < n ? m : n;

    // Iterate from 1 to the smaller number (min)
    for (i = 1; i < min; i++) {
        // Check if 'i' is a common divisor of both m and n
        if (m % i == 0 && n % i == 0) {
            // Update 'res' to the current divisor
            res = i;
        }
    }

    // Return the greatest common divisor found
    return res;
}

int main() {
    int m, n, res;

    // Prompt the user to input two numbers
    printf("Enter any 2 numbers to find GCD: \n");
    scanf("%d %d", &m, &n);

    // Call the GCD function and store the result
    res = find_gcd(m, n);

    // Print the result
    printf("The GCD of %d and %d is: %d\n", m, n, res);

    return 0;
}

