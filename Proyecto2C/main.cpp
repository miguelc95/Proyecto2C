//
//  main.cpp
//  Proyecto2A
//
//  Created by Miguel Cuellar on 4/13/16.
//   Equipo:Miguel Cuellar Carmelo Ramirez.
//
#include<stdio.h>
#include <iostream>
using namespace std;
int tren1[1005],tren2[1005],orden[2005],n,m,t;
int PD[1005][1005];
bool posible;

void matriz(int ix,int iy,int iz){
    if(posible) return;
    if (PD[ix][iy]==1) return;
    if(iz==n+m){
    posible=true;
    return;
    }
    if(ix<n && tren1[ix]==orden[iz])matriz(ix+1, iy, iz+1);
    if(iy<m && tren2[iy]==orden[iz])matriz(ix,iy+1,iz+1);
    PD[ix][iy]=1;
}
int main(){
    int i,j;
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        for(i=0; i<n; i++){
            cin>>tren1[i];}
        for(i=0; i<m; i++){
            cin>>tren2[i];}
        for(i=0; i<n+m; i++){
            cin>>orden[i];}
            posible=false;
            for (i=0;i<=n;i++)
            for (j=0;j<=m;j++)
            PD[i][j]=0;
        matriz(0,0,0);
        (posible)?cout<<("possible")<<endl:cout<<("not possible")<<endl;
        
    }
    return 0;
}