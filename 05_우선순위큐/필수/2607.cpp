#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

const int alpha = 26;

//알파벳 개수 차이
int diffCharCount(vector<char>& word , char input[] ,int compare_size){
    int standard[alpha] ={0,}; //기준 단어에서 알파벳 개수
    int compare[alpha] = {0,}; //비교할 단어에서 알파벳 개수
    int diff_count =0;
    // 기준 단어에서 알파벳 개수 세기
    for (int i =0; i< word.size(); i++){
        standard[(int)(word[i]-65)]++;
    }
    // 비교할 단어에서 알파벳 개수 세기
    for (int j =0; j<compare_size; j++){
        compare[(int)(input[j]-65)]++;
    }
    //개수가 다른 알파벳 개수
    for(int k =0; k < alpha; k++){
        // 특정 알파벳이 등장하는 횟수가 다르다면
       if(standard[k]!=compare[k]){
           diff_count += abs(standard[k]- compare[k]);
       }
    }
   return diff_count;
}

//비슷한 단어인지 찾는 함수
bool isSimilar(vector<char> word , string s){
    int diff_char =0;

    char compare_word[s.length()];
    strcpy(compare_word , s.c_str());

    int word_size = word.size();
    int compare_size = s.length();

    diff_char = diffCharCount(word,compare_word,compare_size);

    //단어 길이가 같다면
    if(word_size == compare_size){

        //같은 문자열의 개수가 같거나 하나 차이 날 경우
        if(diff_char <= 2) {
            return 1;
        }
        else return 0;
    }
        //단어 길이가 같지 않다면
    else{
        //단어 길이 차이가 2 이상이라면
        if(abs(word_size-compare_size)>1){
            return 0;
        }
            //단어 길이가 1 이하라면
        else{
            if(diff_char > 1){
                return 0;
            }
            else return 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //단어의 개수 , 비슷한 단어 개수
    int n , count =0;
    string s_word , s_input;
    //첫번째 단어 담을 배열
    vector<char> word;
    //비교할 단어 담을 배열
    vector<string> inputs;

    cin >> n;
    cin >> s_word;

    for(int i =0; i<s_word.length(); i++){
        word.push_back(s_word[i]);
    }

    n-=1;

    //연산
    while(n--){
       cin >> s_input;
       inputs.push_back(s_input);
    }

    for(int i =0; i<inputs.size(); i++){
        if(isSimilar(word,inputs[i])){
            count++;
        }
    }

    //출력
    cout << count <<"\n";
    return 0;
}


