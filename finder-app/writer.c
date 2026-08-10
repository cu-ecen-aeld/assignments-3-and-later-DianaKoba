#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int writer(const char *writefile, const char *writestr)
{
    FILE *fp;
    openlog("ASSIGNMENT2", LOG_PID, LOG_USER);
    if (writefile == NULL || writestr == NULL) {
        syslog(LOG_ERR, "Error: two arguments required");
        closelog();
        return 1;
    }
    fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error: could not create file %s", writefile);
        closelog();
        return 1;
    }
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    if (fprintf(fp, "%s\n", writestr) < 0) {
        syslog(LOG_ERR, "Error: could not write to file %s", writefile);
        fclose(fp);
        closelog();
        return 1;
    }
    fclose(fp);
    closelog();
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        syslog(LOG_ERR, "Error: three  arguments required");
        return 1;
    }
    return writer(argv[1], argv[2]);
}
