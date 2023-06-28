// ============================================================================
// File: cscreen.h
// ============================================================================
// This is the header file for the CScreen class.
// ============================================================================

#ifndef CSCREEN_H
#define CSCREEN_H

#include    <iostream>
#include    <fstream>
using namespace std;

// defined constants
const char DEFAULT_DISPCHAR = '*';
const int  DEFAULT_SLEEP = 200;
const int  LAST_COLOR_PAIR_INDEX = 7;

// class declaration
class   CScreen
{
public:
    // constructor
    CScreen(const char  fname[]);

    // member functions
    void    InitCurses();
    void    Scatter();

private:
    char        m_dispChar;
    int         m_sleep;
};

#endif  // CSCREEN_H