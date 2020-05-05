#include<stdio.h>
const int m=10;
const int n=10;

int checkresult(int tab[m][n]);
{
    int c=0;
    //check hàng ngang
    int countngang[10]={}, countdoc[10]={}, countcheo1[10]={},countcheo2[10]={},win=1;
    for(i=0;i<10;i++) for(j=0;j<10;j++) 
    {if(tab[i][j]==tab[i][j+1]) countngang[j]++;}
    
    //check hàng dọc
    if(tab[i][j]==tab[i+1][j]) countdoc[i]++;
    
    //check chéo lên trái~chéo xuống phải, quy định boundary
    if(i<6&&j<6) {if(tab[i][j]==tab[i+1][j+1]) countcheo1[i]++;}
    
    //check chéo xuống trái~chéo lên phải, quy định boundary
    if(i>3&&j>3) {if(tab[i][j]==tab[i+1][j-1]) countcheo2[i]++;}
    
    //đếm các count xem có >=5 để win
    for(j=0;j<10;j++) {
        if(countngang[j]!=countngang[j+1] && j<j+4 && countngang[j]==null) win=0;
        if(j>5&&win==0) break; }
    for(i=0;i<10;i++) {
        if(countdoc[i]!=countdoc[i+1] && i<i+4 && countdoc[j]==null) win=0;
        if(i>5&&win==0) break; }
    
    return(win);
}

int main()
{
    int i,j,repeat,won;
    int table[10][10]={-1};
    
    for (repeat=0;repeat<99999;repeat++)
    {printf("player 1 nhập tọa độ x y"); scanf("%d %d",&i,&j); table[i][j]=0;
    for(i=0;i<10;i++) {for(j=0;j<10;j++) if(table[i][j]!=-1) printf("X"); else printf(" "); printf("\n");}
    won=checkresult(table); if(won==1) {printf("player 1 win");break;}
    
    printf("player 2 nhập tọa độ x y"); scanf("%d %d",&i,&j); table[i][j]=1;
    for(i=0;i<10;i++) {for(j=0;j<10;j++) if(table[i][j]!=-1) printf("O"); else printf(" "); printf("\n");}
    won=checkresult(table); if(won==1) {printf("player 2 win");break;} }
    
    return 0;
}