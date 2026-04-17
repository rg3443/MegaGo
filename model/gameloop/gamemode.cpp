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
    settings.maxSlotsInTeam = maxPlayersInTeam_;
    settings.teamsAmmount = teamAmmount;
    settings.fieldSize.Set(fieldSizeX,fieldSizeY);


    field = new Field(settings.fieldSize.x,settings.fieldSize.y,ID_FIELD_CLASSIC,this);
    for(int i=0;i<settings.teamsAmmount;i++) {
        ldTeams.append(new Team(this));
        ldTeams.last()->SetMaxPlayers(settings.maxSlotsInTeam);
    }
}

bool GameMode::AssignClientToTeam(ClientAccount *client, uint64_t teamId)
{
    for(int timid=0;timid<ldTeams.size();timid++) {
        if(ldTeams[timid] != nullptr)
            if(ldTeams[timid]->GetId() == teamId) {
                ldTeams[timid]->AssignClient(client->GetId());
                return true;
            }
    }
    return false;
}

bool GameMode::TurnOn(uint64_t firstTurnTeamId)
{
    try {
        if(firstTurnTeamId ==  0)
            if(ldTeams.size() < 0)
                throw "NOE TEAMS ERROR";
            else currentTeamTurnIndex = ldTeams[0]->GetId();
        else currentTeamTurnIndex = firstTurnTeamId;
    } catch(const char* err) { if(IsDebuging_) Log(err); return false; }
    
    return true;
}

bool GameMode::PlaceToken(Player * player, Pos2d pos)
{
    try {
        if(player == nullptr) 
            throw "";
        // create token in player
        Token * token = player->CreateToken();
        if(token == nullptr)
            throw "";
        // place it in field by coordinates
        if(!field->PlaceToken(token,pos))
            throw "";
        else {
            // pass turn to next team
            // tick current team
            if(!ldTeams[currentTeamTurnIndex]->TurnMade(player->GetId()))
                throw "No such player in team";
            _CycleTurnIndex();
        }   
    } catch(const char* err) { if(IsDebuging_) Log(err); return false; }
    
    return true;
}

bool GameMode::PassTurn(Player * player)
{
    try {
        if(player == nullptr)
            throw "";
            // pass turn to next team
            // tick current team
            if(!ldTeams[currentTeamTurnIndex]->TurnMade(player->GetId()))
                throw "No such player in team";
            _CycleTurnInde();
    } catch(const char * err ) { if(IsDebuging_) Log(err); return false; }

    return true;
}

void GameMode::_CycleTurnIndex()
{
    
            // change index
            if(currentTeamTurnIndex == ldTeams.size()-1) 
                currentTeamTurnIndex = 0;
            else 
                currentTeamTurnIndex++;
            
}
