#pragma once
// #include "globals.cpp"

typedef struct
{
    bool Q = false;
    bool Qn = false;
    bool comportamento_indefinido = true;
    bool enable = false;
    bool set = false;
    bool reset = false;
} FlipFlopStates;

FlipFlopStates getFlipFlopState();
void setFlipFlopState(FlipFlopStates state);

// extern FlipFlopStates FlipFlopState;
