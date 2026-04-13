#include "room.h"

using namespace MegaGo::Model;

Room::Room()
    : ModelObject()
{

}

Room::~Room()
{
    if(IsDebuging_) Log("It is room!");
}


bool Room::AddPlayerId(int64_t id)
{
    playersClientId.push_back(id);
    return true;
}

bool Room::DeletePlayerId(int64_t id)
{
    try {
        for(int i=0;i<playersClientId.size();i++) {
            if(playersClientId[i] == id)  {
                playersClientId.erase(playersClientId.begin()+i);
                return true;
            }
        }
        throw "Cant find player with id";
    } catch(const char* err) { if(IsDebuging_) Log(err); }
}


