#ifndef BODY_H_
#define BODY_H_

typedef struct {
    char *name;
    double mass;
    double x, y, z;
    double vx, vy, vz;
} body_t;

body_t* body_create(char *name);

void body_cleanup(body_t *body);

void body_print(body_t *body);

#endif 
