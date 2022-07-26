#include<iostream>

using namespace std;

class polynomial{
public:
int coefficientOfVariable;
unsigned int degreeOfVariable;
polynomial* next;
polynomial(int data,int degree){
    this->coefficientOfVariable=data;
    this->degreeOfVariable=degree;
    this->next=NULL;
}
};

void makeNode(polynomial* &head,polynomial* &tail,int coefficient,int exponent){
    if(head==NULL){
    head=new polynomial(coefficient,exponent);
    tail=head;
    }
    else{
        polynomial* tmp=new polynomial(coefficient,exponent);
        tail->next=tmp;
        tail=tail->next;
    }
}

polynomial* equation(){
    int coefficientData;
    polynomial* head=NULL;
    polynomial* tail=NULL;
    int polynomialDegree;
    cout<<"Enter the degree of the polynomial equation : ";
    cin>>polynomialDegree;
    while(polynomialDegree>=0){
        cout<<"Enter the coefficient of x^"<<polynomialDegree<<" : ";
        cin>>coefficientData;
        if(coefficientData==0){
            polynomialDegree--;
            continue;
        }
        makeNode(head,tail,coefficientData,polynomialDegree);
        polynomialDegree--;
    }
    return head;
}

void printPoly(polynomial* head){
    cout<<endl;
    polynomial* trav=head;
    while(trav!=NULL){
        if(trav->coefficientOfVariable>=0){
        if(trav==head)
        cout<<trav->coefficientOfVariable<<"x^"<<trav->degreeOfVariable<<" ";
        else
        cout<<"+"<<trav->coefficientOfVariable<<"x^"<<trav->degreeOfVariable<<" ";
        }
        else
        cout<<trav->coefficientOfVariable<<"x^"<<trav->degreeOfVariable<<" ";
        trav=trav->next;
    }
}

polynomial* addition(polynomial* pe1,polynomial* pe2){
    polynomial* sumHead=NULL;
    polynomial* sumTail=NULL;
    polynomial* trav1=pe1;
    polynomial* trav2=pe2;
    while(trav1!=NULL&&trav2!=NULL){
        if(trav1->degreeOfVariable==trav2->degreeOfVariable){
            int coefficient=trav1->coefficientOfVariable+trav2->coefficientOfVariable;
            makeNode(sumHead,sumTail,coefficient,trav1->degreeOfVariable);
            trav1=trav1->next;
            trav2=trav2->next;
        }
        else{
            if(trav1->degreeOfVariable>trav2->degreeOfVariable){
                makeNode(sumHead,sumTail,trav1->coefficientOfVariable,trav1->degreeOfVariable);
                trav1=trav1->next;
            }
            else{
                makeNode(sumHead,sumTail,trav2->coefficientOfVariable,trav2->degreeOfVariable);
                trav2=trav2->next;
            }
        }
    }
    return sumHead;
}

polynomial* multiplication(polynomial* pe1,polynomial* pe2){
    polynomial* trav1=pe1;
    polynomial* trav2=pe2;
    polynomial* multi=NULL;
    polynomial* multiTail=NULL;
    while(trav1!=NULL&&trav2!=NULL){
        if(trav1->degreeOfVariable>=trav2->degreeOfVariable){
            while(trav2!=NULL){
                int coef;
                int expo;
                coef=trav1->coefficientOfVariable*trav2->coefficientOfVariable;
                expo=trav1->degreeOfVariable+trav2->degreeOfVariable;
                makeNode(multi,multiTail,coef,expo);
                trav2=trav2->next;
            }
            pe1=pe1->next;
            trav1=pe1;
            trav2=pe2;
        }
        else{
            while(trav1!=NULL){
                int coef;
                int expo;
                coef=trav1->coefficientOfVariable*trav2->coefficientOfVariable;
                expo=trav1->degreeOfVariable+trav2->degreeOfVariable;
                makeNode(multi,multiTail,coef,expo);
                trav1=trav1->next;
            }
            pe2=pe2->next;
            trav2=pe2;
            trav1=pe1;
        }
    }

    //algorithm to merge the nodes with the same value of exponents
    trav1=multi;
    while(trav1->next!=NULL){
        int coef=0;
        polynomial* prev=trav1;
        trav2=trav1->next;
        while(trav2!=NULL){
            
            if(trav1->degreeOfVariable==trav2->degreeOfVariable){
                coef=coef+trav2->coefficientOfVariable;
                prev->next=trav2->next;
            }
            trav2=trav2->next;
            if(prev->next!=trav2)
            prev=prev->next;
        }
        trav1->coefficientOfVariable+=coef;
        trav1=trav1->next;
    }
    return multi;
}
