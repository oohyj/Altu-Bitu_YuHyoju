#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int , int> ci;
const int INF = 2e5; // 최대 V-1개의 간선을 지나게 됨 -> V*(가중치 최댓값)

//다익스트라
vector<int> dijkstra(int start , int v , vector<vector<ci> > &graph) {
    vector<int> dist(v + 1, INF); // 각 정점까지의 최단 경로 저장
    //현재 탐색하는 중간 정점까지의 최단 경로
    priority_queue<ci, vector<ci>, greater<ci> > pq; // first: 시작점으로부터 거리 , second : 정점

    dist[start] = 0; // 시작 노드 거리를 0으로 함
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int weight = pq.top().first; // 거리 , 가중치 값
        int node = pq.top().second; //현재 탐색하려는 정점
        pq.pop(); //현재 큐의 가장 상위에 있는 값을 시작으로 탐색을 시작함

        if(weight > dist[node]) { // 이미 더 작은 값으로 기록된 정점이라면
            continue; //넘어감
        }
        for(int i =0; i < graph[node].size(); i++){ //현재 정점에서 이어진 정점이 있는 경우동안
            int next_node = graph[node][i].first; //현재 정점과 연결된 정점
            // 시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값
            int next_weight = weight + graph[node][i].second; // 현재
            if(next_weight < dist[next_node]){
                dist[next_node] = next_weight;
                pq.push(make_pair(next_weight , next_node));
            }
        }
    }
    return dist;
}
int main(){
    int v , e , k , a, b, w;

    //입력
    cin >> v >> e >>k; //순서대로 정점 , 간선 , 시작 정점
    vector<vector<ci> > graph(v+1 , vector<ci>(0)); // 인접 리스트
    while(e--){
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b,w)); //방향 그래프 , a->b까지 가중치 w
    }

    //연산
    vector<int> dist = dijkstra(k , v, graph);

    //출력
    for(int i =1; i<=v; i++){
        if(dist[i] == INF){
            cout << "INF";
        }else{
            cout << dist[i];
        }
        cout << "\n";
    }

    return 0;
}


