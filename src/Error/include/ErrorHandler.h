/**
 * 
 */

#include "IError.h"

#include <deque>
#include <memory>

#define EMPTY if (!this->length)
#define RNULLPTR return nullptr

class ErrorHandler {
    public:
        ErrorHandler();
        ~ErrorHandler() {};

        const std::shared_ptr<IError> getFirstError();
        const std::shared_ptr<IError> getLastError();
        std::shared_ptr<IError> processError();
        std::shared_ptr<IError> processLastError();

        void pushFront(std::shared_ptr<IError>);
        void pushBack(std::shared_ptr<IError>);

        const size_t getLength();
    
    protected:
    private:
        size_t length;
        std::deque<std::shared_ptr<IError>> errs;
};