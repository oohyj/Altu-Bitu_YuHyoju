#include <iostream>

using namespace std;

int main(){

    //입력
    int n , x;
    int sum = 0, share =0;
    cin >> n;
    //연산
    while(n--){
        cin >> x;
        sum += x;
        share += x/2;
    }
    //출력
    if((sum%3)==0 && share >= (sum/3)){
        cout <<"YES";
    }
    else cout <<"NO";

    return 0;
}