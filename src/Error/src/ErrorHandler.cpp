/**
 * ErrorHandler implementation
 */

#include "ErrorHandler.h"

ErrorHandler::ErrorHandler(): length(0) {

}

const std::shared_ptr<IError> ErrorHandler::getFirstError() {
    return errs.front();
}

const std::shared_ptr<IError> ErrorHandler::getLastError() {
    return errs.back();
}

std::shared_ptr<IError> ErrorHandler::processError() {
    std::shared_ptr<IError> errFront = errs.front();

    EMPTY RNULLPTR;
    errs.pop_front();
    length -= 1;

    return errFront;
}

std::shared_ptr<IError> ErrorHandler::processLastError() {
    std::shared_ptr<IError> errBack = errs.back();

    EMPTY RNULLPTR;
    errs.back();
    length -= 1;

    return errBack;
}

void ErrorHandler::pushFront(std::shared_ptr<IError> err) {
    if (err == nullptr) return;

    errs.push_front(err);
    length += 1;
}

void ErrorHandler::pushBack(std::shared_ptr<IError> err) {
    if (err == nullptr) return;

    errs.push_back(err);
    length += 1;
}


const size_t ErrorHandler::getLength() {
    return length;
}