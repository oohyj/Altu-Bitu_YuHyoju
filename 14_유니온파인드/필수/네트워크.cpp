#include <string>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node){
    if(parent[node] <0){
        return node;
    }
    return parent[node] = findParent(parent[node]); // 그래프 압축
}

void unionInput(int x , int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp){
        return;
    }

    if(parent[xp] <parent[yp]){
        swap(xp , yp);
    }

    parent[yp] += parent[xp];
    parent[xp] = yp;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    parent.assign(n , -1);
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(computers[i][j] == 1){ //연결되어있으면
                unionInput(i , j);
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(parent[i] <0){
            answer++;
        }
    }

    return answer;
}
