#include <unistd.h>

int main(int argc, char* argv[]) {
    char str[] = "Hello, World!\n";
    write(1, str, sizeof(str) - 1); // Почему sizeof(str) - 1? Потому, что строка в Си заканчивается нулевым байтом, а его нам печатать не нужно.
    _exit(0);
}