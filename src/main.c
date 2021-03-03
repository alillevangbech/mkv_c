#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "network.h"
#include "base64.h"

int main(void)
{
        // prints a bunch of stuff.
        http_get_example();

        // test base64
        char *encoded;
        char hey[] = "I dunno";
        int len = strlen(hey);
        encoded = malloc(Base64encode_len(len));
        Base64encode(encoded, hey, len);
        printf("%s \n", encoded);

}
