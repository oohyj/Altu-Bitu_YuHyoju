#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> parents;
vector<int> cost;

int friendshipCost(int n){
    int sum =0;
    for(int i = 1; i<=n; i++){
        if(parents[i]<0){ //루트 노드면 친구해야함
            sum += cost[i];
        }
    }
    return sum;
}

int findParent(int x){
    if(parents[x] < 0){
        return x;
    }
    return parents[x] = findParent(parents[x]);
}

void unionFind(int x , int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp){ //이미 같은 집합에 있는 경우
        return;
    }

    if(cost[xp] > cost[yp]){ //xp의 cost값을 더 작게 만들기
        swap(xp , yp);
    }

    parents[yp] = xp;

}


/*
 * 루트 노드와 친구가 되면 다른 친구랑은 다 친구가 되니까 루트 노드랑 친구가 되는 값만 구하면 됨
 * */
int main(){
    int n , m , k , a , x , y;

    cin >> n >> m >> k;

    parents.assign(n+1 , -1);
    cost.resize(n+1);


    for(int i = 1; i<= n; i++){
        cin >> a;
        cost[i] =a;
    }

    while(m--){
        cin >> x >> y;
        unionFind(x , y);
    }

    int ans = friendshipCost(n);

    cout << (ans <= k ? to_string(ans) : "Oh no"); //삼항 연산자 사용 시 자료형 맞춰야 함

    return 0;
}
