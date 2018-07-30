#include "Libraries/CPGL/Application.cpp"
#include "Libraries/CPGL/Window.cpp"

int main(int argc, char *argv[])
{
    CPGL::Application application;
    CPGL::Window window(&application, NULL);

    window.show();
    while(1)
    {}

    return 0;
}
