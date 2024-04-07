#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

    int t, w; //자두가 떨어지는 시간(횟수) , 자두가 움직일 수 있는  횟수
    cin >> t >> w; //입력

    vector<int> plum(t+1); // 자두 위치 저장

    for(int i =1; i<=t; i++){
        cin >> plum[i];//자두 위치 입력
    }
    vector<vector<int> > dp(t+1 , vector<int>(w+1 , 0));//행은 자두 위치 , 열은 자두가 움직일 수 있는 힛수

    for(int i =1; i<=t; i++){
        if(plum[i] ==1){ // 첫번째 나무에서 자두가 떨어짐
            dp[i][0] = dp[i-1][0]+1;  // 처음에는 자두가 1위 위치에 있으므로 자두 +1
        }
        else{
            dp[i][0] = dp[i-1][0]; // 자두가 다른 위치(2)에 있어서 자두를 먹지 못함
        }

        for(int j =1; j<=w; j++){
            if(plum[i] ==2 && j%2 ==1){ //위치가 2개 밖에 없기 때문에 홀수 번 움직이면 2번 나무에 있는 상태
                dp[i][j] = max(dp[i-1][j-1] , dp[i-1][j])+1;//위치를 바꾸지 않거나 바꾸는 경우 중 dp값이 큰 걸 선택하고 1 더하기
            }
            else if(plum[i]==1 && j%2 ==0){//짝수 번 움직이면 1번 나무에 있는 상태 & 자두 나무가 1번인 상황
                dp[i][j] = max(dp[i-1][j-1] , dp[i-1][j])+1; // 위와 같이 위치를 바꾸지 않거나 바꾸는 경우 중 dp값이 큰 걸 선택하고 1 더하기
            }
            else{ //자두를 잡을 수 없는 경우
                dp[i][j] = max(dp[i-1][j-1] , dp[i-1][j]);
            }
        }
    }
    // t번째에서 자두가 자리를 몇 번 바꿔야 가장 큰 자두를 갖게 되는지 찾기
    cout << *max_element(dp[t].begin(), dp[t].end())<<'\n';
    return 0;
}