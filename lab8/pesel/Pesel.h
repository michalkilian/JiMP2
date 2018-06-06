//
// Created by kilimich on 25.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>

using namespace std;
namespace academia {
    class Pesel {
    public:
        Pesel(string pesel);

        void validatePESEL(const char *);

    private:
        string _pesel;
    };
    class InvalidPeselChecksum{

    };

    class InvalidPeselLength{

    };
    class InvalidPeselCharacter{

    };
    class AcademiaDataValidationError{

    };
}

#endif //JIMP_EXERCISES_PESEL_H
