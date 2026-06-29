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

void reverseArray(vector <int> &arr, int left, int right){
    
    while(left<=right){

        swap(arr[left], arr[right]);

        left++;
        right--;

    }

}


void rotateArray(vector <int> &arr, int k){

    int n = arr.size();

    k = k%n;

    reverseArray(arr, 0, n-1);
    reverseArray(arr, 0, k-1);
    reverseArray(arr, k, n-1);

}


int main (){

    vector <int> arr = {1,2,3,4,5,6,7};
    int k = 9;
    int n = arr.size();

    
    rotateArray(arr, k);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

}