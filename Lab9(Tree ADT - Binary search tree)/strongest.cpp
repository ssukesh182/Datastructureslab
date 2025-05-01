#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int test;
    cin >> test;
    while(test--){
        int num; //num of elements in the vector
        cin >> num;
        vector<int>arr(num);
        for(int i=0; i < num; ++i){
            cin >> arr[i];
        }
        int max1 = *max_element(arr.begin(),arr.end());
        int max2 = -1;
        for(int i = 0; i < num; ++i){
            if(arr[i]!= max1){
                max2 = max(max2,arr[i]);
            }
        }
        if(max2 == -1)max2 = max1;
        for(int i = 0; i < num;++i){
            if(arr[i]== max1){
                cout <<arr[i] - max2 << " ";
            }else{
                cout << arr[i] - max1 << " ";
            }
        }
    }
}

int main(){
    solve();
    return 0;
}