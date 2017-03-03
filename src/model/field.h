// field.h
#ifndef FIELD_H
#define FIELD_H

#include <vector>

class Field
{
    public:
        Field();
        Field(int width, int height);

        void setSize(int width, int height);
        int getWidth() const;
        int getHeight() const;

        void setBarrier(int x, int y);
        void removeBarrier(int x, int y);
        bool hasBarrier(int x, int y) const;

    private:
        void init(int width, int height);

    private:
        std::vector<std::vector<int>> _barriers;
};

#endif

