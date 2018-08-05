class CPGL::Window
{
    private:

        Display* display;
        int screenNumber;
        ::Window parent;
        ::Window window;

    public:

        Window(Display* display, int screenNumber, Window* cpglParent) : display(display), screenNumber(screenNumber)
        {
            if (cpglParent == NULL)
            {
                parent = RootWindow(display, screenNumber);
            }
            else
            {
                parent = cpglParent->getXServerWindow();
            }

            window = XCreateSimpleWindow(
                display,
                parent,
                0, 0, 800, 400, 1,
                BlackPixel (display, screenNumber),
                WhitePixel(display, screenNumber));

            XSelectInput(display, window, ExposureMask | KeyPressMask);
        }

        /**
         * Setts a name to the window
         * {const char*} name - name of the window to set
         */
        void setName(const char* name)
        {
            //XSetWMName(display, window, name);
        }

        /**
         * Returns the X server Window class
         * @return {Window}
         */
        ::Window getXServerWindow()
        {
            return window;
        }

        /**
         * Shows window on the screeen
         */
        void show()
        {
            XMapWindow(display, window);
        }
};
