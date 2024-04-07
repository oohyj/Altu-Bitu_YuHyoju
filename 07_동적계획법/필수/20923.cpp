#include<iostream>
#include<vector>
#include<deque>
using namespace std;

typedef vector<deque<int> > cards; //0: 도도 , 1: 수연
const int DO =0, SU = 1;

/**승리 판단하기*/
string judge(cards& deck){
    int do_deck = deck[DO].size() , su_deck = deck[SU].size();
    if(do_deck > su_deck){ // 도도의 덱 사이즈가 수연의 덱 사이즈보다 크다면
        return "DO"; //도도의 승리
    }
    else if(do_deck < su_deck){ //도도의 덱 사이즈가 수연의 덱 사이즈보다 작다면
        return "SU";  // 수연의 승리
    }
    return "dosu"; // 무승부
}
/**그라운드에서 덱으로 카드 옮기기*/
void groundToDeck(deque<int>& deck , deque<int>& ground){
    while(!ground.empty()){ //그라운드 카드가 없어질 때까지
        deck.push_back(ground.back()); // 그라운드의 카드를 뒤집고(back), 자신의 덱의 아래에 넣으니까 뒤로 넣어준다.
        ground.pop_back(); // 그라운드에서는 해당 카드를 없앤다
    }
}

/**종을 쳤을 때*/
void ringTheBell(int player , cards& deck , cards& ground){
    groundToDeck(deck[player], ground[!player]); //현재 종을 친 사람의 덱에 그라운드에 있는 상대방의 카드 더하기
    groundToDeck(deck[player], ground[player]); //현재 종을 친 사람의 그라운드 카드를 다시 본인 덱에 다 가져가기
}
/**종을 울릴 수 있는 사람 판단*/
int whoCanRingTheBell(cards& deck , cards& ground){
    if(!ground[DO].empty() && ground[DO].front() == 5){ //도도의 그라운드 카드가 비어있지 않고 도도가 낸 카드 중 가장 앞에 있는 게 5라면
        return DO; // 도도는 종을 울릴 수 있다
    }
    else if(!ground[SU].empty() && ground[SU].front() ==5){//수연의 그라운드 카드가 비어있지 않고 수연이가 낸 카드 중 가장 앞에 있는 카드가 5라면
        return DO; // 도도는 종을 울릴 수 있다
    }
    else if(!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front()+ground[SU].front() ==5)){
        return SU; // 도도와 수연의 그라운드 카드가 비어있지 않고 맨 위에 있는 카드 2장의 합이 5라면 수연이는 종을 울릴 수 있다.
    }
    return -1; // 아무도 종을 울릴 수 없음
}


/**게임 진행*/
string game(int m, cards& deck , cards& ground){
    bool turn = DO;// 도도 먼저
    while(m--){
        ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드), 덱의 맨 앞의 카드가 제일 위에 있는 카드이다.
        deck[turn].pop_front(); // 그라운드로 카드를 옮겼으니까 덱에서는 제거
        if(deck[turn].empty()){
            break; //제거하고 나서 만약 방금 차례였던 사람의 덱에 카드가 없으면 상대방이 이긴 것이므로 반복문 종료
        }

        int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
        if(bell != -1){ //도도나 수연이 종을 울릴 수 있으면
            ringTheBell(bell , deck , ground); // 카드를 그라운드에서 덱으로 옮긴 상황을 반환
        }
        turn = !turn; //차례 바꾸기
    }
    return judge(deck); // 승리 판단

}

/**
 * 도도 , 수연이 각각 덱과 그라운드를 가짐
 * 도도 -> 수연 -> 도도 -> 수연... 순으로 차례를 바꿔가면 게임 진행(game 함수)
 * 1. 카드를 덱에서 한 장 내려놓음
 * 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
 * 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell , groundToDeck 함수)
 * 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
 * */
int main(){

    int n , m , card1, card2; //카드의 개수 , 게임 진행 횟수, 도도 카드, 수연이 카드
    cards deck(2) , ground(2); //deque 자료형으로 0번은 도도 , 1번은 수연이 카드가 들어감

    //입력
    cin>> n>>m; // 카드 개수 , 게임 횟수
    while(n--){
        cin >> card1 >> card2; //순서대로 도도 카드 , 수연이 카드
        deck[DO].push_front(card1); //맨 아래 있는 카드부터 입력되니까 deque의 앞쪽으로 넣어주기
        deck[SU].push_front(card2);
    }
    //출력 & 연산
    cout << game(m, deck,ground);


    return 0;
}
