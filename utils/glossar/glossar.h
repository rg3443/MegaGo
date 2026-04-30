#ifndef GLOSSAR_H
#define GLOSSAR_H

#include <stdio.h>
#include <cstdint>
#include <vector>
#include <typeinfo>
#include <typeindex>

namespace KrendUtils {
    struct GlossarRecord {
        void ** pointerTracker;
        std::type_index type;
        int64_t id;

        GlossarRecord(const std::type_index& type_,void ** tracker = nullptr, int64_t id_ = -1)
            : pointerTracker(tracker),type(type_),id(id_)
        {
        }
        void Set(const std::type_index& type_, void ** tracker, int64_t id_) {
            pointerTracker = tracker;
            type = type_;
            id = id_;
        }
        bool Delete() {
            if(*pointerTracker != nullptr) {
                delete *pointerTracker;
                *pointerTracker = nullptr;
            }
        }
    };

    template<class T>
    GlossarRecord CreateGRecord(T object)
    {
        GlossarRecord newRecord;
        newRecord.pointerTracker = new T*;
        *newRecord.pointerTracker = new T(object);
        return newRecord;
    }

    class Glossar {
    private:
        std::vector<GlossarRecord> lRecords;
        std::vector<GlossarRecord> lLostedRecords;
    public:
        Glossar();
        ~Glossar();

        // get record
        GlossarRecord * GetRecord(void * pointer);
        GlossarRecord * GetRecord(int64_t id);
        std::vector<GlossarRecord*> GetRecords(const std::type_index& type);

        // add new record
        void AddRecord(GlossarRecord newRecord);
        // search and delete existing record
        bool DeleteRecord(void * pointer);
        bool DeleteRecord(int64_t id);
        // search and erase existing record
        bool EraseRecord(void * pointer);
        bool EraseRecord(int64_t id);
        // check records for nullptr pointers
        bool CheckRecords();
        // clear 'losted' records, records become 'losted' when their tracked pointer become nullptr
        // return ammount of cleared records
        int ClearLostedRecords();
    };
}

#endif // GLOSSAR_H
