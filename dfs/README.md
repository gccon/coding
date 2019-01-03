###  DFS

例题

1. [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/description/)



从jfk机场开始 找出能完成所有航程而且 字母序最小的序列 dfs的一个应用吧

best 代码（这个代码参考算法导论里面拓扑排序，的dfs解法，相当于到底之后才把airport放进去，最后还要把rst反过来。

```c++
class Solution {
public:
    //**important** dfs with a multiset to save neighbor airports in order.
    //time: O(ElogE), space: O(E); E is #itinerary
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> map;
        vector<string> rst;
        for (auto ticket : tickets) map[ticket.first].insert(ticket.second);
        visit("JFK", map, rst);
        reverse(rst.begin(), rst.end());
        return rst;
    }
    void visit(string airport, unordered_map<string, multiset<string>>& map, vector<string>& rst) {
        while (map[airport].size() != 0) {
            string next = *map[airport].begin();
            map[airport].erase(map[airport].begin());
            visit(next, map, rst);
        }
        rst.push_back(airport); //看起来类似后续遍历 
    }
};
```

我的代码：

```c++
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        set<string> ss;
        map<string, int> ma;
        vector<string> v_tmp, vs;
         vector<int> vi, re;
        for(auto v : tickets){
            ss.insert(v.first);
            ss.insert(v.second);
        }
        int p = 0;
        for(auto s : ss){
            v_tmp.push_back(s); 
            ma[s] = p++;   //每个机场代号对应一个0,1,2,3…… 
        }
        vector<vector<int>> vvi(p, vector<int>(p, 0)); //p个机场
        for(auto v : tickets){
            vvi[ma[v.first]][ma[v.second]]++;  //用矩阵来存储
        }
        
        int n = tickets.size() + 1;
        vi.push_back(ma["JFK"]);
        bool f = false;
        dfs(vvi, ma["JFK"], vi, n, re, f);
       
        for(auto i : re){
            vs.push_back(v_tmp[i]);
        }
        return vs;
    }
    
    void dfs(vector<vector<int>>& vvi, int start, vector<int>& vi, int n, vector<int>& re, bool& f){
        if(f) return;
        if(vi.size() == n){
            re = vi; 
            f = true;
            return;
        }
        for(int i = 0 ; i < vvi[start].size(); i++){
            if(vvi[start][i] > 0){
                vvi[start][i]--;
                vi.push_back(i);
                dfs(vvi, i, vi, n, re, f);
                vi.pop_back();
                vvi[start][i]++;  
            }
                
        }
    }
};
```

参考discuss改进了一下： 但速度还是更慢了 40ms

```c++
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
      
        unordered_map<string, set<string>> ma;
        unordered_map<string, int> record; 
       
       	for(auto v : tickets){
            ma[v.first].insert(v.second); 
            record[v.first + v.second]++; //这里很漂亮
        }
        vector<string> vs, re;
        int n = tickets.size() + 1;
        vs.push_back("JFK");
        bool f = false;
        dfs(ma, record, "JFK", vs, n, re, f);
        return re;
    }
    
    void dfs(unordered_map<string, set<string>>& ma, unordered_map<string, int>& record, string start, vector<string>& vs, int n, vector<string>& re, bool& f){
        if(f) return;
        if(vs.size() == n){
            re = vs; 
            f = true;
            return;
        }
        for(auto des : ma[start]){
            if(record.find(start + des) != record.end() && record[start + des] > 0){
                record[start + des]--;
                vs.push_back(des);
                dfs(ma, record, des, vs, n, re, f);
                vs.pop_back();
                record[start + des]++;  
            }
                
        }
    }
};
```



k老师的解法：

看dfs里面，有且仅有res.size==ans的时候，才会返回1， 其他时候都是0， 所以15行 那里0的时候相当于什么都没做。只有是1的时候才做了。做完了就return了。

![aa](https://raw.githubusercontent.com/gccon/coding/master/dfs/8.png)





DFS回溯的要点是注意不要往回走了，也就是走过的路不能重复走，否则陷入死循环，最后有个visit数组，标志下是否走过，走过了就不要走了