class Solution {
public:
    
    int res = 1e5;
    
    void bfs(int src, vector<vector<int>>& graph, vector<int> & vec, vector<pair<int,int>> & value){
        
        vector<int> visited(graph.size());
        
        queue<vector<int>> q;
        q.push({src, 0, -1}); // node, level, parent
        visited[src] = true;
        value[src].first = 0;
        
        
        while(!q.empty()){
            
            auto p = q.front(); q.pop();
            int u = p[0], level = p[1], parent = p[2];
            
            for(auto v : graph[u]){
                if(!visited[v] && !vec[v]){
                    visited[v] = true; value[v].first = level + 1;
                    q.push({v, level + 1, u});
                }
                else if(v != parent){
                    int val = level + 1;
                    if(val > value[v].first && val < value[v].second){
                        value[v].second = val;
                    }
                    else if(val < value[v].first){
                        value[v].second = value[v].first; value[v].first = val;
                    }
                    
                    res = min(res, value[v].second + value[v].first);
                }
            }
        }
        
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto & e : edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> vec(n); // bery bery important
        
        for(int i = 0; i<n; i++){
            vector<pair<int,int>> value(n, {1e5, 1e5});
            bfs(i, graph, vec, value);
            vec[i] = 1;
        }
        
        return (res == 1e5 ? -1 : res) ;
    }
};