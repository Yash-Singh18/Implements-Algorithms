#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cp(vector<int>& col,vector<int>& row){

    vector<vector<int>> R;

    for(int i=0;i<col.size();i++){
        for(int j=0;j<row.size();j++){
            R.push_back({col[i],row[j]});
        }
    }

    return R;
}

vector<vector<int>> Warshall(int n,unordered_map<int,int>& st,int r,vector<vector<int>>& R){
    vector<vector<int>> W0(n,vector<int>(n,0));

    for(int i=0;i<r;i++){
        int row= st[R[i][0]];
        int col=st[R[i][1]];

        W0[row][col]=1;
    }

    for(int i=0;i<n;i++){

        // col:
        vector<int> col;
        for(int j=0;j<n;j++){
            if(W0[j][i]==1){
                col.push_back(j);
            }
        }
        vector<int> row;
        for(int j=0;j<n;j++){
            if(W0[i][j]==1){
                row.push_back(j);   
            }
        }

        // abh apne pe 1st relation banane ke liye data hai enough;

        vector<vector<int>> Ri= cp(col,row);

        for(int k=0;k<Ri.size();k++){
            W0[Ri[k][0]][Ri[k][1]]=1;
        }
    }

    return W0;
}


int main(){
    int n;

    cout<< "Enter number of elements in the set:" << endl;
    cin>> n;

    unordered_map<int,int> st;

    cout<< "Enter set elements:" << endl;
    for(int i=0;i<n;i++){
        int temp;
        cin>> temp;
        st[temp]=i;
    }


    vector<vector<int>> R;
    int r;

    cout<< "Enter number of elements in relation" << endl;
    cin >> r;

    cout<< "Enter relation element:" << endl;
    for(int i=0;i<r;i++){
        vector<int> temp(2,0);
        cin>> temp[0] >> temp[1];

        R.push_back(temp);
    }

    vector<vector<int>> test=Warshall(n,st,r,R);

    cout<< "Output: " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << test[i][j] << " ";
        }
        cout<< endl;
    }

    // vector<vector<int>> reflexiveclouser=Warshall(n,st,r,R);

    return 0;
}   