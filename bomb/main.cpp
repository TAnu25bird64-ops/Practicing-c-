#include <iostream>
#include <string>
#include <vector>

using namespace std;

void input_grid(vector<string>& grid, int h, int w){
    for(int i = 0; i < h; i++){
        string gd_line;
        cin >> gd_line;
        if(gd_line.size() > w) break;

        grid[i] = gd_line;
    }
}

void display_grid(vector<string>& grid){
    int line = grid.size();
    for(int i = 0; i < line; i++){
        cout << grid[i] << endl;
    }
}

bool found_bomb(vector<string>& grid,int *x_bomb, int *y_bomb){
    int h = grid.size();
    int w = grid[0].size();

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == 'B'){
                 *x_bomb = i;
                 *y_bomb = j;
                 return true;
            }
        }
    }
    return false;
}

int count_bomb(vector<string>& grid){
    int cnt = 0;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 'B') cnt++;
        }
    }

    return cnt;
}

/*
＊dx,dy配列について
    [left,right,up,down]をそれぞれ割り当てている
*/

int bomb_dangerzone(vector<string>& grid, int bomb_len){
    int cnt = count_bomb(grid);
    int x_bomb = 0;
    int y_bomb = 0;

    if(!found_bomb(grid,&x_bomb,&y_bomb)) return -1;
    if(cnt != 1) return -2;

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};   

    grid[x_bomb][y_bomb] = '*';
    for(int dir = 0; dir < 4; dir++){
        for(int i = 1; i <= bomb_len; i++){
            int nx = x_bomb + dx[dir] * i;
            int ny = y_bomb + dy[dir] * i;

            if(nx >= grid.size() || nx < 0 || ny >= grid[0].size() || ny < 0) break;
            if(grid[nx][ny] == '#')    break;

            grid[nx][ny] = '*';
        }
    }
    return 0;
}

int main(void){
    int height   = 0;
    int wide     = 0;
    int bomb_len = 0;

    cin >> height >> wide >> bomb_len;

    if(height < 0 || height > 100 || wide < 0 || wide > 100){
        cout << "Error: Please input correct number.m(_ _)m" << endl;
        return -1;
    } 

    if(bomb_len < 0 || bomb_len > 10){
        cout << "Error: Please input correct number.m(_ _)m" << endl;
        return -1;
    } 

    vector<string> grid(height);
    input_grid(grid,height,wide);
    int find = bomb_dangerzone(grid,bomb_len);

    cout << endl;

    if(find == -1){
        cout << "bomb is none :)" << endl;
    }else if(find == -2){
        cout << "There are 2 or more bombs (T_T) " << endl;
    }else{
        display_grid(grid);
    }

    return 0;
}