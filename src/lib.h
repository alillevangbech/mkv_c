

typedef enum Deleted
{
    NO,
    SOFT,
    HARD,
} Deleted;

typedef struct Record
{
    char** rvolumes;
    Deleted deleted;
    char* hash;
} Record;

typedef struct sortvol
{
    char** score;
    char* string;
} sortvol;

/*
Record ToRecord(char** data);
char** FromRecord(Record rec);
char* Key2Path(char** key)
*/

