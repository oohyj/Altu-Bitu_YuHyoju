#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std ;


int main(){
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	int count; //포함된 문자열의 수
	string input;
	map<string, int> arr; //key: 문자열 , value: 번호
	
	//입력
	cin >> n >>m;
	
	for(int i =1; i<=n; i++){
	    cin >> input;
	    arr[input] =i;
	}
	
	//출력
	while(m--){
	    cin >> input;
	    if(arr[input]){
	        count++;
	    }
	}
	
	cout << count <<'\n';
	
    return 0;
}