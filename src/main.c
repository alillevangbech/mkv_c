#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "network.h"
#include "base64.h"

#if defined(__APPLE__)
#  include <CommonCrypto/CommonDigest.h>
#  define MD5 CC_MD5
#else
#  include <openssl/md5.h>
#endif


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
        unsigned char digest[16];
        MD5(hey, len, digest);
        printf("%d \n", digest[0]);

}
