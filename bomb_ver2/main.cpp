#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct State{
    int x;
    int y;
    int t;
};

void input_grid(vector<string>& grid){
    int h = grid.size();
    for(int i = 0; i < h; i++){
        cin >> grid[i];
    }
}


void fire_sim(vector<string>& grid, int time){

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    queue<State> q;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 'F') q.push({j,i,0});
        }
    }


    while(!q.empty()){
        State s = q.front();
        q.pop();

        if(s.t == time) continue;
        for(int dir = 0; dir < 4; dir++){
            int ny = s.y + dy[dir];
            int nx = s.x + dx[dir];

            if(ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid[0].size()) continue;
            if(grid[ny][nx] == '#') continue;
            if(grid[ny][nx] == 'F') continue;

            grid[ny][nx] = 'F';
            q.push({nx,ny,s.t + 1});
        }
    }
}

void display_grid(vector<string>& grid){
    for(int i = 0; i < grid.size(); i++){
        cout << grid[i] << endl;
    }
}

int main(void){
    int height = 0;
    int wide   = 0;
    int time   = 0;

    cin >> height >> wide >> time;
    vector<string> grid(height);

    input_grid(grid);
    fire_sim(grid,time);
    cout << endl;
    display_grid(grid);

    return 0;

}