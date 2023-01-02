#include <iostream>
using namespace std;
//----------------------------------------------------------------------------------------------------//
//                                     Declaring our Variables                                        //
//----------------------------------------------------------------------------------------------------//
// Declarying our 2D Array Aka Matrix                                                                 //  
                                                                                                      //
char Matrix[3][3]= {'1','2','3','4','5','6','7','8','9'};                                             //
                                                                                                      //
char player; // Our Little Player                                                                     //
int counter = 0; // our little counter                                                                //
                                                                                                      //
char player_stock; // Stock For our Little PLayer                                                     //
//----------------------------------------------------------------------------------------------------//
//                                     Declaring our Variables                                        //
//----------------------------------------------------------------------------------------------------//

// Prototypes--------------------------------------------------------
void PrintMatrix();//                                               ||
void pos();//                                                       ||
char WhoWin();//                                                    ||
void newgame();//                                                   ||
char check_draw();//                                                || 
// Prototypes--------------------------------------------------------

int main(void)
{
    char dec;
    while(true)
    {
        cout<<"Please Choose Be ( X ) or ( O ) :\n";
        cin>>player;
        if(player != 'X' && player != 'x' && player != 'O' && player != 'o')
        {
            cout<<"Please Choose Be ( X ) or ( O ) :\n";
            cin>>player;   
        }
        else
            break;
    }
    player_stock = player;

    while(WhoWin()=='.')
    {
        PrintMatrix();
        pos();
        counter++;
        if(counter == 9)
        {
            PrintMatrix();
            if (check_draw() == 'Z')
            {
                cout<<"This is Draw!\n";
                break;
                
            }
        }
             /*if (check_draw() != 'Z')
            {
                PrintMatrix();
                if (WhoWin() == 'x' && WhoWin() == 'X' && WhoWin() == 'O' && WhoWin() == 'o')
                {
                    cout<<"The Winner is : "<<WhoWin()<<endl;
                    break;
                }

            }*/
    }
    PrintMatrix();
    if (WhoWin() == 'x' || WhoWin() == 'X' || WhoWin() == 'O' || WhoWin() == 'o')
    {
        cout<<"The Winner is : "<<WhoWin()<<endl;
    }

    

    
    cout<<"Exit == ( Y )\nNew Game == N\nYour Decision is ??\n";

    cin>>dec;

    if(dec == 'Y' || dec == 'y')
    {
        system("cls");
        cout<<"Bye User\n";
        system("pause");
        return 0;
    }
    else
        cout<<"this is the new Game:\n";
        newgame();
        main();
        return 0;  
}

void PrintMatrix()
{
    //system("cls"); // Disable it when using VSCODE but use it when u use CMD / Powershell Terminal...
    for(int i = 0 ; i<3;i++)
    {
        for(int j =0;j<3;j++)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void pos()
{
    char Pos;
    cout<<"Choose Your Position - Player ( " << player <<" ) : ";
    cin >> Pos;
    for(int i = 0 ; i<3;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(Matrix[i][j] == Pos)
            {
                Matrix[i][j] = player;
                
            }
        }
    }
    if (player == 'X')
    {
        player = 'O';
    }
    else if (player == 'x')
    {
        player = 'o';
    }
    else if (player == 'o')
    {
        player = 'x';
    }
    else if (player == 'O')
    {
        player = 'X';
    }
}

char WhoWin()
{
 
// -----------------------------------------------------------------------------------------------------------------------------------//
//                                                     CHECKING DIAGONALS ( NORMAL )                                                  //    
// -----------------------------------------------------------------------------------------------------------------------------------//    
    if(Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X') // Check on Capital X Diagonally
    {
       
        return 'X';
    }
     else if(Matrix[0][0] == 'x' && Matrix[1][1] == 'x' && Matrix[2][2] == 'x') // Check on Small x Diagonally
    {
        
        return 'x';
    }
    else if(Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O') // Check on Capital O Diagonally
    {
        
        return 'O';
    }
    else if(Matrix[0][0] == 'o' && Matrix[1][1] == 'o' && Matrix[2][2] == 'o') // Check on Smaller o Diagonally
    {
        
        return 'o';
    }
// -----------------------------------------------------------------------------------------------------------------------------------//
//                                                      CHECKING INVERTED DIAGONALS                                                   //
// -----------------------------------------------------------------------------------------------------------------------------------//
    else if(Matrix[0][2] == 'X' && Matrix[1][1] == 'X' && Matrix[2][0] == 'X') // Check on Capital X Inverted Diagonally
    {
        
        return 'X';
    }
    else if(Matrix[0][2] == 'x' && Matrix[1][1] == 'x' && Matrix[2][0] == 'x') // Check on Smaller x Inverted Diagonally
    {
        
        return 'x';
    }
    else if(Matrix[0][2] == 'O' && Matrix[1][1] == 'O' && Matrix[2][0] == 'O') // Check on Capital O Inverted Diagonally
    {
        
        return 'O';
    }
    else if(Matrix[0][2] == 'o' && Matrix[1][1] == 'o' && Matrix[2][0] == 'o') // Check on Capital O Inverted Diagonally
    {
        
        return 'o';
    }
// -----------------------------------------------------------------------------------------------------------------------------------//
//                                              CHECKING HORIZONTALLY ROWS                                                            //  
// -----------------------------------------------------------------------------------------------------------------------------------// 
    else if (Matrix[0][0] == 'X' && Matrix[0][1] == 'X' && Matrix[0][2] == 'X') // Check on Capital Letter X Horizontally 1st Row
    {
        
        return 'X';
    }
    else if (Matrix[0][0] == 'x' && Matrix[0][1] == 'x' && Matrix[0][2] == 'x') // Check on Lower Letter x Horizontally 1st Row
    {
        
        return 'x';
    }
    else if (Matrix[0][0] == 'O' && Matrix[0][1] == 'O' && Matrix[0][2] == 'O') // Check on Capital Letter O Horizontally 1st Row
    {
        
        return 'O';
    }
    else if (Matrix[0][0] == 'o' && Matrix[0][1] == 'o' && Matrix[0][2] == 'o') // Check on Lower Letter o Horizontally 1st Row
    {
        
        return 'o';
    }
// -----------------------------------------------------------------------------------------------------------------------------------//
    else if (Matrix[1][0] == 'X' && Matrix[1][1] == 'X' && Matrix[1][2] == 'X') // Check on Capital Letter X Horizontally 2nd Row
    {
        
        return 'X';
    }   
    else if (Matrix[1][0] == 'x' && Matrix[1][1] == 'x' && Matrix[1][2] == 'x') // Check on Lower Letter x Horizontally 2nd Row
    {
        
        return 'x';
    }    
    else if (Matrix[1][0] == 'O' && Matrix[1][1] == 'O' && Matrix[1][2] == 'O') // Check on Capital Letter O Horizontally 2nd Row
    {
        
        return 'O';
    }
    else if (Matrix[1][0] == 'o' && Matrix[1][1] == 'o' && Matrix[1][2] == 'o') // Check on Lower Letter o Horizontally 2nd Row
    {
        
        return 'o';
    }
// -----------------------------------------------------------------------------------------------------------------------------------//
    else if (Matrix[2][0] == 'o' && Matrix[2][1] == 'o' && Matrix[2][2] == 'o') // Check on Lower Letter o Horizontally 3rd Row
    {
        
        return 'o';
    }          
    else if (Matrix[2][0] == 'O' && Matrix[2][1] == 'O' && Matrix[2][2] == 'O') // Check on Capital Letter O Horizontally 3rd Row
    {
        
        return 'O';
    }    
    else if (Matrix[2][0] == 'X' && Matrix[2][1] == 'X' && Matrix[2][2] == 'X') // Check on Capital Letter X Horizontally 3rd Row
    {
        
        return 'X';
    }    
    else if (Matrix[2][0] == 'x' && Matrix[2][1] == 'x' && Matrix[2][2] == 'x') // Check on Lower Letter x Horizontally 3rd Row
    {
        
        return 'x';
    }
// -----------------------------------------------------------------------------------------------------------------------------------// 
//                                                      CHECKING VERTICALLY COULOMNS                                                  //
// -----------------------------------------------------------------------------------------------------------------------------------// 
    else if (Matrix[0][0] == 'X' && Matrix[1][0] == 'X' && Matrix[2][0] == 'X') // Check on Capital Letter X Vertically 1st Coulomn
    {
        
        return 'X';
    }
    else if (Matrix[0][0] == 'x' && Matrix[1][0] == 'x' && Matrix[2][0] == 'x') // Check on Lower Letter x Vertically 1st Coulomn
    {
        
        return 'x';
    }
    else if (Matrix[0][0] == 'O' && Matrix[1][0] == 'O' && Matrix[2][0] == 'O') // Check on Capital Letter O Vertically 1st Coulomn
    {
        
        return 'O';
    }
    else if (Matrix[0][0] == 'o' && Matrix[1][0] == 'o' && Matrix[2][0] == 'o') // Check on Lower Letter o Vertically 1st Coulomn
    {
        
        return 'o';
    }
// -----------------------------------------------------------------------------------------------------------------------------------//
    else if (Matrix[0][1] == 'X' && Matrix[1][1] == 'X' && Matrix[2][1] == 'X') // Check on Capital Letter X Vertically 2nd Coulomn
    {
        
        return 'X';
    }   
    else if (Matrix[0][1] == 'x' && Matrix[1][1] == 'x' && Matrix[2][1] == 'x') // Check on Lower Letter x Vertically 2nd Coulomn
    {
        
        return 'x';
    }    
    else if (Matrix[0][1] == 'O' && Matrix[1][1] == 'O' && Matrix[2][1] == 'O') // Check on Capital Letter O Vertically 2nd Coulomn
    {
        
        return 'O';
    }
    else if (Matrix[0][1] == 'o' && Matrix[1][1] == 'o' && Matrix[2][1] == 'o') // Check on Lower Letter o Vertically 2nd Coulomn
    {
        
        return 'o';
    }
// -----------------------------------------------------------------------------------------------------------------------------------//
    else if (Matrix[0][2] == 'o' && Matrix[1][2] == 'o' && Matrix[2][2] == 'o') // Check on Lower Letter o Vertically 3rd Coulomn
    {
        
        return 'o';
    }          
    else if (Matrix[0][2] == 'O' && Matrix[1][2] == 'O' && Matrix[2][2] == 'O') // Check on Capital Letter O Vertically 3rd Coulomn
    {
        
        return 'O';
    }    
    else if (Matrix[0][2] == 'X' && Matrix[1][2] == 'X' && Matrix[2][2] == 'X') // Check on Capital Letter X Vertically 3rd Coulomn
    {
        
        return 'X';
    }    
    else if (Matrix[0][2] == 'x' && Matrix[1][2] == 'x' && Matrix[2][2] == 'x') // Check on Lower Letter x Vertically 3rd Coulomn
    {
        
        return 'x';
    }
// -----------------------------------------------------------------------------------------------------------------------------------//    
    return '.';
}

void newgame()
{
   char Matrix_stock[3][3] = {'1','2','3','4','5','6','7','8','9'};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            Matrix[i][j]=Matrix_stock[i][j];    //reset the array to 1,2,3,....
            cout<<Matrix[i][j]<<" ";
        }
    cout<<endl;

    }
}

char check_draw()
{
    char check_Matrix [3][3] = {'1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3 ; j++)
        {
            if(Matrix[i][j] != check_Matrix[i][j])
            {
                if(Matrix[j][i] != check_Matrix[j][i])
                {
                    return 'Z'; // t3adol   تعادل
                }
            }
        }
    }
    return 'k';
}
