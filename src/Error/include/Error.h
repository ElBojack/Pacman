#ifndef ERROR_HPP
#define ERROR_HPP

#include "IError.h"

class Error: public IError {
    public:
        Error(std::string s, Seriousness ss);
        Error();
        virtual ~Error() {};
        virtual std::string getString() const;
        virtual Seriousness getSeriousness() const;

    protected:
        void setString(std::string);
        void setSeriousness(Seriousness);

    private:
        std::string err;
        Seriousness serr;
};

#endif