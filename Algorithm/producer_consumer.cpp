#include<iostream>
#include<pthread.h>
#include<stdio.h>

using namespace std;

int count = 0;
pthread_t ptid[2];
pthread_mutex_t mutex;
pthread_cond_t cond[2];

void* producer(void* arg){
    while(1){
        pthread_mutex_lock(&mutex);
        while(count>=5)
            pthread_cond_wait(&cond[1],&mutex);
        ++count;
        pthread_cond_signal(&cond[0]);
        cout<<"produce one,count is"<<count<<endl;
        pthread_mutex_unlock(&mutex);
    }
    return (void*)0;
}

void* consumer(void* arg){
    while(1){
        pthread_mutex_lock(&mutex);
        while(count<=0)
            pthread_cond_wait(&cond[0],&mutex);
        --count;
        pthread_cond_signal(&cond[1]);
        cout<<"consume for one,cout is"<<count<<endl;
        pthread_mutex_unlock(&mutex);
    }
    return (void*)0;
}


int main(){
    pthread_mutex_init(&mutex,NULL);
    for(int i =0;i<2;i++)
        pthread_cond_init(&cond[i],NULL);

    if(pthread_create(&ptid[0],NULL,producer,NULL)!=0){
        perror("pthread create error!\n");
    }
    if(pthread_create(&ptid[1],NULL,consumer,NULL)!=0){
        perror("pthread create error!\n");
    }

    for(int i = 0;i<2;i++)
        pthread_join(ptid[i],NULL);

    pthread_mutex_destroy(&mutex);
    for(int i =0;i<2;i++)
        pthread_cond_destroy(&cond[i]);
    
    return 0;
}
