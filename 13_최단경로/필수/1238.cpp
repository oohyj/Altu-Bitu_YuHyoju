#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int , int> ci; //다익스트라는 인접리스트 & 큐를 사용
const int INF = 1e5; // n * 가중치의 최댓값

//다익스트라
vector<int> dijkstra(int start ,  int n , vector<vector<ci> > &graph){
    vector<int> dist(n+1 , INF); //각 정점까지의 최단 경로 저장
    //현재 탐색하는 중간 정점까지의 최단 경로
    priority_queue<ci , vector<ci>, greater<ci> > pq; //first : 시작점으로부터의 거리 , second : 정점

    //시작 정점 초기화
    dist[start] =0;
    pq.push(make_pair(0, start));//자기 자신은 가중치 0으로 초기화
    while(!pq.empty()){
        int weight = pq.top().first; //현재 정점까지의 경로값
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]){ //더 작은 값이라면 그대로 진행
            continue;
        }
        for(int i =0; i< graph[node].size(); i++){
            int next_node = graph[node][i].first; // 연결된 정점
            //시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값
            int next_weight = weight + graph[node][i].second;
            if(next_weight < dist[next_node]){ //새로운 값이 이전 값보다 작다면
                dist[next_node] = next_weight; // 값 갱신
                pq.push(make_pair(next_weight, next_node));
            }
        }
    }
    return dist;
}

// 각 마을에서 파티 마을로 가는 최솟값
int allToX(vector<int> dist , int x){ //최솟값을 담은 배열 , 파티 마을
    return dist[x];
}

int main() {
    int n, m, x; //마을 개수 , 도로 개수 , 모이는 마을 번호
    int a, b, w; // 시작점 , 끝점 , 가중치
    cin >> n >> m >> x;
    vector<vector<ci> > graph(n + 1, vector<ci>(0)); // 인접 리스트
    while (m--) {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
    }

    //연산
    // 두 개를 구해야함 각 마을에서 x번 마을로의 값 , x번 마을에서 각 마을로의 값
    vector<int> distXtoAll= dijkstra(x, n, graph); //x에서 각 마을로의 값

    // 각 마을에서 x로의 값을 담을 벡터
    for(int i =1; i<=n; i++){
        if(i == x){
            continue;
        }
        vector<int> distAlltoX = dijkstra(i , n , graph);
        distXtoAll[i] += distAlltoX[x];
    }


    sort(distXtoAll.begin() , distXtoAll.end());

    cout << distXtoAll[n-1] << "\n";


}