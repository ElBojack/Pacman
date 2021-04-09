/**
 * Interface for Window
 */

class IWindow {
    public:
        virtual ~IWindow() {};
        virtual int setSize(int, int) = 0;
};