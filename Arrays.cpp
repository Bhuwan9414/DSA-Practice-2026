#include<iostream>
#include<vector>
using namespace std;

// two sum problem

// brute force
vector <int> twoSum(vector<int> arr, int n, int target){

    vector <int> pairs = {};

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;i++){

            if(arr[i] + arr[j] == target){

                pairs.push_back(arr[i]);
                pairs.push_back(arr[j]);
                return pairs;
            }

        }
    }

    return pairs;

}


// optimal approach with two pointers but only works for a sorted array

vector <int> twoSumNew(vector<int> arr, int n, int target){

    vector <int> pairs = {};

   int i = 0, j = n-1;

   while(i<j){

    int sum = arr[i] + arr[j];

    if(sum == target ){
        pairs.push_back(arr[i]);
        pairs.push_back(arr[j]);
        i++;
        j--;
        return pairs;
    }
    else if(sum > target){
        j--;
    }
    else {
        i++;
    }

   }

   return pairs;

}


// ----------------------------------------------------------------------------


// best time to buy and sell stocks

// [7,1,5,3,6,4]

int stock(vector <int> arr, int n){

   int minPrice = arr[0], price = arr[0], profit = 0;
   int maxProfit = 0;


   for(int i=0;i<n;i++){
    
    if(arr[i] < minPrice){
        minPrice = arr[i];
    }

    profit = arr[i] - minPrice;

    maxProfit = max(maxProfit, profit);

   }

   return maxProfit;

}

// ----------------------------------------------------------------------------

// rotate array




int main (){

    vector <int> arr = {2,7,11,15};
    int target = 9;
    int n = arr.size();

    int ans = stock(arr, n);

    cout << ans << endl;


}