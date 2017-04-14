#ifndef LBODY_H_
#define LBODY_H_

#include "body.h"

#include <stdio.h>

static const int DEFAULT_ARRAY_SIZE = 16;

typedef struct {
    body_t *bodies;

    int body_count;
    int array_size;
} lbody_t;

void lbody_initialize(lbody_t *list);

void lbody_cleanup(lbody_t *list);

void lbody_add(body_t *body, lbody_t *list);

void lbody_read(lbody_t *list, FILE *in);

static void lbody_extend(lbody_t* list);

#endif
