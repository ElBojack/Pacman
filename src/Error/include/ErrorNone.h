#ifndef ERRORNONE_HPP
#define ERRORNONE_HPP

#include "Error.h"

class ErrorNone: public Error {
    public:
        ErrorNone() {
            setSeriousness(Seriousness::None);
        }
};

#endif