/* AUTHOR -- code_blooded */

/**
*
*	This program aims at checking if an integer is a Fibonacci number or not.
*
*/

#include <bits/stdc++.h>
using namespace std;

bool is_perfect_sq(int n){
    return (n == (int)sqrt(n)*sqrt(n));
}

bool is_fib(int n){
    return is_perfect_sq(5*n*n+4) || is_perfect_sq(5*n*n-4);
}

int main(){

    int n;
    cout<<"Enter a number \n";
    cin>>n;
    
    if(is_fib(n))
        cout<<n<<" is a fibonacci number \n";
    else
        cout<<n<<" is not a fibonacci number \n";
    
    return 0;
}
