#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findMaxLength(int m , int n , vector <int> snack){
    int max = 1; // 과자의 최대 길이
    int cnt = 0; // 과자 개수
    int a ;
    // 조카 수가 과자 개수보다 적은 경우
    if( n >= m ){
        a = n; //뒤에서부터 최대 길이 찾기
        max = snack[a - 1];

        while(max > 0 ) { // 줄 수 있는 과자 개수가 조카 수보다 작은 경우에만 while문 돌기

            for (int i = 0; i <= n; i++) {
                if (max <= snack[i]) { // 만약 과자 길이가 max 값보다 크면
                    cnt++; // 줄 수 있는 과자 개수가 늘어남
                }
            }
            if (cnt < m) { // 줄 수 있는 과자 개수가 조카 수보다 적으면
                a--;
                max = snack[a-1];
                cnt = 0;
            }
            else if(cnt == m){
                break;
            }
        }
    }
    else{ // 조카 수가 과자 개수보다 많은 경우
       a = n;
       max = snack[a-1]; // 가지고 있는 과자 개수 중에 가장 큰 값
       while(max > 0){ // 조카 수보다 과자 개수가 적은 상태에서
           for(int i =0; i <n ; i++){
               cnt += snack[i] / max ; // 하나에
           }
           if(cnt < m){ // 만약 만들 수 있는 과자 개수가 조카 수보다 작다면
               if((a-2) < 0){ //근데 a가 0보다 작아지게 되면
                   max = max-1; //max 값을 1씩 줄이기
                   cnt = 0;
               }
               else {
                   a--; // 더 작은 값을 max 값으로 만들기
                   max = snack[a - 1];
                   cnt = 0;// 개수 초기화
               }
           }
           else if(cnt == m){
               break;
           }
       }
    }
    return max;
}

int main(){

    int m , n , len;
    vector<int> snack;

    cin >> m >> n;
    for(int i =0; i<n; i++){
        cin >> len ;
        snack.push_back(len);
    }

    sort(snack.begin() , snack.end());

    cout << findMaxLength(m , n , snack) <<'\n';
    return 0;
}