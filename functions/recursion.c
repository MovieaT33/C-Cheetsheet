/* Basic recursion syntax:
return_type function_name(parameters) {
    if (base_condition) {
        return base_value; // base case
    return function_name(modified_parameters); // recursive case
}
*/

int factorial(int n) {
    if (n <= 1) return 1;           // base case
    return n * factorial(n - 1);    // recursive case
}

int main(void) {
    int result = factorial(5); // 5! = 120
    main();
    return result;
}