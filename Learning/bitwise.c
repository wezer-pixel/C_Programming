#include <stdio.h>

// & AND operator
// Only 1 when both bits are 1
void BitwiseAND() {
    int a = 7;
    int b = 12;
    int result = a & b;
    printf("%d & %d = %d\n", a, b, result);
    /* 
     * Bitwise Representation of AND
     * bit 8 4 2 1
     * 7   0 1 1 1 &
     * 12  1 1 0 0
     * 4   0 1 0 0 = result
     */
}

// | OR operator
// Only 0 when both bits are 0
void BitwiseOR() {
    int a = 5;
    int b = 3;
    int result = a | b;
    printf("a: %d | b: %d = Result: %d\n", a, b, result);
    /*
     * Bitwise Representation of OR
     * bit 8 4 2 1
     * 5   0 1 0 1 |
     * 3   0 0 1 1
     * 7   0 1 1 1 = result
     */
}

// ^ EXCLUSIVE OR (XOR) operator
// Only 1 when bits are opposite; if same, output is 0
void BitwiseXOR() {
    int a = 5;
    int b = 3;
    int result = a ^ b;
    printf("a: %d ^ b: %d = Result: %d\n", a, b, result);
    /*
     * Bitwise Representation of XOR
     * bit 8 4 2 1
     * 5   0 1 0 1 ^
     * 3   0 0 1 1
     * 6   0 1 1 0 = result
     */
}

// ~ One's Complement operator (unary operator)
// Each bit becomes its opposite, i.e., 1 becomes 0 and vice versa
void OnesComplement() {
    int a = 5;
    int result = ~a;
    printf("~%d = %d\n", a, result);
}

// << Left Shift Operator
// a << pos => a * 2^pos
void LeftShift() {
    int x = 10;
    printf("x before left shift: %d\n", x);
    int y = x << 2;
    printf("x after 2-bit left shift: %d\n", y);
    /*
     * 10 * 2^2 = 40
     */
}

// >> Right Shift Operator
// a >> pos => a / 2^pos
void RightShift() {
    int x = 10;
    printf("x before right shift: %d\n", x);
    int y = x >> 1;
    printf("x after 1-bit right shift: %d\n", y);
    /*
     * 10 / 2^1 = 5
     */
}

int main() {
    BitwiseAND();
    BitwiseOR();
    BitwiseXOR();
    OnesComplement();
    LeftShift();
    RightShift();
    return 0;
}

