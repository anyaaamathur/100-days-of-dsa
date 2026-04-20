// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include <stdio.h>

int main() {
    char s[100];
    int left = 0, right = 0;

    scanf("%s", s);

    while (s[right] != '\0') {
        right++;
    }
    right--;   

    while (left < right) {
        if (s[left] != s[right]) {
            printf("not palindrome");
            return 0;
        }
        left++;
        right--;
    }

    printf("is palindrome");
    return 0;
}
