#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
const int INF = 1e5 * 5;

vector<ll> bellmanFord(int n, int m, int start, vector<ti> &edges) {
    vector<ll> dist(n + 1, INF);
    dist[start] = 0; // 시작 위치 초기화

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if (dist[s] == INF) {
                continue; // 아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
            }
            ll next_weight = w + dist[s]; // 경로가 있다면 갱신
            if (dist[d] > next_weight) {
                if (i == n) {
                    return {INF + 1};
                }
                dist[d] = next_weight;
                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
    return dist;
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vector<ti> edges(m); // 간선 정보를 저장할 벡터(그래프의 관계보다는 간선 자체의 정보가 더 중요함)
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[i] = make_tuple(a, b, c); // make_tuple로 간선 정보를 추가
    }

    vector<ll> ans = bellmanFord(n, m, 1, edges);

    if (ans[0] == INF + 1) {
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        cout << ((ans[i] == INF) ? -1 : ans[i]) << '\n';
    }

    return 0;
}
