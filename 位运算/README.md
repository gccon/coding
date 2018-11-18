位运算

异或 , 1^1 = 0  1^0 = 1 0^1 = 1 0^0 = 1 相同为0，不同为1

[268. Missing Number](https://leetcode.com/problems/missing-number/description/)

```c++
class Solution {//从0到n消失的数字
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};
```

