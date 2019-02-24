#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>

using namespace std;

unsigned char memory[32];
unsigned char acc, pc;
char line[9];

unsigned char lineToChar(char* s) {
    unsigned char result = 0;
    int base = 128;
    while(*s) {
        result += (*s - '0') * base;
        base = (base >> 1);
        s++;
    }
    return result;
}

void getResult(unsigned char num, char* result) {
    int i = 7;
    memset(result, '0', 8);
    result[8] = 0;
    while(num) {
        result[i--] = (num % 2 ) + '0';
        num = (num >> 1);
    }
}

unsigned char startProgram()
{
    unsigned char program, address, instruct;
    pc = 0;
    acc = 0;
    while(1)
    {
        instruct = memory[pc++];
        if(pc > 31) {
            pc=0;
        }
        program = (instruct >> 5);
        address = (instruct & 0x1f);
        
        switch(program) {
            case 0:
                memory[address] = acc;
                break;
            case 1:
                acc = memory[address];
                break;
            case 2:
                if(acc == 0) pc=address;
                break;
            case 3:
                break;
            case 4:
                acc--;
                break;
            case 5:
                acc++;
                break;
            case 6:
                pc=address;
                break;
            case 7:
                return acc;
                break;
        }
    }
    return acc;
}

void mainFunction() {
    int i = 0;
    unsigned char result;
    while(scanf("%s",line) != EOF)
    {
        memory[0] = lineToChar(line);
        for(i=1; i < 32; i++)
        {
            scanf("%s", line);
            memory[i] = lineToChar(line);
        }
        result = startProgram();
        getResult(result, line);
        printf("%s\n", line);
    }
}

int main()
{
    mainFunction();
    return 0;
}