//
// Created by Michał on 2018-04-15.
//

#include <string>
#include <fstream>
#include <utility>
#include <list>
#include <iostream>
#include <regex>
#include "WordCounter.h"

namespace datastructures {
    int WordCounter::TotalWords() {
        int allwords = 0;
        for (auto &&uniqueword : wordcontainer_) {
            allwords += uniqueword.second.GetCount();
        }
        return allwords;
    }

    int WordCounter::DistinctWords() {
        return wordcontainer_.size();
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> resultsortedlist;
        for (auto &pairitem : wordcontainer_) {
            resultsortedlist.insert(pairitem.first);
        }
        return resultsortedlist;
    }

    WordCounter::WordCounter(std::initializer_list<Word> in) {
        for (auto &&worditem : in) {
            //find REFERENCE to list element, or empty
            std::pair<Word, Counts> &repetitionindex = this->FindElement(worditem);
            if (repetitionindex.first.Empty()) {
                wordcontainer_.push_back(std::make_pair(worditem, Counts(1)));
            } else {
                //if element exists, increment Counts
                ++repetitionindex.second;
            }
        }
    }

    std::pair<Word, Counts> &WordCounter::FindElement(const Word &checkthisword) {
        for (auto &wordcountpair : wordcontainer_) {
            if (wordcountpair.first == checkthisword)
                return wordcountpair;
        }
        return brutal_;
    }

    void WordCounter::Insert(Word newword) {
        auto &it = FindElement(newword);
        if (it.first.Empty())
            wordcontainer_.push_back(std::make_pair(newword, Counts(0)));
        else
            it.second++;
    }

    WordCounter WordCounter::FromInputStream(std::istream &is) {
        WordCounter resultwc;
        while (!is.eof()) {
            Word obj;
            is >> obj;
            resultwc.Insert(obj);

        }

    }

    Counts &WordCounter::operator[](std::string lookforword) {
        return FindElement(Word(lookforword)).second;
    }

    std::ostream &operator<<(std::ostream &os, const WordCounter &wcout) {
        for (auto &&pairitem : wcout.wordcontainer_) {
            os << "Word: \"" << pairitem.first;
            os << "\", Count: " << pairitem.second << std::endl;
        }
        return os;
    }
}
