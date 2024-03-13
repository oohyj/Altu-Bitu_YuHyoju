#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//에라토스테네스의 체
vector<bool> findPrime(int n){
    vector<bool> is_prime(n+1 , true); //소수 여부 저장
    is_prime[0] = is_prime[1] = false;
    for(int i =2 ; i*i <= n ; i++){
       if(is_prime[i]){
           for(int j =i*i; j<= n ; j += i){
               is_prime[j] = false;
           }
       }
    }
    return is_prime;
}

// b-a 값이 가장 큰 거 찾아서 출력
int findBigOne(int n , vector<bool> &is_prime){

    for(int i =3; i<= n/2; i+=2){
        if(is_prime[i] && is_prime[n-i]) {
            return i;
        }
    }
    //두 홀수 소수의 합으로 나타낼 수 없는 경우
    return 0;
}

int main(){

    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    vector<int> input;

    while(1){
        cin >> n;
        if(n == 0) break;
        else input.push_back(n);
    }

     int max_num = *max_element(input.begin(),input.end()); //*max_element는 범위 중에 가장 큰 값의 value를 반환함
     vector<bool> is_prime = findPrime(max_num); //가장 큰 값까지 소수 여부 먼저 구하기

    for(int i =0; i<input.size(); i++){
        int a = findBigOne(input[i],is_prime);

        //출력
        if(a !=0) {
            cout << input[i] << " = " << a <<" + "<< input[i]-a <<"\n";
        }
        else{
            cout << "Goldbach's conjecture is wrong.\n";
        }
        }

     return 0;
}
