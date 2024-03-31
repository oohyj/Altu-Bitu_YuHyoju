#include <iostream>
#include <vector>

using namespace std;

int main(){
    //입력
    long long n;
    long long x;
    vector<long long> speed;
    cin >> n;
    while(n--){
        cin >> x;
        speed.push_back(x);
    }
    //연산
    long long min =0;
    long long share; //정수배를 위한 몫
    for(int i = speed.size()-1 ; i>=0; i--){
        if(speed[i] >= min){
            min = speed[i];
        }
        else {
            //최솟값이 해당 속도 보다 큰 경우
            share = min / speed[i];
            min = speed[i]*(share+1);
        }
    }
    //출력
    cout << min;
    return 0;
}
