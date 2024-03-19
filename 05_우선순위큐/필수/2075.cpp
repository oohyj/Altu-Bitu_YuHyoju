#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    priority_queue<int, vector<int>, greater<int> > min_heap;

    cin >> n;

    for(int i =0; i< n*n; i++){
        if(min_heap.size() > n){
            min_heap.pop();
        }
        int x ;
        cin >> x;
        min_heap.push(x);
    }
    min_heap.pop();
    cout << min_heap.top();

    return 0;
}
