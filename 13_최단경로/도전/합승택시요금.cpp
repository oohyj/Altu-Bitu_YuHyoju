#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e7 * 2; //n의 최댓값 * 가중치 최댓값

//fares 배열은 한 방향만 제시해준다고 했으므로 다시 그래프를 만들어야 함
vector<vector<int>> makeGraph(int n , vector<vector<int>> &fares){
    vector<vector<int>> graph(n+1 , vector<int> (n+1 , INF));
    for(int i = 1; i<=n; i++){
        graph[i][i] =0;
    }

    for(int i =0; i<fares.size(); i++){
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    return graph;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    vector<vector <int> > graph = makeGraph(n ,fares);

    for(int k =1; k<=n ; k++){ //중간지점
        for(int i =1; i<=n; i++){ //시작지점
            for(int j =1; j<=n; j++){ //종점
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j],cost);
            }
        }
    }

    int answer = INF;

    //합승은 도착지 말고 모든 지점까지 가능함
    for(int i = 1 ; i<=n ; i++){ // i는 중간지점
        int cost_A = graph[i][a];
        int cost_B = graph[i][b];
        int total_cost = graph[s][i] + cost_A + cost_B;
        answer = min(answer , total_cost);
    }

    return answer;
}
