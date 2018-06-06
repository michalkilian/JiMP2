//
// Created by Michał on 2018-05-16.
//
#include "Algo.h"
namespace algo{
    //===== Zrobione
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy_n(v.begin(),n_elements, std::back_inserter(*out));
    }

    void InitializeWith(int initial_value, std::vector<int> *v){
        std::fill(v->begin(), v->end(), initial_value);
    }
    std::vector<int> InitializedVectorOfLength(int length, int initial_value){
        std::vector<int> v;
        std::fill_n(v.begin(), length, initial_value);
        return v;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v){
        std::vector<std::string> s;
        std::transform(v.begin(),v.end(), std::back_inserter(s), [](double i){
            return std::to_string(i);
        });
        return s;
    }

    void SortInPlace(std::vector<int> *v){
        std::stable_sort(v->begin(), v->end());
    }

    std::vector<int> Sort(const std::vector<int> &v){
        std::vector<int> l = v;
        std::sort(l.begin(), l.end());
        return l;
    }

    int Sum(const std::vector<int> &v){
        std::accumulate(v.begin(), v.end(), 0);
    }

    int Product(const std::vector<int> &v){
        int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return (v.find(key) != v.end());
    }

    bool Contains(const std::vector<int> &v, int element) {
        return (std::find(v.begin(), v.end(), element) != v.end());
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        std::vector<int> result;
        std::transform(v.begin(), v.end(), std::back_inserter(result), [](auto x) {
            return x.second;
        });
        return (std::find(result.begin(), result.end(), value) != result.end());
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        std::vector<std::string> result = v;
        std::sort(result.begin(), result.end());
        std::vector<std::string> result2;
        std::unique_copy(v.begin(), v.end(), std::back_inserter(result2));
        return result2;
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {
        std::stable_sort(v->begin(), v->end());
        std::unique(v->begin(), v->end());
    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        std::count_if(v.begin(), v.end(), [inclusive_short_length](int i) { return (inclusive_short_length < i); });
    }

    bool sortbyfirst(std::pair<int, int> i, std::pair<int, int> j) { return (i.first < j.first); }

    bool sortbysecond(std::pair<int, int> i, std::pair<int, int> j) { return (i.second < j.second); }

    bool sortbythird(std::tuple<int, int, int> i, std::tuple<int, int, int> j) { return (std::get<2>(i) < std::get<2>(j)); }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), sortbyfirst);
    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), sortbysecond);

    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
        std::sort(v->begin(), v->end(), sortbythird);

    }
    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor){
        std::map<std::string, int> out;
        std::copy_if(m.begin(),m.end(),std::inserter(out,m.end()),[divisor](std::pair<std::string,int> p){ return (p.second%divisor==0);});
        return out;
    };

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> result;
        std::transform(m.begin(), m.end(), std::inserter(result, result.begin()), [](auto x) {
            return x.first;
        });
        return result;
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> result;
        std::transform(m.begin(), m.end(), std::back_inserter(result), [](auto x) {
            return x.second;
        });
        return result;
    }
}
