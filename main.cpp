#include <iostream>
#include "Engine/Engine.h"
#include "Engine/Exceptions/EngineException.h"

int main() {
    try {
        Engine engine("Spacer");
        engine.update();
    } catch (EngineException& ex) {
        std::cerr << ex.error() << std::endl;
    }
    return 0;
}
