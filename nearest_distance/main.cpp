#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void input_grid(vector<string>& grid){
    int h = grid.size();
    for(int i = 0; i < h; i++){
        cin >> grid[i];
    }
}

int bfs(vector<string>& grid){
    queue<pair<int,int>> coord;
    int h = grid.size();
    int w = grid[0].size();

    vector<vector<int>> dist(h,vector<int>(w,-1));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == 'S'){
                 coord.push({j,i});
                 dist[i][j] = 0;
            }
        }
    }

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    while(!coord.empty()){
       auto[x_s,y_s] = coord.front(); 
       coord.pop();

        for(int dir = 0; dir < 4; dir++){
            int ny = y_s + dy[dir];
            int nx = x_s + dx[dir];

            if(ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid[0].size()) continue;
            if(grid[ny][nx] == 'G') return dist[y_s][x_s] + 1;
            if(grid[ny][nx] == '#') continue;
            if(dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[y_s][x_s] + 1;
            coord.push({nx,ny});
        }

    }

    return -1;
}

int nearest_distance(vector<string>& grid){
    int distance = bfs(grid);
    return distance;
}

void display_grid(vector<string>& grid){
    for(int i = 0; i < grid.size(); i++){
        cout << grid[i] << endl;
    }
}

int main(void){
    int height = 0;
    int wide   = 0;

    cin >> height >> wide;
    vector<string> grid(height);
    input_grid(grid);
    int dis = nearest_distance(grid);
    cout << dis << endl;
    return 0;
}
