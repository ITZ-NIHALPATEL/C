/**
 * @file
 * @brief Program to identify if a number is a [palindrome
 * number](https://en.wikipedia.org/wiki/Palindrome) or not.
 * @details A palindrome number is a number that reads the same backward as
 * forward. This implementation checks this mathematically by reversing the number
 * and comparing it to the original.
 *
 * ### Examples
 *
 * 1.  `isPalindrome(121)`
 * - Original: 121
 * - Loop 1: remainder = 1, reversedNumber = 1, number = 12
 * - Loop 2: remainder = 2, reversedNumber = 12, number = 1
 * - Loop 3: remainder = 1, reversedNumber = 121, number = 0
 * - Final Check: 121 == 121 -> `true`
 *
 * 2.  `isPalindrome(123)`
 * - Original: 123
 * - Loop 1: remainder = 3, reversedNumber = 3, number = 12
 * - Loop 2: remainder = 2, reversedNumber = 32, number = 1
 * - Loop 3: remainder = 1, reversedNumber = 321, number = 0
 * - Final Check: 123 == 321 -> `false`
 *
 * @see project_euler/problem_4/sol1.c
 */
#include <assert.h>  /// for assert()
#include <stdbool.h> /// for bool
#include <stdio.h>

bool isPalindrome(int number);

/** Driver Code */
int main() {
    // assert() checks if the expression is true. If it's false, the program
    // will terminate. These are self-tests.
    assert(isPalindrome(0));        // 0 is a palindrome
    assert(isPalindrome(1));        // Single digits are palindromes
    assert(isPalindrome(12321));    // A standard palindrome
    assert(!isPalindrome(1234));    // A standard non-palindrome
    // Note: This implementation doesn't correctly handle negative numbers.
    // e.g., isPalindrome(-121) would return false, as originalNumber (-121)
    // would not equal reversedNumber (-121) because the loop doesn't run.
    return 0;
}

/**
 * Check given number whether is palindrome number or not.
 * @param number The integer to check.
 * @return `true` if the given number is a palindrome.
 * @return `false` if the given number is not a palindrome.
 */
bool isPalindrome(int number) {
    int reversedNumber = 0;
    int originalNumber = number; // Store the original number for later comparison

    // Rebuild the number in reverse
    // Loop continues as long as there are digits left (number is not 0)
    while (number != 0) {
        // Get the last digit of the number
        int remainder = number % 10;

        // Append the last digit to the reversedNumber
        // (e.g., if reversedNumber = 12 and remainder = 3, it becomes 120 + 3 = 123)
        reversedNumber = reversedNumber * 10 + remainder;

        // Remove the last digit from the number using integer division
        // (e.g., 123 / 10 = 12)
        number /= 10;
    }

    // A number is a palindrome if its original value equals its reversed value
    return originalNumber == reversedNumber;
}
