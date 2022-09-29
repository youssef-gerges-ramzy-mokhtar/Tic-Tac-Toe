#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// Functions For the Game //

void initialize_board(int boardSize, char board[boardSize][boardSize]) {
   // Iterating through the 2D Array and setting each element to the value '-'
   int i, j;
   for (i = 0; i < boardSize; i++) {
      for (j = 0; j < boardSize; j++) {
         board[i][j] = '-';
      }
   }
}


void display_board(int boardSize, char board[boardSize][boardSize]) {
   // Iterating through the 2D array and outputting each element in the 2D array to the screen
   int i, j;
   for (i = 0; i < boardSize; i++) {
      for (j = 0; j < boardSize; j++) {
         printf("%c", board[i][j]);
         printf(" ");
      }
      printf("\n");
   }
   printf("\n");
}


void update_board(int player, int rowUpdate, int colUpdate, int boardSize, char board[boardSize][boardSize]) {
   /* This Functions takes in 5 parameters:
      1) A integer value player that represents which player is updating the board
      2) A parmeter called rowUpdate which is an integer representing the row value the player selected
      3) A parameter called colUpdate which is an integer representing the column value the player selected
      4) the size of the board 2D array
      5) The 2D array passed by reference and altered inside the function
   */

   // Decrementing the rowUpdate and the colUpdate, because the board from the user point of view starts from a 1-based board
   rowUpdate--;
   colUpdate--;

   if (player == 1) board[rowUpdate][colUpdate] = 'X';
   else board[rowUpdate][colUpdate] = 'O';
}


int switch_player(int prevPlayer) {
   if (prevPlayer == 1) return 2;
   if (prevPlayer == 2) return 1;
}


int check_winner_rows(int boardSize, char board[boardSize][boardSize]) {
   // This Funciton is used to check all rows in the 2D Array board and see if any player has filled any row, and returns 1 if palyer 1 wins
   // and returns 2 if player 2 wins, and returns 0 if no player have won


   // Iterating through the 2D Array, and checking if all elements in the row is equal
   for (int row = 0; row < boardSize; row++) {
      int winnerDetected = 0;
      for (int col = 0; col < (boardSize - 1); col++) {
         if (board[row][col] == board[row][col + 1]) {
            winnerDetected++;
         }
      }

      if (winnerDetected == (boardSize - 1)) {
         if (board[row][0] == 'X') return 1;
         else if (board[row][0] == 'O') return 2;
      }
   }

   return 0;
}


int check_winner_columns(int boardSize, char board[boardSize][boardSize]) {
   // This Funciton is used to check all columns in the 2D Array board and see if any player has filled any column, and returns 1 if palyer 1 wins
   // and returns 2 if player 2 wins, and returns 0 if no player have won


   // Iterating through the 2D Array, and checking if all elements in the colulmn is equal
   for (int col = 0; col < boardSize; col++) {
      int winnerDetected = 0;
      for (int row = 0; row < (boardSize - 1); row++) {
         if (board[row][col] == board[row + 1][col]) {
            winnerDetected++;
         }
      }

      if (winnerDetected == (boardSize - 1)) {
         if (board[0][col] == 'X') return 1;
         else if (board[0][col] == 'O') return 2;
      }
   }

   return 0;
}


int check_winner_increasing_diagonals(int boardSize, char board[boardSize][boardSize]) {
   // This Funciton is used to check the increasing element position diagonal in the 2D Array board and see if any player has filled the diagonal,
   // and returns 1 if palyer 1 wins and returns 2 if player 2 wins, and returns 0 if no player have won
   
   int col, row;
   int winnerDetected = 0;

   // Iterating through the 2D Array, and checking if all elements in the increasing element position diagonal is equal
   for (int row = 0; row < (boardSize - 1); row++) {
      if (board[row][row] == board[row + 1][row + 1]) {
         winnerDetected++;
      }
   }

   if (winnerDetected == (boardSize - 1)) {
      if (board[0][0] == 'X') return 1;
      else if (board[0][0] == 'O') return 2;
   }

   return 0;
}


int check_winner_decreasing_diagonals(int boardSize, char board[boardSize][boardSize]) {
   // This Funciton is used to check the decreasing element position diagonal in the 2D Array board and see if any player has filled the diagonal,
   // and returns 1 if palyer 1 wins and returns 2 if player 2 wins, and returns 0 if no player have won

   int col, row;
   int winnerDetected = 0;

   // Iterating through the 2D Array, and checking if all elements in the decreasing element position diagonal is equal
   for (row = 0; row < (boardSize - 1); row++) {
      if (board[row][(boardSize - 1) - row] == board[row + 1][(boardSize - 1) - row - 1]) {
         winnerDetected++;
      }
   }

   if (winnerDetected == (boardSize - 1)) {
      if (board[0][boardSize - 1] == 'X') return 1;
      else if (board[0][boardSize - 1] == 'O') return 2;
   }

   return 0;
}


int winner(int boardSize, char board[boardSize][boardSize]) {
   // This Functions runs every time the player finishes playing to check if there is any player that have won

   // We call the check_winner_rows function to check if there is any row in the 2D array board convered by any player
   int rowCheck = check_winner_rows(boardSize, board);
   if (rowCheck == 1) return 1;
   else if (rowCheck == 2) return 2;

   // We call the check_winner_columns function to check if there is any column in the 2D array board convered by any player
   int colCheck = check_winner_columns(boardSize, board);
   if (colCheck == 1) return 1;
   else if (colCheck == 2) return 2;

   // We call the check_winner_increasing_diagonals function to check if there is any increasing element position diagonal in the 2D array board convered by any player
   int diagonalCehck1 = check_winner_increasing_diagonals(boardSize, board);
   if (diagonalCehck1 == 1) return 1;
   else if (diagonalCehck1 == 2) return 2;

   // We call the check_winner_decreasing_diagonals function to check if there is any decreasing element position diagonal in the 2D array board convered by any player
   int diagonalCheck2 = check_winner_decreasing_diagonals(boardSize, board);
   if (diagonalCheck2 == 1) return 1;
   else if (diagonalCheck2 == 2) return 2;

   // If all the above cases fail, that means the function is not exited and there is no return statement is executed, so a 0 is returend to indicate that no player have won
   return 0;
}


//////////////////////////////////////
// Functions for User Input Validation
//////////////////////////////////////

bool invalid_value(int boardSize, int rowUpdate, int colUpdate) {
   /* 
      The function takes in the following parameters
         1) the row value the user inputted
         2) the column value the user inputted
         3) the size of the 2D array
   */
   // This Function returns true if the rowUpdate or colUpdate is negative or is a value larger than the size of the 2D Array Board
   // This Function returns false if the user inputted a correct range value for rowUpdate & colUpdate   
   
   if (rowUpdate <= 0 || colUpdate <= 0 || rowUpdate > boardSize || colUpdate > boardSize) return true;

   return false;
}

bool repeated_position(int rowUpdate, int colUpdate, int boardSize, char board[boardSize][boardSize]) {
   /* 
      The function takes in the following parameters
         1) the row value the user inputted
         2) the column value the user inputted
         3) the size of the 2D array
         4) a 2D array of characters
     
      This Functions return true if the user inputted a position that was used before
      This Function returns false if the user choosed a position that was not used before
   */
   
   // We called invalid_value here, because maybe we can use a value that is above than the array bounds, and when accessing out of bounds in arrays
   // undefined behaviour may occur if the array is accessed out of bounds
   if (invalid_value(boardSize, rowUpdate, colUpdate)) return true;
   if (board[rowUpdate - 1][colUpdate - 1] != '-') return true;

   return false;
}

bool invalid_datatype(int scanfValue) {
   // A function that takes in one paremeter called scanfValue
   // This Function checks if the scanf called return a value not equal to 2, if that is the case the function returns true indicating that the 
   // scanf couldn't store 2 values, else a false is returned indicating that the scanf successfully stored 2 values
   // The 2 Values reprsent the rowUpdate & colUpdate variables inputted in by the user

   if (scanfValue != 2) return true;

   return false;
}

bool validation_check(int rowUpdate, int colUpdate, int boardSize, char board[boardSize][boardSize], int scanfValue) {
   /* a function that takes in the following parameters
         1) the row value the user inputted
         2) the column value the user inputted
         3) the size of the 2D array
         4) the 2D Array of Characters
         5) The scanfValue returned when calling the scanf built-in function
      
      This Function returns true if there is an error in the user input
      This Function returns false if there is no error in the user input 
   */

   // If any of the two tests are true the function returns true indicating there is a problem with the input
   // otherwise the function returns false indicating that there is no any errors in the user input
   bool test1 = repeated_position(rowUpdate, colUpdate, boardSize, board);
   bool test2 = invalid_datatype(scanfValue);
   if (test1 || test2) return true;

   return false;
}


void scanf_problems_absorber(char dummy[], int dummyTextLength) {
   // Thif functoin receives 2 parameters, an array of characters called dummy, and the length of the dummy array called dummyTextLength
   // Finally this function executes the built-in functoin fgets and store the result of fgets in the dummy array

   // This command when executed after a scanf statement absorbes any extras of the scanf
   // example inputting 2,2 then the scanf will store \n in the input buffer, which will be used by fgets and stored in dummy
   // so dummy will be equal dummy = ['\n','\0'];
   // example inputting 3,5randomtext the scanf will use the value 3 and 5, and store this values in the specified variables and the extra test inputtted
   // will be stored in the input buffer, which will be used by fgets and stored in dummy, so dummy will be equal dummy = ['r','a','n','d','o','m','t','e','x','t','\0']
   
   // This is used that if a user inputted an invalid DATA TYPE, the fgets store the the value inputted that is stored in the buffer, so when using another scanf call
   // is used it scans only the user input not the data stored in the buffer, also that we don't run into an inifinte loop when validating invalid datatype
   // For example if you inputted (Text) instead of (1,1) the buffer will store the value Text, then we use the fgets to empty the buffer and store the value (Text) to dummy
   // Also is used that if a user inputted a correct input followed by any other data, only the correct input will be used and ony other data will be stored
   // in the buffer, and the fgets get this data and store it in the dummy array, so fgets is used before any scanf call.

   // Even if the user inputted a string larger than 250 characters (which reprsent the lenght of the dummy array), simply 2 printf invalid statements will be outputted,
   // This is because the while loop is accessed twice as if we inputted 350 characters for example 350 - 250 = 100 additional characters will be stored in the input buffer
   // and this will make the scanf to read to use the value stored in the input buffer, and this will cause the loop to be enterd again
   // because the scanf_value variable will hold 0, then the fgets will be used once again and is used to store the additional 100 characters stoerd in the input buffer
   // and the user will be prompted to try again

   // Also we could have implemented this by using a built-in function that clears the data stored in the input buffer, but we didn't yet learned about this built-in function
   
   fgets(dummy, dummyTextLength, stdin);
}

int* coordinates_input(int* currentPlayer) {
   char dummyText[250];
   int rowUpdate, colUpdate;

   if (*currentPlayer == 1) printf("Player 1 - Place mark: ");
   if (*currentPlayer == 2) printf("Player 2 - Place mark: ");

   scanf_problems_absorber(dummyText, 250); // Running the scanf_problems_absorber to store any extra values from the previous scanf call
   int scanf_value = scanf("%d , %d", &rowUpdate, &colUpdate);

   // The data Array holds the coordinates and the scanf_value
   int* data = malloc(sizeof(int) * 3);
   data[0] = rowUpdate;
   data[1] = colUpdate;
   data[2] = scanf_value;

   return data;
}

void user_input(int* currentPlayer, int size_of_board, char board[size_of_board][size_of_board]) {
   char dummyText[250];
   int* data = coordinates_input(currentPlayer);
   int scanf_value = data[2];
   int coordinates[2] = {data[0], data[1]};

   // Entering a while loop as long as calling the validation_check returns true, to check if the user inputted invalid coordinates, or any invalid thing
   while (validation_check(coordinates[0], coordinates[1], size_of_board, board, scanf_value)) {
      printf("Invalid Position. Please Try Again\n");
      display_board(size_of_board, board);

      data = coordinates_input(currentPlayer);
      coordinates[0] = data[0];
      coordinates[1] = data[1];
   }
   
   update_board(*currentPlayer, coordinates[0], coordinates[1], size_of_board, board); // Calling the update_board function to print the updated grid based on the user inputs
   display_board(size_of_board, board);
   *currentPlayer = switch_player(*currentPlayer);
}


// Main Function
int main()
{
   char dummyText[250];
   int size_of_board;

   // Promppting the user to input the size of 2D array board he want to use
   printf("Welcome To Tic Tac Toe Game\n\n");
   printf("Enter Board Size: ");
   scanf("%d", &size_of_board);

   // Validating the user input by checking that the board is less or equal to 1, or that the board is larger than 50
   while (size_of_board <= 1 || size_of_board > 50) {
      if (size_of_board <= 0) printf("Invalid (Using Negative Numbers or Zero Value) Try Again\n");
      else if (size_of_board == 1) printf("Board is too small this is a 2 Player game (Please Choose a higher Board Size)\n");
      else printf("You used a very large Board Size, try using a smaller board\n");
      
      printf("Enter Board Size: ");
      
      // Using the scanf_problems_absorber to store any unwanted text preceeding the size_of_board in the array dummyText
      scanf_problems_absorber(dummyText, 250);
      scanf("%d", &size_of_board);
   }

   // Declaring the board based on the user input
   char board[size_of_board][size_of_board];

   // Calling the initialize_board & the display_board functions
   initialize_board(size_of_board, board);
   display_board(size_of_board, board);

   // Declaring a variabble i to determine if we reached the end of the 2D array size
   int gameState = 0;
   int moves_made = 1; // change the name of i
   int player = 1;

   while ( (gameState == 0) && (moves_made <= (size_of_board * size_of_board)) ) {
      int scanf_value;
      int rowUpdate, colUpdate;

      user_input(&player, size_of_board, board);
      
      // Updating gameState only after i is greater than or equal to the (size of the board * 2) - 1
      // This is because it is impossible for a player to win until the 2 players have filled in at least (size of the board * 2) - 1
      if (moves_made >= ((size_of_board * 2) - 1)) gameState = winner(size_of_board, board);

      moves_made++;
   }

   if (gameState == 1) printf("Congratulations! Player 1 Won");
   else if (gameState == 2) printf("Congratulations! Player 2 Won");
   else printf("Draw Match");

   return 0;
}


// This is just optional & I commented out, because for any 2 by 2 board game of tic tac toe always the first palyer wins regardless of the positions he choose on the board
// if (size_of_board == 2) {
//    gameState = 1;
// } 