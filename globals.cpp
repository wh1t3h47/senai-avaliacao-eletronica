#include "globals.hpp"

FlipFlopStates FlipFlopState;

FlipFlopStates getFlipFlopState()
{
    return FlipFlopState;
}
void setFlipFlopState(FlipFlopStates state)
{
    FlipFlopState = state;
}
