#include <iostream>

using namespace std; //std 네임스페이스 지정

int main(){
    //입출력 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m , x, value =0; // 차례대로 연산의 수 , 피연산자 , 현재 집합 s
    string op ; //연산
    cin >> m; //연산의 수 입력
    while(m--){ //연산의 수 동안
        cin >> op; //연산 입력
        //피연산자 x가 있는 경우
        if(op =="all"){ //"all"이면
            for(int i=1; i<=20; i++){
                value = value|(1<<i); //1~20까 있어야하므로 한 칸 왼쪽으로 옮기고 or 연산
            }
        }
        else if(op =="empty"){  // "empty"면
            value =0;  //공집합으로 만들어줌
        }
        //피연산자가 있는 경우
        else{
            cin >> x; //피연산자를 입력받고
            if(op =="add"){ //"add"인 경우
                value = value | (1<<x); //"add"면 피연산자를 왼쪽으로 한 번 shift하고 or연산
            }
            else if (op == "remove"){ //"remove"인 경우
                value = value & ~(1<<x); //shift하고 not 연산으로 빼주기
            }
            else if (op =="check"){ //"check"인 경우
                if(value & (1<<x)){ //해당하는 피연산자가 이미 s에 있다면
                    cout << "1\n"; // 1을 출력
                }else{ //없는 경우
                    cout <<"0\n"; //0을 출력
                }
            }
            else if(op =="toggle"){ //"toggle"인 경우
                value =  value ^(1<<x); // 해당하는 피연산자 shift 해주고 x가 있다면 0을 반환하기때문에 사라지고 x가 없다면 1을 반환해서 추가됨
            }
        }
    }
    return 0;//종료
}
