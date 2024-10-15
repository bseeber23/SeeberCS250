//Braden Seeber - 10/15/24
//Header file for volleyball, which inherits Athlete.h
#ifndef VOLLEYBALL_H
#define VOLLEYBALL_H

#include <Athlete.h>
#include <string>

using namespace std;

class VolleyBall : public Athlete
{
    public:
        VolleyBall();
        VolleyBall(string position, float reactionTime);
        string getPosition();
        void setPosition(string);
        float getReactionTime();
        void setReactionTime(float);

    protected:

    private:
        string m_position;
        float m_reactionTime;
};

#endif // VOLLEYBALL_H
