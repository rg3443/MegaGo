#include "team.h"

using namespace MegaGo::Model;

Team::Team(QObject * parent)
    : ModelObject(parent)
{
    currentPlayerTurnIndex = 0;
}

Team::~Team()
{
    if(IsDebuging_) Log("It is team");
}

void Team::SetMaxPlayers(uint16_t maxAmmount)
{
    maxPlayersAmmount = maxAmmount;
}

void Team::AssignClient(QString login)
{
    if(ldPlayers.size() < maxPlayersAmmount) {
        ldPlayers.push_back(new Player(this));
        ldPlayers.last()->AssignClientLogin(login);
    } else
        Log("Too much players in team: can't assign new client");
}

Player* Team::GetCurrentTurnPlayer()
{
    if(currentPlayerTurnIndex >= ldPlayers.size())
        currentPlayerTurnIndex = 0;
    return ldPlayers[currentPlayerTurnIndex];
}

bool Team::TurnMade(uint64_t playerId)
{
    bool found = false;
    for(int i=0;i<ldPlayers.size();i++) {
        if(ldPlayers[i]->GetId() == playerId)
            found = true;
    }
    if(found) currentPlayerTurnIndex++;
    return found;
}

Player* Team::GetPlayer(uint16_t internalId)
{
    for(int i=0;i<ldPlayers.size();i++) {
        if(ldPlayers[i]->GetId() == internalId)
            return ldPlayers[i];
    }
    return nullptr;
}

Player* Team::GetPlayer(QString login)
{
    for(int i=0;i<ldPlayers.size();i++) {
        if(ldPlayers[i]->GetClientLogin() == login)
            return ldPlayers[i];
    }
    return nullptr;
}
