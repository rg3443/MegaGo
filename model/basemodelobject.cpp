#include "basemodelobject.h"

using namespace MegaGo::Model;
unsigned long long int MegaGo::Model::ModelObject::internalIdCounter = 0;

ModelObject::ModelObject(QObject * parent)
    :   QObject(parent)
{
    this->SetId(internalIdCounter);
    internalIdCounter++;
}

ModelObject::~ModelObject()
{
    if(IsDebuging_) {
        Log(QString("deleting object with id:%1.").arg(internalId));
    }
}

void ModelObject::SetId(unsigned long long id) { internalId = id; }

unsigned long long int ModelObject::GetId() { return internalId; }

void ModelObject::Log(QString str)
{
    qDebug() << str;
}

