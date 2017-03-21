// field_loader.h
#ifndef FIELD_LOADER_H
#define FIELD_LOADER_H

#include "field.h"

#include <string>
#include <tuple>

class FieldLoader
{
    public:
        FieldLoader();

        std::tuple<Field, std::tuple<int, int, bool>, std::tuple<int, int, bool>> getNextField();

    private:
        void loadFieldNames();
        std::string getNextFieldName();

    private:
        std::vector<std::string> _fieldNames;

        size_t _fieldNameIter = 0;

        std::tuple<int, int, bool> shipStartPosition = std::make_tuple(-1, -1, false);
        std::tuple<int, int, bool> shipEndPosition = std::make_tuple(-1, -1, false);
};

#endif

