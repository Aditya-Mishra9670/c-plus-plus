/*What is bucket sort Algorithm
Bucket sort is a sorting technique that involves dividing elements into various groups, or buckets. 
These buckets are formed by uniformly distributing the elements. 
Once the elements are divided into buckets, they can be sorted using any other sorting algorithm. 
Finally, the sorted elements are gathered together in an ordered fashion.
----------------------------------------------------------------------------------------------------
Bucket Sort Algorithm:
Step1:Create n empty buckets (Or lists) and do the following for every array element arr[i].
Step2:Insert arr[i] into bucket[n*array[i]]
Step3:Sort individual buckets using insertion sort.
Step4:Concatenate all sorted buckets.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getmax(int arr[], int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void bucketsortAlgo(float arr[],int n){
    vector<vector<float>>bucket(n,vector<float>());
    //step1

    //step2 : inserting elements into bucket
    for(int i=0;i<n;i++){
        int index=arr[i]*n;
        bucket[index].push_back(arr[i]);
    }

    //step3: Sorting individual buckets
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }
    //step4: combining elements from buckets
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }
}
int main(){
    float arr[]={0.25,0.13,0.34,0.45,0.32,0.45,0.46,0.47,0.91,0.21,0.92,0.45,0.49,0.28};
    cout<<"Unsorted array"<<endl;
    int i;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

//Algorithm call
    bucketsortAlgo(arr,n);

    cout<<"Sorted Array is "<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}
