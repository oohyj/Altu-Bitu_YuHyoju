#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//중간값 찾기
vector<int> findMid(vector<int> input){
    //최대힙
    priority_queue<int> max_heap;
    //최소힙
    priority_queue<int, vector<int>, greater<int> > min_heap;
    // 직전 값
    int prev, temp;

    // 결과 저장할 배열
    vector<int> results;

    for(int i =0; i< input.size(); i++){
        //첫 입력값이면
        if(i == 0){
          max_heap.push(input[i]); // 일단 최대힙에 넣기
          results.push_back(input[i]);
        }
        //직전 값보다 크거나 같을 경우
        else if(input[i] >= prev){
            //최소힙에 넣어주기
            min_heap.push(input[i]);
            //만약 최소힙 크기 - 최대힙 크기 차이가 2 이상이라면
            if((min_heap.size()-max_heap.size())>=2){
                temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
            }
            //i가 홀수이면 실제로 숫자 개수는 짝수 개
            if((i%2) !=0){
                //최소힙과 최대힙의 루트 값 중 작은 걸 결과값에 저장
                results.push_back(min(max_heap.top(),min_heap.top()));

            }
            else{ //i가 짝수일 때 실제로 숫자 개수는 홀수 개
                if(max_heap.size() > min_heap.size()) {
                    results.push_back(max_heap.top());
                }
                else {
                    results.push_back(min_heap.top());
                }
            }

        }
        else if(input[i] < prev){
            //직전 값보다 작은 경우 최대힙에 넣기
            max_heap.push(input[i]);
            //만약 최대힙 크기 - 최소힙 크기 차이가 2 이상이면
            if((max_heap.size()-min_heap.size())>=2){
                temp = max_heap.top();
                max_heap.pop();
                min_heap.push(temp);
            }

            //i가 홀수이면 실제로 숫자 개수는 짝수 개
            if((i%2) !=0){
                //최소힙과 최대힙의 루트 값 중 작은 걸 결과값에 저장
                results.push_back(min(max_heap.top(),min_heap.top()));
            }
            else{ //i가 짝수일 때 실제로 숫자 개수는 홀수 개
                if(max_heap.size() > min_heap.size()) {
                    results.push_back(max_heap.top());
                }
                else {
                    results.push_back(min_heap.top());
                }
            }
        }
        prev = input[i];

    }
    return results;
}



int main(){

    //입력
    int n , x;
    cin >> n;
    vector<int> input;
    vector<int> answer;
    while(n--){
        cin >> x;
        input.push_back(x);
    }
    //연산
    answer = findMid(input);
    //출력
    for(int i =0; i<answer.size(); i++){
        cout << answer[i] <<'\n';
    }

    return 0;
}
