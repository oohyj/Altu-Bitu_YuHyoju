#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> cal(string a , string b){

    int raise=0;
    int rest =0;
    stack <int> sum;
    int temp_sum =0;

    reverse(a.begin(), a.end());
    reverse(b.begin(),b.end());

    int max_length= max(a.size(), b.size());
    a.resize(max_length, '0');
    b.resize(max_length, '0');

    for(int i =0; i< a.size(); i++){
        temp_sum = (a[i]-'0')+(b[i]-'0')+raise;
        raise = temp_sum /10;
        rest = temp_sum % 10;
        sum.push(rest);
    }

    if(raise > 0) sum.push(raise);

    return sum;
}

int main(){

    string a ,  b;

    stack<int> sum ;
    cin >> a >> b;
    sum = cal(a,b);

    while(!sum.empty()){
        cout << sum.top();
        sum.pop();
    }

    cout << "\n";

    return 0;
}
