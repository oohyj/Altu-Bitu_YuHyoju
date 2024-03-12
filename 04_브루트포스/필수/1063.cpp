#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair < char,char> cc;

vector<cc> moving (string king , string stone , vector<string> &move){
    //왕의 자리 , 돌의 자리
    pair <int, int> k;
    k.first = int(king[0] -64); //first가 열
    k.second = king[1] -'0'; //second가 행

    pair <int , int> s;
    s.first = int(stone[0]-64); //first가 열
    s.second = stone[1] -'0';  //second가 행


    for(int i =0; i<move.size(); i++){
        int row =0 , column =0;

        if(move[i] =="R"){
           row = k.first+1;
           if(row >8) continue; //체스판 밖이면 넘어가기
           else if(row == s.first && k.second ==s.second) {
               //둘 다 안나가면 옮기기
               if((s.first+1) >8) continue;
               else {
                   s.first = s.first +1;
                   k.first = k.first +1;
               }
           }
           else k.first = k.first+1;
        }
        else if(move[i]=="L"){
            row = k.first -1;
            if(row < 1 ) continue;
            else if(row == s.first && k.second ==s.second) {
                //둘 다 안나가면 옮기기
                if((s.first-1) <1) continue;
                else {
                    s.first = s.first -1;
                    k.first = k.first -1;
                }
            }
            else k.first = k.first-1;

        }
        else if(move[i]=="B"){
            column = k.second -1;
            if(column<1) continue;
            else if(k.first == s.first && column ==s.second) {
                //둘 다 안나가면 옮기기
                if((s.second -1) <1) continue;
                else {
                    s.second = s.second -1;
                    k.second = k.second -1;
                }
            }
            else k.second = k.second -1;
        }
        else if(move[i]=="T"){
            column = k.second +1;
            if(column>8) continue;
            else if(k.first == s.first && column ==s.second) {
                 //둘 다 안나가면 옮기기
                if((s.second +1) >8) continue;
                else {
                    s.second = s.second +1;
                    k.second = k.second +1;
                }
            }
            else k.second = k.second +1;

        }
        else if(move[i]=="RT"){
            row = k.first+1;
            column = k.second +1;
            if( row >8 || column >8) continue;
            else if( row == s.first && column == s.second){
                if((s.first +1) >8 || (s.second+1) >8 ) continue; // 돌이 체스판 밖으로 나가는지 확인
                else { //둘 다 안나가면 옮기기
                    s.first = s.first+1;
                    k.first = k.first +1;
                    s.second = s.second +1;
                    k.second = k.second +1;
                }
            }
            else {
                k.first = k.first +1;
                k.second = k.second +1;
            }
        }
        else if(move[i]=="LT"){
            row = k.first-1;
            column = k.second +1;
            if( row <1 || column >8) continue;
            else if( row == s.first && column ==s.second){
                if((s.first -1) <1 || (s.second+1) >8 ) continue; // 돌이 체스판 밖으로 나가는지 확인
                else { //둘 다 안나가면 옮기기
                    s.first = s.first-1;
                    k.first = k.first -1;
                    s.second = s.second +1;
                    k.second = k.second +1;
                }
            }
            else {
                k.first = k.first -1;
                k.second = k.second +1;
            }
        }
        else if(move[i]=="RB"){
            row = k.first+1;
            column = k.second -1;
            if( row >8 || column <1) continue;
            else if( row == s.first && column ==s.second){
                if((s.first +1) >8 || (s.second-1) <1 ) continue; // 돌이 체스판 밖으로 나가는지 확인
                else { //둘 다 안나가면 옮기기
                    s.first = s.first+1;
                    k.first = k.first +1;
                    s.second = s.second -1;
                    k.second = k.second -1;
                }
            }
            else {
                k.first = k.first +1;
                k.second = k.second -1;
            }
        }
        else if(move[i]=="LB") {
            row = k.first-1;
            column = k.second -1;
            if( row <1 || column <1) continue;
            else if( row == s.first && column ==s.second){
                if((s.first -1) <1 || (s.second-1) <1 ) continue; // 돌이 체스판 밖으로 나가는지 확인
                else { //둘 다 안나가면 옮기기
                    s.first = s.first-1;
                    k.first = k.first -1;
                    s.second = s.second -1;
                    k.second = k.second -1;
                }
            }
            else {
                k.first = k.first -1;
                k.second = k.second -1;
            }

        }
    }
    //결과
    vector<cc> result(2);
    result[0].first = char(k.first+64);
    result[0].second = char(k.second+'0');
    result[1].first = char(s.first+64);
    result[1].second = char(s.second+'0');

    return result;
}

int main(){

    //입력
    string king , stone;
    int n;
    vector<string> move;
    string input;
    cin >> king >> stone >> n;
    while(n--){
        cin >> input;
        move.push_back(input);
    }
    //연산
    vector<cc> result = moving ( king ,stone , move);
    //출력
    for(int i =0; i<2; i++){
        cout << result[i].first<<result[i].second<<'\n';
    }

    return 0;
}
