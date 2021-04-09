#include "Core.h"

int main(int argc, char *argv[]) {
    Core core;

    core.load();

    core.loop();
}