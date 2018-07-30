#include <iostream>

class Application
{
    private:



    public:

        /**
         * Inits nesessary variables for the XLib
         */
        Application()
        {
            Display* display = XOpenDisplay(NULL);
            int ScreenNumber = DefaultScreen(display);

            if (display == NULL)
            {
                std::cout << "ERROR: cannot connect to the X server." << std::endl;
                exit(1);
            }
        }
};
