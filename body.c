#include "body.h"

#include <stdlib.h>
#include <string.h>

body_t* body_create(char *name)
{
    body_t *body = malloc(sizeof *body);

    if (body == NULL) {
        return NULL;
    }

    body->name = malloc(strlen(name) + 1);

    if (body->name == NULL) {
        return NULL;
    }

    strcpy(body->name, name);

    return body;
}
