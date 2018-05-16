//
// Created by Michał on 2018-05-16.
//

#include <iostream>
#include "Algo.h"

namespace algo {
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.cbegin(), n_elements, std::back_inserter(*out));

    }

    bool Contains(const std::vector<int> &v, int element) {
        return (std::find(v.begin(), v.end(), element) != v.end());
    }


    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> result;
        std::fill_n(std::back_inserter(result), length, initial_value);
        return result;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> s;
        std::transform(v.begin(), v.end(), std::back_inserter(s), [](double i) {
            return std::to_string(i);
        });
        return s;
    }


    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return (v.find(key) != v.end());
    }

    /* std::set<std::string> Keys(const std::map<std::string, int> &m) {
         std::set<std::string> result;
         std::transform(m.begin(), m.end(), std::inserter(result, result.begin()), [](auto x) {
             return x.first;
         });
         return result;
     }
 */
    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        std::vector<int> result;
        std::transform(v.begin(), v.end(), std::back_inserter(result), [](auto x) {
            return x.second;
        });
        return (std::find(result.begin(), result.end(), value) != result.end());
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> result;
        std::transform(m.begin(), m.end(), std::back_inserter(result), [](auto x) {
            return x.second;
        });
        return result;
    }

    std::vector<int> DivisableBy(const std::vector<int> &m, int divisor) {
        std::vector<int> result;
        std::copy_if(m.begin(), m.end(), std::back_inserter(result), [divisor](auto x) { return (x % divisor == 0); });
        return result;
    }


    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(), v->end());
    }

    std::vector<int> Sort(const std::vector<int> &v) {
        std::vector<int> result;
        std::sort(v.begin(), v.end());
        result = v;
        return result;
    }

    bool myfunction(std::pair<int, int> i, std::pair<int, int> j) { return (i.first < j.first); }

    bool myfunction2(std::pair<int, int> i, std::pair<int, int> j) { return (i.second < j.second); }

    bool myfunction3(std::tuple<int, int, int> i, std::tuple<int, int, int> j) { return (i.[2] < j.[2]); }


    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), myfunction);
    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), myfunction2);

    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
        std::sort(v->begin(), v->end(), myfunction3);

    }

    //int Number () { return (std::rand()%100); }
    //
    //int algo::Sum(const std::vector<int> &v) {
    //    return std::count(v.begin(), v.end(),10);
    //}
    //



    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        std::vector<std::string> result;
        std::unique_copy(v.begin(), v.end(), std::back_inserter(result));
        return result;
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {
        std::unique(v->begin(), v->end());
    }


    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        std::count_if(v.begin(), v.end(), [inclusive_short_length](int i) { return (inclusive_short_length < i); });
    }
}