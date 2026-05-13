int helper(int remaining, int k) {
    if (remaining == 0) return 1;
    if (k*k > remaining) return 0;

    return helper(remaining - k*k, k+1) + helper(remaining, k + 1);
}
int countWaySumOfSquare(int x) {
    return helper(x, 1);
}