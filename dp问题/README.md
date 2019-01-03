### dp问题研究

01背包问题： 一个数组能否分成两拨，两拨的和一样？ 一维DP，注意点是从后面到前面。对每个数，包括或者不包括，装或者不装。装的大小是sum。

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max_num = *max_element(nums.begin(), nums.end());
        int half = sum / 2;
        if((sum & 1) || max_num > half) return false;
        vector<int> dp(half + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){   //这上面从0到n 或者从n到0都无所谓
            for(int j = half; j >= nums[i]; j--){ //  这里要从后面到前面，从前到后面就是可以重复使用这个数了。一定要从后到前面
                dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[half];
    }
};
```

二维dp，状态转移方程：

```c
// dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max_num = *max_element(nums.begin(), nums.end());
        int half = sum / 2;
        if((sum & 1) || max_num > half) return false;
        vector<vector<int>> dp(n, vector<int>(half + 1, 0)); // dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        dp[0][0] = dp[0][nums[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= half; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= nums[i])
                    dp[i][j] |= dp[i - 1][j - nums[i]];
            }
        }
        return dp[n - 1][half];
    }
};
```

