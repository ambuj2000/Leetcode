/**Intuition
Explanation:

If we have numbers [1..n], and we put 1 in the first position, it will create no inversions with the rest of the array. If we choose 2 for the first position, it will create one inversion. If we choose n for the first position, it will create n - 1 inversion with the rest of the array.

We can see a recursion here - we can now apply the same logic for n - 1 and k - i + 1, where i is the number we choose for the first position in the previous step.

Similar question: 903. Valid Permutations for DI Sequence.

Top-Down DP
We will start with the most intuitive implementation, which, with the help of memoisation, will have O(n * k * k) time complexity.

Note that this and the following solutions are not accepted by OJ. They are here for demonstration purposes. We will build it up to O(n * k) solution in the end.

int dp[1001][1001] = {};
int kInversePairs(int n, int k) {
    if (k <= 0)
        return k == 0;
    if (dp[n][k] == 0) {
        dp[n][k] = 1;
        for (auto i = 0; i < n; ++i) {
            dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % 1000000007;
        }
    }
    return dp[n][k] - 1;
}
Complexity Analysis

Time: O(n * k * k)
Memory: O(n * k)
Bottom-Up DP
After we get the top-down memoisation right, we can convert it to a bottom-up tabulation. A tabulation algorithm is iterative, and it often leads to further runtime and/or memory optimizations.

int kInversePairs(int n, int k) {
    int dp[1001][1001] = { 1 };
    for (int N = 1; N <= n; ++N)
        for (int K = 0; K <= k; ++K)
            for (int i = 0; i <= min(K, N - 1); ++i) 
                dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
    return dp[n][k];
}
Complexity Analysis

Same as for top-down approach.
Time Optimization
As it happens, the bottom-up DP gives us an insight that can improve the time complexity. If you look at the inner loop, you can realize that it iterates over the (K - 1) values for the next K. It becomes very clear if you look how the tabulation matrix is populated.
image

In the picture above, you can see that value for n == 5 is a sum of 5 values in the previous column: dp[N - 1][K] + dp[N - 1][K-1]+... + dp[N-1][K - 4]. For the next value - K + 1, we can add to that value dp[N - 1][K + 1], and subtract dp[N - 1][K - 4].

Therefore, we can use a sliding window technique to calculate dp[N][K] in O(1), reducing the overall time complexity to O(n * k).

int dp[1001][1001] = { 1 };
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (dp[n][k])
            return dp[n][k];
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K) {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % 1000000007;
                if (K >= N)
                    dp[N][K] = (1000000007 + dp[N][K] - dp[N - 1][K - N]) % 1000000007;
            }
        return dp[n][k];
    }
};
Complexity Analysis

Time: O(n * k)
Memory: O(n * k)
Memory Optimization
From the above algorithm, you can notice that we only look one step back (N - 1). Therefore, we only need two rows (k column each) for the tabulation.

int kInversePairs(int n, int k) {
    int dp[2][1001] = { 1 };
    for (int N = 1; N <= n; ++N)
        for (int K = 0; K <= k; ++K) {
            dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % 1000000007;
            if (K >= N)
                dp[N % 2][K] = (1000000007 + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % 1000000007;
        }
    return dp[n % 2][k];
}
Complexity Analysis

Time: O(n * k)
Memory: O(k)
**/


class Solution {
public:
    int kInversePairs(int n, int k) {
         int dp[2][1001] = { 1 };
    for (int N = 1; N <= n; ++N)
        for (int K = 0; K <= k; ++K) {
            dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % 1000000007;
            if (K >= N)
                dp[N % 2][K] = (1000000007 + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % 1000000007;
        }
    return dp[n % 2][k];   
    }
};