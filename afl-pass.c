#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include "alloc-inl.h"
#include "afl-pass.h"

unsigned int collect_constraints_opcua(unsigned char * buf, unsigned int buf_size, unsigned char * pass_check, credentials * pass_value){
    /*
    buf:
    buf_size:
    pass_check: 
    */
    if(buf_size >= 32){
        if(!strncmp(buf,"OPN",3))
        {
            memcpy(pass_value -> val, buf + (buf_size - 24), 8);
            *pass_check = 1;
        }
        return *pass_check;
    }
    else
    {
        return 0;
    }
}

unsigned int conform_constraints_opcua(unsigned char * buf, unsigned int buf_size, credentials * pass_value){
    if (buf_size >= 16)
    {
        memcpy(buf + 8, pass_value -> val, 8);
        return 1;
    }
    return 0; 
}