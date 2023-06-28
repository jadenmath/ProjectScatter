
// ============================================================================
// File: cscreen.cpp
// ============================================================================
// This is the implementation file for the CScreen class.
// ============================================================================

#include    <cstdlib>
#include    <ctime>
#include    <fstream>
#include    <ncurses.h>
#include    <unistd.h>
#include    "cscreen.h"
#include    "cmatrix.h"

using namespace std;


// ==== CScreen::CScreen ======================================================
//
// This is the constructor for the CScreen class. It uses the parameter to open
// the configuration file and fetch the display character and sleep interval to
// initialize the object. If values cannot be read from the input file, default
// values are used. Then the random number generator is seeded with the current
// system time, and the curses library is initialized before returning.
//
// Input:
//      fname [IN]      -- a cstring containing the name of the configuration
//                         file
//
// ============================================================================

CScreen::CScreen(const char  fname[])
{
        // initiating ifstream for dataFile
    ifstream dataFile;

        // opening fname(config.dat)
    dataFile.open(fname);
    // if it doesn't open, set to default values
    if (dataFile.fail())
    {
        m_dispChar = DEFAULT_DISPCHAR;
        m_sleep = DEFAULT_SLEEP;
    }
        // Otherwise get the display character and sleep interval from fname
    else
    {
        dataFile.get(m_dispChar);
        dataFile >> m_sleep;
    }

        // Close the file
    dataFile.close();

    // Seed the random number generator
    srand((unsigned)time(NULL));

        // Initialize the Curses library via CScreen::InitCurses
    InitCurses();

}  // end of "CScreen::CScreen"



// ==== CScreen::InitCurses ===================================================
//
// This function is responsible for initializing the curses library. It also
// establishes the foreground and background colors for all of the color pair
// structures.
//
// Input:
//      Nothing
//
// Output:
//      Nothing
//
// ============================================================================

void    CScreen::InitCurses()
{
        // Initialize the curses library
        initscr();
        // Set to hide the cursor
        curs_set(0);
        // Starts color to set color pairs
        start_color();
        // Creates 7 pairs of colors, the order is (pair #, foreground, background)
        init_pair(1, COLOR_CYAN, COLOR_BLUE);
        init_pair(2, COLOR_BLUE, COLOR_MAGENTA);
        init_pair(3, COLOR_BLACK, COLOR_WHITE);
        init_pair(4, COLOR_WHITE, COLOR_YELLOW);
        init_pair(5, COLOR_YELLOW, COLOR_RED);
        init_pair(6, COLOR_RED, COLOR_GREEN);
        init_pair(7, COLOR_BLACK, COLOR_YELLOW);

}  // end of "CScreen::InitCurses"



// ==== CScreen::Scatter ======================================================
//
// This function contains an infinite loop that draws characters to random
// locations on the screen. Inside the loop, a COLOR_PAIR is activated, then a
// local CMatrix object is used to fill the screen with the display character.
// After the screen has been filled, the loop pauses for about a half-second,
// before doing it all over again and again, until the user presses Ctrl+c,
// which terminates the loop so that the function can return to the caller.
//
// Input:
//      Nothing
//
// Output:
//      Nothing
//
// ============================================================================

void    CScreen::Scatter()
{
        // Set the color pair initially to 1
        int colPair = 1;

        // Creating an infinite loop
        while (1)
        {
                // Set the color pair
                attron(COLOR_PAIR(colPair));
                // Calling the CMatrix contructor and setting the # of columns and rows
                CMatrix cm = CMatrix(COLS, LINES);

                // Calling the CMatrix fill function to fill the screen
                cm.Fill(m_dispChar, m_sleep);

                // Increment the color pair by 1 and loop from 1-7
                if (colPair < 7) colPair++;
                else colPair = 1;
        }
}  // end of "CScreen::Scatter"                                                                                                                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                                                                 
