class Solution {
public: 
    bool validTree(int n, vector<vector<int>>& edges) {
        //if no nodes given
        if (n == 0){
            return true;
        }

        unordered_set<int> hashset;
        unordered_map<int, vector<int>> hashmap;
        //build hashmap for dfs
        for (int i ; i < n; i++){
            hashmap[i] = {};
        }

        for (int i ; i < edges.size(); i++){
            hashmap[edges[i][0]].push_back(edges[i][1]);
            hashmap[edges[i][1]].push_back(edges[i][0]);
        }

        //run dfs through hashmap value and mark places visted while also checking if has been visited
        function<bool(int, int)> dfs = [&](int i, int parent){

            //check if node has already been visited (cycle in graph)
            if(hashset.contains(i) == true){
                return false;
            }

            hashset.insert(i);
            for(int j =0; j < hashmap[i].size(); j++){
                if(hashmap[i][j] == parent){
                    continue;
                }
                if (dfs(hashmap[i][j], i) == false){
                    return false;
                }
            }

            //return true for the cycle check
            return true;
        };
        
        //call dfs lambda function
        if(dfs(0, -1) == false){
            return false;
        }
        
        return hashset.size() == n;
    }
};
