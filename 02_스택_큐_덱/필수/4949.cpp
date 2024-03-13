#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string input){
    stack<char> s;

    for(int i =0; i<input.length(); i++) {
        char ch = input[i];

        switch (ch) {
            case '(':
            case '[':
                s.push(ch);
                break;

            case ')':
                if (s.empty() || s.top() != '(') {
                    return false;
                }
                s.pop();
                break;

            case ']':
                if (s.empty() || s.top() != '[') {
                    return false;
                }
                s.pop();
                break;
        }
    }
    return s.empty();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    string input;

    while(true){
        getline(cin, input);

        if(input =="."){
            break;
        }

        //연산 & 출력
        if(isBalanced(input)){
            cout <<"yes\n";
        }
        else {
            cout<<"no\n";
        }
    }

    return 0;
}

