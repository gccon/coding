二分查找

STL里面的lower_bound和upper_bound ，返回迭代器

一个应用LIS，最长递增子序列，best ac代码

```c++
  int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        if (nums.size()==0) return 0;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); ++i){
            if (ans.back() < nums[i]) 
                ans.push_back(nums[i]);
            else{
                vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), nums[i]); //
                *it = nums[i];
            }
        }
        return ans.size();
    }
```



介绍：

在从小到大的排序数组中，

lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个***大于或等于*** num的数字，找到返回该数字的地址（迭代器），不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个***大于*** num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

```c++
int num[6]={1,2,4,7,15,34}; 
sort(num,num+6);                         //按从小到大排序 
int pos1=lower_bound(num,num+6,7)-num;   //返回数组中第一个大于或等于被查数的数的下标 pos1 = 3
int pos2=upper_bound(num,num+6,7)-num;   //返回数组中第一个大于被查数的值 pos2 = 4

```

```c++
// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n'; //输出3
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n'; //输出6

  return 0;
}
```





LIS我的实现：

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int p = 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            //while(!s.empty() && s.top() >= nums[i]) s.pop(); //用栈来维护一个递增数列，但不会是最长的。所以错误的
            //s.push(nums[i]);
            if(nums[i] > dp[p]){  //大于的时候直接添加到最后//等于的时候不用添加
                dp[++p] = nums[i];  
            }else if(nums[i] < dp[p]){
                //int j = p;
                //while(j >= 0 && dp[j] >= nums[i]) j--;  //dp[i] 表示维持长度为i时候的数组里面的最小值 这里要取到等号来
                int j = binary_search(dp, 0, p, nums[i]);
                dp[j] = nums[i]; //上一步可以改成二分查找提高效率 //lower_bound//第一个大于或者等于他的数字下标
            }
        }
        return p+1;
        
    }
    int binary_search(vector<int>& dp, int lbound, int rbound, int target){
        while(lbound <= rbound){
            int mid = lbound + (rbound-lbound)/2;
            if(dp[mid] >= target){  //这里要取到等号。否则报错，相当于lower_bound的实现
                rbound = mid - 1;
            }else{
                lbound = mid + 1;
            }
        }
        return lbound;
        
    }
};
```

