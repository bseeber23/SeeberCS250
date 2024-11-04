//Braden Seeber 11/3/2024
#include "GuessedLetters.h"
#include <string>
#include <list>
#include <algorithm>

GuessedLetters::GuessedLetters()
{

}

std::string GuessedLetters::getLetters()
{
    std::string result;
    for (std::list<char>::iterator it = m_guessed.begin(); it != m_guessed.end(); ++it) {
        result += *it;
    }
    return result;
}

 void GuessedLetters::addLetter(char letter)
 {
    // only add the letter if it's not already in m_guessed
    if (std::find(m_guessed.begin(), m_guessed.end(), letter) == m_guessed.end()) {
        m_guessed.push_back(letter);
    }
}
