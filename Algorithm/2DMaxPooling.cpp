#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>

using namespace std;

void printfMatrix(vector<vector<int> >& matrix){
    for(int i =0;i<matrix.size();++i){
        for(int j =0;j<matrix[i].size();++j)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

vector<vector<int> > MaxPooling(vector<vector<int> >& matrix,int stride_x,int stride_y,int k_x,int k_y){
    int outW = (matrix.size()-k_x)/stride_x+1;
    int outH = (matrix.size()-k_y)/stride_y+1;
    vector<vector<int> >res(outW,vector<int>(outH,INT_MIN));
    for(int i =0;i<outW;++i)
        for(int j =0;j<outH;++j)
            for(int x =0;x<k_x;++x)
                for(int y =0;y<k_y;++y)
                    res[i][j] = max(res[i][j],matrix[i*stride_x+x][j*stride_y+y]);
    return res;
}

int main(){
    vector<vector<int> >feature_map(6,vector<int>(6));
    int tmp = 0;
    for(int i =0;i<6;++i)
        for(int j = 0;j<6;++j)
            feature_map[i][j] = ++tmp;
    cout<<"input is:"<<endl;
    printfMatrix(feature_map);
    vector<vector<int> >outPut = MaxPooling(feature_map,2,2,2,2);
    cout<<"output is:"<<endl;
    printfMatrix(outPut);
}
