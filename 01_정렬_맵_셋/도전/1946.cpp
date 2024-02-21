#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> ci; // pair를 first,second 둘 다 int형으로 정의, first와 second에 다른 자료형 넣어도 됨

int maxEmploy(vector<ci> candidates){
    //이미 오름차순으로 정렬했으니까 서류 심사 1등은 무조건 합격
    int count =1 , highest_rank= candidates[0].second;
    //i번째 사람은 0 ~(i-1)번째 사람보다 무조건 서류심사 순위가 낮으니까 면접 순위가 앞의 사람들보다 더 높아야함
    for(int i =1; i<candidates.size(); i++){
        if(candidates[i].second < highest_rank){ //이전 사람보다 면접 순위가 높은 경우
            highest_rank = candidates[i].second; //가장 높은 면접 순위 갱신 ( 더 성적이 좋은 걸로)
            count++; //합격자 추가
        }
    }

    return count;
}

int main(){

    int t , n , count;
    //입력 , 테스트케이스 개수
    cin >> t;
    while(t--){
        cin >> n;
        vector<ci> candidates (n , ci(0,0));
        for(int i =0; i < n ; i++){
            cin >> candidates[i].first >> candidates[i].second; //first는 서류심사 순위 , second는 면접심사 순위
        }
        //서류심사 순위를 오름차순으로 정렬
        sort(candidates.begin(), candidates.end());
        count = maxEmploy(candidates);
        //출력
        cout << count << '\n';
    }
    return 0;
}