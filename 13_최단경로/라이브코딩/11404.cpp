#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF=1e7; // 최대 n-1개의 간선을 지나므로 n * (가중치의 최댓값)

//모든 정점 사이의 최단 경로르 구할 때는 플로이드-워셜을 사용해야함 , 플로이드-워셜은 dp 알고리즘이다.
void floydWarshall(int n , vector<vector<int> > &graph){
    for(int k = 1; k <=n; k++){ //중간정점
        for(int i =1; i<=n; i++){ //시작 정점
            for(int j =1; j<=n; j++){ //도착 정점
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j] , cost);
            }
        }
    }
}
int main(){
    int n , m , a ,b ,c;

    cin >> n >> m;
    vector<vector<int> > graph(n+1 , vector<int>(n+1 , INF));
    for(int i =1; i<=n; i++){
        graph[i][i] = 0;
    }
    while (m--){
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b] , c);
    }

    floydWarshall(n , graph);

    for(int i =1; i<=n; i++){
        for(int j =1 ; j<=n; j++){
            cout <<(graph[i][j] == INF? 0 : graph[i][j]) <<' ';
        }
        cout <<"\n";
    }

}
