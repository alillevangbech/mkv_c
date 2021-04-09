#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "network.h"
#include "base64.h"
//#include "utils/md5.h"
#include <openssl/md5.h>
#include <leveldb/c.h> 

int try_lvldb(void);
int try_curl(void);
int try_base64(void);
int try_md5(void);

int main(void)
{
    try_lvldb();
    try_curl();
    try_base64();
    try_md5();
}

/* ------------------------------------------------------------------------ */

int try_curl(void)
{
        // prints a bunch of stuff.
        http_get_example();
        return 0;
}

int try_base64(void)
{
        char* encoded;
        char* hey = "I dunno";
        int len = strlen(hey);
        encoded = malloc(Base64encode_len(len));
        Base64encode(encoded, hey, len);
        printf("base64 => %s: %s \n", hey, encoded);
        return 0;
}

int try_md5()
{
    char* str = "message digest";
    int len = strlen(str);

    unsigned char md5_result[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)str,len,md5_result);

    printf("md5 => %s: ",str);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        printf("%02x", md5_result[i]);
    }
    printf("\n");
    return 0;
}


int try_lvldb(void)
{
    /* intial */
    char* err = NULL;
    char* name = "testdb";
    char* read;
    size_t readlen;
    leveldb_options_t* lvldb_opt;
    leveldb_readoptions_t* lvldb_readopt;
    leveldb_writeoptions_t* lvldb_writeopt;
    leveldb_t* lvldb;

    /* open */
    lvldb_opt = leveldb_options_create();
    leveldb_options_set_create_if_missing(lvldb_opt,1);
    lvldb = leveldb_open(lvldb_opt, name, &err);

    if (err != NULL) {
        fprintf(stderr, "open fail\n");
        return 1;
    }
    leveldb_free(err); err = NULL;
    
    /* write */
    lvldb_writeopt = leveldb_writeoptions_create();
    leveldb_put(lvldb, lvldb_writeopt,"key",3,"value",5,&err);

    if (err != NULL) {
        fprintf(stderr, "write fail\n");
        return 1;
    }
    leveldb_free(err); err = NULL;

    /* read */
    lvldb_readopt = leveldb_readoptions_create();
    read = leveldb_get(lvldb, lvldb_readopt,"key",3, &readlen,&err);

    if (err != NULL) {
        fprintf(stderr, "read fail\n");
        return 1;
    }
    
    printf("leveldb => key: %s\n", read);

    leveldb_free(err); err = NULL;

    /* close */
    leveldb_close(lvldb);

    /*destroy*/
    leveldb_destroy_db(lvldb_opt, name, &err);

    if (err != NULL) {
        fprintf(stderr, "destroy fail\n");
        return 1;
    }
    return 0;
}

