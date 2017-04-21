#include "lbody.h"

#include "body.h"

#include <stdio.h>
#include <stdlib.h>

void lbody_initialize(lbody_t *list)
{
    list->bodies = malloc(DEFAULT_ARRAY_SIZE * sizeof *(list->bodies));

    if (list->bodies == NULL) {
        return;
    }

    list->body_count = 0;
    list->array_size = DEFAULT_ARRAY_SIZE;
}

void lbody_read(lbody_t *list, FILE *in)
{
    char name[256];
    double mass;
    double x,y,z;
    double vx,vy,vz;

	while (fscanf(in, "%s %lf %lf %lf %lf %lf %lf %lf", name, &mass, &x, &y, &z, &vx, &vy, &vz) == 8) {
	    if (mass < 0) {
	        fprintf(stderr, "Masa nie moze byc ujemna, cialo pominiete.\n");
	        continue;
        }
        
        body_t *body = body_create(name);
        
        if (body != NULL) {
            body->mass = mass;
            body->x = x;
            body->y = y;
            body->z = z;
            body->vx = vx;
            body->vy = vy;
            body->vz = vz;
            
            lbody_add(body, list);
        }   
    }
}
