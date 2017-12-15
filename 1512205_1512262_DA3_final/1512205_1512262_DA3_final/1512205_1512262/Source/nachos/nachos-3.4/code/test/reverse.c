/*reverse program*/
#include "syscall.h"

int
main()
{
    char s[128];
    int i, chk, ret;
    OpenFileID inpf, outf;
    WriteF("Input file name: ", 18, ConsoleOutput);
    ret = ReadF(s, 9, ConsoleInput);
    s[ret] = 0;
    inpf = OpenF(s, 1);
    if (inpf != -1) {
        WriteF("Output file name: ", 19, ConsoleOutput);
        ret = ReadF(s, 9, ConsoleInput);
        s[ret] = 0;
        chk = CreateF(s);
        if (chk == 0) {
            outf = OpenF(s, 0);
            for (i = SeekF(-1, inpf); i >= 0; --i) {
                ret = SeekF(i, inpf);
                if (ret == -1) break;
                ret = ReadF(s, 1, inpf);
                if (ret <= 0) break;
                WriteF(s, 1, outf);
            }
            CloseF(outf);
            WriteF("Reverse file: Success\n", 23, ConsoleOutput);
        } else WriteF("Cannot create file to copy\n", 28, ConsoleOutput);
        CloseF(inpf);
    } else WriteF("Input file not exist\n", 22, ConsoleOutput);
    Halt();
}
