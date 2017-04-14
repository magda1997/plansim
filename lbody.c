#include "lbody.h"

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
