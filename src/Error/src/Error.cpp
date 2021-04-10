/**
 * Error Implementation
 */

#include "Error.h"

Error::Error(std::string s, Seriousness ss): err(s), serr(ss) {

}

Error::Error() {

}

std::string Error::getString() const {
    return (err);
}

Seriousness Error::getSeriousness() const {
    return (serr);
}

void Error::setString(std::string error) {
    err = error;
}

void Error::setSeriousness(Seriousness seriousness) {
    serr = seriousness;
}