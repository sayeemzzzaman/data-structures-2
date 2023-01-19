#include<iostream>
using namespace std;

struct maxmin{
    int mx,mn;
};

maxmin findMaxmin(int a[],int i, int j){
    if(i==j){
        // maxmin val;
        // val.mx = a[i];
        // val.mn = a[i];
        // return val;
        return{a[i],a[i]};//assigns the values into structure serially
    }
    else{
        int mid = (i+j) / 2;
        maxmin v1 = findMaxmin(a,i,mid);
        maxmin v2 = findMaxmin(a,mid+1,j);
    //    int mx, mn;
    //    if (v1.mx>v2.mx) mx = v1.mx;
    //    else mx = v2.mx;
    //    if (v1.mn < v2.mn) mn = v1.mn;
    //    else mn = v2.mn;
    //    return {mx, mn}
    return{max(v1.mx,v2.mx),min(v1.mn,v2.mn)};
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    maxmin value = findMaxmin(a,0,n-1);
    cout << value.mx <<  " " << value.mn << endl;
}