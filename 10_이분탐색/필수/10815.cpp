#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch( int n  , int input , vector<int> &arr){
    int left =0;
    int right = n-1;
    int mid;

    while(left <= right){
        mid = (left + right) /2;
        if(arr[mid] == input){
            return 1;
        }
        else if(arr[mid] > input){
            right = mid -1;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , m , input;

    cin >> n;
    vector<int> arr(n,0);
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin() , arr.end());

    cin >> m;
    while(m--){
        cin >> input;

        cout << binarySearch(n, input , arr) << " ";
    }

    return 0;
}