#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <iostream>

namespace CPGL
{
    class Application;
    class Window;
};

class CPGL::Application
{
    private:

        Display* display;
        int ScreenNumber;

    public:

        /**
         * Inits nesessary variables for the XLib
         */
        Application()
        {
            display = XOpenDisplay(NULL);
            ScreenNumber = DefaultScreen(display);

            if (display == NULL)
            {
                std::cout << "ERROR: cannot connect to the X server." << std::endl;
                exit(1);
            }
        }

        /**
         * Returns structure got from X server
         * @return {Display*}
         */
        Display* getGraphixSystemDescriptor()
        {
            return display;
        }

        /**
         * Returns number of screen where application has been placed
         * @return {int}
         */
        int getScreenNumber()
        {
            return ScreenNumber;
        }
};
