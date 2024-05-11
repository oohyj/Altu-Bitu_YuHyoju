#include <iostream>
#include <vector>

using namespace std;

int N, M; //굴다리 길이 , 가로등의 개수
vector<int> light; // 가로등을 설치할 수 있는 가로등의 위치
int ans; // 가로등의 최소 높이

/***
 * 굴다리 전체를 비추는지 탐색
 */
bool check(int length){ //가로등의 높이 매개변수로 받기
    if(light[0] > length){ //가로등의 높이가 처음 가로등을 놓을 수 있는 위치보다 작다면 어두운 부분이 생김
        return false; //false 리턴
    }
    for(int i = 1; i< M ; i++){ //0번은 검사해서 처음으로 위치한 가로등으로 앞쪽을 다 밝힐 수 있다면 그 다음부터 탐색
        if(light[i] - light[i-1] > 2 * length){ //가로등 사이의 거리가 가로등 높이의 두 배보다 크다면
            return false; // 굴다리에서 어두운 곳이 생기므로 false 리턴
        }
    }

    if(N - light[M-1] > length){ //마지막 가로등에서 굴다리 끝까지의 거리가 가로등의 높이보다 크다면
        return false; //어두운 부분이 생김 false 리턴
    }

    return true; // 위의 경우에 해당하지 않으면 해당 높이는 조건에 충족함
}
/**
 * 모든 길을 비출 수 있는 가로등의 최소 높이 찾기 : 이분탐색
 * */
void binarySearch(){
    //초기화
    int start;
    int end = N;//가로등이 비추는 거리의 최댓값
    int mid = (start + end) / 2; // 중간값

    while(start <= end){ //start가 end보다 작은 경우에는 연산
        //mid의 높이로 모든 길을 비출 수 있다면
        if(check(mid)){ // mid에 해당하는 높이로 가로수의 모든 길을 비출 수 있다면
            ans = mid; // 답은 해당하는 mid가 되고
            end = mid -1; // 최솟값을 구해야 하니까 더 짧은 높이로도 가능한지 탐색
        }
        else{ // mid에 해당하는 길이로 가로수를 모두 비출 수 없다면
            start = mid +1; // 최소 길이를 더 늘려서 탐색
        }
        mid = (start + end) / 2; // start와 end 값 중 하나는 바뀌었으니 mid값 갱신
    }
}

int main(){
    //입력
    cin >> N >> M;
    light.resize(M);
    for(int i = 0; i< M ; i++){
        cin >> light[i];
    }
    //연산
    binarySearch();
    //출력
    cout << ans;


    return 0;
}