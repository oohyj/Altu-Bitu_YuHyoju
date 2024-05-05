#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > matrix; //2차원 배열 정의
const int SIZE =20, EMPTY =0; // 바둑판은 1~19까지 있으니까 크기는 20 , 만약 바둑판에 바둑이 없으면 0

const int dx[] =  {-1, 0, 1, 1}; //행 이동
const int dy[] = {1,1,1,0}; //열 이동

bool isValid(matrix &board , int x , int y ,int color){
    // 흰 , 검 바둑 모두 바둑판을 벗어나면 안되며 해당 바둑이 주어진 바둑 색과 일치해야함
    return (x > 0 && x < SIZE && y >0 && y < SIZE && board[x][y] == color);
}

bool checkWin( matrix &board , int x, int y){
    int color = board[x][y]; //기준 색
    // idx =0인 경우는 / , 1인 경우는 - , 2인 경우는 \ , 3인 경우는 |을 나타낸다
    for(int idx =0; idx <4 ; idx++){
        int cnt =1; //첫 바둑 개수 세기
        int prev_x = x-dx[idx] , prev_y = y - dy[idx]; //4가지 방향
        int next_x = x+dx[idx] , next_y = y+ dy[idx]; //4가지 방향
        // 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 계속함
        if(isValid(board , prev_x , prev_y, color)){
            continue;
        }
        // 같은 방향으로 바둑이 놓여졌으며 그 바둑의 개수가 6 미만이라면 계속 해서 다음 바둑의 위치를 옮김
        while(isValid(board , next_x , next_y , color) && cnt < 6){
            next_x += dx[idx];
            next_y += dy[idx];
            cnt++;
        }
        // 바둑의 개수가 5에 도달했으면 true 반환
        if(cnt == 5 ){
            return true;
        }
    }
    // 아닌 경우는 모두 false 반환
    return false;
}



int main(){
    //입력
    matrix board(SIZE , vector<int>(SIZE,0));
    for(int i =1; i< SIZE; i++){
        for(int j =1; j<SIZE; j++){
            cin >> board[i][j];
        }
    }

    for(int y =1; y< SIZE; y++){
        for(int x =1; x<SIZE; x++){
            if(board[x][y] == EMPTY){
                continue; // 바둑이 없는 상태라면 다음 칸으로 이동
            }
            if(checkWin(board, x,y)){ //만약 해당 칸을 기준으로 오목이 완성되면 true 출력 , 해당 위치 출력
                cout << board[x][y] <<'\n' << x << ' ' << y;
                return 0;
            }
        }
    }
    //아닌 경우 0 출력
    cout << 0;

    return 0;
}


