#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int startingnum, endingnum, flag=0, count=0,sum=0;
    cout<<"Enter Starting Number:";
    cin>>startingnum;
    cout<<"Enter Ending Number:";
    cin>>endingnum;
    for(int num = startingnum; num <= endingnum; num++) {
    if(num<=1){
        flag=1;
    }else{
        flag = 0;
        for(int i=2; i<=sqrt(num); i++){
            if(num%i==0){
            flag=1;
            break;
            }
            }
         }if(flag == 0) {
            sum=sum+num;
            cout <<num<<endl;
            count++;
            
        }
        
    }
    cout << "Total Prime Numbers = " << count<<endl;
    cout << "Total Sum of Numbers = " << sum;
}
