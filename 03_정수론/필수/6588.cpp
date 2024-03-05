#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체
vector<bool> findPrime(int n){
    vector<bool> is_prime(n+1 , true); //소수 여부 저장
    is_prime[0] = is_prime[1] = false;
    for(int i =2 ; i*i <= n ; i++){
       if(is_prime[i]){
           for(int j =i*i; j<=n ; j += i){
               is_prime[j] = false;
           }
       }
    }
    return is_prime;
}

// b-a 값이 가장 큰 거 찾아서 출력
void findBigOne(vector<bool> is_prime){

    for(int i =2; i< is_prime.size(); i++){
        int rest = is_prime.size()-1 - i;
        if(is_prime[i] && is_prime[rest]) {
            cout << rest + i << " = " << i <<" + "<< rest <<"\n";
            return;
        }
    }
    //두 홀수 소수의 합으로 나타낼 수 없는 경우
    cout << "Goldbach's conjecture is wrong." << "\n";
    return;
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

    //에라토스테네스의 체로 소수 걸러내고 b-a가 가장 큰 것 찾아내기
    for(int i =0; i<input.size(); i++){
        vector<bool> is_prime = findPrime(input[i]);
        findBigOne(is_prime);
    }

    return 0;
}
