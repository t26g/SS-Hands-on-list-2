#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", hard, unit);

    printf("====================\n");
}

void main()
{
    int status;
    struct rlimit resourceLimits;
    status = getrlimit(RLIMIT_AS, &resourceLimits);
    print("Max size of process's virtual memory", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    status = getrlimit(RLIMIT_CORE, &resourceLimits);
    print("Max size of a core file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    status = getrlimit(RLIMIT_CPU, &resourceLimits);
    print("Max CPU time that the process can consume", resourceLimits.rlim_cur, resourceLimits.rlim_max, "seconds");
    status = getrlimit(RLIMIT_DATA, &resourceLimits);
    print("Max size of process's data segement", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    status = getrlimit(RLIMIT_FSIZE, &resourceLimits);
    print("Max size of files that  the  process  may  create", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    status = getrlimit(RLIMIT_LOCKS, &resourceLimits);
    print("Max number of locks that a process may establish", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");
    status = getrlimit(RLIMIT_MEMLOCK, &resourceLimits);
    print("Max number of bytes of memory that may be locked into RAM", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    status = getrlimit(RLIMIT_MSGQUEUE, &resourceLimits);
    print("Max number of bytes of that can be allocated for POSIX message queues", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    status = getrlimit(RLIMIT_NICE, &resourceLimits);
    print("Ceiling of the process's nice value", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");
    status = getrlimit(RLIMIT_NOFILE, &resourceLimits);
    print("Max file descriptor", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    status = getrlimit(RLIMIT_NPROC, &resourceLimits);
    print("Limit on the number of threads", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");
    status = getrlimit(RLIMIT_RSS, &resourceLimits);
    print("Limit on the  number of virtual pages resident in the RAM", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    status = getrlimit(RLIMIT_RTPRIO, &resourceLimits);
    print("Ceiling on the real-time priority", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");
    status = getrlimit(RLIMIT_RTTIME, &resourceLimits);
    print("Amount of CPU time that a  process scheduled  under a real-time scheduling policy", resourceLimits.rlim_cur, resourceLimits.rlim_max, "ms");
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    print("The number of signals that may be queued", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");
    print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
}
