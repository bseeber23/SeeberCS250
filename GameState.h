//Braden Seeber 11/3/2024
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <string>
#include <list>
#include <vector>

class GameState
{
    public:
        GameState();
        std::string getState();
        void addState();
        bool gameOver();

    protected:

    private:
        std::list<std::string> m_state;
        const std::vector<std::string> m_allStates = { // All body parts
        "PLATFORM", "HEAD", "BODY", "LEFT_ARM", "RIGHT_ARM", "LEFT_LEG", "RIGHT_LEG"};
        int m_nextState = 0;
};

#endif // GAMESTATE_H
