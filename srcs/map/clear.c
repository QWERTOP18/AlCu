#include "interface.h"

void map_clear(t_map **m)
{
    free(*m);
    *m = NULL;
}
