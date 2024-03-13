#include <iostream>

using namespace std;

//최대공약수 구하기
int getGcd(int a, int b) {
    if (b == 0) return a;
    return getGcd(b, a % b);
}

//최소공배수
int getLcd(int a , int b){
    int gcd = getGcd(a,b);
    return (a*b)/ gcd;
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
    int gcd = getGcd(lcd , sum);

    sum = sum /gcd;
    lcd = lcd /gcd;


    cout << sum << " "<< lcd << "\n";

    return 0;
}

