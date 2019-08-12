#include<stdio.h>
#include<assert.h>

char* strcpy(char* dest,const char* src){
    assert(dest!=NULL&&src!=NULL);
    char* tmp = dest;
    while((*dest++ = *src++)!='\0');
/*
    while(*src!='\0'){  //has not copy \0 !
        *dest++ = *src++;
    }
*/
    return tmp;
}

int main()
{
    char* src = "hello world\n";
    
    char dest[20];
    for(int i = 0;i<20;i++)
        dest[i] = 'a';
    printf("%s",strcpy(dest,src));
}
