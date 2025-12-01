#include<iostream>
#include <cmath>
using namespace std;
int main(){
    int num, flag=0, i;
    cout<<"Enter a number:";
    cin>>num;
    if(num<=1){
        flag=1;
    }
    for(i=2; i<= sqrt(num); i++){
        if(num%i == 0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<num<<" is a prime number"<<endl;
    }else{
        cout<<num<<" is not a prime number"<<endl;
    }
}