#include <iostream>
#include <string>

using namespace std;

//종말의 수 찾기
int findNum(int n){
    int endNum= 665;
    string temp;
    for(int i =0; i<n; i++){
        while(1){
            endNum ++;
            temp = to_string(endNum);
            if(temp.find("666") != -1) break;
        }
    }
    return endNum;
}
int main(){

    //입력
    int n;
    cin >> n;
    //연산
    int ans = findNum(n);
    //출력
    cout << ans <<"\n";
    return 0;
}
