/**/
typedef struct{
    char num;       /*number of ...*/
    short *pos;       /*position ...*/
    char *val;       /*the check value....*/
} credentials;


unsigned int collect_constraints_opcua(unsigned char * buf, unsigned int buf_size, unsigned char * pass_check, credentials * pass_value);
extern unsigned int (*collect_constraints)(unsigned char * buf, unsigned int buf_size, unsigned char * pass_check, credentials * pass_value);

unsigned int conform_constraints_opcua(unsigned char * buf, unsigned int buf_size, credentials * pass_value);
extern unsigned int (*conform_constraints)(unsigned char * buf, unsigned int buf_size, credentials * pass_value);