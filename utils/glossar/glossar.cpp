#include "glossar.h"


using namespace KrendUtils;

Glossar::Glossar()
{

}

Glossar::~Glossar()
{

}

GlossarRecord* Glossar::GetRecord(void *pointer)
{
    for(int i=0;i<lRecords.size();i++) {
        if(*lRecords[i].pointerTracker == pointer) {
            return &lRecords[i];
        }
    }
    return nullptr;
}

GlossarRecord* Glossar::GetRecord(int64_t id)
{
    for(int i=0;i<lRecords.size();i++) {
        if(lRecords[i].id == id) {
            return &lRecords[i];
        }
    }
    return nullptr;
}

std::vector<GlossarRecord*> Glossar::GetRecords(const std::type_index &type)
{
    std::vector<GlossarRecord*> res;
    for(int i=0;i<lRecords.size();i++) {
        if(lRecords[i].type == type) {
            res.push_back(&lRecords[i]);
        }
    }
    return res;
}

void Glossar::AddRecord(GlossarRecord newRecord)
{
    lRecords.push_back(newRecord);
}

bool Glossar::DeleteRecord(void *pointer)
{
    for(int i=0;i<lRecords.size();i++) {
        if(*lRecords[i].pointerTracker == pointer) {
            delete *lRecords[i].pointerTracker;
            lRecords.erase(lRecords.begin()+i);
        }
    }
}

bool Glossar::DeleteRecord(int64_t id)
{
    for(int i=0;i<lRecords.size();i++) {
        if(lRecords[i].id == id) {
            delete *lRecords[i].pointerTracker;
            lRecords.erase(lRecords.begin()+i);
        }
    }
}

bool Glossar::EraseRecord(void *pointer)
{
    for(int i=0;i<lRecords.size();i++) {
        if(*lRecords[i].pointerTracker == pointer) {
            lRecords.erase(lRecords.begin()+i);
        }
    }
}

bool Glossar::EraseRecord(int64_t id)
{
    for(int i=0;i<lRecords.size();i++) {
        if(lRecords[i].id == id) {
            lRecords.erase(lRecords.begin()+i);
        }
    }
}

bool Glossar::CheckRecords()
{
    for(int i=0;i<lRecords.size();i++) {
        if(*lRecords[i].pointerTracker == nullptr) {
            lLostedRecords.push_back(lRecords[i]);
            lRecords.erase(lRecords.begin()+i);
        }
    }
}

int Glossar::ClearLostedRecords()
{
    int res = lLostedRecords.size();
    lLostedRecords.clear();
    return res;
}


