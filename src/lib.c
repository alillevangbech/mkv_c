
#include <stddef.h>
#include <string.h>
#include "lib.h"

const char *s =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";


/* This was a mistake ..

#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define SHA1 CC_SHA1
#else
#  include <openssl/md5.h>
#endif

void md5sum(unsigned char digest[16], char *str) 
{
        MD5_CTX ctx;
        MD5_Init(&ctx);
        MD5_Update(&ctx, str, strlen(str));
        MD5_Final(digest, &ctx);
}

*/ 
