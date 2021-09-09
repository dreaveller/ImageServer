#ifndef _HTTPENTITY_
#define _HTTPENTITY_

struct HTTPRequest
{
    char *method;
    char *url;
    char *version;

    char *body;
};

struct HTTPResponse
{
    char *version;
    char *status;
    char *comment;

    char *body;
};

#endif