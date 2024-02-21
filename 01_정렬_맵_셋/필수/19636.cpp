#include <iostream>
#include <cmath>

using namespace std ;


int main(){
    
    int weight,intake1, T, day, intake2, active;
    //intake1이 변하기 전 일일기초대사량 , 다이어트 이전 에너지 섭취량
    //intake2는 다이어트 기간 일일 에너지 섭취량 
    
    cin >> weight >> intake1 >> T;
    cin>> day >> intake2 >> active;
    
    int weight1 = weight;
    int weight2 = weight;
    
    //역치값 초과일때 , 변한 기초 대사량
    int after_basic = intake1;
    
    //체중 += 일일에너지섭취량 - (일일 기초 대사량 + 일일활동대사량)
    for(int i= 0; i< day; i++){
        weight1 += intake2 - (intake1 + active);
        weight2 += intake2 - (after_basic + active);
        if(abs(intake2 - (after_basic + active))>T){
            after_basic += floor((intake2 - (after_basic + active))/2 + 0.5);
        }
    }
    
    //다이어트 후 원래 일일에너지 섭취량과 일일 활동 대사량으로 돌아감
    //int after_diet = intake2 -(after_basic+active);
    
    //일일 기초 대사량 변화 고려 x
    if(weight1 <= 0){
        cout << "Danger Diet"<<"\n";
    }
    else cout << weight1 <<" " << intake1 << "\n";
    
    //일일 기초 대사량 변화 고려 
    if(weight2<=0 ||after_basic <=0){
         cout << "Danger Diet"<<"\n";
    }
    else if (intake1>after_basic ){
        cout << weight2 <<" "<<  after_basic << "  YOYO"<<"\n";
    }
    else {
        cout << weight2 << " " << after_basic<<" no"<<"\n";
    }
    
    return 0;
}
