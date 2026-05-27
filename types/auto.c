auto int main(void) // warning: function definition declared 'auto'
{
    auto int a = 5; // storage-class (stack) specifier. Only historical. No sense

    // Error: multiple storage classes in declaration specifiers
    // static auto var;
    // register auto var;
}