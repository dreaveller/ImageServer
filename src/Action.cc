#include "Action.h"
#include <stdio.h>
#include "HTTPEntity.h"

char* exampleResponse()
{
    char *buf = "example";
    return buf;
}

int sendRandomImage(int fd, HTTPResponse hTTPResponse)
{
    char buff[4096];

}