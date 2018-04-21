#include<bits/stdc++.h>
using namespace std;
int Phi[10009];
const int Mx = 1000;
void Siv(){
    int i,j;
    Phi[1]=1;
    for(i=2;i<Mx;i++){
        if(!Phi[i]){
            Phi[i]=i-1;
            for(j = (i<<1);j<Mx;j+=i){
                if(!Phi[j])Phi[j]=j;
                Phi[j]=(Phi[j]/i)*(i-1);
            }
        }
    }
}
int main(){
    Siv();
    for(int i=1;i<=20;i++)cout<<Phi[i]<<" ";
}
