#include "field.h"

using namespace MegaGo::Model;

Field::Field(uint64_t sizeX_, uint64_t sizeY_, uint8_t type_, QObject * parent)
    : ModelObject(parent)
{
    type = type_;
    sizeX = sizeX_;
    sizeY = sizeY_;
    this->_InitTileMatrix();
}

Field::~Field()
{
    if(IsDebuging_) Log("It is field");
}

Tile* Field::GetTile(uint64_t posX_, uint64_t posY_)
{
    try {
        if(posX_ > tileMatrix.size())
            throw "Field::GetTile: wrong x";
        else if(posY_ > tileMatrix.first().size())
            throw "Field::GetTile: wrong y";
        else
            return tileMatrix[posX_][posY_];
    } catch(const char* err) { if(IsDebuging_) Log(err);  return nullptr; }
}

QVector<QVector<Tile*>> * Field::GetTileMatrix() { return &tileMatrix; }

bool Field::PlaceToken(Token *token, Pos2d pos)
{
    try {
        if(token == nullptr)
            throw "";

        if(_PosIsValid(pos))
            throw "";

        Tile * currTile = tileMatrix[pos.x][pos.y];
        if(currTile == nullptr)
            throw "";
        else if(currTile->GetToken() != nullptr)
            throw "";
        else {
            currTile->SetToken(token);
            token->SetPos(currTile->GetPos());
        }

        Allience * closestAllience = this->GetClosestAllience(pos);
        if(closestAllience == nullptr) {
            // create first allience
        } else {
            closestAllience->GetTokens().push_back(currTile);
        }

        this->_CheckAlliencesStructure();
        this->RecalcAlliencesBreathe();
    } catch(const char* err) { if(IsDebuging_) Log(err);  return false; }
}

bool Field::UnplaceToken(Token *token)
{
    try {
        if(token == nullptr)
            throw "";

        // cycling all tiles for search
        for(int x=0;x<tileMatrix.size();x++) {
            for(int y=0;y<tileMatrix[x].size();y++) {
                // check if tile found
                if(tileMatrix[x][y]->GetToken() == token) {
                    if(IsDebuging_)
                        if(*tileMatrix[x][y]->GetToken()->GetPos() != *token->GetPos())
                            Log("token coordinates was wrong");

                    // clear tile
                    tileMatrix[x][y]->SetToken(nullptr);
                    // clear token pos
                    token->SetPos(-1,-1);

                    this->_CheckAlliencesStructure();
                    this->RecalcAlliencesBreathe();
                }
            }
        }
    } catch(const char * err) { if(IsDebuging_) Log(err);  return false; }
}

bool Field::ClearTile(Pos2d pos)
{
    try {
        if(!this->_PosIsValid(pos))
            throw "";

        Token * token = tileMatrix[pos.x][pos.y]->GetToken();
        if(IsDebuging_)
            if(pos != *token->GetPos())
                Log("token coordinates was wrong");
        token->SetPos(-1,-1);
        tileMatrix[pos.x][pos.y]->SetToken(nullptr);

        this->_CheckAlliencesStructure();
        this->RecalcAlliencesBreathe();
    } catch(const char * err) { if(IsDebuging_) Log(err);  return false; }
}

bool Field::CheckAllianceLifeness(Allience *allience)
{
    int breatheCounter = 0;
    QVector<Tile*>& lTokens = allience->GetTokens();
    for(int tokid=0;tokid<lTokens.size();tokid++) {
        if(CheckTokenLifenessByTile(lTokens[tokid]))
            breatheCounter++;
    }
    allience->SetBreathe(breatheCounter);
    if(breatheCounter > 0) return true;
    else return false;
}

bool Field::CheckTokenLifenessByTile(Tile* tile)
{
    Pos2d maxModifier,minModifier;
    if(p->x == 0) {
        minModifier.Set(1,0);
        maxModifier.Set(0,0);
    } else if(p->y == 0) {
        minModifier.Set(0,1);
        maxModifier.Set(0,0);
    } else if(p->x == 0 && p->y == 0) {
        minModifier.Set(1,1);
        maxModifier.Set(0,0);
    } else if(p->x == tileMatrix.size()-1) {
        minModifier.Set(0,0);
        maxModifier.Set(-1,0);
    } else if(p->y == tileMatrix[0].size()-1) {
        minModifier.Set(0,0);
        maxModifier.Set(0,-1);
    } else if(p->x == tileMatrix.size() && p->y == tileMatrix[0].size()) {
        minModifier.Set(0,0);
        maxModifier.Set(-1,-1);
    } else {
        minModifier.Set(0,0);
        maxModifier.Set(0,0);
    }
    
    for(int xadj=-1+minModifier.x;xadj<2+maxModifier.x;xadj++) {
        for(int yadj=-1+minModifier.y;yadj<2+maxModifier.y;yadj++) {
            if(tileMatrix[p->x+xadj][p->y+yadj]->GetToken() == nullptr) 
                return true;     
        }
    }
    return false;
}

bool Field::ClearAllience(Allience *allience)
{
    QVector<Tile*>& lTokens = allience->GetTokens();
    for(int tokid=0;tokid<lTokens.size();tokid++) {
        lTokens->SetToken(nullptr);
    }
}

Allience* Field::CheckAllienceCloseBy(Pos2d pos, uint64_t playerId)
{
    for(int alid=0;alid<ldAlliences.size();alid++) {
        if(
    }
}

void Field::RecalcAlliencesBreathe()
{
    for(int alid=0;alid<ldAlliences.size();alid++) {
        this->CheckAllianceLifeness(ldAlliences[alid]);
    }
}

void Field::_InitTileMatrix()
{
    for(int x=0;x<sizeX;x++) {
        tileMatrix.append(QVector<Tile*>());
        for(int y=0;y<sizeY;y++) {
            tileMatrix[x].append(new Tile(x,y,nullptr,this));
        }
    }
}

void Field::_CheckAlliencesStructure()
{

}

bool Field::_PosIsValid(Pos2d pos)
{
    try {
        if(!pos.IsValid())
            throw "";
        if(pos.x > tileMatrix.size())
            throw "Field::GetTile: big x err";
        else if(pos.y > tileMatrix.first().size())
            throw "Field::GetTile: big y err";
        return true;
    } catch(const char* err) { if(IsDebuging_) Log(err); return false; }
}
