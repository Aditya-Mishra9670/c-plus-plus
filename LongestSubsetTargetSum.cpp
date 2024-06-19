//Find the length of the largest subarray with given target sum.
//Let's code 
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int maxlen(vector<int> &arr, int target){
    int n = arr.size();
    map<int,int>prefix;
    int maxl = 0;
    int current_prefix_sum = 0;
    
    prefix[0]=-1 ; //this is to handle edge case
    
    for(int i=0;i<n;i++){
        current_prefix_sum+=arr[i];
        
        if(prefix.find(current_prefix_sum-target)!=prefix.end()){
            int len= i - prefix[current_prefix_sum];
            if(len>maxl){
                maxl=len;
            }
        }
        //if not found then add this prefix to the prefix map with index
        if(prefix.find(current_prefix_sum-target)==prefix.end()){
           prefix[current_prefix_sum]=i;
        }
    }
    
    return maxl;
}

int main(){
    vector<int>arr={15,-2,2,-8,1,7,10,23};
    int target = 0 ;// we will find the largest subarray with target sum = 0;
    
    int ans  = maxlen(arr,target);
    cout<<ans<<endl;
    cout<<"Thanks Guys";
    return 0;
}
