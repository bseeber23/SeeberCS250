//Braden Seeber 11/3/2024
#ifndef GUESSEDLETTERS_H
#define GUESSEDLETTERS_H
#include <string>
#include <list>


class GuessedLetters
{
    public:
        GuessedLetters();
        std::string getLetters();
        void addLetter(char);

    protected:

    private:
        std::list<char> m_guessed;
};

#endif // GUESSEDLETTERS_H
