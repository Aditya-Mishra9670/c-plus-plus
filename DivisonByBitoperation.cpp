// Here I have written code with proper comments to understand every step.
int division(int n, int m) {
    if (n == 0 || m == 0) {
        return 0; // Division by zero, return 0
    }

    // Determine sign of the result
    bool sign = (n > 0) ^ (m > 0);

    // Take absolute values of n and m
    unsigned int un = abs(n);
    unsigned int um = abs(m);

    // Initialize the result
    unsigned int result = 0;

    // Subtract m from n until n is less than m
    while (un >= um) {
        int count = 0;

        // Keep shifting m to the left until it's greater than n
        while (un >= (um << count + 1)) {
            count++;
        }

        // Add the power of 2 to the result
        result += 1 << count;

        // Subtract m*(2^count) from n
        un = un - (um << count);
    }

    // Check for overflow and handle sign
    if (result > INT_MAX && !sign) {
        return INT_MIN;
    }

    return sign ? result : -result;
}
