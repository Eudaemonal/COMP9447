// You control the data coming over sockfd

char *readUsername(int sockfd)
{
    char *buf, *s, username[1024];
    int i;

    buf = (char *) malloc(1024);

    if(!buf)
    {
        error("buf allocation failed: %m");
        return NULL;
    }

    if(read(sockfd, username, sizeof(username)-1) <= 0)
    {
        free(buf);
        error("read failure: %m");
        return NULL;
    }

    username[sizeof(username)-1] = '\0';

    s = strchr(username, ':');
    
    if(s)
    {
        *s++ = '\0';
    }

    sprintf(buf, "username=%.32s", username);

    if(s)
    {
        snprintf(buf, sizeof(buf)-strlen(buf)-1, ", style=%s\n", s);
    }

    return buf;
}


