#include "lbody.h"

#include "body.h"

#include <stdlib.h>
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

static void lbody_extend(lbody_t *list)
{
    body_t *bodies = realloc(list->bodies, list->array_size * 2 * sizeof *bodies);

    if (bodies == NULL) {
        fprintf(stderr, "Rozszerzenie tablicy nie powiodlo sie.\n");
        return;
    }

    list->bodies = bodies;
    list->array_size *= 2;
}

/*void lbody_add(body_t *body, lbody_t *list)
{
    if (list->body_count == list->array_size) {
        lbody_extend(list);
    }

    list->bodies[list->body_count++] = body;
}*/
