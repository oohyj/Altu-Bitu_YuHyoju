#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
typedef tuple <int , int , int> tp;

bool bellmanFord(int n , vector<tp>& edges){
    vector<int> dist(n+1 , 0); //보통 INF로 초기화하지만 여기에서는 거리 의미가 없으므로 0으로 초기화
    for(int i =1; i<=n; i++){
        bool flag = true; // 음의 사이클이 없는거임
        for(int j = 0; j< edges.size(); j++){
            // s->d인 간선의 가중치가 w
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);
            int next_weight = dist[s] +w;
            if(next_weight < dist[d]){ //가중치를 더한 값이 이전 값보다 작다면
                flag = false ; //값이 줄어들고 있는거임
                dist[d] = next_weight; // 줄어들었으니까 갱신해주기
                if(i == n){ //지점의 수를 다 돌았다면
                    return false;
                }
            }
        }
        if(flag){
            break;
        }
    }
    return true;
}
/**
 * 벨만포드는 출발점이 특정한 한 점일 때 가능한 알고리즘
 * 그러나 특정 정점 하나만 확인하면 해당 정점과 단절된 노드가 포함된 음수 사이클을 발견할 수 없음
 * 선택지가 2개가 있는데
 * 1) 모든 정점에 대해서 벨만포드 알고리즘을 돌려서 음수 사이클이 발생하는지 확인하거나
 * 2) cycle의 형성 유무에 대해서 생각해보는 방법 <- 이게 뭔 소리일까...?
 * 벨만 포드 알고리즘을 사용할 때 , 초깃값을 INF로 설정하는 이유는 단절된 경로를 배제시키고 , 어떤 지점까지의 거리를 구하기 위해서임
 * 그런데 지금 이 문제에서는 음의 사이클이 존재하느냐가 쟁점이므으로 초깃값을 INF가 아닌 다른 값으로 하여도 상관없음
 *
 *
 * */
int main(){
    int tc , n , m , w , s, e, t;
    cin >> tc;
    while(tc--){
        cin >> n >> m >> w;
        vector<tp> edges; // 간선 정보를 저장할 벡터

        while(m--){
            cin >> s >> e >> t;
            //무방향
            edges.push_back({s , e , t}); // 양의 값을 가지는 간선은 무방향
            edges.push_back({e ,s, t});
        }

        while(w--){ //웜홀은 방향이 있음
            cin >> s >> e >> t;

            edges.push_back({s ,e ,-t});
        }

        if(bellmanFord(n , edges)){
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }

    return 0;
