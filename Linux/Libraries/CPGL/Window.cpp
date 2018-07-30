class CPGL::Window
{
    private:

        Display* display;
        int screenNumber;
        ::Window parent;
        ::Window window;

    public:

        Window(Application* application, Window* cpglParent)
        {
            display = application->getGraphixSystemDescriptor();
            screenNumber = application->getScreenNumber();

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
