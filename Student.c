

#include <stdio.h>
#include <stdlib.h>
#include "Student.h"


// assume that this is player 1, X
int* getMove(int board[][SIZE], int *move)
{ int i,j;
int position[2]={-1};
int self=1;
int opp=2;
move[0]=-1;
move[1]=-1;


//Look for "blockable" opponent's moves.
for(i=0;i<SIZE;i++)

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(board[i][j]==opp)
            {
                position[0]=i;
                position[1]=j;
                move=blockOpponent(position,board,self,opp,move);
                if(move[0]!=-2 && move[1]!=-2)
                {
                    return move;
                }
            }
        }
    }

//If board empty; When self is player 1.
    if(move[0]==-1 && move[1]==-1)
    {
        if(board[4][4]==0)
        {
            move[0]=4;
            move[1]=4;
            return move;
        }

    }

// If no "blockable" opponents; make a move
    if(move[0]==-2 && move[1]== -2)
    {
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(board[i][j]==self)
            {
                position[0]=i;
                position[1]=j;
                move=makemove(position,board,self,opp,move);
                if(move[0]!=-1 && move[1]!=-1)
                {
                    return move;
                }
            }
        }
    }
    }

//When Opponent is Player 1;
     if(move[0]==-2 && move[1]==-2)
    {
        if(board[4][4]==0)
        {
            move[0]=4;
            move[1]=4;
            return move;
        }
        else
        {
            move[0]=9;
            move[1]=9;
            return move;
        }

    }



  return move;
  }


/***************************
Function --- makemove()
        inputs:int position[2]: The position about which patterns have to be searched for.
               int board[][SIZE]: The board
               int self: Self Player number (1 or 2)
               int opp: Opponent's number (1 or 2)
               int* move : Move pointer.
        function: Checks for possible patterns all around the position defined by the
                  array position.Implements 2 pointers for each direction about the
                  central piece.8 directions in total.(vertical, horizontal, diagonal
                  left, diagonal right; each of them split into top and down).
        output: returns the pointer move.

******************************/


int* makemove(int position[2],int board[][SIZE], int self, int opp, int* move)
{
    int i,j;
    int p,q;
    int count=1;
    move[0]=-1;
    move[1]=-1;

    int row=position[0];
    int col=position[1];

    //ALL INCREMENTORS FOR ALL DIRECTIONS

    //diagonal top right
    int diag_topright_x=1;
    int diag_topright_y=1;

    //diagonal top left
    int diag_topleft_x=-1;
    int diag_topleft_y=1;

    //diagonal down right
    int diag_downright_x=1;
    int diag_downright_y=-1;

    //diagonal down left
    int diag_downleft_x=-1;
    int diag_downleft_y=-1;

    //horizontal left
    int hor_left_x=-1;
    int hor_left_y=0;

    //horizontal right
    int hor_right_x=1;
    int hor_right_y=0;

    //vertical up
    int ver_up_x=0;
    int ver_up_y=1;

    //vertical down
    int ver_down_x=0;
    int ver_down_y=-1;


    //################################ HORIZONTAL

    //First horizontal right;
     for(i=1;i<5;i++)
    {
        if(row+hor_right_x*i>SIZE-2 || col+hor_right_y*i>SIZE-2)
        {
            break;
        }
        q=board[row+hor_right_x*i][col+hor_right_y*i];
        p=board[row+hor_right_x*(i+1)][col+hor_right_y*(i+1)];
        if(q==self)
        {
            count++;
        }
        if(q==opp)
        {
            break;
        }
        if(q==0)
        {
            if(p==opp)
            {
                if(count==4)
                {
                    move[0]=row+hor_right_x*i;
                    move[1]=col+hor_right_y*i;
                    return move;
                }
                else
                {
                    break;
                }
            }
            else
            {
                move[0]=row+hor_right_x*i;
                move[1]=col+hor_right_y*i;
                return move;
            }
        }
        if(p==opp)
        {
            break;
        }
        if(q==self && p==0)
        {
            move[0]=row+hor_right_x*(i+1);
            move[1]=col+hor_right_y*(i+1);
            return move;
        }

    }

    //Second Horizontal left

    for(i=1;i<5;i++)
    {
        if(row+hor_left_x*i<0|| col+hor_left_y*i<0)
        {
            break;
        }

        q=board[row+hor_left_x*i][col+hor_left_y*i];
        p=board[row+hor_left_x*i][col+hor_left_y*(i+1)];
        if(q==self)
        {
            count++;
        }
        if(q==opp)
        {
            break;
        }
        if(q==0)
        {
            if(p==opp)
            {
                if(count==4)
                {
                    move[0]=row+hor_left_x*i;
                    move[1]=col+hor_left_y*i;
                    return move;
                }
                else
                {
                    break;
                }
            }
            else
            {
                move[0]=row+hor_left_x*i;
                move[1]=col+hor_left_y*i;
                return move;
            }
        }

        if(p==opp)
        {
            break;
        }

        if(q==self && p==0)
        {
            move[0]=row+hor_left_x*(i+1);
            move[1]=col+hor_left_y*(i+1);
            return move;
        }


    }

    count=1;
    //############################ CHECKING VERTICAL

    //First vertical up of the central piece.
    for(i=1;i<5;i++)
    {
         if(row+ver_up_x*i>SIZE-2 || col+ver_up_y*i>SIZE-2)
        {
            break;
        }

        q=board[row+ver_up_x*i][col+ver_up_y*i];
        p=board[row+ver_up_x*i+ver_up_x][col+ver_up_y*i+ver_up_y];
        if(q==self)
        {
            count++;
        }
        if(q==opp)
        {
            break;
        }
        if(q==0)
        {
            if(p==opp)
            {
                 if(count==4)
                {
                    move[0]=row+ver_up_x*i;
                    move[1]=col+ver_up_y*i;
                    return move;
                }
                else
                {
                    break;
                }
            }
            else
            {
                move[0]=row+ver_up_x*i;
                move[1]=col+ver_up_y*i;
                return move;

            }
        }
        if(p==opp)
        {
            break;
        }
        if(q==self && p==0)
        {
            move[0]=row+ver_up_x*i+ver_up_x;
            move[1]=col+ver_up_y*i+ver_up_y;
            return move;
        }


    }

    //Second Vertical down of the central piece

    for(i=1;i<5;i++)
    {
         if(row+ver_down_x*i<0 || col+ver_down_y*i<0)
        {
            break;
        }

        q=board[row+ver_down_x*i][col+ver_down_y*i];
        p=board[row+ver_down_x*i+ver_down_x][col+ver_down_y*i+ver_down_y];
        if(q==self)
        {
            count++;
        }
        if(q==opp)
        {
            break;
        }
        if(q==0)
        {
            if(p==opp)
            {
                 if(count==4)
                {
                    move[0]=row+ver_down_x*i;
                    move[1]=col+ver_down_y*i;
                    return move;
                }
                else
                {
                    break;
                }
            }
            else
            {
                move[0]=row+ver_down_x*i;
                move[1]=col+ver_down_y*i;
                return move;

            }
        }
        if(p==opp)
        {
            break;
        }
        if(q==self && p==0)
        {
            move[0]=row+ver_down_x*i+ver_down_x;
            move[1]=col+ver_down_y*i+ver_down_y;
            return move;
        }
    }



    count=1;

    //#############################CHECKING LEFT-TO-RIGHT '/' DIAGONAL

    //First Diagonal-top-right of the central piece
    for(i=1;i<5;i++)
    {

        if(row+diag_topright_x*i>SIZE-2 || col+diag_topright_y*i>SIZE-2)
        {
            break;
        }

        q=board[row+diag_topright_x*i][col+diag_topright_y*i];
        p=board[row+diag_topright_x*i+diag_topright_x][col+diag_topright_y*i+diag_topright_y];
        if(q==self)
        {
            count++;
        }
        if(q==opp)
        {
            break;
        }
        if(q==0)
        {
            if(p==opp)
            {
                 if(count==4)
                {
                    move[0]=row+diag_topright_x*i;
                    move[1]=col+diag_topright_y*i;
                    return move;
                }
                else
                {
                    break;
                }
            }
            else
            {
                move[0]=row+diag_topright_x*i;
                move[1]=col+diag_topright_y*i;
                return move;

            }
        }
        if(p==opp)
        {
            break;
        }
        if(q==self && p==0)
        {
            move[0]=row+diag_topright_x*i+diag_topright_x;
            move[1]=col+diag_topright_y*i+diag_topright_y;
            return move;
        }

    }
    //Second Diagonal-down-left of the central move

    for(i=1;i<6;i++)
    {
        if(row+diag_downleft_x*i< 0 || col+diag_downleft_y*i<0)
        {
            break;
        }
        q=board[row+diag_downleft_x*i][col+diag_downleft_y*i];
        p=board[row+diag_downleft_x*i+diag_downleft_x][col+diag_downleft_y*i+diag_downleft_y];
        if(q==self)
        {
            count++;
        }
        if(q==opp)
        {
            break;
        }
        if(q==0)
        {
            if(p==opp)
            {
                 if(count==4)
                {
                    move[0]=row+diag_downleft_x*i;
                    move[1]=col+diag_downleft_y*i;
                    return move;
                }
                else
                {
                    break;
                }
            }
            else
            {
                move[0]=row+diag_downleft_x*i;
                move[1]=col+diag_downleft_y*i;
                return move;
            }

        }
        if(p==opp)
        {
            break;
        }
        if(q==self && p==0)
        {
            move[0]=row+diag_downleft_x*i+diag_downleft_x;
            move[1]=col+diag_downleft_y*i+diag_downleft_y;
            return move;
        }

    }

     count=1;

//#############################CHECKING RIGHT-TO-LEFT \ DIAGONAL

 //First Diagonal-top-left of the central move
    for(i=1;i<6;i++)
    {
         if(row+diag_topleft_x*i < 0 || col+diag_topleft_y*i>SIZE-2)
        {
            break;
        }

        q=board[row+diag_topleft_x*i][col+diag_topleft_y*i];
        p=board[row+diag_topleft_x*i+diag_topleft_x][col+diag_topleft_y*i+diag_topleft_y];
        if(q==self)
        {
            count++;
        }
        if(q==opp)
        {
            break;
        }
        if(q==0)
        {
            if(p==opp)
            {
                if(count==4)
                {
                    move[0]=row+diag_topleft_x*i;
                    move[1]=col+diag_topleft_y*i;
                    return move;
                }
                else
                {
                    break;
                }
            }
            else
            {
                move[0]=row+diag_topleft_x*i;
                move[1]=col+diag_topleft_y*i;
                return move;
            }

        }
        if(p==opp)
        {
            break;
        }
        if(q==self && p==0)
        {
            move[0]=row+diag_topleft_x*i+diag_topleft_x;
            move[1]=col+diag_topleft_y*i+diag_topleft_y;
            return move;
        }

    }


    //Second Diagonal-down-right of the central move

        for(i=1;i<5;i++)
    {
         if(row+diag_downright_x*i>SIZE -2 || col+diag_downright_y*i < 0)
        {
            break;
        }
        q=board[row+diag_downright_x*i][col+diag_downright_y*i];
        p=board[row+diag_downright_x*i+diag_downright_x][col+diag_downright_y*i+diag_downright_y];
        if(q==self)
        {
            count++;
        }
        if(q==opp)
        {
            break;
        }
        if(q==0 &&  p==opp)
        {
            if(p==opp)
            {
                if(count==4)
                {
                    move[0]=row+diag_downright_x*i;
                    move[1]=col+diag_downright_y*i;
                    return move;
                }
                else
                {
                    break;
                }
            }
            else
            {
                move[0]=row+diag_downright_x*i;
                move[1]=col+diag_downright_y*i;
                return move;
            }

        }
        if(p==opp)
        {
            break;
        }
        if(q==self && p==0)
        {
            move[0]=row+diag_downright_x*i+diag_downright_x;
            move[1]=col+diag_downright_y*i+diag_downright_y;
            return move;
        }


    }

    return move;
}

/***********************************
Function blockOpponent()
            inputs:int position[2]: The position about which patterns have to be searched for.
                   int board[][SIZE]: The board
                   int self: Self Player number (1 or 2)
                   int opp: Opponent's number (1 or 2)
                   int* move : Move pointer.
            function:Similar to makemove(). Searches for opponent position given by the position
                     array. Uses 2 pointers for every direction. Checks only 4 directions due to
                     symmetry and the nature of traversal of the board.
            output: Returns the pointer move.
************************************/


int* blockOpponent(int position[2],int board[][SIZE],int self, int opp, int* move)
{
    int i,j,p,q;
    int count=1;
    int row=position[0];
    int col=position[1];

    move[0]=-2;
    move[1]=-2;

    //ALL INCREMENTORS FOR ALL DIRECTIONS

    //diagonal top right
    int diag_topright_x=1;
    int diag_topright_y=1;

    //diagonal top left
    int diag_topleft_x=-1;
    int diag_topleft_y=1;

    //diagonal down right
    int diag_downright_x=1;
    int diag_downright_y=-1;

    //diagonal down left
    int diag_downleft_x=-1;
    int diag_downleft_y=-1;

    //horizontal left
    int hor_left_x=-1;
    int hor_left_y=0;

    //horizontal right
    int hor_right_x=1;
    int hor_right_y=0;

    //vertical up
    int ver_up_x=0;
    int ver_up_y=1;

    //vertical down
    int ver_down_x=0;
    int ver_down_y=-1;



    //horizontal right checking
    for(i=1;i<4;i++)
    {
        if((row+hor_right_x*i) > SIZE-2 || (col+hor_right_y*i)>SIZE-2)
        {
            break;
        }

        q=board[row+hor_right_x*i][col+hor_right_y*i];
        p=board[row+hor_right_x*(i+1)][col+hor_right_y*(i+1)];
        if(q==self|| p==self)
        {
            break;
        }
        if(q==0 && p==opp)
        {
            move[0]=row+hor_right_x*i;
            move[1]=col+hor_right_y*i;
            return move;
        }
        if(q==opp && p==0)
        {
            move[0]=row+hor_right_x*(i+1);
            move[1]=col+hor_right_y*(i+1);
            return move;
        }

    }

    //horizontal left check

     for(i=1;i<4;i++)
    {
        if((row+hor_left_x*i) <= 0 || (col+hor_left_y*i) < =0)
        {
            break;
        }

        q=board[row+hor_left_x*i][col+hor_left_y*i];
        p=board[row+hor_left_x*(i+1)][col+hor_left_y*(i+1)];
        if(q==self|| p==self)
        {
            break;
        }
        if(q==0 && p==opp)
        {
            move[0]=row+hor_left_x*i;
            move[1]=col+hor_left_y*i;
            return move;
        }
        if(q==opp && p==0)
        {
            move[0]=row+hor_left_x*(i+1);
            move[1]=col+hor_left_y*(i+1);
            return move;
        }

    }

    //diagonal top-left from the given position

    for(i=1;i<4;i++)
    {
        if((row+diag_topleft_x*i) < = 0 || (col+diag_topleft_y*i)>SIZE-2)
        {
            break;
        }

        q=board[row+diag_topleft_x*i][col+diag_topleft_y*i];
        p=board[row+diag_topleft_x*(i+1)][col+diag_topleft_y*(i+1)];
        if(q==self|| p==self)
        {
            break;
        }
        if(q==0 && p==opp)
        {
            move[0]=row+diag_topleft_x*i;
            move[1]=col+diag_topleft_y*i;
            return move;
        }
        if(q==opp && p==0)
        {
            move[0]=row+diag_topleft_x*(i+1);
            move[1]=col+diag_topleft_y*(i+1);
            return move;
        }

    }

    //diagonal down-right from the given position

    for(i=1;i<4;i++)
    {
        if((row+diag_downright_x*i) > SIZE-2 || (col+diag_downright_y*i) <= 0)
        {
            break;
        }

        q=board[row+diag_downright_x*i][col+diag_downright_y*i];
        p=board[row+diag_downright_x*(i+1)][col+diag_downright_y*(i+1)];
        if(q==self|| p==self)
        {
            break;
        }
        if(q==0 && p==opp)
        {
            move[0]=row+diag_downright_x*i;
            move[1]=col+diag_downright_y*i;
            return move;
        }
        if(q==opp && p==0)
        {
            move[0]=row+diag_downright_x*(i+1);
            move[1]=col+diag_downright_y*(i+1);
            return move;
        }

    }


    // Diagonal-right-top of given position
    for(i=1;i<4;i++)
    {
        if((row+diag_topright_x*i) > SIZE-2 || (col+diag_topright_y*i)>SIZE-2)
        {
            break;
        }

        q=board[row+diag_topright_x*i][col+diag_topright_y*i];
        p=board[row+diag_topright_x*(i+1)][col+diag_topright_y*(i+1)];

        if(q==self || p==self)
        {
            break;
        }
        if(q==0 && p==opp)
        {
            move[0]=row+diag_topright_x*i;
            move[1]=col+diag_topright_y*i;
            return move;
        }
        if(q==opp && p==0)
        {
            move[0]=row+diag_topright_x*(i+1);
            move[1]=col+diag_topright_y*(i+1);
            return move;
        }

    }

      // Diagonal-down-left of given position
    for(i=1;i<4;i++)
    {
        if((row+diag_downleft_x*i) < =0 || (col+diag_downleft_y*i) < = 0)
        {
            break;
        }

        q=board[row+diag_downleft_x*i][col+diag_downleft_y*i];
        p=board[row+diag_downleft_x*(i+1)][col+diag_downleft_y*(i+1)];

        if(q==self || p==self)
        {
            break;
        }
        if(q==0 && p==opp)
        {
            move[0]=row+diag_downleft_x*i;
            move[1]=col+diag_downleft_y*i;
            return move;
        }
        if(q==opp && p==0)
        {
            move[0]=row+diag_downleft_x*(i+1);
            move[1]=col+diag_downleft_y*(i+1);
            return move;
        }

    }

    //vertical - up

    for(i=1;i<4;i++)
    {
        if((row+ver_up_x*i) < 0 || (col+ver_up_y*i)>SIZE-2)
        {
            break;
        }
        if((row+ver_up_x*(i+1)) < 0 || (col+ver_up_y*(i+1))<0)
        {
            break;
        }
        q=board[row+ver_up_x*i][col+ver_up_y*i];
        p=board[row+ver_up_x*(i+1)][col+ver_up_y*(i+1)];

        if(q==self|| p==self)
        {
            break;
        }
        if(q==0 && p==opp)
        {
            move[0]=row+ver_up_x*i;
            move[1]=col+ver_up_y*i;
            return move;
        }
        if(q==opp && p==0)
        {
            move[0]=row+ver_up_x*(i+1);
            move[1]=col+ver_up_y*(i+1);
            return move;
        }

    }

        //vertical - down

    for(i=1;i<4;i++)
    {
        if((row+ver_down_x*i) < 0 || (col+ver_down_y*i) < = 0)
        {
            break;
        }
        if((row+ver_down_x*(i+1) < 0 || (col+ver_down_y*(i+1)>SIZE-2)
        {
            break;
        }

        q=board[row+ver_down_x*i][col+ver_down_x_y*i];
        p=board[row+ver_down_x*(i+1)][col+ver_down_y*(i+1)];

        if(q==self|| p==self)
        {
            break;
        }
        if(q==0 && p==opp)
        {
            move[0]=row+ver_down_x*i;
            move[1]=col+ver_down_y*i;
            return move;
        }
        if(q==opp && p==0)
        {
            move[0]=row+ver_down_x*(i+1);
            move[1]=col+ver_down_y*(i+1);
            return move;
        }

    }




    return move;
}







