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
n & -n = 00000101 & 11111011 = 00000001, the right most set bit of 5 is 0001.
Another example:
n = 12, -n = -12
n & -n = 00001100 & 11110100 =0100, as you can see the right most set bit of 12 is 0100
*/
				//  5原码:00000101     5的反码:00000101   5的补码:00000101   
//负数是补码表示的 // -5原码:10000101    -5的反码:11111010  -5的补码:11111011  
//正数负数都是补码表示:正数原码反码补码都一样，负数补码为反码+1

// 16原码:00010000     16的反码:00010000   16的补码:00010000   
//-16原码:10010000    -16的反码:11101111  -16的补码:11110000
// 16&(-16) == 16
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



找单身狗 single number III 只有两个单身狗，其他都是一对对的。

```c++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return nums;
        int t = 0;
        for(auto n : nums) t ^= n;   //t就是最后单身狗xor的结果
        t = t & (-t);   // 看上面， 找到最右边那位，，单身狗不一样，异或的结果显然大于0，所以某位不同的就是他们的区别，当然可能有很多位不同，我们找到最右边一位来标记。把单身狗分开来。
        vector<int> re{0,0};
        for(auto n : nums){
            if(n & t) re[0]^=n;   //分开两个单身狗即可。
            else re[1]^=n;
        }
        return re;
    }
};
```



