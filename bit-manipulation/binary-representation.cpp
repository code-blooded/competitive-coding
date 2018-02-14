/* AUTHOR -- code_blooded */

/**
*
*	This program aims at printing the binary representation of an integer.
*
*/

#include <bits/stdc++.h>
using namespace std;

void binary(int n){
    if(n>1)                                 // base case
        binary(n/2);
    if(n%2) cout<<"1";
    else    cout<<"0";
}

int main(){

    int temp,n,ans=0;
    
    cout<<"Enter the number \n";
    cin>>n;
    
    cout<<"Binary Representation of "<<n<<" is ";
    binary(n);
    cout<<"\n";
    
    return 0;
}