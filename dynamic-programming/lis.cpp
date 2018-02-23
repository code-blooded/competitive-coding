/* AUTHOR -- code_blooded */

/**
*
*	This program aims at finding the longest increasing subsequence(not subarray) in an array.
* 
*   The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence
*   of a given sequence such that all elements of the subsequence are sorted in increasing order.
*   
*   eg: arr = [10, 22, 9, 33, 21, 50, 41, 60, 80] then the subsequence would be [10, 22, 33, 50, 60, 80]
* 
*/

#include <bits/stdc++.h>
using namespace std;

// The complexity of this solution is O(n^2).
// Although this problem can be solved in O(nlogn).
int LIS(int arr[],int n){
    int L[n]={0};
    // base case
    L[0]=1;
    // running through the array
    for(int i=1;i<n;i++){
        // checking if the previously calculated subsequence leads to a better solution
        for(int j=0;j<i;j++){
            if(arr[i]>=arr[j]){ 
                L[i]=max(L[i],L[j]+1);
            }
        }
        // if all elements are greater on the left then this is the start
        L[i]=max(1,L[i]);
    }
    return L[n-1];
}

int main(){
    
    // Scanning Input
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"The length of the longest increasing subsequence is ";
    cout<<LIS(arr,n);
    cout<<"\n";
    
    return 0;
}