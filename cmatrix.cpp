
// ============================================================================
// File: cmatrix.cpp
// ============================================================================
// This is the implementation file for the CMatrix class.
// ============================================================================

#include    <cstdlib>
#include    <ctime>
#include        <cmath>
#include    <fstream>
#include    <ncurses.h>
#include    <unistd.h>
#include    "cmatrix.h"

using namespace std;

// The function prototypes for CheckArrayFull and ResetArray
bool CheckArrayFull(const int array[], int n);
void ResetArray(int array[], int n);


// ==== CMatrix::CMatrix ======================================================
//
// This is the CMatrix constructor, it just uses the parameters to initialize
// the CMatrix data members so that the screen dimensions are known to the
// matrix ADT.
//
// Input:
//      numRows [IN]    -- the number of rows in the current display
//
//      numCols [IN]    -- the number of columns in the current display
//
// ============================================================================

CMatrix::CMatrix(int numRows, int numCols)
{
        // setting private data members m_numRows and m_numCols 
        // to numRows and numCols.
        m_numRows = numRows;
        m_numCols = numCols;

}  // end of "CMatrix::CMatrix"



// ==== CMatrix::Fill =========================================================
//
// This function is responsible for filling the screen at random locations
// with the character parameter, and pausing the specified number of micro-
// seconds between the drawing of each character. This drawing of characters
// continues until the screen is completely filled, at which point the
// function returns to the caller.
//
// NOTE: It is assumed that the caller has set the foreground and background
//       colors before making this call.
//
// Input:
//      dispChar [IN]   -- the character to use to fill the screen
//
//      msecs [IN]      -- the number of microseconds to pause between the
//                         drawing of each character
//
// Output:
//      Nothing
//
// ============================================================================

void CMatrix::Fill(char dispChar, int msecs)
{
        // initializning integers and rand for use within the function
        int randomNum, col=0, row=0;
        int uniqueArray[m_numRows * m_numCols] = {0};
        srand((unsigned)time(NULL));

        // Do-while loop which loops while function CheckArrayFull is false
        do {
                // Create a random number between zero and number of rows times columns
                randomNum = rand() % (m_numRows * m_numCols);

                // If the array value is 0, set it to 1, else skip
                if (uniqueArray[randomNum] == 0) {
                        uniqueArray[randomNum] = 1;

                        // Find the column location by performing a modulus operation
                        col = randomNum % m_numCols;
                        // Find the row by performing a division operation
                        row = randomNum / m_numCols;

                        // Print the display character in the identified column and row
                        mvprintw(col, row, "%c", dispChar);

                        // Sleep for specified microseconds
                        usleep(msecs);
                        // refresh display
                        refresh();
                }
                } while (!CheckArrayFull(uniqueArray, m_numRows * m_numCols));

                // Sets value of array to zeroes
                ResetArray(uniqueArray, (m_numRows * m_numCols));

                // Sleep for half a second before the next loop
                usleep(500000);

}  // end of "CMatrix::Fill"


// ==== CheckArrayFull ========================================================
// 
// This function is responsible to return a boolean whether the array is 
// full with 1's or not. This function is used within the CMatrix::Fill function.
// 
// ============================================================================

bool CheckArrayFull(const int array[], int n)
{
        const int checkInt = 1;

        // iterating through the array to find out  whether the array is full of 1's
        // or not
        for (int i=0; i<n; i++)
        {
                if (array[i] != checkInt)
                                // outputs false if not
                                return false;
        }
        // else it returns true
        return true;
}

// ==== ResetArray ===========================================================
// 
// This function is responsible for "clearing" the array with 0's.
// This function is used within the CMatrix:Fill function.
// 
// ===========================================================================
void ResetArray(int array[], int n)
{
        const int zero = 0;
        // iterating through the array and "clearing" it with zeroes
        for (int i=0; i<n; i++)
        {
                array[i] = zero;
        }
}
