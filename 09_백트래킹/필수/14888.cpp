#include <iostream>
#include <vector>

using namespace std;

int n;
long long max_ans = -1000000001,min_ans=1000000001;
vector<int> num;
vector<int> choose;
int cal[4] ={0,0,0,0}; //연산자 개수 저장


void figure(){

    int start = num[0]; // 첫 값 설정
    for(int i =1; i < n; i++){
        if(choose[i-1] == 0){ // 덧셈이면
           start += num[i];
        }
        else if(choose[i-1] == 1){ //뺄셈이면
            start -= num[i];
        }
        else if(choose[i-1] == 2){ // 곱셈이면
            start *= num[i];

        }
        else if(choose[i-1] ==3){ //나눗셈이면
            start /= num[i];
        }
    }

    if(start > max_ans){
        max_ans = start;
    }
    if(start < min_ans){
        min_ans = start;
    }

}


void findMinMax( int cnt){
    //재귀호출 종료
    if(cnt == n-1){
        figure();
        return;
    }
    for(int i =0; i<4;i++){
        //해당 연산자를 다 사용했다면
        if(cal[i]== 0){
            continue;
        }

        cal[i]--;
        choose.push_back(i);

        findMinMax( cnt+1);

        cal[i]++;
        choose.pop_back();

    }
}
/**
 * 연산자는 우선순위를 무시하고 앞에서부터 진행
 * 나눗셈은 정수 나눗셈으로만 몫을 취한다
 * 음수를 양수로 나눌 때는 양수로 바꾼뒤 그 몫을 음수로 바꾸기
 * */
int main(){

    int a;
    cin >> n;
    for(int i =0; i<n; i++){
        cin >> a;
        num.push_back(a);
    }
    for(int i =0; i<4; i++){
        cin >> cal[i];
    }

    findMinMax(0);

    cout<< max_ans << "\n" << min_ans <<"\n";
    return 0;
}
