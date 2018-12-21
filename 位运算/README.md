位运算

异或 , 1^1 = 0  1^0 = 1 0^1 = 1 0^0 = 1 相同为0，不同为1

[268. Missing Number](https://leetcode.com/problems/missing-number/description/)

```c++
class Solution {//从0到n消失的数字//找出单身狗 主要利用异或相当的话会抵掉。所以可以找残缺
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
        countx++;//循环的次数就是1个个数  7 111  110 110 011 10 1 
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

```c++
class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
}

/* using n & -n which get the right most 1 bit (set bit) of n, for example:
n = 5, -n = -5
n & -n = 0101 & 1011 = 0001, the right most set bit of 5 is 0001.
Another example:
n = 12, -n = -12
n & -n = 1100 & 0100=0100, as you can see the right most set bit of 12 is 0100
*/

//负数是补码表示的 // 10000101 原码 10000010  补码 10000011  
```





快速幂运算：

比如计算 5^11次方，那么11 = 2^3+2^1+2^0  二进制（1011）  b每次取最低位判断是否是1,然后往右挪一位。

base 就是 5^1  5^2 5^4  5^8 次方这样变化，碰到是1的时候就乘到ans里面去。

```c++
int quick_pow(int a,int b)
{
    int ans = 1,base = a;
    while(b!=0)
    {
        if(b&1) //相当于 b%2==1
            ans *= base;
        base *= base;
        b>>=1; //相当于 b /= 2;
    }
    return ans;
}

```

