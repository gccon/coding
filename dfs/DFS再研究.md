DFS再研究

40. [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/)


```c++
static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		sort(candidates.begin(), candidates.end());
		vector<int> prefix;
		getSub2(candidates, target, 0, prefix, ret);
		if (binary_search(candidates, target, 0)) ret.push_back({ target });

		return ret;
	}

private:
	bool binary_search(vector<int>& candidates, int target, int low) {
		int high = candidates.size() - 1;
		while (low <= high)
		{
			int mid = low + (high - low) / 2;
			if (candidates[mid] > target) high = mid - 1;
			else if (candidates[mid] < target) low = mid + 1;
			else return true;
		}
		return false;
	}
    
    void getSub2(vector<int>& candidates, int target, int startIndex, vector<int> prefix, vector<vector<int>> &ret) {

		int last_one = -1;
		int mid = target / 2;
		for (size_t i = startIndex; i < candidates.size(); i++)
		{
			if (last_one == candidates[i]) continue;
			if (mid < candidates[i]) break;
			int div = target - candidates[i];
			prefix.push_back(candidates[i]);
			if (binary_search(candidates, div, i + 1)) {
				prefix.push_back(div);
				ret.push_back(prefix);
				prefix.pop_back();
			}
			getSub2(candidates, div, i + 1, prefix, ret);
			prefix.pop_back();
			last_one = candidates[i];
		}

	}

};
```



```c++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = accumulate(candidates.begin(), candidates.end(), 0);
        int mi = *min_element(candidates.begin(), candidates.end());
        if(target < mi || target > sum) return {};
        
        //set<vector<int>> re;
        vector<int> cur;
        vector<vector<int>> vvi;
        dfs(candidates, vvi, cur, target, 0);
       
        //for(auto t : re) vvi.push_back(t);
        return vvi;
    }
    
    
    void dfs(vector<int>& A, vector<vector<int>>& re, vector<int>& cur, int target, int start){
        
        if(target < 0) return;
        if(target == 0){
            re.push_back(cur);
            return;
        }
        for(int i = start; i < A.size(); i++){ //(0)
            if(target < A[i]) continue;
            if(i > start && A[i] == A[i - 1]) continue;  //(1)这样保持同一深度的去掉 这一行是神来之笔，去除了重复的
            cur.push_back(A[i]);
            dfs(A, re, cur, target - A[i], i + 1); //（2）
            cur.pop_back();
        }
    }
};
/* 本题每个数只能使用一次，而且有重复数字，最后的结果不能用重复。 这是和conbination sum I的区别，
[10,1,2,7,6,1,5] 8  =====>[[1,1,6],[1,2,5],[1,7],[2,6]]
 不能是 [[1,1,6],[1,2,5],[1,7],[1,2,5],[1,7],[2,6]] // 两个1不是1个1，所以有重复 没有（1）那一行就会这样。
一个方法是用set，二是用（1）那里的去除同一深度的值，前提是数组sort过。这样就不会有重复。


如果（2）这里的i+1改成i，那么每个数可使用无数次，结果如下：最后结果也是不会有重复，因为有（1）那一行。
[[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,2],[1,1,1,1,2,2],[1,1,1,5],[1,1,2,2,2],[1,1,6],[1,2,5],[1,7],[2,2,2,2],[2,6]]

如果（0）那里start改成0，那么会有逆序倒过来的，最好不要改成那样。
*/
```

