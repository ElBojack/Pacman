/**
 * Error Implementation
 */

#include "Error.h"

std::string Error::getString() {
    return (err);
}

Seriousness Error::getSeriousness() {
    return (serr);
}

void Error::setString(std::string error) {
    err = error;
}

void Error::setSeriousness(Seriousness seriousness) {
    serr = seriousness;
}