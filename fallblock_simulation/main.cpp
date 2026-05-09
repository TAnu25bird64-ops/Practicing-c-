#include <iostream>
#include <vector>
#include <string>

using namespace std;

void input_grid(vector<string>& grid, int wid){
    int h = grid.size();

    for(int i = 0; i < h; i++){
        string dot;
        cin >> dot;
        if(dot.size() > wid) break;

        grid[i] = dot;
    }
}

void gravity_block(vector<string>& grid, int line,int column){
    int h = grid.size();
    
    if(line + 1 >= h) return;
    if(grid[line + 1][column] != '.') return;

    grid[line][column] = '.';
    grid[line + 1][column] = '#';

    gravity_block(grid, line + 1, column);
}

void find_block(vector<string>& grid){
    int h = grid.size();
    int w = grid[0].size();

    for(int i = h-1; i >= 0; i--){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '#') gravity_block(grid,i,j);
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
   
   cin >> height >> wide;
   vector<string> grid(height);

   input_grid(grid,wide);
   find_block(grid);

   cout << endl;
   display_grid(grid);

   return 0;
}