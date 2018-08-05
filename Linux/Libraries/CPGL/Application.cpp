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
        XEvent report;
        GC gc;

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
         * Starts main loop of the application
         */
        void execute()
        {
            while(1)
            {
                XNextEvent(display, &report);

                switch (report.type)
                {
                    case Expose:
                        if (report.xexpose.count != 0)
                            break;
                        break;

                    case KeyPress :
                         XCloseDisplay ( display );
                         exit ( 0 );
                }
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
