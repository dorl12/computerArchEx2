// 313547085 Dor Levy
#ifndef UNTITLED2_EX2_H
#define UNTITLED2_EX2_H

typedef magnitude;

/*
 * The negSign function returns 0 in case the number
 * is positive according to magnitude method.
 * otherwise, it returns a negative number.
 */
int negSign(magnitude x);

/*
 * The value function returns the absolute value of the number.
 */
int value(magnitude y);

/*
 * The add function returns the result of adding
 * two numbers according to magnitude method
 */
magnitude add(magnitude a, magnitude b);

/*
 * The sub function returns the result of subtracting
 * two numbers according to magnitude method
 */
magnitude sub(magnitude a, magnitude b);

/*
 * The multi function returns the result of multiplying
 * two numbers according to magnitude method
 */
magnitude multi(magnitude a, magnitude b);

/*
 * The equal function returns 1 if the numbers are equal and 0 otherwise.
 */
int equal(magnitude a, magnitude b);

/*
 * The greater function returns 1 if the first
 * parameter is greater than the second parameter.
 * otherwise, returns 0.
 */
int greater(magnitude a, magnitude b);

#endif //UNTITLED2_EX2_H
