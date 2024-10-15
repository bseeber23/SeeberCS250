//Braden Seeber - 10/15/24
//Main file for Volleyball

#include "VolleyBall.h"

VolleyBall::VolleyBall() : Athlete()
{
    m_position = "";
    m_reactionTime = 0.0;
}


VolleyBall::VolleyBall(string position, float reactionTime)
{
    m_position = position;
    m_reactionTime = reactionTime;
}
string VolleyBall::getPosition()
{
    return m_position;
}
void VolleyBall::setPosition(string position)
{
    m_position = position;
}
float VolleyBall::getReactionTime()
{
    return m_reactionTime;
}
void VolleyBall::setReactionTime(float reactionTime)
{
    m_reactionTime = reactionTime;
}
