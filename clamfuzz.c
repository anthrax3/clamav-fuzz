#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <clamav.h>

int main(int argc, char *argv[])
{
    cl_init(CL_INIT_DEFAULT);
    struct cl_engine *engine = cl_engine_new();
    cl_engine_compile(engine);
    const char *virusName = NULL;
    long unsigned int scanned = 0;
    while(__AFL_LOOP(1000))
        cl_scanfile(argv[1], &virusName, &scanned, engine, CL_SCAN_STDOPT);
    cl_engine_free(engine);
}
