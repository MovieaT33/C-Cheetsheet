// break; // Error

int main(void) {
    // `while` loop
    int count = 0;
    while (count < 10) {
        if(count == 5) break; // exit loop when count == 5
        count++;
    }

    // `for` loop
    for(int i = 0; i < 10; i++) {
        if (i == 7) break; // exit loop when i == 7
    }

    // `do ... while` loop
    int j = 0;
    do {
        if (j == 3) break; // exit loop when j == 3
        j++;
    } while(j < 10);

    // Switch statement
    int value = 2;
    switch (value) {
        case 1:
            break; // exit switch
        case 2:
            break; // exit switch
        default:
            break;
    }
}
