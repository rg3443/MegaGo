#ifndef BASEMODELOBJECT_H
#define BASEMODELOBJECT_H

#include "ginclude.h"
#include "model/gvar.h"

namespace MegaGo {
namespace Model {
    class ModelObject : public QObject {
        Q_OBJECT
    private:
        unsigned long long int internalId;
        static unsigned long long int internalIdCounter;
    public:
        ModelObject(QObject * parent = nullptr);
        ~ModelObject();

        void SetId(unsigned long long int id);
        unsigned long long int GetId();

        void Log(QString str);

    };
}
}

#endif // BASEMODELOBJECT_H
