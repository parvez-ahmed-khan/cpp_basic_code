#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
int main(){
    float num1, num2, sum, sub, mod, multiply;
    double div;
    cout<<"Enter Two Numbers:";
    cin>>num1>>num2;
    cout<<showpoint;
    cout<<fixed;
    cout<<setprecision(2);
    sum=num1 + num2;
    cout<<setw(15)<<"Sum is:"<<sum<<endl;
    sub=num1 - num2;
    cout<<setw(15)<<"Sub is:"<<sub<<endl;
    div=(float)num1 / num2; //Type Casting
    cout<<setw(15)<<"Div is:"<<div<<endl;
   // mod=num1 % num2;
   // cout<<"Mod is:"<<mod<<endl;
    cout<<noshowpoint;
    multiply=num1 * num2;
    cout<<setw(15)<<"Multiply is:"<<multiply<<endl;
    getch();
    return 0;
}