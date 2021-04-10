/**
 * Interface Error
 * 
 */

#ifndef IERROR_HPP
#define IERROR_HPP

#include <string>

enum Seriousness {
    None = 0,
    Light = 1,
    Moderate = 2,
    Serious = 3,
    Critical = 4
};

/**
 *  Must define Color code for each error type 
 */

class IError {
    public:
        virtual ~IError() {};
        virtual std::string getString() const = 0;
        virtual Seriousness getSeriousness() const = 0;

/*         virtual void setString(std::string) = 0;
        virtual void setSeriousness(Seriousness) = 0; */
};

#endif