#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> li; //톱니바퀴를 저장할 배열
vector<pair<int, int> > stack; //회전해야하는 톱니바퀴 저장
vector<int> visited; // 해당 톱니바퀴를 검사했는지 확인하는 배열

void check_rotation(int current_num, int current_dir) { //현재 기준이 되는 바퀴의 인덱스와 회전 방향
    //왼쪽을 검사하는 경우
    if (current_num - 1 >= 0 && visited[current_num - 1] == 0) {  // 가장 왼쪽인 경우 && 방문을 아직 안한 경우
        if (li[current_num][6] != li[current_num - 1][2]) { // 맞닿아 있는 면이 서로 다른 극인지 체크, 왼쪽 검사하는 경우 현재 톱니바퀴의 6번째 바퀴와 이전 톱니바퀴의 2번째 바퀴가 같지 않다면 돌릴 수 있음
            stack.push_back(make_pair(current_num - 1, current_dir * -1));  //돌릴 수 있으니까 해당 pair 를 저장
            visited[current_num - 1] = 1; //확인했다는 표시
            check_rotation(current_num - 1, current_dir * -1);//왼쪽 톱니바퀴를 기준으로 다시 검사
        }
    }
    if (current_num + 1 < li.size() && visited[current_num + 1] == 0) { //가장 오른쪽인 경우 && 방문을 아직 안한 경우
        if (li[current_num][2] != li[current_num + 1][6]) { // 맞닿아 있는 면이 서로 다른 극인지 체크, 현재 톱니바퀴의 2번째 바퀴와 오른쪽 톱니바퀴의 6번째 인덱스
            stack.push_back(make_pair(current_num + 1, current_dir * -1)); //돌릴 수 있으니까 해당 pair 저장
            visited[current_num + 1] = 1; //방문 표시
            check_rotation(current_num + 1, current_dir * -1); // 오른쪽 톱니바퀴를 기준으로 다시 검사
        }
    }
}

int main() {
    int t; //톱니바퀴 개수
    int k; //회전 횟수

    cin >> t; //톱니바퀴의 개수 T 입력

    li.resize(t); //톱니바퀴 개수만큼 resize
    for (int i = 0; i < t; ++i)
        cin >> li[i]; //톱니바퀴 상태 입력

    cin >> k; // 회전 횟수 K 입력
    for (int i = 0; i < k; ++i) { //k번 돌면서 회전할 수 있는지에 대해 체크
        int num, direction;//톱니바퀴 번호, 방향
        cin >> num >> direction; //방향 입력 (1이면 시계 방항, -1이면 반시계 방향)
        stack.clear(); //입력을 받고 즉각적을 처리하는 방식으로 하기때문에 배열 비워주기
        stack.push_back(make_pair(num - 1, direction)); //첫번째로 돌려야할 톱니바퀴를 짝으로 만들어서 저장해주 , 0번부터 저장해주니까 -1 해주기
        visited.assign(t, 0); //t개만큼 0을 초기화
        visited[num - 1] = 1;//방문 표시
        check_rotation(num - 1, direction);
        //내가 돌려야하는 톱니바퀴를 모두 갱신을 했다면
        while (!stack.empty()) { //stack 배열이 빌 때까지 톱니바퀴 돌려주기
            pair<int, int> top = stack.back(); //stack을 pair형태로 저장했으니까
            stack.pop_back(); //이전 거 pop해주기
            int tmp_num = top.first; //돌려야 할 톱니바퀴의 인덱스
            int tmp_dir = top.second; //돌릴 방향
            if (tmp_dir == 1) { //시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7); //7번 인덱스가 0번 인덱스가 되기때문에 제일 끝 값을 처음으로 붙여주고 7번을 제외 문자열을 그 뒤로 붙여주기
            } else { //반시계방향으로 돌리기
                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];//1번부터 6번까지 붙여주고 그 다음에 0번 인덱스 붙이기
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < t; ++i) { //톱니바퀴 개수 T개
        if (li[i][0] == '1') {
            cnt++; // 첫번째 인덱스 (0번)만 검사하면 됨
        }
    }

    cout << cnt << endl; //출력

    return 0;
}
