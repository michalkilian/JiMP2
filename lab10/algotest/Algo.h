//
// Created by Michał on 2018-05-16.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

namespace algo {




    std::set<std::string> Keys(const std::map<std::string, int> &m);

    std::vector<int> Values(const std::map<std::string, int> &m);

    std::string Join(const std::string &joiner, const std::vector<double> &v);

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor); //jest

    bool Contains(const std::vector<int> &v, int element); //jest

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key); //jest

    bool ContainsValue(const std::map<std::string, int> &v, int value); //jest

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v); //jest

    void RemoveDuplicatesInPlace(std::vector<std::string> *v); //jest

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length); //jest

    std::vector<int> Sort(const std::vector<int> &v); //jest

    void SortInPlace(std::vector<int> *v); //jest

    std::vector<std::string> MapToString(const std::vector<double> &v); //jest

    void InitializeWith(int initial_value, std::vector<int> *v); //jest

    std::vector<int> InitializedVectorOfLength(int length, int initial_value); //jest

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out); //jest

    int Sum(const std::vector<int> &v); //jest

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v); //jest
    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v); //jest
    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v); //jest

    int Product(const std::vector<int> &v); //jest

}

#endif //JIMP_EXERCISES_ALGO_H