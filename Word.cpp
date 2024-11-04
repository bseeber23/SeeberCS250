//Braden Seeber 11/3/2024
#include "Word.h"
#include <string>
#include <algorithm>

// Creates blank with underscores
Word::Word(const std::string& word) : m_word(word), m_currentWord(word.size(), '_') {}

bool Word::findLetter(char c) {
    return m_word.find(c) != std::string::npos;
}

std::string Word::getWord() {
    std::string w = "";
    for (char c : m_currentWord) {
        w += c;
        w += " ";
    }
    return w; // Return the word
}

bool Word::solved() const {
    return std::find(m_currentWord.begin(), m_currentWord.end(), '_') == m_currentWord.end();
}

void Word::addLetter(char letter) {
    for (size_t i = 0; i < m_word.size(); ++i) {
        if (m_word[i] == letter) {
            m_currentWord[i] = letter; // Replace underscore with guessed letter
        }
    }
}
