#ifndef DESCARTES_H_INCLUDED
#define DESCARTES_H_INCLUDED

// structs ------

struct point {
    float x;
    float y;
};

struct distance{
    float d;
};

// typedefs ------

typedef struct point Point;
typedef struct distance Distance;


// funções ------

float d_between_points(Point initial, Point final);

#endif // DESCARTES_H_INCLUDED