// ============================================================================
// File: main.cpp
// ============================================================================
// This is the main module for the "Scatter" project, which draws characters to
// the screen at random locations, over and over again!
// ============================================================================

#include    "cscreen.h"

// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    // create a screen object
    CScreen         screen("config.dat");

    // have the object fill the screen at random locations with colored
    // characters
    screen.Scatter();
    return 0;

}  // end of "main"