/*

a*b = gcd(a,b) * lcm(a,b)

lcm cant solve with recursive
lcm = (a*b) / gcd(a,b)
gcd(48,18)
-gcd(18,48mod18) = gcd(18,12)
    -gcd(12,18mod12) = gcd(12,6)
        -gcd(6,12mod6) = gcd(6,0)
        Answer gcd -> 6
*/
#include<iostream>
using namespace std;

int calcGcd(int a, int b){
    if(a==0)return b;
    else if(b==0)return a;
    else{
        if(a>b)return calcGcd(b,a%b);
        else return calcGcd(a,b%a);
    }
}

int Cgcd(int a, int b){
    if(a==b)return a;
    else{
        if(a>b)return Cgcd(a-b,b);
        else return Cgcd(a,b-a);
    }
}
int main(){
    int a,b;
    cin >> a >> b;
    int gcd = calcGcd(a,b);
    int lcm = (a*b) / gcd;
    
    cout << "GCD: "<<gcd<<endl<<"LCM: "<<lcm<<endl;
}