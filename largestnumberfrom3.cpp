#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter Three Numbers:"<<endl;
    cin>>a>>b>>c;
    if(a>b && a>c){
        cout<<a<<" is the largest number"<<endl;
    }else if(b>a && b>c){
        cout<<b<<" is the largest number"<<endl;
    }else{
        cout<<c<<" is the largest number"<<endl;
    }

}