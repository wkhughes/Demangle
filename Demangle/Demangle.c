#include <windows.h>
#include <stdio.h>
#include <dbghelp.h>

#pragma comment(lib, "dbghelp")

#define MAX_DEMANGLED_SYMBOL_SIZE 1024

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        printf("Usage: Demangle mangledName [otherMangledNames...]\n");
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            char output[MAX_DEMANGLED_SYMBOL_SIZE];
            if (UnDecorateSymbolName(argv[i], output, sizeof(output), UNDNAME_COMPLETE))
            {
                puts(output);
            }
            else
            {
                printf("Failed to demangle %s, error code: %08X\n", argv[i], GetLastError());
            }
        }
    }
}
