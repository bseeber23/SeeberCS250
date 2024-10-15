//Braden Seeber - 10/15/24
//Main file for tennis
#include "Tennis.h"

Tennis::Tennis() : Athlete()
{
    m_serveSpeed = 0;
    m_serveAndVolley = false;
} //sets initial values


Tennis::Tennis(int serveSpeed, bool serveAndVolley)
{
    m_serveSpeed = serveSpeed;
    m_serveAndVolley = serveAndVolley;
}
int Tennis::getServeSpeed()
{
    return m_serveSpeed;
}
void Tennis::setServeSpeed(int serveSpeed)
{
    m_serveSpeed = serveSpeed;
}
bool Tennis::getServeAndVolley()
{
    return m_serveAndVolley;
}
void Tennis::setServeAndVolley(bool serveAndVolley)
{
    m_serveAndVolley = serveAndVolley;
}
