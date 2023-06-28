// ============================================================================
// File: cmatrix.h
// ============================================================================
// This header file contains the declaration for the CMatrix class. The class
// is used by the CScreen class to help fill the screen display with characters
// at random localtions.
// ============================================================================

#ifndef CMATRIX_H
#define CMATRIX_H

#include    <iostream>
#include    <fstream>
using namespace std;

// class declaration
class   CMatrix
{
public:
    // constructor
    CMatrix(int numRows, int numCols);

    // member functions
    void    Fill(char dispChar, int msecs);

private:
    int     m_numRows;
    int     m_numCols;
};

#endif  // CMATRIX_H
