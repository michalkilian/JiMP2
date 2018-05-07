#include "MovieSubtitles.h"
using namespace std;
namespace moviesubs {

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {

        string tmp, subs;
        subs = (*in).str();

        if (fps <= 0) throw Exception("Invalid argument");

        if (!regex_search(subs,
                          regex("(\\{)[0-9]{1,}(\\}\\{)[0-9]{1,}(\\})(.*)(\n\\{)[0-9]{1,}(\\}\\{)[0-9]{1,}(\\})(.*)\n"))) {
            throw InvalidSubtitleLineFormat();
        }
        int line = 0;
        string start, end, text;
        for (int i = 0; i < subs.length(); i++) {
            if (subs[i] == '\n') line++;
            else if (subs[i] == '{' && isdigit(subs[i + 1])) {
                start = "";
                end = "";
                text = "";
                i++;
                while (subs[i] != '}') {
                    start += subs[i];
                    i++;
                }
                i += 2;
                while (subs[i] != '}') {
                    end += subs[i];
                    i++;
                }
                text += '{' + start + '}' + '{' + end + '}';
            } else text += subs[i];
        }

        if (end < start) throw SubtitleEndBeforeStart(line, text);

        for (string::iterator i = subs.begin(); i < subs.end(); i++) {
            if (*i == '{' && isdigit(*(i + 1))) {
                tmp = "";
                *(i++);
                while (*i != '}') {
                    tmp += *i;
                    *(i++);
                }

                if ((atoi(tmp.c_str()) + (delay * fps) / 1000) < 0) throw NegativeFrameAfterShift();

                *out << '{' + to_string(atoi(tmp.c_str()) + (delay * fps) / 1000) + '}';
            } else *out << *i;
        }
        if (subs[subs.length() - 1] != '\n') *out << '\n';
    }

    MicroDvdSubtitles::~MicroDvdSubtitles() {}

    void MovieSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {

        if (fps < 0) {
            throw std::invalid_argument("fps");
        }

        std::string str;
        std::regex pattern{R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
        std::smatch matches;
        int cnt = 0;
        while (getline(*in, str, '\n')) {
            cnt++;
            if (cnt != std::stoi(str)) {
                throw OutOfOrderFrames();
            }

            (*out) << str << '\n';


            getline(*in, str, '\n');

            if (std::regex_search(str, matches, pattern)) {
                ValidateTimes(matches, str, cnt, delay);
                (*out) << matches[1] << ":" << matches[2] << ":";
                int ms = std::stoi(matches[4]) + delay;
                if (ms < 0) {
                    throw OutOfOrderFrames();
                }
                if (ms < 1000) {
                    std::string str2 = std::to_string(ms);
                    while (str2.size() < 3) {
                        str2 = '0' + str2;
                    }
                    (*out) << matches[3] << "," << str2 << " --> ";
                } else {
                    int sec = std::stoi(matches[3]) + ms / 1000;
                    ms %= 1000;
                    std::string str2 = std::to_string(ms);
                    while (str2.size() < 3) {
                        str2 = '0' + str2;
                    }
                    std::string str3 = std::to_string(sec);
                    while (str3.size() < 2) {
                        str3 = '0' + str3;
                    }
                    (*out) << str3 << "," << str2 << " --> ";
                }

                (*out) << matches[5] << ":" << matches[6] << ":";
                ms = std::stoi(matches[8]) + delay;
                if (ms < 1000) {
                    std::string str2 = std::to_string(ms);
                    while (str2.size() < 3) {
                        str2 = '0' + str2;
                    }
                    (*out) << matches[7] << "," << str2 << " --> ";
                } else {
                    int sec = std::stoi(matches[7]) + ms / 1000;
                    ms %= 1000;
                    std::string str2 = std::to_string(ms);
                    while (str2.size() < 3) {
                        str2 = '0' + str2;
                    }
                    std::string str3 = std::to_string(sec);
                    while (str3.size() < 2) {
                        str3 = '0' + str3;
                    }
                    (*out) << str3 << "," << str2 << '\n';

                }
            } else {
                std::regex patt{R"([a-zA-Z]+)"};
                std::smatch match1;
                if (std::regex_search(str, match1, patt)) {
                    throw InvalidSubtitleLineFormat();
                } else {
                    throw InvalidSubtitleLineFormat();
                }
            }
            while (str != "") {
                getline(*in, str, '\n');
                (*out) << str;
                if (!in->eof()) {
                    (*out) << "\n";
                }
            }
        }
    }
    void SubRipSubtitles::ValidateTimes(std::smatch m,std::string str, int cnt,int delay){
        long start_time=std::stoi(m[1])*60*60*1000+std::stoi(m[2])*60*1000+std::stoi(m[3])*1000+std::stoi(m[4]);
        long end_time=std::stoi(m[5])*60*60*1000+std::stoi(m[6])*60*1000+std::stoi(m[7])*1000+std::stoi(m[8]);
        if(end_time<start_time) {
            throw SubtitleEndBeforeStart(cnt, str);
        }
        if(start_time+delay<0 or end_time+delay<0){
            throw NegativeFrameAfterShift();
        }
    }

    NegativeFrameAfterShift::NegativeFrameAfterShift() : Exception("NegativeFrameAfterShift") {}
    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat() : Exception("InvalidSubtitleLineFormat") {}
    MissingTimeSpecification::MissingTimeSpecification() : Exception("MissingTimeSpecification") {}
    OutOfOrderFrames::OutOfOrderFrames() : Exception("OutOfOrderFrames") {}

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_num, string line) : Exception("At line " + std::to_string(line_num) + ": " + line) {
                this->line_number = line_num;
            }
    int SubtitleEndBeforeStart::LineAt() const {
        return this->line_number; }
}