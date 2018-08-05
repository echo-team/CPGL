class CPGL::Application
{
    private:

        Display* display;
        int screenNumber;
        XEvent report;
        GC gc;
        std::map<const char*, Window*> windows;

    public:

        /**
         * Inits nesessary variables for the XLib
         */
        Application()
        {
            display = XOpenDisplay(NULL);
            screenNumber = DefaultScreen(display);

            if (display == NULL)
            {
                std::cout << "ERROR: cannot connect to the X server." << std::endl;
                exit(1);
            }
        }

        /**
         * Creates a window
         * {char*}         name   - name of creating window
         * {CPGL::Window*} parent - parent window
         */
        Window* newWindow(const char* name, Window* parent)
        {
            Window* window = new Window(display, screenNumber, parent);
            window->setName(name);
            windows.insert(std::pair<const char*, Window*>(name, window));

            return window;
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
            return screenNumber;
        }
};
