#include <iostream>
#include <queue>

using namespace std;

int main(){
    //횟수 , a, 선물 가치
    int n , a , x;
    priority_queue<int> max_heap;

    cin >> n;

    while(n--){
        cin >> a;
        if(a==0){
            if(max_heap.empty()){
                cout << "-1\n";
            }
            else{
                cout << max_heap.top()<<"\n";
                max_heap.pop();
            }
        }
        else {
            while(a--){
                cin >> x;
                max_heap.push(x);
            }
        }
    }
    return 0;
}
