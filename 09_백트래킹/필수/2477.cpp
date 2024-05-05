#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a , b ;
int min_a, min_b; // 작은 사각형의 가로, 세로
vector<int> line; // 입력되는 변의 길이 담을 배열
int direction[6]; // 이동 방향을 담은 배열
bool turn_right = false; // 우회전 했는지 확인

void setSmall(int i , int b){
    min_a = b;
    min_b = line[i-1];
    turn_right = true;
}

/**
 * 임의의 한 점에서 반시계 방향으로 둘레가 주어짐 우회전 1번 할 때가 있고 아예 우회전이 없고 좌회전만 할 때가 있음
 * 남쪽(3) , 북쪽(4)이면 세로 길이 / 동쪽(1) , 서쪽(2)이면 가로 길이
 * */

int main(){

    int melon; // 넓이당 참외 개수
    int area; //넓이

    //입력
    cin >> melon;

    for(int i =0; i < 6; i++){
        cin >> a >> b;
        direction[i] = a; //현재 방향 저장
        line.push_back(b); // 입력된 변의 길이 값을 넣는 곳에 넣기
        if(a == 3 || a == 4){ // 남쪽이나 북쪽이 나오면
            if(a == 3 && direction[i-1] == 1){ //현재 방향이 남쪽인데 이전 방향이 동쪽이었다면 우회전
                //우회전 했으니까 현재 b값과 바로 직접 b 값이 빼야하는 세로 , 가로
                setSmall(i,b);
            }
            else if(a==4 && direction[i-1] == 2){ //현재 방향이 북쪽인데 이전 방향이 서쪽이면 우회전
                setSmall(i,b);
            }
        }
        else{ // 동쪽이나 서쪽인 경우
            if(a==2 && direction[i-1]==3){ //현재 방향이 서쪽이고 이전 방향이 남쪽이라면 우회전
                setSmall(i,b);
            }
            else if(a==1 && direction[i-1]==4){ // 현재 방향이 동쪽이고 이전 방향이 북쪽이면 우회전
                setSmall(i,b);
            }
        }
    }

    int max_a = max({line[0] , line[2] , line[4]});
    int max_b = max({line[1] , line[3] , line[5]});

    if(!(turn_right)){ //만약 우회전을 한번도 안하고 좌회전만 했다면
        area = (max_a * max_b) - (line[0] * line[line.size()-1]);
    }
    else{ //우회전 1번 했을 경우
        area = (max_a * max_b)- (min_a * min_b) ; // 넓이
    }

    int ans = area * melon;

    cout << ans <<"\n";

    return 0;

}