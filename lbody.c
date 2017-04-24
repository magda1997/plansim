#include "lbody.h"

#include "body.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    char *buf = NULL;
    long unsigned int n = 0;

    while (n = getline(&buf, &n, in) != -1) {
	n++;
        char *tmp = buf;

        char *name = strsep(&tmp, " ");

        body_t *b = body_create(name);
        if (b == NULL) {
            fprintf(stderr, "Blad: Niewystarczajaca ilosc pamieci.\n");
            exit(EXIT_FAILURE);
        }

        if (sscanf(tmp, "%lf %lf %lf %lf %lf %lf %lf", 
            &b->mass, &b->x, &b->y, &b->z, &b->vx, &b->vy, &b->vz) != 7) {
            fprintf(stderr, "Blad: zbyt malo parametrow, cialo pominiete.\n");
        } else {
            lbody_add(b, list);
            body_print(b);
        }
    }
}

static void lbody_extend(lbody_t *list)
{
    body_t **bodies = realloc(list->bodies, list->array_size * 2 * sizeof *bodies);

    if (bodies == NULL) {
        fprintf(stderr, "Rozszerzenie tablicy nie powiodlo sie.\n");
        return;
    }

    list->bodies = bodies;
    list->array_size *= 2;
}

void lbody_add(body_t *body, lbody_t *list)
{
    if (list->body_count == list->array_size) {
        lbody_extend(list);
    }

    list->bodies[list->body_count++] = body;
}

void lbody_cleanup(lbody_t *list)
{
    int i;
    for (i = 0; i < list->body_count; i++) {
        body_cleanup(list->bodies[i]);
    }

    free(list->bodies);
}
