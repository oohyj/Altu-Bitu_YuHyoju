#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<bool> cycle; // cycle[i] = i번 정점이 속한 집합에 사이클이 있는가

//결과 출력 함수
void printResult(int tc , int cnt){
    cout << "Case " << tc << ": ";
    switch(cnt){
        case 0:
            cout << "No trees.\n";
            break;
        case 1:
            cout << "There is one tree.\n";
            break;
        default:
            cout << "A forest of " << cnt << " trees.\n";
            break;
    }
}

int cntTree(int n){
    int cnt =0;
    for(int i =1; i<=n; i++){

        if(parent[i] < 0 && !cycle[i]){ //루트 정점인데 사이클도 없을 때
            cnt++;
        }
    }
    return cnt;
}
//Find 연산
int findParent(int node){
    if(parent[node] < 0){ //값이 음수면 루트 정점
        return node;
    }
    return parent[node] = findParent(parent[node]); //node 부모의 부모를 찾아줌 어차피 루트 노드를 저장할 것이기 때문에
}

//Union 연산
void unionInput(int x , int y){
    int xp = findParent(x); //x의 루트 노드
    int yp = findParent(y); //y의 루트 노트

    if(xp == yp){ // 이미 같은 집합에 있는 경우
        cycle[xp] = true; // 합치려고 했는데 이미 같이 있는 경우라면 cycle이 만들어짐
        return;
    }

    if(cycle[xp] || cycle[yp]){ //서로 다른 집합이지만 , 하나라도 사이클이 있는 집합이라면
        cycle[xp] = cycle[yp] =true;
    }

    if(parent[xp] < parent[yp]){ //루트 노드는 음수 값을 가지기 때문에 큰 값을 작을 수록 큰 값을 가지는 것이다.
        swap(xp , yp);//여기서는 합집합을 만들 때 yp를 루트 노드로 힘
    }

    parent[yp] += parent[xp]; //둘 다 음수 값이기 때문에
    parent[xp] = yp;

}

int main(){
    int n , m , a, b;
    int tc =0;

    while(cin >> n >> m){
        if(n ==0 && m == 0){
            break; // 종료 조건
        }

        //초기화
        tc++; // 테스트케이스 개수 출력을 위해
        parent.assign(n+1 , -1);
        cycle.assign(n+1 , false);

        while(m--){
            cin >> a >> b;
            //유니온
            unionInput(a, b);
        }
        printResult(tc , cntTree(n));
    }

    return 0;
}

