#include <stdio.h>

void vuln() {
    char input[0x100];

    puts("I bet you can't exploit me ...\n");

    gets(input);
}

void call_me() {
    puts("Good job, you managed to exploit me, here's your flag:\n");
    puts("FLAG{c0ngr@t5 0n 50lv1ng y0Ur f1r5T ch@llEnge}\n");
    puts("... but can you solve challenge two?!\n");
}

int main() {

    vuln();

    return 0;
}
