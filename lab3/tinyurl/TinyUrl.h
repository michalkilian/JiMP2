//
// Created by Michał on 2018-03-19.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H


#include <utility>
#include <string>
#include <array>
#include <memory>
#include <map>
#include <iostream>


namespace tinyurl {
    using ::std::string;
    struct TinyUrlCodec {
        std::map<string, string> mapa;
        std::array<char, 6> hash_tab;
    };

    std::unique_ptr<TinyUrlCodec> Init();

    void NextHash(std::array<char, 6> *state);

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H