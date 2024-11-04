//Braden Seeber 11/3/24
#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
public:
    Word(const std::string& word);
    bool findLetter(char c);
    std::string getWord();
    bool solved() const;
    void addLetter(char letter);

private:
    std::string m_word;
    std::string m_currentWord;  //state of guessed word
};

#endif // WORD_H
