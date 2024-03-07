#include <iostream>
#include <vector>

using namespace std;  //std 네임스페이스 지정

typedef pair<int, char> ic; //int와 char로 이루어진 pair 자료형 선언
const int ALPHA = 26; // 바퀴에는 알파벳이 쓰여져있으므로 알파벳 개수 지정

//index부터 시계방향으로 바퀴에 적어놓은 알파벳 출력
string printWheel(int n, int index, vector<char>& wheel) {
    string ans = ""; //문자열 초기화
    //바퀴를 돌릴 때와 반대방향으로 출력
    for (int i = index + n; i > index; i--) { // index가 음수가 나올 수 있어서 index+n을 해주 index가 될 때까지 감소하는 형태
        ans += wheel[i % n]; // n을 더했기때문에 n을 넘어가니까 n 범위 안에 속할 수 있게 모듈러 연산
    }
    return ans; // 문자열 반환
}

//행운의 바퀴 반환
string makeWheel(int n, int k, vector<ic>& record) {
    vector<char> wheel(n, '?'); //바퀴의 모든 알파벳을 ?로 초기화 , 처음에는 결정되어있지 않으니까 ?로 초기화
    vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크

    int index = 0; //화살표가 가리키는 인덱스

    for (int i = 0; i < k; i++) {
        int s = record[i].first; //화살표가 가리키는 글자가 변하는 횟수
        char ch = record[i].second; //회전을 멈추었을 때 가리키던 글자

        index = (index + s) % n; //회전한 후 화살표가 가리키는 인덱스

        //해당 칸이 ch로 이미 채워져 있는 경우 넘어감
        if (wheel[index] == ch) { //화살표가 가리키는 글자가 이미 ch이면
            continue; // 다음으로 넘어감
        }

        //다른 글자로 채워져있거나 해당 글자가 이미 사용된 알파벳인 경우 ! 반환
        if (wheel[index] != '?' || is_available[ch - 'A']) { //아직 알파벳이 안채워져있거나 이미 사용된 알파벳인 경우
            return "!";  //행운의 바퀴가 아님
        }
        wheel[index] = ch; //해당 칸에 글자 적기
        is_available[ch - 'A'] = true; //해당 알파벳이 사용되었으므로 true로 변경
    }
    return printWheel(n, index, wheel); // 행운의 바퀴 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n, k; // 바퀴 칸의 수 n , 바퀴를 돌리는 횟수 k
    cin >> n >> k;  // 입력받기

    vector<ic> record(k); // 바퀴를 돌리는 횟수만큼 <int, char> 자료형의 입력을 받아야함
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second; // 순서대로 글자가 바뀐 횟수 , 화살표가 가리키는 알파벳
    }

    //연산 & 출력
    cout << makeWheel(n, k, record); //행운의 바퀴 반환

    return 0; //종료
}