#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 500; // n의 최댓값

void floydWarshall(int n , vector<vector<int> > &graph){
    for(int k =1; k<=n ; k++){ //중간지점
        for(int i =1; i<=n; i++){ //시작지점
            for(int j =1; j<=n; j++){ //종점
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j],cost);
            }
        }
    }
}

//1번보다 5번의 키가 클 경우 , 1 -> 5 에 1
int main(){
    int n , m , a, b;
    int order =0;


    cin >> n >> m;

    vector<vector<int> > graph(n+1 , vector<int>(n+1 , INF));

    while(m--){
        cin >> a >> b;
        graph[a][b] = min(graph[a][b] , 1); // 1번의 비교
    }

    floydWarshall(n, graph);

    for(int i =1; i<=n; i++){
        int count =0;
        for(int j =1; j<=n; j++){
            if((0 < graph[i][j] && graph[i][j]< INF) || ( 0<graph[j][i] && graph[j][i] <INF)){
               count++;
            }

        }
        if(count == n-1){
            order++;
        }
    }

    cout << order << "\n";

    return 0;
}
