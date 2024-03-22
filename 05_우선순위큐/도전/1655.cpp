#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 최대 힙과 최소 힙의 top값이 개수를 기준으로 저장했기때문에 잘못 저장되었을 수도 있으니까 균형 맞춰주기
void balance(priority_queue<int> &max_heap , priority_queue<int, vector<int>, greater<int> > &min_heap){
   int M = max_heap.top();
   int m = min_heap.top();

   //최대 힙의 top보다 최소 힙의 top이 작으면 바꿔주기 <- 입력으로 들어온 숫자가 짝수 개면 더 작은 걸 출력해야해서
   if(M>m){
       max_heap.pop();
       min_heap.pop();

       max_heap.push(m);
       min_heap.push(M);
   }

   return;

}

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

    for(int i =0; i<input.size(); i++){
        if(max_heap.size()> min_heap.size()){
            min_heap.push(input[i]);
        }
        else {
            max_heap.push(input[i]);
        }

        //최대 힙과 최소 힙 둘 다 원소가 존재할 때 균형을 맞춤
        if(!max_heap.empty() && !min_heap.empty()){
            balance(max_heap,min_heap);
        }

        results.push_back(max_heap.top());
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
