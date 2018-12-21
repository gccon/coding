priority_queue的用法：

priroty_queue里面的元素默认按照从小到大排，所以pop的时候，pop最后面的，最大的top的先出来

匿名函数的写法：

```c++
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {//出现前k次的字符串，次数相同时，字母序小的排后面，那么就先出来。
        map<string, int> m;
        for(auto w : words){
            m[w]++;
        }
        
       auto fuck = [](pair<string,int> a, pair<string, int> b) ->bool{return a.second == b.second? a.first > b.first : a.second < b.second;};
        priority_queue<pair<string, int>, vector<pair<string,int>>,  decltype(fuck)>  p(fuck);
        
        for(auto a : m){
            p.push(make_pair(a.first, a.second));
        }
        vector<string> re;
        while(k--){
            auto tmp = p.top();
            p.pop();
            re.push_back(tmp.first);
        }
        return re;
    }
};
```

 decltype 指定符

检查实体的声明类型或表达式的类型及值分类。



写比较函数的方法：

```c++
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

--------------------------------------------------------------------------
static bool heapComp(ListNode* a, ListNode* b) {   //static成员函数
        return a->val > b->val;
}
```

```c++
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;//大的在前面。
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue合并k个有序链表
    priority_queue<ListNode *, vector<ListNode *>, compare> q;
    for(auto l : lists) {
        if(l)  q.push(l);
    }
    if(q.empty())  return NULL;

    ListNode* result = q.top();
    q.pop();
    if(result->next) q.push(result->next);
    ListNode* tail = result;            
    while(!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;//每次合并一下//妙啊
        if(tail->next) q.push(tail->next);
    }
    return result;
}
```



```c++
static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
}
ListNode* mergeKLists(vector<ListNode*>& lists) { //make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    vector<ListNode*> v;   
    for(int i =0; i<lists.size(); i++){
        if(lists[i]) v.push_back(lists[i]);
    }
    make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

    while(v.size()>0){
        curNode->next=v.front();
        pop_heap(v.begin(), v.end(), heapComp); //调整堆
        v.pop_back(); 
        curNode = curNode->next;
        if(curNode->next) {
            v.push_back(curNode->next); 
            push_heap(v.begin(), v.end(), heapComp);
        }
    }
    return head.next;
}
```





vector<bool> 不是容器 ，注意避免使用：

```
做为一个STL容器，vector<bool>有两个问题．第一，它不是一个真正STL容器，第二，它并不保存bool类型．

首先vector< bool> 并不是一个通常意义上的vector容器，这个源自于历史遗留问题。 
早在C++98的时候，就有vector< bool>这个类型了，但是因为当时为了考虑到节省空间的想法，所以vector< bool>里面不是一个Byte一个Byte储存的，它是一个bit一个bit储存的！ 
因为没有直接去给一个bit来操作，所以用operator[]的时候，正常容器返回的应该是一个对应元素的引用，但是对于vector< bool>实际上访问的是一个”proxy reference”而不是一个”true reference”，返回的是”std::vector< bool>:reference”类型的对象。 
```

