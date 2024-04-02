#include <iostream>

using namespace std;

int main(){
    int n,cmp;
    int a[1001], dp[1001];
    int max_idx =0;

    cin >> n;

    for(int i =0; i<n; i++){
        cin >> a[i];
        cmp = 0;

        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                cmp = max(dp[j], cmp);
            }
        }
        dp[i] = cmp +1;

        if(dp[i]>max_idx){
            max_idx = dp[i];
        }
    }

    cout << max_idx <<'\n';

    return 0;
}