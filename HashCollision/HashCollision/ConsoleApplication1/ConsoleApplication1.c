#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
unsigned long hashcode = 0x21DD09EC;
unsigned long check_password(const char* p) {
    int* ip = (int*)p;
    int i;
    int res = 0;
    for (i = 0; i < 5; i++) {
        res += ip[i];
    }
    return res;
}

int main(int argc, char* argv[]) {
    char ans[20];
	std::cin >> ans;

    if (argc < 2) {
        printf("usage : %s [passcode]\n", ans);
        return 0;
    }
    if (strlen(ans) != 20) {
        printf("passcode length should be 20 bytes\n");
        return 0;
    }

    if (hashcode == check_password(ans)) {
        //system("/bin/cat flag");
        std::cout << "Good job\n";
        return 0;
    }
    else
        printf("wrong passcode.\n");
    return 0;
}