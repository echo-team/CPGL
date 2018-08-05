#include "Libraries/CPGL/CPGL.cpp"

int main(int argc, char *argv[])
{
    CPGL::Application application;
    CPGL::Window window = *application.newWindow("Main", NULL);

    window.show();
    application.execute();

    return 0;
}
