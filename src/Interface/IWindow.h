/**
 * Interface for Window
 */

#ifndef IWINDOW_HPP
#define IWINDOW_HPP

#include <string>

class IWindow {
    public:
        virtual ~IWindow() {};
        virtual void create(unsigned int /* width */, 
                            unsigned int /* height */, 
                            unsigned int /* bitsPerPixel (default 32) */, 
                            std::string /* title */ ) = 0;
        virtual void open() = 0;
        virtual void close() = 0;
};

#endif