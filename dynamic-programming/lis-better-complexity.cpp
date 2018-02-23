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

// returns the index of element greater than x in the array 
// if all are greater n+1
int ceilBinarySearch(int L[],int n,int x){
    if(x<L[1]){
        return 1;
    }else if(x>L[n]){
        return n+1;
    }
    int low = 1;
    int high = n;
    int mid = 1;
    while(low<high){
        mid = low + (high-low)/2;
        if(L[mid]<x)                low = mid+1;
        else if(L[mid]>x)           high = mid;
        else                        low = mid;
    }
    return high;
}

// The complexity of this solution is O(nlogn).
int LIS(int arr[],int n){
    // L[i] denotes the end of lis of length i
    int L[n+1]={0};  
    int len = 1;
    // base case
    L[1] = arr[0];
    for(int i=1;i<n;i++){
        int index = ceilBinarySearch(L,len,arr[i]);
        if(L[index]>arr[i] && index<=len){
            L[index]=arr[i];
        }else{
            len++;
            L[len]=arr[i];
        }
        // uncomment these lines to see the changes in L array
        // cout<<"Index: "<<index<<" Length: "<<len<<" arr[i]: "<<arr[i]<<endl;
        // cout<<"Subsequences so far \n";
        // for(int j=1;j<=len;j++){
        //     cout<<L[j]<<" ";   
        // }
        // cout<<endl;
    }
    return len;
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