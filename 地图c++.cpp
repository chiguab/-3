#include<bits/stdc++.h>
using namespace std;
int main(){
	int x=5,y=4;
	int a[9][10]={           //a[��][��]������ͼ
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},//(5,5)
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	};
	while(1){
		a[y][x]+=1;
		char xd;
		for(int i=0;i<9;i++){
			for(int j=0;j<10;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		a[y][x]-=1;
		cin>>xd;
		if(xd=='w'||xd=='W'){
			y-=1;
		}
		if(xd=='s'||xd=='S'){
			y+=1;
		}
		if(xd=='a'||xd=='A'){
			x-=1;
		}
		if(xd=='d'||xd=='D'){
			x+=1;
		}
	}
}
