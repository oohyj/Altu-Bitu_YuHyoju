#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

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
        return;
    }

    if(parent[xp] < parent[yp]){ //루트 노드는 음수 값을 가지기 때문에 큰 값을 작을 수록 큰 값을 가지는 것이다.
        swap(xp , yp);//여기서는 합집합을 만들 때 yp를 루트 노드로 힘
    }

    parent[yp] += parent[xp]; //둘 다 음수 값이기 때문에
    parent[xp] = yp;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n , m , cmd , a , b;

    cin >> n >> m;
    parent.assign(n+1 , -1);
    while(m--){
        cin >> cmd >> a >> b;

        //연산
        if(!cmd){ // 0이면 합집합 ->유니온
            unionInput(a , b);
        }
        else{ //1이면 파인드
            if(findParent(a) == findParent(b)){ // 루트 노드가 같은 경우 , 같은 집합
                cout << "YES\n";
            }
            else{
                cout <<"NO\n";
            }
        }
    }

    return 0;
}
