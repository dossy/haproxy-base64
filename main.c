#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern const char *s30tob64(int in, char *out);
extern int b64tos30(const char *in);

int main(int argc, char *argv[])
{
    char str[6];

    if (argc < 3) {
        printf("Usage: %s [ s30tob64 | s32tob64 | b64tos30 | b64tos32 ] [input]\n", argv[0]);
        return -1;
    }

    if (!strcmp(argv[1], "s30tob64")) {
        printf("%s\n", s30tob64(atoi(argv[2]), str));
    } else if (!strcmp(argv[1], "s32tob64")) {
        printf("%s\n", s30tob64(atoi(argv[2]) >> 2, str));
    } else if (!strcmp(argv[1], "b64tos30")) {
        printf("%d\n", b64tos30(argv[2]));
    } else if (!strcmp(argv[1], "b64tos32")) {
        printf("%d\n", b64tos30(argv[2]) << 2);
    } else {
        printf("Usage: %s [ s30tob64 | b64tos30 ] [input]\n", argv[0]);
        return -1;
    }

    return 0;
}
