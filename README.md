# Gomoku-Strategy
Function move() has a strategy to win a game of Gomoku on a 15X15 board. 

Checks if there are any "blockable" moves by the opponent, i.e if there are more than 2 in a row for the opponent. If there is, that is the next move made (using the function blockOpponent() ). If not, a fresh move is made or a move is made to contribute towards an already existing pattern of one's piece (makemove() ). 

Both blockOpponent and makemove take a rudimentary strategy of searching in all directions once a piece is encountered.
