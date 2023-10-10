#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/fcntl.h>

int main(int argc,char *argv[]){
    // if(read(STDIN_FILENO,&numbers,sizeof(numbers))==-1){
    //     write(STDERR_FILENO,"ERror",5);
    //     exit(-1);
    // }
    char buffer[256];
    int sum;
    ssize_t bytes_read; // Объявляем переменную bytes_read здесь
    while((bytes_read=read(STDIN_FILENO,buffer,sizeof(buffer)))>0){
        int num;
        char *ptr=buffer;
        char *end=ptr+bytes_read;
        while(ptr<end){
            if(*ptr>='0' && *ptr<='9'){
                num=strtol(ptr,&ptr,10);
                sum+=num;
            }else{
                ptr++;
            }
        }

        write(STDOUT_FILENO,sum,256);
    }



}