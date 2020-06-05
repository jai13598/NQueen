#include<iostream>
using namespace std;
bool can_we_place(int board[10][10],int i,int j,int n){
	for(int l=0;l<n;l++){//row and col check where any Queen exist
		if(board[i][l] || board[l][j]){
			return false;
		}
	}
	int row=i;//right diognol check where any Queen exist 
	int col=j;
	while(i>=0 && j<n){
		if(board[i][j]){
			return false;
		}
		i--;
		j++;
	}
	i=row;
	j=col;
	while(i>=0 &&j>=0){//left diognol where any Queen exist
		if(board[i][j]){
			return false;
		}
		i--;
		j--;
	}
	return true;
}
bool NQueen(int board[10][10],int i,int n){
	if(i==n){
		for(int k=0;k<n;k++){
			for(int m=0;m<n;m++){
				if(board[k][m]==1){
					cout<<"Q"<<" ";
				}
				else{
					cout<<"_"<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		return true;//return false; //if you want print all possible postion of queen
	}
	for(int j=0;j<n;j++){
		if(can_we_place(board,i,j,n)==true){
			board[i][j]=1;
			bool can_we_also_placedown=NQueen(board,i+1,n);
			if(can_we_also_placedown==true){
				return true;
			}
			board[i][j]=0;
		}
	}
	return false;
}
int main(){
	int n;
	int board[10][10]={0};
	cin>>n;
	NQueen(board,0,n);
	return 0;
}
