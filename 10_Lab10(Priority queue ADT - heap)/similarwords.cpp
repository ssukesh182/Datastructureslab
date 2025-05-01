
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<string>> a(3,vector<string>(n));
        for(int i = 0; i < 3;++i){
            for(int j=0;j < n;++j){
                cin>>a[i][j];

            }
        }
        vector<int>score(3,0);
        unordered_map<string,int>wordscount;
        for(int i = 0; i < 3;++i){
            for(int j = 0; j < n; ++j){
                wordscount[a[i][j]]++;

            }

        }
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < n; ++j){
                if(wordscount[a[i][j]]==1){
                    score[i]+= 3;
                }
                else if(wordscount[a[i][j]]==2){
                    score[i]+= 1;
                }
            }
        }
        for(int i =0;i< 3;++i){
            cout << score[i] << " ";
        }
        cout << endl;
    }

}