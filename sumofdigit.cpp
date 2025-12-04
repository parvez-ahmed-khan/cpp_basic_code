#include<iostream>
using namespace std;
int main (){
    int n,sum=0,reminder,temp;
    cout<<"Enter a number:";
    cin>>n;
    temp=n;
    while(temp!=0){
        reminder=temp%10;
        sum=reminder+sum;
        temp=temp/10;
    }
    cout<<"Sum of " <<n<<" is:"<<sum<<endl;
}