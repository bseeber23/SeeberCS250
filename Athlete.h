//Braden Seeber - 10/15/24
//Header file for athlete

#ifndef ATHLETE_H
#define ATHLETE_H

#include <string>

using namespace std;

class Athlete
{
    public:
       Athlete();
         Athlete(int height, int weight, char gender);
         int getHeight();
         void setHeight(int);
         int getWeight();
         void setWeight(int);
         char getGender();
         void setGender(char);

    protected:
        int m_height;
        int m_weight;
        char m_gender;

    private:

};

#endif // ATHLETE_H
