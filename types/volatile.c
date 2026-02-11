volatile int flag = 0;

void interrupt_handler(void) {
    flag = 1;   // changed outside main program flow
}

int main(void) {
    while (flag == 0) {
        // compiler cannot optimize this loop
    }
}