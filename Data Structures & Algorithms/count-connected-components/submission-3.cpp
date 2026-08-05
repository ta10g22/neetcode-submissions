class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj_list;
        unordered_set<int> visited;
        int count = 0;

        //initialize adjacency list
        for(int i = 0; i < n; i++){
            adj_list[i] = {};
        }
        
        //build adjacency list
        for(int i = 0; i < edges.size(); i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        
        //lambda function for dfs()
        function<void(int)> dfs = [&](int i){
            //case to exit recursion
            if(i >= n){
                return;
            }
            visited.insert(i);

            for(int j = 0; j < adj_list[i].size(); j++){
                if(visited.contains(adj_list[i][j])){
                    continue;
                }
                else{
                    dfs(adj_list[i][j]);
                }
            }
        };

        //check each node has been visited if not dfs
        for(int i = 0; i < n; i++){
            if(visited.contains(i) == false){
                count += 1;
                dfs(i);
            }
        }

        return count;
    }
};
