# 图是否有环(Kahn算法和基于DFS求解法)

 拓扑排序是对**有向无环图(DAG)**进行排序，从而找到一个序列。该序列满足对于任意一对不同的顶点u,v∈V，若G中存在一条从u->v的边，则在此序列中u在v前面.
拓扑排序也可以用来判断一个有向图是否存在环。

  ### 有两种算法可以求得该序列：

 - Kahn算法
其实就是不断的寻找有向图中没有前驱(入度为0)的顶点，将之输出。然后从有向图中删除所有以此顶点为尾的弧。重复操作，直至图空，或者找不到没有前驱的顶点为止。该算法还可以判断有向图是否存在环(存在环的有向图肯定没有拓扑序列)，通过一个count记录找出的顶点个数，如果少于N则说明存在环使剩余的顶点的入度不为0。（indegree数组记录每个点的入度数）


 - 基于DFS的求解方法

算法导论对于该种方法讲述的比较详细，由于它用的单链表存边
思想基于：DFS时候，遇到u->v边，通过在DFS函数快退出时将结点加入到List中实现v在序列的位置始终在u的前面。反向序列即为所求的拓扑序列。（这篇博文有整理算法导论的拓扑排序部分）



判断有向图是否有环的方法：

1，拓扑排序： 方法如下：维护一个indegree数组，表示每个点的入度，维护一个与点相邻的点的集合vector<vector<int>>  即图的邻接表表示。貌似用***队列或者栈***都可以。

- 将所有没有前驱，即入度为0的点，入队列

- 对队列中所有点，pop之前，与其关联的点的度减一，若那个点的度变成0，那么入队列。不断重复这一步骤，同时用一个count计数

- count == N（顶点数)，true则无环， false则有环

  （上述的入队列的顺序或者出队列的就是有向图的其中一个拓扑排序）

  参考：[207. Course Schedule](https://leetcode.com/problems/course-schedule/description/)

  [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/description/)

  ```c++
  
  class Solution {
  public:
      //判断拓扑排序中是否有环路
      bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
          
          vector<vector<int>> vvi(numCourses);
          vector<int> indegree(numCourses, 0);
          for(auto a : prerequisites){
              vvi[a.second].push_back(a.first);
              indegree[a.first]++;
          }
          queue<int> qi;
          for(int i = 0; i < numCourses; i++){
              if(indegree[i] == 0)
                  qi.push(i);
          }
          if(qi.empty()) return false; //如果是空，则直接返回false
          vector<int> vi;
          while(!qi.empty()){
              int t = qi.front();
              qi.pop();
              vi.push_back(t);
              for(auto v : vvi[t]){
                  indegree[v]--;
                  if(indegree[v] == 0)
                      qi.push(v);
              }
          }
          if(vi.size() == numCourses) return true;
          else return false;
      }
  };
  ```
