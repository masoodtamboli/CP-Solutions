/*
* Program: Make stacks eqaul
* Author: Masood Ismail Tamboli 
* Date: Jul 07, 21
*/

#include<iostream>
#include<stack>
using namespace  std;

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int mySum(stack<int> s){
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    return sum;
}

int checkHeight(stack<int> s1, stack<int> s2, stack<int> s3){
    while(!(mySum(s1) == mySum(s2) && mySum(s2) == mySum(s3) && mySum(s1) == mySum(s3))){
        if(mySum(s1) > mySum(s2)){
            s1.pop();
        }
            
        if(mySum(s2) > mySum(s3)){
            s2.pop();
        }
            
        if(mySum(s3) > mySum(s1)){
            s3.pop();   
        }
    }

    if(mySum(s1) == mySum(s2) && mySum(s2) == mySum(s3) && mySum(s1) == mySum(s3)){
        return mySum(s1);
    }
    return 0;
}



int main(){
    stack<int> s1, s2, s3;    

    int n1, n2, n3;
    int temp,i;
    cout<<"Enter number of cylinders in each stack"<<endl;
    
    cout<<"Cylinder 1 :";
    cin>>n1;

    cout<<"Cylinder 2 :";
    cin>>n2;

    cout<<"Cylinder 3 :";
    cin>>n3;

    cout<<endl<<"Now enter cylinder heights in stack 1"<<endl;
    for(i=0; i<n1; i++){
        cin>>temp;
        s1.push(temp);
    }

    cout<<"Now enter cylinder heights in stack 2"<<endl;
    for(i=0; i<n2; i++){
        cin>>temp;
        s2.push(temp);
    }
 
    cout<<"Now enter cylinder heights in stack 3"<<endl;
    for(i=0; i<n3; i++){
        cin>>temp;
        s3.push(temp);
    }

    cout<<checkHeight(s1, s2, s3)<<endl;

}