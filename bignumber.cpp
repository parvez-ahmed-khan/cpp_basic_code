#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter Two Number:"<<endl;
    cin>>a>>b;
    if(a>b){
        cout<<"Bigger number is:"<<a<<endl;
    }
    else if(b>a){
        cout<<"Bigger number is:"<<b<<endl;
    }
    else{
        cout<<"NumberS are same"<<endl;
    }
}