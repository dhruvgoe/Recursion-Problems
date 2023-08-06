// RAT IN MAZE PROBLEM

#include<iostream>
using namespace std;
int ans[10][10]={0};
bool ratInMaze(char arr[5][5],int i,int j,int n)
{
    // Base Case
    if(i==n-1 && j==n-1)
    {
        ans[i][j]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ans[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<"============"<<endl;
        return false;
    }
    // Recursive Case
    ans[i][j]=1;
    if(j+1<n && arr[i][j+1]!='X')
    {
        bool rightAns=ratInMaze(arr,i,j+1,n);
        if(rightAns==true)
        {
            return true;
        }
    }
    if(i+1<n && arr[i+1][j]!='X')
    {
        bool downAns=ratInMaze(arr,i+1,j,n);
        if(downAns==true)
        {
            return true;
        }
    }
    ans[i][j]=0;
    return false;
}
int main()
{
char maze[][5]={
    "0000",
    "00XX",
    "0000",
    "XX00"
};
ratInMaze(maze,0,0,4);
return 0;
}