#include <iostream>
#include <algorithm>

using namespace std;

int getLcd(int a , int b){
    int gcd =0;

    for(int i = min(a,b); i > 0 ; i--){
        if(a % i ==0 && b % i ==0){
            gcd = i;
            return (a*b) / gcd;
        }
    }

    return  1;
}

//분자값 더하기
int addNum(int a_num ,int a_den,  int lcd){
    return a_num * (lcd /a_den);
}

int main(){

    int a_num , a_den , b_num , b_den;
    cin >> a_num >> a_den >> b_num >> b_den;

    //최소 공배수 구하기
    int lcd = getLcd(a_den, b_den);
    int sum = addNum(a_num,a_den,lcd) + addNum(b_num , b_den, lcd);

    cout << sum << " "<< lcd << "\n";

    return 0;
}
