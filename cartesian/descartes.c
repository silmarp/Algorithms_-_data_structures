#include "descartes.h"
#include <math.h>


float d_between_points(Point initial, Point final){
    float result, x_diff, y_diff;

    x_diff=final.x-initial.x;
    y_diff=final.y-initial.y;
    
    result = sqrt((x_diff*x_diff)+(y_diff*y_diff));
    
    return result;
}