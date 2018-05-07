#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H
#include <string>
#include <sstream>
#include <regex>
#include <iostream>
#include <stdexcept>

namespace moviesubs {

    class MovieSubtitles{
    public:
        MovieSubtitles(){}
        virtual ~MovieSubtitles(){}
        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out);
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles() {}
        ~MicroDvdSubtitles();

        virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out);
    };

    class SubRipSubtitles: public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int,int, std::stringstream*,std::stringstream*);
    private:
        void ValidateTimes(std::smatch,std::string,int,int);
    };

    class Exception : public std::invalid_argument{
    public:
        Exception(const std::string &str) : invalid_argument::invalid_argument(str){};
    };

    class NegativeFrameAfterShift : public Exception{
    public:
        NegativeFrameAfterShift();
    };

    class InvalidSubtitleLineFormat : public Exception{
    public:
        InvalidSubtitleLineFormat();
    };

    class OutOfOrderFrames : public Exception{
    public:
        OutOfOrderFrames();
    };

    class MissingTimeSpecification : public Exception{
    public:
        MissingTimeSpecification();
    };

    class SubtitleEndBeforeStart : public Exception{
        int line_number;
    public:
        SubtitleEndBeforeStart(int line_number, std::string line);
        int LineAt() const;
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H