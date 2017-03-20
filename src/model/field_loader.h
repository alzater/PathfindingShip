// field_loader.h
#ifndef FIELD_LOADER_H
#define FIELD_LOADER_H

#include "field.h"
#include <string>

class FieldLoader
{
    public:
        FieldLoader();

        Field getNextField();

    private:
        void loadFieldNames();
        std::string getNextFieldName();

    private:
        std::vector<std::string> _fieldNames;

        size_t _fieldNameIter = 0;
};

#endif

