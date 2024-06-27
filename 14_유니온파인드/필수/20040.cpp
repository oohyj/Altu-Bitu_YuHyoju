#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findParent(int node){
    if(parent[node] < 0){
        return node;
    }
    return parent[node] = findParent(parent[node]); //그래프 압축
}

bool unionInput(int a , int b){

    int ap = findParent(a);
    int bp = findParent(b);

    if(ap == bp){
        return false;
    }

    if(parent[ap] <parent[bp]){
        swap(ap , bp);
    }
    parent[bp] += parent[ap];
    parent[ap] = bp;

    return true;
}


int main(){

    int n , m , a , b , count =0 ;

    cin >> n >> m;

    parent.assign(n , -1);

   for(int i =0; i<m; i++) {
       cin >> a >> b;
       if(!unionInput(a, b)){ //사이클이 없는 경우
           count = i+1;
           break;
       }
   }

    cout << count << '\n';
    return 0;
}
