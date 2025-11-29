#include<iostream>
#include <iomanip>
using namespace std;
int main(){
    int cel,b=32;
    double a=1.8, fer,celsius;
    cout<<"Enter Data:";
    cin>>cel;
    fer=a* cel+b;
    cout<<"Ferhanheit is:"<<fer<<endl;
    cout<<fixed;
    cout<<setprecision(2);

    celsius=(cel-b)/a;
    cout<<"Celsius is:"<<celsius;
    

}