/* AUTHOR -- code_blooded */

/**
*
*   This program aims at finding the nth Fibonacci using,
*   1) Memoization 
*   2) Bottom-Up
*   3) Recursion 
*
*/

#include <bits/stdc++.h>
using namespace std;

// Fibonacci using recursion
int fib_recursion(int n){
    if(n<=1)    return n;
    return fib_recursion(n-1)+fib_recursion(n-2);
}

// Fibonacci using recursion with lookup table
int F[100]={0};
int fib_memo(int n){
    if(F[n]==0){
        if(n<=1){
            F[n]=n;
        }
        else{
            F[n]=fib_memo(n-1)+fib_memo(n-2);
        }
    }
    return F[n];
}

// Fibonacci using dp
int fib_bottom_up(int n){
    int F[100]={0};
    F[1]=1;
    F[2]=1;
    for(int i=3;i<=n;i++){
        F[i]=F[i-1]+F[i-2];
    }
    return F[n];
}

int main(){
    
    int n;
    cin>>n;
    // note: fibonacci grows rapidly
    
    cout<<fib_recursion(n)<<endl;
    cout<<fib_memo(n)<<endl;
    cout<<fib_bottom_up(n)<<endl;
    
    return 0;
}
