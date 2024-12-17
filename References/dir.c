#include <dirent.h>
#include <stdio.h>

int main() {
    DIR *d = opendir(".");
    if (d != NULL) {
        struct dirent *entry;
        while ((entry = readdir(d)) != NULL) {
            printf("Fichier : %s\n", entry->d_name);
        }
        closedir(d);
    }
    return 0;
}
