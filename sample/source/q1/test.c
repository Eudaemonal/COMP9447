// You control the data coming over sockfd

int isUsernameValid(char *user)
{
    char *delimiter;
    int c;

    delimiter = strchr(user, ':');

    if(delimiter)
    {
        c = *delimiter;
        *delimiter = '\0';
    }

    ...

    *delimiter = c;

    return 1;
}

int auth(int sockfd)
{
    char user[1024], *buf;
    size_t size;
    int n, cmd;

    cmd = readInt(sockfd);
    size = readInt(sockfd);

    if(size > MAX_PACKET)
        return -1;

    buf = (char *)calloc(size+1, sizeof(char));

    if(!buf)
        return -1;

    readString(buf, size);

    switch(cmd){
        case USERNAME:
            strncpy(user, buf, sizeof(user));
            if(!isUsernameValid(user))
                goto fail;
            break;
        ...
    }
}

