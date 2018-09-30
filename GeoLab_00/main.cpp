#include "Scene01.h"
#include "Scene02.h"

int main(int argc, char* argv[])
{
    vvr::mainLoop(argc, argv, new Scene01);
    vvr::mainLoop(argc, argv, new Scene02);
    return 0;
}
