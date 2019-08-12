#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void* memcpy(void* dest,const void* src,size_t len){
    assert(dest!=NULL&&src!=NULL);
    char* des = (char*)dest;
    char* sr = (char*)src;
    while(--len>0){
        *des++ = *sr++;
    }
    return dest;
} 

int main(){
    int *src = (int*)malloc(10*sizeof(int)); 
    int *dest = (int*)malloc(30*sizeof(int));
    for(int i =0;i<10;i++)
        *(src+i) = i;
    for(int i = 0;i<30;i++)
        *(dest+i) = 5;
    
    memcpy(dest,src,10*sizeof(int));
    for(int i = 0;i<30;i++)
        printf("%d\t",*(dest+i));
    return 0;
}
