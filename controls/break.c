// break; // error: expected identifier or '(' before 'break'

int main(void)
{
    // break; // error: break statement not within loop or switch

    // if (0) break; // error: break statement not within loop or switch

    // `while` loop
    int count = 0;
    while (count < 10) {
        if (count == 5) break; // exit loop when count == 5
        count++;
    }

    // `for` loop
    for (char i = 0; i < 15; i++) {
        if (i == 10) break; // exit loop when i == 10
    }

    // Nested loops
    for (short j = 0; j < 3; j++)
    {
        for (short k = 0; k < 3; k++)
        {
            if (j == k)
                break;
        }
    }

    // `do { ... } while` loop
    long l = 0;
    do {
        if (l == 3) break; // exit loop when l == 3
        l++;
    } while(l < 10);

    // Switch statements
    long long val = 1;
    switch (val) {
        case 1:
            break; // exit switch
        case 2:
            break; // exit switch
        default:
            break;
    }

    switch (val) {
        case 1:
            switch (val) {
                case 2:
                    break;
            }
            break;
    }
}