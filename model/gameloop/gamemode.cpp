#include "gamemode.h"

using namespace MegaGo::Model;

GameMode::GameMode(QObject * parent)
    : ModelObject(parent)//, field(fieldSizeX,fieldSizeY,ID_FIELD_CLASSIC,this)
{
 //   Init(fieldSizeX,fieldSizeY,teamAmmount,teamSize);

}

GameMode::~GameMode()
{
    if(IsDebuging_) Log("It is gamemode");
}

void GameMode::InitRoom(int fieldSizeX, int fieldSizeY, int teamAmmount, uint16_t maxPlayersInTeam_)
{
    maxPlayersInTeam = maxPlayersInTeam_;
    field = new Field(fieldSizeX,fieldSizeY,ID_FIELD_CLASSIC,this);
    for(int i=0;i<teamAmmount;i++) {
        ldTeams.append(new Team(this));
        ldTeams.last()->SetMaxPlayers(maxPlayersInTeam);
    }
}

void GameMode::AssignClientToTeam(ClientAccount *client, int16_t teamId)
{
    if(teamId < 0) // its random
    {

    } else if(teamId >= ldTeams.size()) { // teamId too big -> random?

    } else {
        ldTeams[teamId]->AssignClient(client->GetLogin());
    }

}

void GameMode::TurnOn(int16_t firstTurnTeamId)
{
    if(firstTurnTeamId < 0)
        currentTeamTurnIndex = 0;
    else currentTeamTurnIndex = firstTurnTeamId;
}

bool GameMode::PlaceToken(Player * player, Pos2d pos)
{
    try {
        //take field
        QVector<QVector<Tile*>> * tiles = field->GetTileMatrix();
        //check for field size and pos
        if(tiles->size() > pos.x && tiles->size() != 0) {
            if((*tiles)[0].size() > pos.y && (*tiles)[0].size() != 0) {
                //take tile with pos
                Tile * tile = (*tiles)[pos.x][pos.y];
                //check if ocupied
                if(tile->GetToken() == nullptr) { // its free
                    //if not place on field + add to player
                    
                } else // its ocupied
                    throw "Can't place token: tile is ocupied";
            }
        }
    } catch(const char* err) { if(IsDebuging_) Log(err); }
}
