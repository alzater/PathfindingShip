// field_loader.cpp
#include "field_loader.h"

#include <fstream>

FieldLoader::FieldLoader()
{
    loadFieldNames();
}

std::tuple<Field, std::tuple<int, int, bool>, std::tuple<int, int, bool>>  FieldLoader::getNextField()
{
    std::ifstream config( "fields/" + getNextFieldName() );
    Field field(1, 1);
    std::tuple<int, int, bool> shipStartPosition = std::make_tuple(-1, -1, false);
    std::tuple<int, int, bool> shipEndPosition = std::make_tuple(-1, -1, false);

    if( config )
    {
        int width, height;
        config >> width >> height;
        field = Field(width, height);

#ifdef EMSCRIPTEN
        if( width > 20 || height > 20 )
            return getNextField();
#endif

        for( size_t i = 0; i < height; ++i )
        {
            for( size_t j = 0; j < width; ++j )
            {
                char cell;
                config >> cell;

                if( cell == '1' )
                    field.setBarrier(j, i);
                if( cell == 's' )
                    shipStartPosition = std::make_tuple(j, i, true);
                if( cell == 'S' )
                    shipStartPosition = std::make_tuple(j, i, false);
                if( cell == 'f' )
                    shipEndPosition = std::make_tuple(j, i, true);
                if( cell == 'F' )
                    shipEndPosition = std::make_tuple(j, i, false);
            }
        }
    }

    return std::make_tuple(field, shipStartPosition, shipEndPosition);
}

void FieldLoader::loadFieldNames()
{
    std::fstream config("fields/names.txt");

    while( !config.eof() )
    {
        char name[256];
        config.getline(name, 256);

        std::string strName(name);
        if( strName.empty() )
            continue;

        _fieldNames.push_back(strName);
    }
}

std::string FieldLoader::getNextFieldName()
{
    if( _fieldNames.empty() )
        return "";

    const std::string& result = _fieldNames[_fieldNameIter];

    _fieldNameIter += 1;

    if( _fieldNameIter >= _fieldNames.size() )
        _fieldNameIter = 0;

    return result;
}
