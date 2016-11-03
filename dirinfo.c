#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main() {
    DIR* d = opendir(".");
    struct dirent* thing = readdir(d);
    int size = 0;
    printf("Files in this directory:\n");
    while (thing) {
        printf("%s", (*thing).d_name);
        if (thing->d_type == DT_DIR) {
            printf(" (a sub-directory)");
        } else {
            struct stat buf;
            stat((*thing).d_name, &buf);
            printf(" (%lli bytes)", buf.st_size);
            size += buf.st_size;
        }
        printf("\n");
        thing = readdir(d);
    }
    printf("Total size: %i bytes\n", size);
    return 0;
}