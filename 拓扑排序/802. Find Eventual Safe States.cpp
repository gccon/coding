class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==0) return {};
        if(n==1){
            if(graph[0].size() == 0) return {0}; //只有一个节点0,没有边
            else return {};  
        }
        //有向图的拓扑排序，每条有向边要反过来，相当于从本来结束的点开始溯源，因为从可以结束的点往回溯，只要那些点不在环上，都是可以到达结束的点的
        //环上的边，反过来，还是环，所以不影响的。
        vector<vector<int>> vvi(n); //类似拓扑排序了
        vector<int> vi;
        queue<int> q;
        vector<int> indegree(n);
        for(int i = 0; i < n; i++){
            int m = graph[i].size();
            indegree[i] = m;
            if(m == 0) q.push(i);
            for(int j = 0; j < m; j++){
                vvi[graph[i][j]].push_back(i); //这里是把每条边反过来
            }
        }
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int t = q.front(); q.pop();
                vi.push_back(t);
                for(int a : vvi[t]){
                    indegree[a]--;
                    if(indegree[a] == 0) q.push(a);
                }
            }
        }
        sort(vi.begin(), vi.end());
        return vi;
    }
};