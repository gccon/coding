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

```c++
int func(int x){
    int countx = 0;//作用是统计x的二进制表示中 1的位数
    while(x){
        countx++;
        x = x&(x-1);
    }
    return countx;
} 
```

## 用来判断某数是否是2的N次幂

```c++
int func(int x){
    if( (x&(x-1)) == 0 ) return 1;  //如果是0，则表示x是2的n次方
    else return 0; //注意上面==优先级大于 & 所以一定要带上括号！！！！！！
}
```

