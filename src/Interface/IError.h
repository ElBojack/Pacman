/**
 * Interface Error
 * 
 */

#include <string>

enum Seriousness: int {
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
        virtual std::string getString() = 0;
        virtual Seriousness getSeriousness() = 0;

        virtual void setString(std::string) = 0;
        virtual void setSeriousness(Seriousness) = 0;
};