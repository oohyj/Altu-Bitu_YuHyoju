#include <iostream>
#include <vector>

using namespace std;

int n;
int infected (int num, vector<vector <int> >& line , vector<bool>& visited_dfs, vector<int>& stack){
    int ans =0;
    visited_dfs[num] = true; // 처음 노드 방문 표시
    stack.push_back(num);

    for (int i = 1; i <= n; i++) {
        if (line[num][i] == 1 && !visited_dfs[i]) {
            infected(i,line,visited_dfs, stack);
        }
    }

    for(int i =0; i<visited_dfs.size(); i++){
        if(visited_dfs[i] == true){
            ans++;
        }
    }
    return ans;
}

int main(){

    int m ;
    cin >> n >> m;

    vector<vector <int> > line(n+1, vector<int>(n+1)); // 간선 존재 여부
    vector<bool> visited_dfs(n+1 , false); //dfs 방문 여부
    vector<int> stack;

    for(int i =0; i<m; i++){
        int a , b;
        cin >> a >> b;
        line[a][b]=1;
        line[b][a]=1;
    }

    int count = infected(1, line, visited_dfs, stack);

    cout << count-1 <<"\n";

    return 0;
}
