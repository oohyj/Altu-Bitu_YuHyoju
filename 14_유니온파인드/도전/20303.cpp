#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int , int> ci;

vector<ci> parent; //first : 해당 집합 아이들 수 , second : 사탕 총합


int findParent(int node){
    if(parent[node].first < 0){
        return node;
    }
    return parent[node].first = findParent(parent[node].first);
}

void unionInput(int x , int y){
    int xp = findParent(x);
    int yp = findParent(y);

    if(xp == yp){
        return;
    }

    if(parent[xp].first < parent[yp].first){
        swap(xp , yp);
    }

    parent[yp].first += parent[xp].first; //아이의 수 더하기
    parent[yp].second += parent[xp].second; // 사탕의 수 더하기 , 루트 노드로 모든 사탕이 모임
    parent[xp].first = yp;
}

int knapsack(int n , int k){
    vector<ci> collected; // first : 아이들의 수 , second : 사탕 총합
    for(int i =1; i<=n; i++){
        if(parent[i].first < 0){ //루트 노드인 경우
            collected.push_back(make_pair(-parent[i].first, parent[i].second)); //각집
        }
    }

    vector<int> dp(k,0); //1부터 k-1까지 뺏을 수 있는 초콜릿 수


    for(int i =0; i< collected.size(); i++){
        for(int j = k-1; j >= collected[i].first; j--){
            dp[j] = max(dp[j] , dp[j - collected[i].first] + collected[i].second);
        }
    }

    return dp[k-1]; // k명 울려버리면 안됨
}


int main(){

    int n , m , k , x , y;
    cin >> n >> m >> k;

    parent.assign(n+1 , make_pair(-1,0));

    for(int i = 1; i<= n; i++){
        cin >> parent[i].second;
    }

    while(m--){
        cin >> x >> y;
        unionInput(x , y);
    }

    cout << knapsack(n ,k) <<'\n';

    return 0;
}


