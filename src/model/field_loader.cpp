// field_loader.cpp
#include "field_loader.h"

#include <fstream>
#include <iostream>

FieldLoader::FieldLoader()
{
    loadFieldNames();
}

Field FieldLoader::getNextField()
{
    std::ifstream config( "fields/" + getNextFieldName() );
    if( !config )
        return Field(1, 1);

    int width, height;
    config >> width >> height;
    Field field(width, height);

    for( size_t i = 0; i < width; ++i )
    {
        for( size_t j = 0; j < width; ++j )
        {
            char barrier;
            config >> barrier;
            if( barrier == '1' )
                field.setBarrier(i, j);
        }
    }

    return field;
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
        return {};

    _fieldNameIter += 1;

    if( _fieldNameIter >= _fieldNames.size() )
        _fieldNameIter = 0;

    return _fieldNames[_fieldNameIter];
}
