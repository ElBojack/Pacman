#include "IError.h"

class Error: public IError {
    public:
        virtual std::string getString();
        virtual Seriousness getSeriousness();
        virtual void setString(std::string);
        virtual void setSeriousness(Seriousness);

    protected:

    private:
        std::string err;
        Seriousness serr;
};