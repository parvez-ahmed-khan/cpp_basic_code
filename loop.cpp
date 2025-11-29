#include<iostream>
using namespace std;
int main(){
    int n;
    int sum=0;
    cout<<"Enter a number:";
    cin>>n;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    cout<<"Sum of " <<n<<" is:" <<sum<<endl;
}