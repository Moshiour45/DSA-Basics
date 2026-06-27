# include<bits/stdc++.h>
# include<ext/pb_ds/assoc_container.hpp>
# include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
# define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define endl '\n'

vector<char> ways = {'U', 'D', 'L', 'R'};
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
int n, m;

// 'A', 'B' and '.' are valid paths in the grid
bool isValid(int x, int y, vector<vector<char>>& grid){
    return((x >= 0 and x < n and y >= 0 and y < m) and grid[x][y] != '#');
}

// Standar BFS in the grid from A
void bfs(pair<int,int> root, vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& parent){
    queue<pair<int,int>> q;
    q.push(root);
    visited[root.first][root.second] = true;
    while(!q.empty()){
        pair<int,int> node = q.front();
        int x = node.first;
        int y = node.second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = dir[i].first;
            int dy = dir[i].second;
            if(isValid(x + dx, y + dy, grid)){
                if(!visited[x + dx][y + dy]){
                    q.push({x + dx, y + dy});
                    visited[x + dx][y + dy] = true;
                    parent[x + dx][y + dy] = i;
                }
            }
        }
    }
}

void pathConstruction(pair<int, int> start, pair<int, int> end, vector<vector<int>>& parent){
    if(parent[end.first][end.second] == -1 and start != end){
        cout << "NO" << endl;
        return;
    }
    
    pair<int,int> node = end;
    vector<char> path;
    while(node != start){
        int index = parent[node.first][node.second];
        path.push_back(ways[index]);
        int dx = dir[index].first;
        int dy = dir[index].second;
        node.first -= dx;
        node.second -= dy;
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    for(auto u : path){
        cout << u;
    }
    cout << endl;
}

int main(){
    optimize();
    
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(auto &u : grid){
        for(auto & v : u){
            cin >> v;
        }
    }
    pair<int,int> start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                start = {i, j};
            }
            if(grid[i][j] == 'B'){
                end = {i, j};
            }
        }
    }
    vector<vector<int>> parent(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bfs(start, grid, visited, parent);
    pathConstruction(start, end, parent);
   
    
    return 0;
}

// Problem: Labyrinth (https://cses.fi/problemset/task/1193)