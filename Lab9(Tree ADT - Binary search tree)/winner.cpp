//Program to eliminate the players on the given sequence and find the number of players who win without getting eliminated

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        //k is the number of elements in the sequence
        //q is the number of rounds
        //playnum is the number of players in each round
        int k,q;
        cin >> k >> q;
        vector<int> a(k);
        for(int i = 0;i < k;i++){
            cin >> arr[i];
        }
        int minval = arr[0]-1;
        while(q--){
            int playnum;
            cin >> playnum;
            int minimum = min(minval,playnum);
            cout << minimum << " ";

        }
        cout << "\n";
    }
}