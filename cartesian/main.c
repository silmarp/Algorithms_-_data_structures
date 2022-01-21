#include <stdio.h>
#include <stdlib.h>
#include "descartes.h"


int main(){
    int n_de_pontos;
    float total_distance=0;

    scanf("%i", &n_de_pontos);

    
    Point *pontos = calloc(n_de_pontos, sizeof(Point));
    Distance *distancias=calloc(n_de_pontos-1, sizeof(Distance));


    for(int i=0;i<n_de_pontos;i++){
        scanf("%f %f", &pontos[i].x, &pontos[i].y);
    }

    // distancia entre um ponto e nada = 0;
    if(n_de_pontos<=1){
        printf("%.2f\n", total_distance);
        free(pontos);
        free(distancias);
        return 0;
    }    

    for(int i=0;i<n_de_pontos-1;i++){
        distancias[i].d = d_between_points(pontos[i], pontos[i+1]);
    }

    for(int i=0;i<n_de_pontos-1;i++){
        total_distance += distancias[i].d;
    }


    printf("%.2f\n", total_distance);
    free(pontos);
    free(distancias);

    return 0;

}
