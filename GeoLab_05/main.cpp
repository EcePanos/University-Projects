#include "MoldingScene.h"
#include "CollinearScene.h"

int main(int argc, char* argv[])
{
    //return mainLoop(argc, argv, new MoldingScene);
    return mainLoop(argc, argv, new CollinearScene);
}
