#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int alpha = 26;

vector<char> palindrome(char name[] , int size){
    //문자 개수 담을 배열
    int freq[alpha] ={0,};
    vector <char> result;
    int temp; //문자열 재배치할 때 쓸 변수
    int index;
    //알파벳 개수 세기
    for(int i =0; i < size; i++){
        freq[name[i] -'A']++;
    }

    int odd=0 , even =0;

    for(int i =0; i<alpha; i++){
        //짝수 개인 경우
        if((freq[i]%2)==0 && freq[i] !=0){
            even++;
        }
        else if((freq[i]%2)!=0 && freq[i] !=0){
            index = i; //해당하는 인덱스 저장하기
            freq[i]--; //일단 1을 빼서 짝수 개로 만들어주기
            odd++;
        }
    }

    //홀수 개가 1개거나 0개이면 펠린드롬
    if(odd == 1){
        for(int i =0; i<alpha; i++) {
            if (freq[i] % 2 == 0 && freq[i] != 0) {
                //짝수 개라면
                temp = freq[i] / 2;
                while (temp--) {
                    result.push_back(i + 'A');
                }
            }
        }
        result.push_back(index+'A');
        //여기까지 절반 채웠고 이제 나머지 채움
        for(int i = result.size()-2; i>=0; i--){
            result.push_back(result[i]);
        }
    }
    else if(odd == 0){
        //홀수 개인 알파벳이 없다면
        for(int i =0; i<alpha; i++){
            if(freq[i]%2 ==0 && freq[i] !=0){
                //짝수 개라면
                temp = freq[i]/2;
                while(temp--){
                    result.push_back(i+'A');
                }
            }
        }
        for(int i = result.size()-1; i>=0; i--){
            result.push_back(result[i]);
        }
    }

    return result;
}

int main(){
    //입력
    string s;
    vector<char> result;
    cin >> s;
    //연산
    char name[s.size()];
    strcpy(name, s.c_str());
    result = palindrome(name , s.size());
    //출력
    if(result.size() ==0 ){
        cout <<"I'm Sorry Hansoo";
    }
    else{
        for(int i =0; i<result.size(); i++){
            cout << result[i];
        }
    }

    return 0;
}
