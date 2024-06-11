#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'


ll counta=0;
ll cx=0,co=0;

struct Move
{
    ll row,col;
};

void setupboard(char board[3][3]){
    for (ll i=0;i<3;i++)
    {
        for (ll j=0;j<3;j++)
        {
            board[i][j]=' ';
        }
    }
}
void showboard(char board[3][3])
{
    cout<< " --------- "<<endl;
    cout<<" "<<board[0][0]<< " | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<< " --------- "<<endl;
    cout<<" "<<board[1][0]<< " | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<< " --------- "<<endl;
    cout<<" "<<board[2][0]<< " | "<<board[2][1]<<" | "<<board[2][2]<<endl;
    cout<< " --------- "<<endl;
}
void player1move(char board[3][3])
{
    cout<<"Player 1 turn"<<endl;
    ll k,m; cin>>k>>m;
    board[k][m]='X';
   
}
void player2move(char board[3][3])
{
    cout<<"Player 2 turn"<<endl;
    ll k,m; cin>>k>>m;
    board[k][m]='O';
    
}
string checkresult(char board[3][3])
{
    for (ll i=0;i<3;i++)
    {
         cx=0,co=0;
        for (ll j=0;j<3;j++)
        {
            if (board[i][j]=='X')
            {
                cx++;
            }
            else if(board[i][j]=='O')
            {
                co++;
            }
        }
        if (cx==3)
        {
            return "X";
        }
        else if (co==3)
        {
            return "O";
        }
    }
     for (ll i=0;i<3;i++)
    {
         cx=0,co=0;
        for (ll j=0;j<3;j++)
        {
            if (board[j][i]=='X')
            {
                cx++;
            }
            else if(board[j][i]=='O')
            {
                co++;
            }
        }
        if (cx==3)
        {
            return "X";
        }
        else if (co==3)
        {
            return "O";
        }
    }
    cx=0,co=0;
    for (ll i=0;i<3;i++)
    {
        if (board[i][i]=='X')
        {
            cx++;
        }
        else if (board[i][i]=='O')
        {
            co++;
        }
    }
    if (cx==3)
    {
        return "X";
    }
     if (co==3)
    {
        return "O";
    }
    cx=0,co=0;
    for (ll i=0;i<3;i++)
    {
        if (board[i][2-i]=='X')
        {
            cx++;
        }
        else if (board[i][2-i]=='O')
        {
            co++;
        }
    }
    if (cx==3)
    {
        return "X";
    }
    if (co==3)
    {
        return "O";
    }
    counta=0;
    for (ll i=0;i<3;i++)
    {
        for (ll j=0;j<3;j++)
        {
            if (board[i][j] != ' ')
            {
                counta++;
            }
        }
    }
    if (counta==9)
    {
        return "Draw";
    }
    return "";

}
ll minimax(char board[3][3], ll depth, bool isMax)
{
    string m;
    m=checkresult(board);
    if (m=="X")
    {
        return -10;
    }
    else if(m=="O")
    {
        return 10;
    }
    else if(m=="Draw")
    {
        return 0;
    }
    else
    {
    if (isMax)
    {
        ll best=-1000;
        for (ll i=0;i<3;i++)
        {
            for(ll j=0;j<3;j++)
            {
                if (board[i][j]==' ')
                {
                    board[i][j]='O';
                    best=max(best,(minimax(board,depth+1,false)));
                    board[i][j]=' ';
                }
            }
        }
        return best;
    }
    else
    {
        ll best=1000;
        for (ll i=0;i<3;i++)
        {
            for (ll j=0;j<3;j++)
            {
                if (board[i][j]==' ')
                {
                    board[i][j]='X';
                    best=min(best,(minimax(board,depth+1,true)));
                    board[i][j]=' ';
                }
            }
        }
        return best;
    }
    }
}
Move findbestmove (char board[3][3]){
    ll bestval=-1000;
    Move bestMove;
    bestMove.row=-1;
    bestMove.col=-1;

    for (ll i=0;i<3;i++)
    {
        for (ll j=0;j<3;j++)
        {
           
           if (board[i][j]==' ')
            {
                board[i][j]='O';
                ll moveval=(minimax(board,0,false));
                board[i][j]=' ';
            
            if (moveval>bestval)
            {
                bestval=moveval;
                bestMove.row=i;
                bestMove.col=j;
            }
            }
        }
    }
    return bestMove;
}
int main() {
    
    cout<<"Tic-Tac-Toe Game"<<endl;
    cout<<"Press 1 for two player mode and Press 2 for single player mode"<<endl;
    ll n; cin>>n;
    char board[3][3];
    setupboard(board);
    string fn;
    bool flag= true;
    if (n==1)
    {
        showboard(board);
        while (flag){
        player1move(board);
        showboard(board);
        fn=checkresult(board);
        if (fn!="")
        {
            flag=false;
            if (fn=="X")
            {
                cout<<"Player 1 Wins";
            }
            else if (fn=="O")
            {
                cout<<"Player 2 Wins";
            }
            else 
            {
                cout<<"Draw"<<endl;
            }
            break;
        }
        if (flag)
        {
            player2move(board);
            showboard(board);
        }
        fn=checkresult(board);
        if (fn!="")
        {
            flag=false;
            if (fn=="X")
            {
                cout<<"Player 1 Wins";
            }
            else if (fn=="O")
            {
                cout<<"Player 2 Wins";
            }
            else 
            {
                cout<<"Draw"<<endl;
            }
        }

        }
        
    }
    else
    {
        showboard(board);
        while(flag)
        {
            
            player1move(board);
            showboard(board);
            fn=checkresult(board);
            if (fn!="")
        {
            flag=false;
            if (fn=="X")
            {
                cout<<"Player 1 Wins";
            }
            else if (fn=="O")
            {
                cout<<"Player 2 Wins";
            }
            else 
            {
                cout<<"Draw"<<endl;
            }
            break;
        }
        if (flag)
        {
            Move bestMove=findbestmove(board);
            board[bestMove.row][bestMove.col]='O';
            cout<<"Computer's Turn:"<<endl;
            cout<<"Computer Played : "<<bestMove.row<<" "<<bestMove.col<<endl;
            showboard(board);
        }
        fn=checkresult(board);
        if (fn!="")
        {
            flag=false;
            if (fn=="X")
            {
                cout<<"Player 1 Wins";
            }
            else if (fn=="O")
            {
                cout<<"Player 2 Wins";
            }
            else 
            {
                cout<<"Draw"<<endl;
            }
        }
        }
    }
}