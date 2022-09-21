#include<stdio.h>
#include<sys/resource.h>
#include<string.h>

int main(){
  
    struct rlimit rlim;
    
    printf("default value for RLIMIT_FSIZE\n");
    getrlimit(RLIMIT_FSIZE,&rlim);
    printf("RLIMIT_FSIZE\t%lu\t%lu\n",rlim.rlim_cur,rlim.rlim_max);
    printf("new value for RLIMIT_FSIZE\n");
    rlim.rlim_cur = 327680123012;
    rlim.rlim_max = 327680123012;
    setrlimit(RLIMIT_FSIZE,&rlim);
    memset(&rlim,0,sizeof(rlim));
    getrlimit(RLIMIT_FSIZE,&rlim);
    printf("RLIMIT_FSIZE\t%lu\t%lu\n",rlim.rlim_cur,rlim.rlim_max);

    return 0;
}
