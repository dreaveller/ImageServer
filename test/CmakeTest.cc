#include<iostream>
#include<fcntl.h>
#include<stdio.h>

int main() 
{
    FILE *f = fopen("../resource/response/normal.txt", "r");
    std::cout << fileno(f) << std::endl;

    // std::cout << open("../resource/response/normal.txt", O_RDONLY) << std::endl;
}