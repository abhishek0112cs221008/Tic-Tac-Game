#include <iostream>
using namespace std;

char turn = 'X';
bool draw = false;

class Game
{
private:
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int choice;
    int row,column;
public:
//////////////////////display_board function/////////////////////////
    void display_board(){
    system("cls");
    cout<<"\t\t\t#---------------------------------------#"<<endl;
    cout<<"\t\t\t| T I C K -- T A C -- T O E -- G A M E  |"<<endl;
    cout<<"\t\t\t|---------------------------------------|"<<endl;
    cout<<"\t\t\t|                                       |"<<endl;                            //\t\t\n\n
    cout<<"\t\t\t|->Player 1. [X]                        |\n\t\t\t|->Player 2. [O]                        |"<<endl;
    cout<<"\t\t\t|                                       |"<<endl;
    cout<<"\t\t\t#---------------------------------------#"<<endl;
    cout<<"\t\t\t|\t     |     |     \t\t|"<<endl;
    cout<<"\t\t\t|\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \t\t|"<<endl;
    cout<<"\t\t\t|\t_____|_____|_____\t\t|"<<endl;
    cout<<"\t\t\t|\t     |     |     \t\t|"<<endl;
    cout<<"\t\t\t|\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \t\t|"<<endl;
    cout<<"\t\t\t|\t_____|_____|_____\t\t|"<<endl;
    cout<<"\t\t\t|\t     |     |     \t\t|"<<endl;
    cout<<"\t\t\t|\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \t\t|"<<endl;
    cout<<"\t\t\t|\t     |     |     \t\t|"<<endl;
    cout<<"\t\t\t#---------------------------------------#"<<endl;
    }

//////////////////////player_turn function/////////////////////////
    void player_turn(){
    if(turn == 'X'){
        cout<<"\t\t\t ->Player - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\t\t\t ->Player - 2 [O] turn :";
    }

    cin>> choice;

    switch(choice){
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
            cout<<"\t\t\t     Invalid Choice !!";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"\t\t\t Box already filled!\n\t\t\t Please choose another!!\n\n";
        player_turn();
    }
    display_board();
    }

/////////////////////////////////////gameover function//////////////////////////////
    bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
    }
};


int main()
{
    Game g;
    while(g.gameover()){
        g.display_board();
        g.player_turn();
        g.gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"\n\nCongratulations!Player with 'X' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n\nCongratulations!Player with 'O' has won the game";
    }
    else
    cout<<"\n\nGAME DRAW!!!\n\n";
}
