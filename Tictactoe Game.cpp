    // library files
    #include<bits/stdc++.h>
    //standard namespace
    using namespace std;
    class TicTacToe
    {
       private:
       char board[3][3];
       public:
       TicTacToe() {}
       void SetBoard()
       {
          int n = 1;
          int i = 0;
          int j = 0;
          for ( i = 0; i < 3; i++ )
          {
             for ( j = 0; j < 3; j++ )
             {
                board[i][j] = '0' + n;
                n++;
             }
          }
       }
       void PrintBoard()
       {
          int i = 0;
          int j = 0;
          for ( i = 0; i < 3; i++ )
          {
             for ( j = 0; j < 3; j++ )
             {
                if ( j < 2 )
                {
                   cout << board[i][j] << "  |  ";
                }
                   else
                   {
                      cout << board[i][j] << endl;
                   }
             }
          }
       }
       void PlayerTurn(char num, char Player)
       {
          int i = 0;
          int j = 0;
          bool WrongMove = true;
          for( i = 0; i < 3; i++ )
          {
             for( j = 0; j < 3; j++ )
             {
                if(board[i][j] == num)
                {
                   board[i][j] = Player;
                   WrongMove = false;
                }
             }
          }
          if(WrongMove == true) { cout << "You can only mark the open sets!\n"; }
       }
       bool CheckResult(char Player, bool GameOver)
       {
          for(int i = 0; i < 3; i++)
          {
             if(board[i][0] == board[i][1] && board[i][1] ==
             board[i][2]) GameOver = true;
          }
          for(int i = 0; i < 3; i++)
          {
             if(board[0][i] == board[1][i] && board[1][i] ==
             board[2][i]) GameOver = true;
          }
          if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
          {
             GameOver = true;
          }
          if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
          {
             GameOver = true;
          }
          if(GameOver == true)
          {
             cout << "Player " << Player << " wins!\n\n";
          }
             return GameOver;
       } //End Check Winner
    //Check the board to see if the match has come to a draw
       bool CheckDraw(bool GameOver)
       {
          int n = 1;
          int i = 0;
          int j = 0;
          int c = 0;
          for( i = 0; i < 3; i++ )
          {
             for( j = 0; j < 3; j++ )
             {
                if(board[i][j] == '0' + n)
                {
                   c++;
                }
                n++;
             }
          }
          if( c< 1 )
          {
             cout << "Drawn!\n\n";
             GameOver = true;
          }
          return GameOver;
       }
    };
    int main()
    {
        bool done     = false, GameOver      = false;
        char Player   = 'O', num;

        cout << "-=Tic-Tac-Toe=-\n";
        cout << "-------------"<< endl;
        TicTacToe myGame;
        myGame.SetBoard();
        do
        {
            if( Player == 'X' )
            {
               Player = 'O';
            }
               else
               {
                  Player = 'X';
               }
            myGame.PrintBoard();
            cout << "\nPlayer \"" << Player << "\", it's your turn: ";
            cin >> num;
            cout << "\n";
            myGame.PlayerTurn(num, Player);
            GameOver = myGame.CheckResult(Player, GameOver);
            GameOver = myGame.CheckDraw(GameOver);
            if(GameOver == true)
            {   myGame.SetBoard();
                GameOver = false;
            }
        } while(!done);
        system("pause");
        return 0;
    }
