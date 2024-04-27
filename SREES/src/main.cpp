//#include "main.hpp"
#include "Application.h"
#include <td/StringConverter.h>
#include <gui/WinMain.h>

int main(int argc, const char * argv[])
{
    Application app(argc, argv);
    app.init("BA");

    if (!app.connectToDB())
    {
        std::cout << "Stavite bazu podataka na lokaciju: %HOME%/Work/PZI_Baza/baza.db\n";
        return 1;
    }

    return app.run();
}
