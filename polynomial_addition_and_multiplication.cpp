#include<iostream>
#include "algorithms_for_execution.h"
using namespace std;

int main(){
    int check=1;
    while(check!=-1){
        cout<<endl;
        cout<<"To calculate the addition of two polynomials enter 1"<<endl;
        cout<<"To calculate the multiplication of two polynomials enter 2"<<endl;
        cout<<"To end the execution of the program enter -1"<<endl;
        cout<<"Enter your choice : ";
        cin>>check;
        if(check==-1){
            continue;
        }
        else if(check==1){
            polynomial* pe1=equation();
            polynomial* pe2=equation();
            polynomial* sum=addition(pe1,pe2);
            printPoly(sum);
        }
        else if(check==2){
            polynomial* pe1=equation();
            polynomial* pe2=equation();
            polynomial* prod=multiplication(pe1,pe2);
            printPoly(prod);
        }
        else{
            cout<<"Error : choose from the given options"<<endl;
        }
    }
}