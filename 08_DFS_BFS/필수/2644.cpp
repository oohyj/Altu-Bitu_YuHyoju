#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n , x , y ,m ;
    cin >> n >> x >> y >> m;

    vector<vector <int> > line(n+1,vector<int>(n+1));
    vector<int> visited_bfs(n+1,0);
    queue <int> q;
    int count =0; // 촌수

    for(int i =0; i<m; i++){
        int a , b;
        cin >> a >> b;
        line[a][b] =1;
        line[b][a] =1;
    }

    q.push(x);
    visited_bfs[x] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(int i = 1; i<=n; i++){
            if(line[node][i] ==1 && !visited_bfs[i]){
                visited_bfs[i] = visited_bfs[node]+1;
                q.push(i);
            }
        }

    }
    count = visited_bfs[y] - visited_bfs[x];
    if(visited_bfs[y] == 0){
        count = -1;
    }
    cout << count <<"\n";

    return 0;
}
