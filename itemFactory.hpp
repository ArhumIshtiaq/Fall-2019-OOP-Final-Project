#pragma once
#include "game.hpp"
#include "trafficList.hpp"
#include "perkList.hpp"

class itemFactory
{
private:
    perk **perkAssets = new perk *[2];
    Traffic **obstacleAssets = new Traffic *[3];

    trafficList *tList;
    perkList *pList;
    const int lanes[3] = {310, 390, 470};

    float timedelay;
    Uint32 trafficSpeed = 0;
    int trafficGenFactor = 1000;
    Uint32 perkSpeed = 6000;
    Uint32 checkpointSpeed = 10000;
    SDL_Renderer *ren;

    void initializeAssets();
    void collisionDetection();

public:
    void increaseTrafficSpeed();
    void resetTrafficSpeed();
    void deleteAllItems();
    void freeMem();
    itemFactory(trafficList *Traffic, perkList *powerups, SDL_Renderer *renderer);
    void update();
};
