class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n, sum = 0, product = 1;

        while (temp) {
            int digit = temp % 10;
            sum += digit;
            product *= digit;
            temp /= 10;
        }

        return n % (sum + product) == 0;
    }
};
