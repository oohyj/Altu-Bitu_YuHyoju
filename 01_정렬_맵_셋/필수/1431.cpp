#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std ;

bool comp(string a , string b){
    
    int aSum =0 , bSum =0;
    
    //string a와 string b의 길이 비교
    if(a.length()!= b.length()){
        return a.length()<b.length();
    }
    
    for(int i =0; i< a.length(); i++){
        if(isdigit(a[i])){
            aSum += a[i] - '0';
        }
    }
    
    for(int i =0; i<b.length(); i++){
        if(isdigit(b[i])){
            bSum += b[i] - '0';
        }
    }
    
    if(aSum != bSum){
        return aSum<bSum;
    }
    else return a<b;
    
}



int main(){
    
    int n;
    
    cin >>n;
    
    vector<string> serial(n);
    for(int i =0; i<n; i++){
        cin >> serial[i];
    }
    
    sort(serial.begin(), serial.end(),comp);
    
    for(int i =0; i<serial.size(); i++){
        cout <<serial[i] <<"\n";
    }
    
    return 0;
}