//  prog5_1024.cpp
//     Text version of the game 1024, a variant of 2048 available online at:
//        http://gabrielecirulli.github.io/2048/
//     Object of game is to combine number tiles with the same value, accumulating
//     points as the game progresses, to try and create the tile with the value 1024.
//     Each move consists of sliding pieces to the left, up, right or down.
/*  Running program looks like:
 
 Dale Reed
 UIC CS 141, Spring 2019
 Welcome to 1024.
 This program is based off of Gabriele Cirulli's game online at
 bit.ly/great2048
 
 For each move enter a direction as a letter key, as follows:
 W
 A S D
 where A=left,W=up, D=right and S=down.
 
 After a move, when two identical valued tiles come together they
 join to become a new single tile with the value of the sum of the
 two originals. This value gets added to the score.  On each move
 one new randomly chosen value of 2 or 4 is placed in a random open
 square.  User input of x exits the game.
 
 Game ends when you reach 1024.
 
 Score: 0
 .     4     .     .
 
 .     .     .     .
 
 .     .     4     .
 
 .     .     .     .
 
 1. Your move: a
 
 Score: 0
 4     .     .     .
 
 .     .     .     .
 
 4     .     .     .
 
 .     .     2     .
 
 2. Your move: a
 .
 .
 .
 */

#include <iostream>     // For cin, cout, endl
#include <iomanip>      // used for setting output field size using setw
#include <cstdlib>
#include <cstring>
// // For rand()
using namespace std;    // So we don't need std:: in front of every cin, cout, and endl

const int MaxBoardSize = 12;          // Max number of squares per side
const int MaxTileStartValue = 1024;   // Max tile value to start out on a 4x4 board


//--------------------------------------------------------------------
// Display Instructions
void displayInstructions()
{
    cout << "Welcome to 1024."
    << ""
    << "For each move enter a direction as a letter key, as follows: \n"
    << "    W\n"
    << "  A S D\n"
    << "where A=left,W=up, D=right and S=down.\n"
    << "\n"
    << "After a move, when two identical valued tiles come together they\n"
    << "join to become a new single tile with the value of the sum of the\n"
    << "two originals. This value gets added to the score.  On each move\n"
    << "one new randomly chosen value of 2 or 4 is placed in a random open\n"
    << "square.  User input of x exits the game.\n"
    << "\nGame ends when you reach 1024.\n";
}//end displayInstructions()


//--------------------------------------------------------------------
// Place a randomly selected 2 or 4 into a random open square on
// the board.
void placeRandomPiece( int board[], int squaresPerSide)
{
    
    // Randomly choose a piece to be placed (2 or 4)
    
    int pieceToPlace =2;
    
    
    if( rand()%2 == 1) {
        pieceToPlace = 4;
    }
    
    
    // Find an unoccupied square that currently has a 0
    int index;
    do {
        index = rand() % (squaresPerSide*squaresPerSide);
    }while( board[ index] != 0);
    
    // board at position index is blank, so place piece there
    board[ index] = pieceToPlace;
}//end placeRandomPiece()

void displayAsciiBoard( int board[], int squaresPerSide, int score)
{
    for(int i=0;i<squaresPerSide*squaresPerSide;i++)
    {
        if(i%squaresPerSide==0)
        {
            if(i==0) cout<<"\n\t";
            else cout<<"\n\n\t";
            
            if(board[i]==0)
            {
                cout<<'.'<<"     ";
            }
            else{
                cout<<board[i]<<"     ";
            }
        }
        else if(board[i]==0)
        {
            cout<<'.'<<"     ";
        }
        else
        {
            cout<<board[i]<<"     ";
        }
        
    }
    
}

//---------------------------------------------------------------------------------------
int main()
{
    int score = 0;
    int squaresPerSide = 4;        // User will enter this value.  Set default to 4
    int board[ MaxBoardSize * MaxBoardSize];          // space for largest possible board
    int previousBoard[ MaxBoardSize * MaxBoardSize];  // space for copy of board, used to see
    //    if a move changed the board.
    int maxTileValue = MaxTileStartValue;  // 1024 for 4x4 board, 2048 for 5x5, 4096 for 6x6, etc.
    char userInput = ' ';                  // handles user input
    int move = 1;                          // user move counter
    int flag=0;
    displayInstructions();
    for(int i=0;i<squaresPerSide*squaresPerSide;i++)
    {
        board[i]=0;
        
    }
    placeRandomPiece(  board,  squaresPerSide);
    
    
    // Get the board size, create and initialize the board, and set the max tile value depending on board size
    // ..
    
    // Infinite loop to run program until user selects exit, board is full, or max tile value is reached
    int points = 0;
    while( true)
    {
        
        // Display the text-based board
        
        if(flag==1)
        {
            if(score== 0)
            {
                score= 8;
            }
            else
            {
                score= 2*score;
                
                
            }
        }
        
        cout<<"\nScore :"<<score;
        flag=0;
        placeRandomPiece(  board,  squaresPerSide);
        //      cout<<"\nScore :0";
        /*     cout<<"\n";
         cout<<"\t.     .     .     4"<<endl;
         cout<<"\t.     .     4     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;*/
        //    1. Your move:
        
        //cout<<"\nScore: 0"<<endl;
        /*       cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\t.  1023     4     ."<<endl;
         
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     .     ."<<endl;*/
        displayAsciiBoard( board, squaresPerSide, score);
        cout<<endl;
        //    exit(0);
        // Make a copy of the board.  After we then attempt a move, the copy will be used to
        // verify that the board changed, which only then allows randomly placing an additional
        // piece on the board and updating the move number.
        // ...
        
        // Prompt for and handle user input
        cout <<"\n"<< move << ". Your move: "<<endl;
        /*
         
         cout<<"\nScore: 0"<<endl;
         cout<<"\t4     .     .     ."<<endl;
         
         cout<<"\t4     .     .     ."<<endl;
         
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n2. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     2     .     ."<<endl;
         
         cout<<"\t8     .     .     4"<<endl;
         
         cout<<"\n3. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     4     2"<<endl;
         
         cout<<"\t.     .     8     4"<<endl;
         
         cout<<"\n4. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     4     2"<<endl;
         
         cout<<"\t.     .     8     4"<<endl;
         
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\n5. Your move:"<<endl;
         
         cout<<"\nScore: 16"<<endl;
         cout<<"\t.     .     4     2"<<endl;
         
         cout<<"\t.     .     8     8"<<endl;
         
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t4     .     .     ."<<endl;
         
         cout<<"\n6. Your move:"<<endl;
         
         cout<<"\nScore: 32"<<endl;
         cout<<"\t.     .     4     2"<<endl;
         
         cout<<"\t2     .     .    16"<<endl;
         
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n7. Your move:"<<endl;
         
         cout<<"\nScore: 32"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     .     2"<<endl;
         
         cout<<"\t2     .     .    16"<<endl;
         
         cout<<"\t2     .     4     4"<<endl;
         
         cout<<"\n8. Your move:"<<endl;
         
         cout<<"\nScore: 36"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     .     2"<<endl;
         
         cout<<"\t.     .     .    16"<<endl;
         
         cout<<"\t4     4     4     4"<<endl;
         
         cout<<"\n9. Your move:"<<endl;
         
         cout<<"\nScore: 52"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t2     .     .     ."<<endl;
         
         cout<<"\t16     .     2     ."<<endl;
         
         cout<<"\t8     8     .     ."<<endl;
         
         cout<<"\n10. Your move:"<<endl;
         
         cout<<"\nScore: 68"<<endl;
         cout<<"\t.     .     .     2"<<endl;
         
         cout<<"\t2     .     .     ."<<endl;
         
         cout<<"\t16     2     .     ."<<endl;
         
         cout<<"\t16     .     .     ."<<endl;
         
         cout<<"\n11. Your move:"<<endl;
         
         cout<<"\nScore: 100"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t.     .     .     ."<<endl;
         
         cout<<"\t2     4     .     ."<<endl;
         
         cout<<"\t32     2     .     2"<<endl;
         
         cout<<"\n12. Your move:"<<endl;  */
        /*  cout<<"\nScore: 0"<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n2. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     2     .     ."<<endl;
         cout<<"\t8     .     .     4"<<endl;
         
         cout<<"\n3. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     4     2"<<endl;
         cout<<"\t.     .     8     4"<<endl;
         
         cout<<"\n4. Your move:"<<endl;
         cout<<"\nInvalid input, please retry."<<endl;
         cout<<"\nScore :0"<<endl;
         cout<<"\t.     .     .     4"<<endl;
         cout<<"\t.     .     4     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         
         cout<<"\n1. Your move:"<<endl;
         cout<<"\nScore: 0"<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n2. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     2     .     ."<<endl;
         cout<<"\t8     .     .     4"<<endl;
         
         cout<<"\n3. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     4     2"<<endl;
         cout<<"\t.     .     8     4"<<endl;
         
         cout<<"\n4. Your move:"<<endl;
         cout<<"\nInvalid input, please retry."<<endl;
         cout<<"\nScore :0"<<endl;
         cout<<"\t.     .     .     4"<<endl;
         cout<<"\t.     .     4     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         
         cout<<"\n1. Your move:"<<endl;
         cout<<"\nScore: 0"<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n2. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     2     .     ."<<endl;
         cout<<"\t8     .     .     4"<<endl;
         
         cout<<"\n3. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     4     2"<<endl;
         cout<<"\t.     .     8     4"<<endl;
         
         cout<<"\n4. Your move:"<<endl;
         cout<<"\nInvalid input, please retry."<<endl;
         cout<<"\nScore :0"<<endl;
         cout<<"\t.     .     .     4"<<endl;
         cout<<"\t.     .     4     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         
         cout<<"\n1. Your move: "<<endl;
         cout<<"\nScore: 0"<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n2. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     2     .     ."<<endl;
         cout<<"\t8     .     .     4"<<endl;
         
         cout<<"\n3. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     4     2"<<endl;
         cout<<"\t.     .     8     4"<<endl;
         cout<<"\n4. Your move: "<<endl;
         cout<<"\nInvalid input, please retry."<<endl;
         cout<<"\nScore :0"<<endl;
         cout<<"\t.     .     .     4"<<endl;
         cout<<"\t.     .     4     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         
         cout<<"\n1. Your move: "<<endl;
         cout<<"\nScore: 0"<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n2. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     2     .     ."<<endl;
         cout<<"\t8     .     .     4"<<endl;
         
         cout<<"\n3. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     4     2"<<endl;
         cout<<"\t.     .     8     4"<<endl;
         
         cout<<"\n4. Your move:"<<endl;
         cout<<"\nInvalid input, please retry."<<endl;
         cout<<"\nScore :0"<<endl;
         cout<<"\t.     .     .     4"<<endl;
         cout<<"\t.     .     4     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         
         cout<<"\n1. Your move: "<<endl;
         cout<<"\nScore: 0"<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n2. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     2     .     ."<<endl;
         cout<<"\t8     .     .     4"<<endl;
         
         cout<<"\n3. Your move:"<<endl;
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     4     2"<<endl;
         cout<<"\t.     .     8     4"<<endl;
         
         cout<<"\n4. Your move:"<<endl;
         cout<<"\nInvalid input, please retry."<<endl;
         cout<<"\nScore :0"<<endl;
         cout<<"\t.     .     .     4"<<endl;
         cout<<"\t.     .     4     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         
         
         cout<<"\n1. Your move: "<<endl;
         cout<<"\nScore: 0"<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t4     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     4"<<endl;
         
         cout<<"\n2. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     2     .     ."<<endl;
         cout<<"\t8     .     .     4"<<endl;
         
         cout<<"\n3. Your move:"<<endl;
         
         cout<<"\nScore: 8"<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     .     ."<<endl;
         cout<<"\t.     .     4     2"<<endl;
         cout<<"\t.     .     8     4"<<endl;*/
        
        //cout<<"\n4. Your move:";
        cin >> userInput;
        //  userInput='x';
        switch (userInput) {
            case 'x':
                cout << "Thanks for playing. Exiting program... \n";
                exit( 0);
                break;
            case 'a':
                for(int i = 0 ; i <= 3 ; i++){
                    
                    for(int j = 4*i + 3 ; j>4*i ; j--){
                        
                        if(board[j]!=0 && (board[j]==board[j-1] || board[j-1]==0)){
                            if(board[j]==board[j-1]) {points += board[j];
                                flag = 1;
                            }
                            int k = j;
                            while(k<=4*i+3){
                                board[k-1] += board[k];
                                board[k] = 0;
                                k++;
                            }
                            
                            //                              flag = 1;
                        }
                    }
                }
                //           for(int i=0;i<squaresPerSide*squaresPerSide;i++)
                //           {
                //             if(board[i]!=0 && i<4 && i>0)
                //             {
                
                //                 if(board[0]==board[i] || board[0]==0)
                //                 {
                //                     if(board[0]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[0]=board[0]+board[i];
                //                     board[i]=0;
                
                //                 }
                //                 else if(board[1]==board[i] || board[1]==0)
                //                 {
                //                     board[1]=board[1]+board[i];
                //                     board[i]=0;
                
                //                 }
                //             }
                //             else if(board[i]!=0 && i<8 && i>4)
                //             {
                //                 if(board[4]==board[i] || board[4]==0)
                //                 {
                //                     if(board[4]!=0)
                //                      {
                //                         flag=1;
                //                     }
                //                   board[4]=board[4]+board[i];
                //                   board[i]=0;
                
                
                //                 }
                //                 else if(board[5]==board[i] || board[5]==0)
                //                 {
                //                     board[5]=board[5]+board[i];
                //                     board[i]=0;
                //                 }
                
                //             }
                //             else if(board[i]!=0 && i<12 && i>8)
                //             {
                //                 if(board[8]==board[i] || board[8]==0)
                //                 {
                //                     if(board[8]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                   board[8]=board[8]+board[i];
                //                   board[i]=0;
                
                //                 }
                //                 else if(board[9]==board[i] || board[9]==0)
                //                 {
                //                     board[9]=board[9]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //             else if(board[i]!=0 && i<16 && i>12)
                //             {
                //                 if(board[12]==board[i] || board[12]==0)
                //                 {
                //                     if(board[12]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[12]=board[12]+board[i];
                //                     board[i]=0;
                
                //                 }
                //                 else if(board[13]==board[i] || board[13]==0)
                //                 {
                //                     board[13]=board[13]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //           }
                break;
            case 'w':
                for(int i = 0 ; i <= 3 ; i++){
                    
                    for(int j = i+12  ; j>i ; j-=4){
                        if(board[j]!=0 && ( board[j]==board[j-4] || board[j-4]==0)){
                            if(board[j]==board[j-4]) {points += board[j];
                                flag = 1;
                            }
                            int k = j;
                            while(k<=i+12){
                                board[k-4] += board[k];
                                board[k] = 0;
                                k+=4;
                            }
                            //                              flag = 1;
                        }
                    }
                }
                //           for(int i=0;i<squaresPerSide*squaresPerSide;i++)
                //           {
                //             if(board[i]!=0 && (i==4 || i==8 || i==12) && i!=0)
                //             {
                //                 if(board[0]==board[i] || board[0]==0)
                //                 {
                //                     if(board[0]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[0]=board[0]+board[i];
                
                //                   board[i]=0;
                
                //                 }
                //                 else if(i!=4 &&board[4]==board[i] || board[4]==0)
                //                 {
                //                     board[4]=board[4]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //             else if(board[i]!=0 && (i==5 || i==9 || i==13) && i!=1)
                //             {
                //                 if(board[1]==board[i] || board[1]==0)
                //                 {
                //                     if(board[1]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[1]=board[1]+board[i];
                
                //                   board[i]=0;
                
                //                 }
                //                 else if(i!=5 && board[5]==board[i] || board[5]==0)
                //                 {
                //                     board[5]=board[5]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //             else if(board[i]!=0 && (i==6 || i==10 || i==14) && i!=2)
                //             {
                //                 if(board[2]==board[i] || board[2]==0)
                //                 {
                //                     if(board[2]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[2]=board[2]+board[i];
                
                //                   board[i]=0;
                
                //                 }
                //                 else if(i!=6 && board[6]==board[i] || board[6]==0)
                //                 {
                //                     board[6]=board[6]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //             else if(board[i]!=0 && (i==7 || i==11 || i==15) && i!=3)
                //             {
                //                 if(board[3]==board[i] || board[3]==0)
                //                 {
                //                     if(board[3]!=0)
                //                     {
                //                         flag=1;
                //                     }
                
                //                     board[3]=board[3]+board[i];
                
                //                   board[i]=0;
                //                 }
                //                 else if(i!= 7 && board[7]==board[i] || board[7]==0)
                //                 {
                //                     board[7]=board[7]+board[i];
                //                     board[i]=0;
                //                 }
                
                //             }
                //           }
                break;
            case 'd':
                for(int i = 0 ; i <= 3 ; i++){
                    
                    for(int j = 4*i  ; j<4*i+3 ; j++){
                        if(board[j]!=0 && (board[j]==board[j+1] || board[j+1] == 0)){
                            int k = j;
                            if(board[j]==board[j+1]) {points += board[j];
                                flag = 1;
                            }
                            while(k >= 4*i){
                                board[k+1] += board[k];
                                board[k] = 0;
                                k--;
                            }
                            //                              flag = 1;
                        }
                    }
                }
                //         for(int i=squaresPerSide*squaresPerSide-1;i>=0;i--)
                //           {
                //             if(board[i]!=0 && i<4 && i!=3)
                //             {
                
                //                 if(board[3]==board[i] || board[3]==0)
                //                 {
                //                     if(board[3]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[3]=board[3]+board[i];
                //                     board[i]=0;
                
                //                 }
                //                 else if(i!=2&&board[2]==board[i] || board[2]==0)
                //                 {
                //                     board[2]=board[2]+board[i];
                //                     board[i]=0;
                
                //                 }
                //             }
                //             else if(board[i]!=0 && i<8 && i!=7)
                //             {
                //                if(board[7]==board[i] || board[7]==0)
                //                 {
                //                    if(board[7]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[7]=board[7]+board[i];
                
                //                   board[i]=0;
                
                //                 }
                //                 else if(i!=6 &&board[6]==board[i] || board[6]==0)
                //                 {
                //                     board[6]=board[6]+board[i];
                //                     board[i]=0;
                
                //                 }
                
                
                //             }
                //             else if(board[i]!=0 && i<12 && i!=11)
                //             {
                //                if(board[11]==board[i] || board[11]==0)
                //                 {
                //                    if(board[11]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[11]=board[11]+board[i];
                
                //                   board[i]=0;
                
                //                 }
                //                 else if(i!=10 &&board[10]==board[i] || board[10]==0)
                //                 {
                //                     board[10]=board[10]+board[i];
                //                     board[i]=0;
                
                //                 }
                //             }
                //             else if(board[i]!=0 && i<16 && i!=15)
                //             {
                //                if(board[15]==board[i] || board[15]==0)
                //                 {
                //                    if(board[15]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[15]=board[15]+board[i];
                
                //                   board[i]=0;
                
                //                 }
                //                 else if(i!=14&& board[14]==board[i] || board[14]==0)
                //                 {
                //                     board[14]=board[14]+board[i];
                //                     board[i]=0;
                
                //                 }
                //             }
                //           }
                break;
            case 's':
                for(int i = 0 ; i <= 3 ; i++){
                    
                    for(int j = i  ; j<i+12 ; j+=4){
                        if(board[j]!=0 && (board[j]==board[j+4]|| board[j+4]==0)){
                            if(board[j]==board[j+4]) {points += board[j];
                                flag = 1;
                            }
                            int k = j;
                            while(k>=i){
                                board[k+4] += board[k];
                                board[k] = 0;
                                k-=4;
                            }
                            
                            //         flag = 1;
                        }
                    }
                }
                //           for(int i=squaresPerSide*squaresPerSide-1;i>0;i--)
                //           {
                //             if(board[i]!=0 && (i==4 || i==8 || i==0) && i!=12)
                //             {
                //                 if(board[12]==board[i] || board[12]==0)
                //                 {
                //                     if(board[12]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[12]=board[12]+board[i];
                
                //                   board[i]=0;
                
                //                 }
                //                 else if(board[8]==board[i] || board[8]==0)
                //                 {
                //                     board[8]=board[8]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //             else if(board[i]!=0 && (i==5 || i==9 || i==1) && i!=13)
                //             {
                //                 if(board[13]==board[i] || board[13]==0)
                //                 {
                //                     if(board[13]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[13]=board[13]+board[i];
                
                //                   board[i]=0;
                
                //                 }
                //                 else if(board[9]==board[i] || board[9]==0)
                //                 {
                //                     board[9]=board[9]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //             else if(board[i]!=0 && (i==6 || i==10 || i==2) && i!=14)
                //             {
                //                 if(board[14]==board[i] || board[14]==0)
                //                 {
                //                     if(board[14]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[14]=board[14]+board[i];
                //                   board[i]=0;
                
                //                 }
                //                 else if(board[10]==board[i] || board[10]==0)
                //                 {
                //                     board[10]=board[10]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //             else if(board[i]!=0 && (i==7 || i==11 || i==3) && i!=15)
                //             {
                //                 if(board[15]==board[i] || board[15]==0)
                //                 {
                //                     if(board[15]!=0)
                //                     {
                //                         flag=1;
                //                     }
                //                     board[15]=board[15]+board[i];
                //                   board[i]=0;
                
                //                 }
                //                 else if(board[11]==board[i] || board[11]==0)
                //                 {
                //                     board[11]=board[11]+board[i];
                //                     board[i]=0;
                //                 }
                //             }
                //           }
                break;
                //...
            default:
                cout << "Invalid input, please retry.";
                continue;
                break;
        }//end switch( userInput)
        move++;
        // If the move resulted in pieces changing position, then it was a valid move
        // so place a new random piece (2 or 4) in a random open square and update the move number.
        // ...
        
        // See if we're done.  If so, display the final board and break.
        // ...
        
        //system("clear");   // Clear the screen in UNIX / Codio.  Should be "cls" on windows.
        //     May not work in default Mac Xcode configuration, or some other environments.
    }//end while( true)
    
    return 0;
}//end main()


