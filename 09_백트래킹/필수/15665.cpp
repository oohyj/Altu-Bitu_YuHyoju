#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n,m;
vector<int> num; // 골라야하는 숫자
int sequence[7]; // 고른 숫자 저장용

void printSequence(){
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backTrack(int cnt){
    if(cnt == m){
        printSequence();
        return;
    }

    for(int i =0; i<num.size();i++){

        sequence[cnt] = num[i];

        backTrack(cnt +1);

    }
}

int main(){
    int a;

    cin >> n >> m;

    for(int i = 0; i< n; i++){
        cin >> a;
        if(find(num.begin(), num.end(), a) == num.end()) {//a가 존재하지 않으면
             num.push_back(a); // 벡터에 a 넣기
        }
    }

    sort(num.begin(), num.end());

    backTrack(0);

    return 0;
}
