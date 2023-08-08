#include<bits/stdc++.h>
using namespace std;
char game[3][3] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}};
int row;
int column;
char symbol = 'X';
bool draw = false;
string s1;
string s2;
void board()
{
    cout<<"     |     |     "<<endl;
    cout<<"  "<<game[0][0]<<"  | "<<game[0][1]<<"  |  "<<game[0][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<game[1][0]<<"  | "<<game[1][1]<<"  |  "<<game[1][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<game[2][0]<<"  | "<<game[2][1]<<"  |  "<<game[2][2]<<endl;
    cout<<"     |     |     "<<endl;
}

void start()
{
    int digit;
    if(symbol=='X')
    {
        cout<<s1<<" please enter:-";
    }
    else if(symbol=='0')
    {
        cout<<s2<<" please enter:-";
    }
    cin>>digit;
    switch(digit){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }
    if(symbol=='X'&&game[row][column]!='X'&&game[row][column]!='0')
    {
        game[row][column] = 'X';
        symbol = '0';
    }
    else if(symbol=='0'&&game[row][column]!='X'&&game[row][column]!='0')
    {
        game[row][column] = '0';
        symbol = 'X';
    }
    else
    {
        cout<<"place not empty";
        start();
    }
    board();
}

bool end()
{
    for(int i = 0;i<3;i++)
    {
        if(game[i][0] == game[i][1] && game[i][0] == game[i][2] || game[0][i] == game[1][i] && game[0][i] == game[2][i])
        {
            return false;
        }
        if(game[0][0] == game[1][1] && game[0][0] == game[2][2] || game[0][2] == game[1][1] && game[0][2] == game[2][0])
        {
            return false;
        }
    }

    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            if(game[i][j]!='X'&&game[i][j]!='0')
            {
                return true;
            }
        }
    }
    draw = true;
    return false;
}

int main()
{
    cout<<"First Player:-";
    getline(cin,s1);
    cout<<"Second Player:-";
    getline(cin,s2);
    cout<<s1<<" will play first"<<endl;
    cout<<s2<<" will play second"<<endl;
    cout<<"-------------TIC TAC TOE-------------";
    while(end())
    {
        board();
        start();
        end();
    }
    if(symbol=='X'&&draw==false)
    {
        cout<<"Congratulations "<<s1<<", you have won the game!!";
    }
    else if(symbol=='0'&&draw==false)
    {
        cout<<"Congratulations "<<s2<<", you have won the game!!";
    }
    else
    {
        cout<<"Game is Draw";
    }
}