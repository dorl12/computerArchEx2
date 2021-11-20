// 313547085 Dor Levy
#include "ex2.h"

/*
 * The negSign function returns 0 in case the number
 * is positive according to magnitude method.
 * otherwise, it returns a negative number.
 */
int negSign(magnitude x) {
    return x & 0x80000000;
}

/*
 * The value function returns the absolute value of the number.
 */
int value(magnitude y) {
    return y & 0x7FFFFFFF;
}

/*
 * The add function returns the result of adding
 * two numbers according to magnitude method
 */
magnitude add(magnitude a, magnitude b) {
    // In case the numbers are positive
    if (!negSign(a) && !negSign(b)) {
        int result = a + b;
        // in case of overflow, return the absolute value of the result
        if (negSign(result)) {
            return value(result);
        }
        return result;
    }
    // In case the numbers are negative
    if (negSign(a) && negSign(b)) {
        int result = -value(a) + (-value(b));
        // in case of overflow, change the MSB to be 1
        if (!negSign(result)) {
            result = result | 0x80000000;
        }
        result = -result;
        // in case the result is equal to 0 in magnitude method
        if(equal(result, 0)) {
            return 0;
        }
        return result | 0x80000000;
    }
    // In case the first parameter is negative and the second parameter is positive
    if (negSign(a) && !negSign(b)) {
        int result = -value(a) + b;
        // in case the result is negative, convert it into 2's complement
        if (result < 0) {
            result = -result;
            return result | 0x80000000;
        }
        // in case the result is equal to 0 in magnitude method
        if(equal(result, 0)) {
            return 0;
        }
        return result;
    }
    // In case the first parameter is positive and the second parameter is negative
    if (!negSign(a) && negSign(b)) {
        int result = -value(b) + a;
        // in case the result is negative, convert it into 2's complement
        if (result < 0) {
            result = -result;
            return result | 0x80000000;
        }
        // in case the result is equal to 0 in magnitude method
        if(equal(result, 0)) {
            return 0;
        }
        return result;
    }
    return 0;
}

/*
 * The sub function returns the result of subtracting
 * two numbers according to magnitude method
 */
magnitude sub(magnitude a, magnitude b) {
    /*
     * in case the second parameter is negative
     * call add func with a and the absolute value of the
     * second parameter
     */
    if (negSign(b)) {
        return add(a, value(b));
    }
    // in case the second parameter is positive, change the MSB to 1 and call add func
    int negSign = 0x80000000;
    b = b | negSign;
    return add(a, b);
}

/*
 * The multi function returns the result of multiplying
 * two numbers according to magnitude method
 */
magnitude multi(magnitude a, magnitude b) {
    // In case the numbers are positive multiply regular
    if (!negSign(a) && !negSign(b)) {
        int result = a * b;
        return result;
    }
    // In case the numbers are negative
    if (negSign(a) && negSign(b)) {
        int result = -value(a) * -value(b);
        // return the absolute value because the result should be positive
        return value(result);
    }
    // In case the first parameter is negative and the second parameter is positive
    if (negSign(a) && !negSign(b)) {
        int result = -value(a) * b;
        // in case the result is equal to 0 in magnitude method
        if(equal(result, 0)) {
            return 0;
        }
        // convert it into 2's complement
        result = -result;
        return result | 0x80000000;
    }
    // In case the first parameter is positive and the second parameter is negative
    if (!negSign(a) && negSign(b)) {
        int result = -value(b) * a;
        // in case the result is equal to 0 in magnitude method
        if(equal(result, 0)) {
            return 0;
        }
        // convert it into 2's complement
        result = -result;
        return result | 0x80000000;
    }
    return 0;
}

/*
 * The equal function returns 1 if the numbers are equal and 0 otherwise.
 */
int equal(magnitude a, magnitude b) {
    int zeroNegRep = 0x80000000;
    // in case the first parameter is equal to 0 in magnitude method
    if (a == zeroNegRep) {
        a = 0;
    }
    // in case the second parameter is equal to 0 in magnitude method
    if (b == zeroNegRep) {
        b = 0;
    }
    // in case the numbers are not equal
    if (a^b) {
        return 0;
    }
    return 1;
}

/*
 * The greater function returns 1 if the first
 * parameter is greater than the second parameter.
 * otherwise, returns 0.
 */
int greater(magnitude a, magnitude b) {
    // in case the first parameter is equal to 0 in magnitude method
    if (equal(a, 0)) {
        a = 0;
    }
    // in case the second parameter is equal to 0 in magnitude method
    if (equal(b, 0)) {
        b = 0;
    }
    // In case the numbers are positive
    if (!negSign(a) && !negSign(b)) {
        if (a > b) {
            return 1;
        }
        return 0;
    }
    // In case the numbers are negative, compare their absolute value
    if (negSign(a) && negSign(b)) {
        if (value(a) < value(b)) {
            return 1;
        }
        return 0;
    }
    // In case the first parameter is negative and the second parameter is positive
    if (negSign(a) && !negSign(b)) {
        return 0;
    }
    // In case the first parameter is positive and the second parameter is negative
    if (!negSign(a) && negSign(b)) {
        return 1;
    }
    return 0;
}

