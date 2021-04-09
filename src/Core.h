/**
 * 
 * 
 */

#include "IWindow.h"
#include "IError.h"

#include <memory>

class Core {
    public:
        Core();
        ~Core() {};
        void load();
    protected:

    private:
        std::shared_ptr<IWindow> window; // Init properly by the compiler
};