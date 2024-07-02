#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map <ll , ll> parent;

/*
 * 투숙객이 원하는 방이 비어 있다면 방 배정
 * 방 배정 후, 해당 방의 다음 방을 집합의 루트 정점으로 설정 (다음 빈 방을 바로 찾을 수 있음)
 * 벡터로 parent를 선언하면 전체 방 개수(k)의 최대가 10^12이기 때문에 메모리 초과
 * 필요한 방의 parent 정보 저장을 위해 map 사용 (key: 방 번호, value: 문제의 조건 4를 만족하는 방의 번호)
 * 그냥 map 사용시 시간초과, 키 값을 정렬하지 않는 unordered_map (해쉬테이블 기반) 사용
 */

ll findParent(ll node){
    if(parent[node] == 0){
        parent[node] = node +1; //만약 아직 0이라면 +1한 값을 부모 값으로 설정
        return node;
    }

    return parent[node]  = findParent(parent[node]); //이전에 들어왔던 숫자가 다시 들어오면 이미 value에 부모노드 값이 지정되어있으니까 해당 부모노드의 부모노드 ,,, 이런 식으로 그래프 압출
}

vector<ll> assignRoom(vector<ll> room_number){
    vector<ll> answer;
    for(ll num : room_number){
        ll room = findParent(num);
        answer.push_back(room);
    }
    return answer;
}
vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer = assignRoom(room_number);
    return answer;
}
