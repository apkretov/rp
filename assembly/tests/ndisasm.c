#include <stdio.h> // Disassembling code with NASM | Review ICS 312 @ http://courses.ics.hawaii.edu/ReviewICS312/morea/ControlStructures/reading-dissassemble.html

int main() {
        int i;
        int sum = 0x1234;

        sum += 0xABCDEF;
        for (i=0; i < 10; i++) {
                sum += i;
        }
        printf("sum=%d\n",sum);
        sum = 0x2345;
}