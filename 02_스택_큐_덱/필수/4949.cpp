#include <iostream>
#include <stack>


using namespace std;

int main(){


    while(true){

        char a[100];
        stack<char> s;
        cin.getline(a,100);
        if(a[0] == '.') break;

        for(int i =0; i< 100; i++){
            if(a[i] == '(' || a[i] =='[') s.push(a[i]);
            else if(a[i] == ')'){
                if(!s.empty() && s.top() == '(') s.pop();
                else {
                    s.push(a[i]);
                    break;
                }
            }
            else if(a[i] == ']'){
                if(!s.empty() && s.top() =='[') s.pop();
                else {
                    s.push(a[i]);
                    break;
                }
            }
        }
        if (s.empty()) cout<< "yes"<<"\n";
        else cout <<"no" <<"\n";
    }


    return 0;
}

