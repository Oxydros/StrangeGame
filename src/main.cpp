#include <App.hpp>

int main() {
    try
    {
        App app(800, 600, "StrangeGame");

        app.run();
    } catch (std::exception &e)
    {
        std::cout << "Got Exception: " << e.what() << std::endl;
    }
    return 0;
}