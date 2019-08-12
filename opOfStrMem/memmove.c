#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void* memmove(void* dest,const void* src,size_t len){
    assert(dest!=NULL&&src!=NULL);
    char* des = (char*)dest;
    char* sr = (char*)src;
    if(des>sr&&des<sr+len){
        for(int i = len-1;i>=0;i--){
            *(des+i) = *(sr+i);
        }
    }else{
        while(--len>0){
            *des++ = *sr++;
        }
    }
    return dest;
} 

int main(){
    int *src = (int*)malloc(40*sizeof(int)); 
    int *dest = src+10;
    for(int i =0;i<40;i++)
        *(src+i) = i;
    
    memmove(dest,src,30*sizeof(int));
    for(int i = 0;i<30;i++)
        printf("%d\t",*(dest+i));
    return 0;
}
