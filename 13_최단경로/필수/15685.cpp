//못 풀겎다
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100;

// 방향 : 우(0) , 상(1) , 좌(2) , 하(3)
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0};

// 1 x 1 정사각형 개수 계산
int cntSquares(vector<vector<bool> >& plane){
    int ans = 0;
    for(int i =0 ; i< SIZE; i++){
        for(int j =0; j< SIZE; j++) {
            if (plane[i][j] && plane[i+1][j] && plane[i][j+1] && plane[i+1][j+1]){
                ans++;
            }
        }
    }
    return ans;
}

//드래곤 커브 점 표시
void drawDragonCurve(vector<vector<bool> >& plane , int x , int y , int d , int g){
    vector<int> direct; // 방향 저장
    plane[y][x] = plane[y+dy[d]][x+dx[d]] = true; // 평면에 표시 (초기화)  , y와 x의 자리를 바꾼 이유는 문제에서 제시한 평면이 배열과 다르기 때문
    x += dx[d];
    y += dy[d];
    direct.push_back(d);
    while(g--){
        int size_d = direct.size();
        for(int j = size_d -1; j >= 0; j--){ // 방향 계산
            int next_d = (direct[j] +1) % 4;
            x += dx[next_d];
            y += dy[next_d];
            plane[y][x] = true;     //평면에 표시
            direct.push_back(next_d);
        }
    }
}

/*
 * 방향을 생각해야함
 * 규칙
 * 0세대 : 0
 * 1세대 : 0 1
 * 2세대 : 0 1 2 1
 * 3세대 : 0 1 2 1 2 3 2 1
 * 숫자는 방향을 의미함
 * **/

int main(){

    int n , x , y, d , g;
    vector<vector <bool> > plane(SIZE +1 , vector<bool>(SIZE + 1 , false)); //평면

    cin >> n;

    while(n--){
        cin >> x >> y >> d >> g;
        drawDragonCurve(plane , x , y, d, g);
    }

    cout << cntSquares(plane) << "\n";

    return 0;
}
