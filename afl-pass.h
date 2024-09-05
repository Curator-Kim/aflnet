/**/
typedef struct{
    char num;       /*number of ...*/
    int *pos;       /*position ...*/
    int *val;       /*the check value....*/
} credentials;


unsigned int collect_constraints_opcua(unsigned char * buf, unsigned int buf_size, unsigned char * pass_check);
extern unsigned int* (*collect_constraints)(unsigned char * buf, unsigned int buf_size, unsigned char * pass_check);

unsigned int conform_constraints_opcua(unsigned char * buf, unsigned int buf_size, unsigned int pass_value);
extern unsigned int (*conform_constraints)(unsigned char * buf, unsigned int buf_size, unsigned int pass_value);