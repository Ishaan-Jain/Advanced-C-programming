#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(strcmp(argv[1],"-c") == 0 && argc != 3)
    {
        printf("[ERROR] Usage: %s <-c> <filename>\n", argv[0]);
        return 0;
    }
    if(strcmp(argv[1],"-d") == 0 && argc != 3)
    {
        printf("[ERROR] Usage: %s <-d> <filename>\n", argv[0]);
        return 0;
    }
    if(strcmp(argv[1],"-r") == 0 && argc != 4)
    {
        printf("[ERROR] Usage: %s <-r> <filename1> <filename2>\n", argv[0]);
        return 0;
    }
    if(strcmp(argv[1],"-c") != 0 && strcmp(argv[1],"-d") != 0 && strcmp(argv[1],"-r") != 0)
    {
        printf("[ERROR] Usage: %s <argument> <filename1> <filename2>(if required)\n", argv[0]);
        return 0;
    }
    if(strcmp(argv[2],"-c") == 0 || strcmp(argv[2],"-d") == 0 || strcmp(argv[2],"-r") == 0)
    {
         printf("[ERROR] Usage: %s <argument> <filename1> <filename2>(if required)\n", argv[0]);
         return 0;
    }

    DIR *dp;
    struct dirent *ep;
    int flag_c = 0;
    int flag_d = 0;
    int flag_r = 1;
    int flag_r2 = 0;

    dp = opendir("./");
    if(dp != NULL)
    {
        while((ep = readdir(dp)))
        {   
            if(strcmp(argv[1],"-r") == 0)
            {
                 if(strcmp(ep->d_name,argv[3]) == 0)
                {
                    flag_r = 0;
                }
            }
           
            if(strcmp(ep->d_name,argv[2]) == 0 )
            {
                flag_c = 1;
                flag_d = 1;
                flag_r2 = 1;
            }
        }

        if(strcmp(argv[1],"-r") == 0)
        {
            if(flag_r == 1 && flag_r2 == 1)
            {
                if(rename(argv[2],argv[3]) == -1 )
                {
                    printf("Error in renaming\n");
                    (void) closedir(dp);
                    return 0;
                }
                printf("The first filename is renamed to the second\n");
                (void) closedir(dp);
                return 0;
            }
            else{
                printf("Conditions for renaming not met\n");
                (void) closedir(dp);
                return 0;
            }
        }
        if(strcmp(argv[1],"-c") == 0)
        {
            if(flag_c == 1)
            {
                printf("Filename already exists within the current directory\n");
                (void) closedir(dp);
                return 0;
            }
            else
            {
                FILE *fp = fopen(argv[2],"w");
                printf("Filename created within the current directory\n");
                fclose(fp);
                (void) closedir(dp);
                return 0;
            }
        }
        if(strcmp(argv[1],"-d") == 0)
        {
            if(flag_d == 1)
            {
                int r = remove(argv[2]);
                if(r == -1)
                {
                    printf("error in deletion of filename\n");
                    (void) closedir(dp);
                    return 0;
                }

                printf("Filename deleted within the current directory\n");
                (void) closedir(dp);
                return 0;
            }
            else{
                printf("Filename does not exist within the current directory\n");
                (void) closedir(dp);
                return 0;
            }
        }
        (void) closedir(dp);
    }
    else
    {
        perror("Could not open directory");
    }

    

    return 0;
}
