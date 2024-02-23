#include <iostream>
#include <map>

using namespace std;

int main(){
    //입력
    int t , n;
    cin >> t;
    string outfit, outfit_type;

    while(t--){
        cin >> n;
        map <string , int> clothes;
        int answer =1;

        while(n--){
            cin >> outfit >> outfit_type;
            clothes[outfit_type]++; // 해당하는 종류의 옷 개수 +1
        }

        for(auto iter = clothes.begin(); iter != clothes.end(); iter++){
            answer *= (iter -> second +1); // 해당하는 종류의 옷 개수 + 안입는 경우
        }

        answer--; //알몸인 경우

        cout << answer <<'\n';
    }
    return 0;
}