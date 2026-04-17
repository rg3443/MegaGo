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
    if(maxAmmount != 0)
        maxPlayersAmmount = maxAmmount;
}

void Team::AssignClient(uint64_t clientId)
{
    if(ldPlayers.size() < maxPlayersAmmount) {
        ldPlayers.push_back(new Player(this));
        ldPlayers.last()->AssignClient(clientId);
    } else
        Log("Too much players in team: can't assign new client");
}

bool Team::DeletePlayer(uint64_t clientId)
{
    for(int plid=0;plid<ldPlayers.size();plid++) {
        if(ldPlayers[plid]->GetClientId() == clientId) {
            delete ldPlayers[plid];
            ldPlayers.erase(ldPlayers.begin()+plid);
        }
    }
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
        if(ldPlayers[i]->GetId() == playerId) {
            if(i == ldPlayers.size()-1)
                currentPlayerTurnIndex = 0;
            else
                currentPlayerTurnIndex = ldPlayers[i+1];
        }
    }
    if(found) currentPlayerTurnIndex++;
    return found;
}

Player* Team::GetPlayer(uint64_t clientId)
{
    for(int i=0;i<ldPlayers.size();i++) {
        if(ldPlayers[i]->GetClientId() == clientId)
            return ldPlayers[i];
    }
    return nullptr;
}

Player* Team::GetPlayer(unsigned long int playerId)
{
    for(int i=0;i<ldPlayers.size();i++) {
        if(ldPlayers[i]->GetId() == playerId)
            return ldPlayers[i];
    }
    return nullptr;
}
