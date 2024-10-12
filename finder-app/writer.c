#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){

    // open log
    openlog(NULL,0,LOG_USER);

    if (argc!=3) {
        syslog(LOG_ERR, "Invalid Number of arguments: %d", argc);
        closelog();
        return 1;
    }

    // input variables
    const char *writefile = argv[1];
    const char *writestr = argv[2];
    
    // read file
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Could not create or open file: %s", writefile);        
        fclose(file);
        closelog();
        return 1;
    }
    else {
        // write to file
        syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);        
        if (fprintf(file, "%s", writestr) < 0) {
            syslog(LOG_ERR, "Error: Could not write to file %s: %s", writefile, strerror(errno));
        }
        fclose(file);
        closelog();
        return 0;
    }
}