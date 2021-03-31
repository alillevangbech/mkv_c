#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "network.h"
#include "utils/base64.h"
#include "utils/md5.h"

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

        // test md5
        const char* md5_string = "message digest";
        unsigned int md5_len = strlen(md5_string);

        const unsigned char md5_digest[MD5_DIGEST_SIZE];
        md5sum(md5_string,md5_len,md5_digest);

        printf("%s \n", md5_digest);
}
