#include<bits/stdc++.h>
#define MAX 4
using namespace std;

int sol[288][MAX][MAX];

bool NotInSqr(int mat[][MAX],int i,int j,int k,int n)
{
    int row=0;
    int col=0;
    
    if(i>=0 && i<n/2)
		row=0;
    else
		row=n/2;
    
    if(j>=0 && j<n/2)
		col=0;
    else
		col=n/2;
    
    for(i=row;i<row+2;i++)
    {
        for(j=col;j<col+2;j++)
        {
            if(mat[i][j]==k)
            return false;
        }
    }
    return true;
}
 
bool NotInCol(int mat[][MAX],int i,int j,int k,int n)
{
    int r;
    for(r=0;r<i;r++)
    {
        if(mat[r][j]==k)
        return false;
    }
    return true;
}
bool NotInRow(int mat[][MAX],int i,int j,int k,int n)
{
    int r;
    for(r=0;r<j;r++)
    {
        if(mat[i][r]==k)
        return false;
    }
    return true;
}

void sudoku(int mat[MAX][MAX],int i,int j,int &cnt,int n)
{
    if(i>n || j>n)
    return;
     
    else if(i==n && j==0)
    {
		for(int i1=0;i1<4;i1++)
		{
			for(int j1=0;j1<4;j1++)
			{
				sol[cnt][i1][j1] = mat[i1][j1];
			}
		}
        cnt++;
        return;
    }
     
    else if(i<n && j<n)
    {
        int k;
        for(k=1;k<5;k++)
        {
            if(NotInRow(mat,i,j,k,n) && NotInCol(mat,i,j,k,n) && NotInSqr(mat,i,j,k,n))
            {
                mat[i][j]=k;
                sudoku(mat,(i+(j+1)/n),(j+1)%n,cnt,n);
                mat[i][j]=0;
                 
            }
        }
    }
}

int main()
{
    int cnt = 0;
    int mat[MAX][MAX];
    memset(mat,0,sizeof(mat));
    
    sudoku(mat,0,0,cnt,MAX);
    
    int t;
    cin>>t;
    while(t--)
    {
		int a[4][4];
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				cin>>a[i][j];
		}
		
		int res = INT_MAX;
		for(int k=0;k<cnt;k++)
		{
			int ans = 0;
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					ans += (sol[k][i][j]-a[i][j])*(sol[k][i][j]-a[i][j]);
				}
			}
			res = min(res,ans);
		}
		cout<<res<<endl;
	}
	
    return 0;
}
