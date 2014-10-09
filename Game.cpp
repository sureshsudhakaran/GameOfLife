#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int MAX=11;
struct Stat
{
    int neighalive;
    int alive;
};
class Grid
{
    private:
        int tim;
        Stat mat[MAX+1][MAX+1];
    public:
        Grid();
        void update();
        void display();
};
Grid::Grid()
{
    tim=0;
    srand(time(NULL));
    for(int i=0;i<=MAX;i++)
        mat[0][i].alive=mat[i][0].alive=mat[MAX][i].alive=mat[i][MAX].alive=mat[0][i].neighalive=mat[i][0].neighalive=mat[MAX][i].neighalive=mat[i][MAX].neighalive=0;
    for(int i=1;i<MAX;i++)
        for(int j=1;j<MAX;j++)
        {    
            mat[i][j].alive=rand()%2;
            mat[i][j].neighalive=0;
        }
    for(int i=1;i<MAX;i++)
        for(int j=1;j<MAX;j++)
            mat[i][j].neighalive+=mat[i+1][j].alive+mat[i+1][j+1].alive+mat[i+1][j-1].alive+mat[i][j-1].alive+mat[i][j+1].alive+mat[i-1][j].alive+mat[i-1][j+1].alive+mat[i-1][j-1].alive;
    display();
}
void Grid::display()
{
    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<MAX;j++)
            cout<<mat[i][j].alive<<"\t";
        cout<<endl;
    }
    //cout<<"\n\n\n\n\n";
    /*
    for(int i=1;i<MAX;i++)
    {    
        for(int j=1;j<MAX;j++)
            cout<<mat[i][j].neighalive<<"\t";
        cout<<endl;
    }
    */
    cout<<"time is "<<tim<<"\n";
}
void Grid::update()
{
    cout<<"Entering update";
    int mat2[MAX+1][MAX+1];
    for(int i=0;i<MAX+1;i++)
        for(int j=0;j<MAX+1;j++)
            mat2[i][j]=mat[i][j].neighalive;
    for(int i=1;i<MAX;i++)
        for(int j=1;j<MAX;j++)
        {
            if((mat2[i][j]<2)||(mat2[i][j]>=4))
                mat[i][j].alive=0;
            if(mat2[i][j]==3)
                mat[i][j].alive=1;
        }
    for(int i=0;i<=MAX;i++)
        mat[0][i].alive=mat[i][0].alive=mat[MAX][i].alive=mat[i][MAX].alive=mat[0][i].neighalive=mat[i][0].neighalive=mat[MAX][i].neighalive=mat[i][MAX].neighalive=0;
    for(int i=1;i<MAX;i++)
        for(int j=1;j<MAX;j++)
        {
            mat[i][j].neighalive=0;
        }
    for(int i=1;i<MAX;i++)
        for(int j=1;j<MAX;j++)
            mat[i][j].neighalive+=mat[i+1][j].alive+mat[i+1][j+1].alive+mat[i+1][j-1].alive+mat[i][j-1].alive+mat[i][j+1].alive+mat[i-1][j].alive+mat[i-1][j+1].alive+mat[i-1][j-1].alive;
    tim++;
}
int main()
{
    Grid g;
    char ch;
    cout<<"Do you want to continue? ";
    cin>>ch;
    while((ch=='y')||(ch=='Y'))
    {
        g.display();
        g.update();
        cin>>ch;
    }
    return 0;
}
