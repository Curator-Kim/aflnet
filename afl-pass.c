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

unsigned int collect_constraints_opcua(unsigned char * buf, unsigned int buf_size,unsigned char * pass_check){
    if(buf_size >= 12){
        if(strncmp(buf,"OPN",3) && *pass_check == 0){
            *pass_check = 0;
        }
        else{
            *pass_check = 1;
        }
        return buf[8] + (buf[9]<<8) + (buf[10]<<16) + (buf[11]<<12);
    }
    else{
        return 0;
    }
}

unsigned int conform_constraints_opcua(unsigned char * buf, unsigned int buf_size, unsigned int pass_value){
    if (buf_size >= 12){
        buf[8] = pass_value & 0xff;
        buf[9] = (pass_value >> 8) & 0xff;
        buf[10] = (pass_value >> 16) & 0xff;
        buf[11] = (pass_value >> 24);
        return 1;
    }
    return 0; 
}