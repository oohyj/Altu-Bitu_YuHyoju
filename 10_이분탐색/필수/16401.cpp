#include <iostream>
#include <vector>

using namespace std;

#define MAX_COOKIE 1000000000 //쿠키의 최대 길이

int binarySearch(int m , vector<int> &cookie){
    int right = MAX_COOKIE; //과자의 최대 길이
    int left  = 1; //쿠키의 최소 길이
    int res = 0; //막대 과자의 최대 길이

    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 0; // 해당 길이로 몇 명에게 나눠줄 수 과자 개수
        //mid 길이만큼 나눠주면 몇 명에게 나눠줄 수 있는지 세기
        for(int i =0; i< cookie.size(); i++){ //주어진 과자를 모두 탐색
            cnt += cookie[i]/mid; // 주어진 과자 길이로 나올 수 있는 과자 개수 세기
        }
        if(cnt >= m){ // 만약 조카 수보다 과자 개수가 크다면
            left = mid +1; // 과자 길이를 더 크게 해서 탐색하기
            res = mid; // mid 길이로는 일단 조카의 수를 만족하니까 res를 mid로
        }
        else {//mid 길이로 나눠줄 수 있는 과자의 개수가 조카 수보다 작다면
            right = mid - 1; //과자 길이를 더 작게해서 다시
        }

    }
    return res; //나눠줄 수 있는 최대 과자 길이
}

int main(){
    int m , n; // m: 조카 수 , n : 과자 개수
    //입력
    cin >> m >> n;
    vector<int> cookie(n); //주어진 과자 길이 담을 배열

    for(int i = 0; i< n; i++){
        cin >> cookie[i];
    }
    //이분 탐색
    cout << binarySearch(m , cookie);

    return 0;
}
