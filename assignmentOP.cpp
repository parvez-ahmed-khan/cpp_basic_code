#include<iostream>
using namespace std;
int main(){
    int x=5, y=2;
    x+=5;
     cout<<x<<endl;
    x-=1;
     cout<<x<<endl;
    x+=y;
     cout<<x<<endl;
    x-=y;
     cout<<x<<endl;
    x*=3;
     cout<<x<<endl;
    x/=2;
     cout<<x<<endl;
    x%=5;
    cout<<x<<endl;
    x=x+y;
    cout<<x;
    return 0;
}