#include<iostream>
using namespace std;
int main(){
    int mark;
    cout<<"Enter your marks:"<<endl;
    cin>>mark;
    if(mark<101){
            if(mark >= 80){
                cout<<"A+";
            }else if(mark >= 70){
                cout<<"A";
            }else if(mark >= 60){
                cout<<"B";
            }else if(mark >= 50){
                cout<<"C";
            }else if(mark >= 40){
                cout<<"D";
            }else{
                cout<<"Fail";
            }
    }else{
        cout<<"Invalid marks"<<endl;
    }

}