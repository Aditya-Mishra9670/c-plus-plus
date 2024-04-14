/*Search the target value i a 2d integer matrix of dimension n * m and return 1 if found
else return 0. Thsi matrix has the following properties : 
1. Integers in each row are sorted from left to righ.
2.The first integer of each row is greater than the last integer of the previous row.*/
include<iostream>
#include<vector>
using namespace std;
void binarysearch(vector<vector<int>>&matrix, vector<int> &arr, int target,int n, int m){
    int low =0, high=n;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(matrix[mid][0]==target || matrix[mid+1][0]>target){
            arr[0]=mid;
            int low2=0, high2=m-1;
            while(low2<=high2){
                int mid2=low2+(high2-low2)/2;
                if(matrix[mid][mid2]==target){
                    arr[1]=mid2;
                    return;
                }else if (matrix[mid][mid2]<target){
                    low2=mid2+1;
                }else if(matrix[mid][mid2]>target){
                    high2=mid2-1;
                }
            }
        } else if(matrix[mid][0]<target){
            low=mid+1;
        } else if(matrix[mid][0]>target){
            high=mid-1;
        }
    }
}
int main(){
    int n,m;
    cout<<"Enter the size of the array : ";
    cin>>n>>m;
    int temp;
    vector<vector<int>>matrix(n,vector<int>(m));

    cout<<"Now Enter the  array"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp;
            matrix[i][j]=temp;
        }
    }
    cout<<endl;
    int target; 
    cout<<"Enter the target to search: ";
    cin>>target;
    vector<int>arr(2,0);
    binarysearch(matrix,arr,target,n,m);
    cout<<endl;
    cout<<"The target is at Index is : "<<arr[0]<<" "<<arr[1];
return 0;
}
