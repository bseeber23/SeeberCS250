//Braden Seeber 11/3/2024
#include "GameState.h"
#include <string>
#include <list>

GameState::GameState()
{

}

std::string GameState::getState()
{
    std::string result;
    for (const auto & state : m_state) {
        result += state + " ";
    }
    return result;
}

// Adds the next state from m_allStates to m_state
void GameState::addState()
{
    if (m_nextState < m_allStates.size()) {
        m_state.push_back(m_allStates[m_nextState]);
        m_nextState++;
    }
}

// Game over if all states have been added
bool GameState::gameOver()
{
    return m_nextState >= m_allStates.size();
}
