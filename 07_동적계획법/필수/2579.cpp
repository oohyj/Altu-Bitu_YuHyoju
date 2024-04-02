#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n , a; // 계단 개수
    cin >> n;
    vector<int> stair(n+1); // 계단별 점수 저장
    vector<int> dp(301,0);
    //시작점
    stair.push_back(0);

    for(int i =1; i<=n; i++){
        cin >> a;
        stair[i] = a;
    }

    dp[1] = stair[1];
    dp[2] = stair[1]+stair[2];

    for(int i =3; i<=n; i++){
        dp[i] = max(dp[i-3]+stair[i-1]+stair[i] , dp[i-2]+stair[i]);
    }

    cout << dp[n]<<"\n";

    return 0;
}
