#include <stdio.h>

int main(int argc, char **argv) {
    #ifdef __GNUC__
        printf ("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
    #endif
}