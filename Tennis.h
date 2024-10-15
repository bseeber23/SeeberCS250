#ifndef TENNIS_H
#define TENNIS_H

#include <Athlete.h>
#include <string>

using namespace std;

class Tennis : public Athlete
{
    public:
        Tennis();
        Tennis(int serveSpeed, bool serveAndVolley);
        int getServeSpeed();
        void setServeSpeed(int);
        bool getServeAndVolley();
        void setServeAndVolley(bool);

    protected:

    private:
        int m_serveSpeed;
        bool m_serveAndVolley;
};

#endif // TENNIS_H
