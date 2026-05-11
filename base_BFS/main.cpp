#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void input_island(vector<string>& island, int w){
    for(int i = 0; i < island.size(); i++){
        string map_k;
        cin >> map_k;
        island[i] = map_k; 
    }
}

int bfs_island(vector<string>& island){
    int height = island.size();
    int wide   = island[0].size();

    queue<pair<int,int>> q;
    vector<vector<bool>> visited(height,vector<bool>(wide,false));

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int cnt = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < wide; j++){
            if(island[i][j] == '#' && !visited[i][j]){
                q.push({i,j});
                visited[i][j] = true;
                cnt++;

                while(!q.empty()){
                    auto[y_h,x_w] = q.front();
                    q.pop();

                    for(int k = 0; k < 4; k++){
                        int ny = y_h + dy[k];
                        int nx = x_w + dx[k];

                        if(ny < 0 || ny >= height || nx < 0 || nx >= wide) continue;
                        if(island[ny][nx] != '#') continue;
                        if(visited[ny][nx]) continue;

                        visited[ny][nx] = true;
                        q.push({ny,nx});
                        }
                    }
                }

            }
        }

    return cnt;
}

void display_island(vector<string>& island){
    for(int i = 0; i < island.size(); i++){
        cout << island[i] << endl;
    }
}

int main(void){
    int height = 0;
    int wide   = 0;

    cin >> height >> wide;

    vector<string> island(height);
    input_island(island,wide);
    int found_island = bfs_island(island);

    cout << found_island << endl;
    return 0;
}