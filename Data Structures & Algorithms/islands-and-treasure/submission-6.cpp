#include <queue>

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //second solution with BFS (multi souce BFS)
        queue<pair<int, int>> q;
        int distance = 1;

        // loop through grid and store treasure chest in a queue
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        function<void(int,int)> bfs = [&](int i, int j){
            //check if not an inf square or out of bounds or 
            if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == - 1 || (grid[i][j] != (1<<31)-1)){
                return;
            }

            //set grid block to distance
            grid[i][j] = distance;

            //add to queue
            q.push({i,j});
        };

        //keep doing bfs till the queue is empty and 
        while (q.size() > 0){
            //loop through elements of the queue to run bfs
            int levelsize = q.size();
            for(int k = 0; k < levelsize; k++){
                auto [i, j] = q.front();
                q.pop();
                //top
                bfs(i-1,j);
                //right
                bfs(i,j+1);
                //bottom
                bfs(i+1,j);
                //left
                bfs(i,j-1);
            }
            distance +=1;
        }

    }   
};
