/* AUTHOR -- code_blooded */

/**
*
*	  This program aims at finding pow(x,n) in O(logn).
*
*/

#include <bits/stdc++.h>
using namespace std;

// x is integer and n is a non-negative integer .. 2^4
long long power(int x,int n){
    if(n==0)    return 1;
    long long split = power(x,n/2);
    if(n%2==0){
        return split*split;
    }else{
        return x*split*split;
    }
}

// x is real and n is an integer .. 2.03^-3
double POWER(double x,int n){
    if(n==0)    return 1;
    double split = POWER(x,n/2);
    if(n%2==0){
        return split*split;
    }else if(n>0){
        return x*split*split;
    }else{
        return (split*split)/x;
    }
}

int main(){
    
    // Scanning Input
    cout<<"Enter x and n \n";
    int x,n;
    cin>>x>>n;
    
    cout<<"The value of x^n is ";
    cout<<power(x,n);
    cout<<"\n";
    
    // Scanning Input
    cout<<"Enter x(can be real) and n(can be negative int) \n";
    double X,N;
    cin>>X>>N;
    
    cout<<"The value of x^n is ";
    cout<<POWER(X,N);
    cout<<"\n";
    
    return 0;
}
