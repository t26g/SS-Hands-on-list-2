#include <unistd.h>
#include <stdio.h>
void print(char *text, long value, char *unit)
{
    printf("%s - %ld %s\n", text, value, unit);
    printf("========================\n");
}

void main()
{
    long value;value = sysconf(_SC_ARG_MAX);
    print("Maximum length of the arguments to the exec family of functions", value, "");
    value = sysconf(_SC_CHILD_MAX);
    print("Maximum number of simultaneous process per user id", value, "");
    value = sysconf(_SC_CLK_TCK);
    print("Number of clock ticks (jiffy) per second", value, "");
    value = sysconf(_SC_OPEN_MAX);
    print("Maximum number of open files", value, "");
    value = sysconf(_SC_PAGESIZE);
    print("Size of a page", value, "bytes");
    value = sysconf(_SC_PHYS_PAGES);
    print("Total number of pages in the physical memory", value, "");
    value = sysconf(_SC_AVPHYS_PAGES);
    print("Number of  currently available pages in the physical memory", value, "");

}
